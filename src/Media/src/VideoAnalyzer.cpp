﻿//
// LibSourcey
// Copyright (C) 2005, Sourcey <http://sourcey.com>
//
// LibSourcey is is distributed under a dual license that allows free, 
// open source use and closed source use under a standard commercial
// license.
//
// Non-Commercial Use:
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// 
// Commercial Use:
// Please contact mail@sourcey.com
//


#include "Sourcey/Media/VideoAnalyzer.h"


using namespace std;
using namespace Poco;


namespace Sourcey {
namespace Media {


VideoAnalyzer::VideoAnalyzer(const Options& options) : 
	_options(options),
	_video(NULL),
	_audio(NULL),
	_videoConv(NULL)
{
	LogTrace() << "[VideoAnalyzer:" << this <<"] Creating" << endl;
}


VideoAnalyzer::~VideoAnalyzer() 
{
	LogTrace() << "[VideoAnalyzer:" << this <<"] Destroying" << endl;
	
	if (_video)
		delete _video;
	if (_videoConv)
		delete _videoConv;
	if (_audio)
		delete _audio;
}

void VideoAnalyzer::start()
{
	FastMutex::ScopedLock lock(_mutex); 

	if (_options.ifile.empty())
		throw Poco::FileException("Please specify an input file.");

	//if (_options.ofile.empty())
	//	throw Poco::FileException("Please specify an output file.");

	LogTrace() << "[VideoAnalyzer:" << this <<"] Loading: " << _options.ifile << endl;

	_error = "";
	
	try 
	{
		// Open the output file.
		//_ofile.open(_options.ofile.data(), ios::out | ios::binary);
		//if (!_ofile.is_open())		
		//	throw Poco::OpenFileException("Cannot open output file: " + _options.ofile);

		// Open the input file decoder.
		_reader.openFile(_options.ifile);
		
		if (_reader.video()) {
			//if (_options.maxFPS)
			//	_reader.video()->maxFPS = _options.maxFPS;
			_video = new VideoAnalyzer::Stream("Video");
			_video->initialize(_options.numFFTBits, sizeof(*_video->rdftData) *
				(_reader.video()->ctx->width * 
				 _reader.video()->ctx->height));
			_videoConv = NULL;
		}

		if (_reader.audio()) {
			//if (_options.maxFPS)
			//	_reader.audio()->maxFPS = _options.maxFPS;
			_audio = new VideoAnalyzer::Stream("Audio");
			_audio->initialize(_options.numFFTBits, AVCODEC_MAX_AUDIO_FRAME_SIZE
				//sizeof(*_audio->rdftData) *
				//(_reader.audio()->stream->codec->frame_size * 2 * 
				// _reader.audio()->stream->codec->channels)
				 );
		}
	
		_reader += packetDelegate(this, &VideoAnalyzer::onVideo);
		_reader += packetDelegate(this, &VideoAnalyzer::onAudio);

		_reader.ReadComplete += delegate(this, &VideoAnalyzer::onReadComplete);
		if (_options.blocking)
			_reader.run();
		else
			_reader.start();
	} 
	catch (Exception& exc) 
	{
		_error = exc.displayText();
		LogError() << "[VideoAnalyzer:" << this << "] Error: " << _error << endl;
		exc.rethrow();
	}
}


void VideoAnalyzer::stop() 
{
	LogTrace() << "[VideoAnalyzer:" << this <<"] Destroying" << endl;
	
	// Can't lock here in case we inside a callback.
	//FastMutex::ScopedLock lock(_mutex); 
	
	_reader.ReadComplete -= delegate(this, &VideoAnalyzer::onReadComplete);
	_reader -= packetDelegate(this, &VideoAnalyzer::onVideo);
	_reader -= packetDelegate(this, &VideoAnalyzer::onAudio);
	_reader.stop();
	//_ofile.close();
}


void VideoAnalyzer::processSpectrum(VideoAnalyzer::Stream& stream, double time)
{
    av_rdft_calc(stream.rdft, stream.rdftData);

	/*
//#define NBITS   8
//#define N       (1<<(NBITS)) // 256
    volatile FFTSample av_re = stream.rdftData[0];
    volatile FFTSample av_im = 0;
    for (int i = 1; i < N/2; i += 2) {
        av_re = stream.rdftData[i];
        av_im = stream.rdftData[i+1];
		printf("re=%10f im=%10f im=%10f\n", prefix##_re, prefix##_im)
    }
    av_re = stream.rdftData[1];
    av_im = 0;
	return;

	double val = 0.0;
	double min = 99999.9;
	double max = -99999.9;
	stream.name, 
	*/

	VideoAnalyzer::Packet packet(time);
	double sum = 0.0;
	double avg = 0.0;

	//for (int i = 0; i < _options.fftPoints / 2; ++i) {
	//for (int i = 1; i < N/2; i += 2) {
	for (int i = 0; i < stream.filled / 2; i += 2) {
	    packet.value = GetFrequencyIntensity(stream.rdftData[i], stream.rdftData[i+1]);
		if (packet.value > packet.max)
			packet.max = packet.value;
		if (packet.value < packet.min)
			packet.min = packet.value;
		//printf("re=%10f im=%10f im=%10f\n", stream.rdftData[i], stream.rdftData[i+1]);
		//LogTrace() << "[VideoAnalyzer:" << this << "] Value: " 
		//	<< stream.rdftData[i] << ": " << stream.rdftData[i+1] << endl;
		sum += packet.value; 
	}

	// TODO: Better way of gathering avg?
	// Not all FFT values are useful.
	avg = sum / (stream.filled / 4);
	packet.value = avg;	

	PacketOut.dispatch(this, stream, packet);
	//writeCSV(stream.name, time, avg, min, max);
}


/*
void VideoAnalyzer::writeCSV(const VideoAnalyzer::Packet& packet) //, double avg
{
	LogTrace() << "[VideoAnalyzer:" << this << "] Writing:"
		<< packet.name << "," << packet.time << "," << packet.value << "," 
		<< packet.min << "," << packet.max << endl;

	_ofile << packet.name << "," << packet.time << "," << 
		packet.value << "," << packet.min << "," << packet.max << "\r\n";
}
*/


void VideoAnalyzer::onVideo(void* sender, VideoPacket& packet)
{
	LogTrace() << "[VideoAnalyzer:" << this << "] On Video: " 
		<< packet.size() << ": " << packet.time << endl;
	
	FastMutex::ScopedLock lock(_mutex); 

	VideoDecoderContext* video = _reader.video();
	
	/*
	// Skip frames if we exceed the maximum processing framerate.
	double fps = _video->frames / packet.time;
	if (_options.maxFPS > 0 && fps > _options.maxFPS) {
		LogTrace() << "[VideoAnalyzer:" << this << "] Skipping video frame at fps: " << fps << endl;
		return;
	}
	*/

	_video->frames++;	
		
	/*
	// Create and allocate the conversion frame.
	if (oframe == NULL) {
		oframe = avcodec_alloc_frame();	
		if (oframe == NULL)
			throw Exception("Video Analyzer: Unable to allocate the output video frame.");

		avpicture_alloc(reinterpret_cast<AVPicture*>(oframe), 
			PIX_FMT_GRAY8, video->ctx->width, video->ctx->height);
	}
	
	// Convert the image from its native format to GREY8.
	if (_videoConv == NULL) {
		_videoConv = sws_getContext(
			video->ctx->width, video->ctx->height, video->ctx->pix_fmt, 
			video->ctx->width, video->ctx->height, PIX_FMT_GRAY8, 
			SWS_BICUBIC, NULL, NULL, NULL);
	}
	*/
	if (_videoConv == NULL) {
		
		VideoCodec iparams;
		iparams.width = video->ctx->width;
		iparams.height = video->ctx->height;
		iparams.pixelFmt = av_get_pix_fmt_name(video->ctx->pix_fmt);
		VideoCodec oparams;
		oparams.width = video->ctx->width;
		oparams.height = video->ctx->height;
		oparams.pixelFmt = "gray";
		
		_videoConv = new VideoConversionContext();
		_videoConv->create(iparams, oparams);
	}
	if (_videoConv == NULL)
		throw Exception("Video Analyzer: Unable to initialize the video conversion context.");	
		
	// Convert the source image to grayscale.
	AVFrame* oframe = _videoConv->convert(video->frame);

	/*
	if (sws_scale(_videoConv,
		video->frame->data, video->frame->linesize, 0, video->ctx->height,
		oframe->data, oframe->linesize) < 0)
		throw Exception("Video Analyzer: Pixel format conversion not supported.");
		*/

	// Populate the FFT input data.
	// Examples:
	//	http://stackoverflow.com/questions/7790877/forward-fft-an-image-and-backward-fft-an-image-to-get-the-same-result
	//	http://code.google.com/p/video-processing-application/source/browse/trunk/+video-processing-application/untitled6/Fourier/highpassrgb.cpp
	//	http://codepaste.ru/9226/
	_video->filled = 0;
	for (int y = 0; y < video->ctx->height; y++) {
		for (int x = 0; x < video->ctx->width; x++) {
			_video->filled = y * video->ctx->width + x; // * 3;
			_video->rdftData[_video->filled] = (float)oframe->data[0][_video->filled] * pow(-1.0, y + x);
		}
	}

	processSpectrum(*_video, packet.time);
}


void VideoAnalyzer::onAudio(void* sender, AudioPacket& packet)
{
	//LogTrace() << "[VideoAnalyzer:" << this << "] On Audio: " << packet.size() << ": " << packet.time << endl;	

	FastMutex::ScopedLock lock(_mutex); 
		
	/*
	// Skip frames if we exceed the maximum processing framerate.
	double fps = _audio->frames / packet.time;
	if (_options.maxFPS > 0 && fps > _options.maxFPS) {
		LogTrace() << "[VideoAnalyzer:" << this << "] Skipping audio frame at fps: " << fps << endl;
		return;
	}
	*/
	_audio->frames++;
	
	short const* data = reinterpret_cast<short*>(packet.data());	
	int size = packet.size(); //FFMIN(_reader.audio()->frameSize, packet.size());
	int channels = _reader.audio()->stream->codec->channels;
	//int filled = 0;
	
	// Packet size / 2 = 2 bytes per sample (short)
	// Example at http://blackhole.ubitux.fr/bench-fftw-ffmpeg-fft/fft.c
	_audio->filled = 0;
    for (int i = 0; i < size / 2; i += channels) {
        int k, v = 0;
        for (k = 0; k < channels; k++) // mix channels
            v += data[i + k];

        _audio->rdftData[_audio->filled++] = (float)v / channels / SHRT_MAX;
        //if (filled == _options.fftPoints) {
        //    processSpectrum(_audio, packet.time);
        //    filled = 0;
        //}
    }

	processSpectrum(*_audio, packet.time);
}


void VideoAnalyzer::onReadComplete(void* sender)
{
	LogTrace() << "[VideoAnalyzer:" << this << "] On Read Complete" << endl;	

	AVInputReader* reader = reinterpret_cast<AVInputReader*>(sender);	
	{
		FastMutex::ScopedLock lock(_mutex); 
		if (_error.empty())
			_error = reader->error();
	}

	Complete.dispatch(this);
}


AVInputReader& VideoAnalyzer::reader()
{ 
	FastMutex::ScopedLock lock(_mutex);
	return _reader; 
}


/*
std::ofstream& VideoAnalyzer::ofile()
{ 
	FastMutex::ScopedLock lock(_mutex);
	return _ofile; 
}
*/


VideoAnalyzer::Options& VideoAnalyzer::options()
{ 
	FastMutex::ScopedLock lock(_mutex);
	return _options; 
}


string VideoAnalyzer::error() const
{
	FastMutex::ScopedLock lock(_mutex);	
	return _error;
}


// ---------------------------------------------------------------------
//
VideoAnalyzer::Packet::Packet(double time, double value, double min, double max) : //const std::string& name, 
			time(time), value(value)/*name(name), , min(min), max(max)*/
{	
	this->min = min;
	this->max = max;
}
	

// ---------------------------------------------------------------------
//
VideoAnalyzer::Stream::Stream(const std::string& name) : //, int rdftBits, int rdftSize
	name(name), rdft(NULL), rdftData(NULL), lastPTS(0), frames(0), filled(0)
{	
}
	

VideoAnalyzer::Stream::~Stream()
{
	uninitialize();
}

	
void VideoAnalyzer::Stream::initialize(int rdftBits, int rdftSize)
{
	LogTrace() << "[VideoAnalyzerStream:" << this << ":" << name << "] Initializing" << endl;	

	lastPTS		= 0;
	frames		= 0;
	filled		= 0;
	rdft		= av_rdft_init(rdftBits, DFT_R2C);
	rdftData	= (FFTSample*)av_malloc(rdftSize);
}

	
void VideoAnalyzer::Stream::uninitialize()
{
	LogTrace() << "[VideoAnalyzerStream:" << this << ":" << name << "] Uninitializing" << endl;	
	
	if (rdft)
		av_rdft_end(rdft);
	if (rdftData)
		av_free(rdftData);
}


} } // namespace Sourcey::Media