# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/deploy/src/libsourcey

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/deploy/src/libsourcey/build

# Include any dependencies generated for this target.
include src/util/CMakeFiles/util.dir/depend.make

# Include the progress variables for this target.
include src/util/CMakeFiles/util.dir/progress.make

# Include the compile flags for this target's objects.
include src/util/CMakeFiles/util.dir/flags.make

src/util/CMakeFiles/util.dir/src/ScopedConfiguration.cpp.o: src/util/CMakeFiles/util.dir/flags.make
src/util/CMakeFiles/util.dir/src/ScopedConfiguration.cpp.o: ../src/util/src/ScopedConfiguration.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/deploy/src/libsourcey/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/util/CMakeFiles/util.dir/src/ScopedConfiguration.cpp.o"
	cd /home/deploy/src/libsourcey/build/src/util && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/util.dir/src/ScopedConfiguration.cpp.o -c /home/deploy/src/libsourcey/src/util/src/ScopedConfiguration.cpp

src/util/CMakeFiles/util.dir/src/ScopedConfiguration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/util.dir/src/ScopedConfiguration.cpp.i"
	cd /home/deploy/src/libsourcey/build/src/util && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/deploy/src/libsourcey/src/util/src/ScopedConfiguration.cpp > CMakeFiles/util.dir/src/ScopedConfiguration.cpp.i

src/util/CMakeFiles/util.dir/src/ScopedConfiguration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/util.dir/src/ScopedConfiguration.cpp.s"
	cd /home/deploy/src/libsourcey/build/src/util && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/deploy/src/libsourcey/src/util/src/ScopedConfiguration.cpp -o CMakeFiles/util.dir/src/ScopedConfiguration.cpp.s

src/util/CMakeFiles/util.dir/src/ScopedConfiguration.cpp.o.requires:
.PHONY : src/util/CMakeFiles/util.dir/src/ScopedConfiguration.cpp.o.requires

src/util/CMakeFiles/util.dir/src/ScopedConfiguration.cpp.o.provides: src/util/CMakeFiles/util.dir/src/ScopedConfiguration.cpp.o.requires
	$(MAKE) -f src/util/CMakeFiles/util.dir/build.make src/util/CMakeFiles/util.dir/src/ScopedConfiguration.cpp.o.provides.build
.PHONY : src/util/CMakeFiles/util.dir/src/ScopedConfiguration.cpp.o.provides

src/util/CMakeFiles/util.dir/src/ScopedConfiguration.cpp.o.provides.build: src/util/CMakeFiles/util.dir/src/ScopedConfiguration.cpp.o

src/util/CMakeFiles/util.dir/src/DiagnosticManager.cpp.o: src/util/CMakeFiles/util.dir/flags.make
src/util/CMakeFiles/util.dir/src/DiagnosticManager.cpp.o: ../src/util/src/DiagnosticManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/deploy/src/libsourcey/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/util/CMakeFiles/util.dir/src/DiagnosticManager.cpp.o"
	cd /home/deploy/src/libsourcey/build/src/util && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/util.dir/src/DiagnosticManager.cpp.o -c /home/deploy/src/libsourcey/src/util/src/DiagnosticManager.cpp

src/util/CMakeFiles/util.dir/src/DiagnosticManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/util.dir/src/DiagnosticManager.cpp.i"
	cd /home/deploy/src/libsourcey/build/src/util && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/deploy/src/libsourcey/src/util/src/DiagnosticManager.cpp > CMakeFiles/util.dir/src/DiagnosticManager.cpp.i

src/util/CMakeFiles/util.dir/src/DiagnosticManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/util.dir/src/DiagnosticManager.cpp.s"
	cd /home/deploy/src/libsourcey/build/src/util && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/deploy/src/libsourcey/src/util/src/DiagnosticManager.cpp -o CMakeFiles/util.dir/src/DiagnosticManager.cpp.s

src/util/CMakeFiles/util.dir/src/DiagnosticManager.cpp.o.requires:
.PHONY : src/util/CMakeFiles/util.dir/src/DiagnosticManager.cpp.o.requires

src/util/CMakeFiles/util.dir/src/DiagnosticManager.cpp.o.provides: src/util/CMakeFiles/util.dir/src/DiagnosticManager.cpp.o.requires
	$(MAKE) -f src/util/CMakeFiles/util.dir/build.make src/util/CMakeFiles/util.dir/src/DiagnosticManager.cpp.o.provides.build
.PHONY : src/util/CMakeFiles/util.dir/src/DiagnosticManager.cpp.o.provides

src/util/CMakeFiles/util.dir/src/DiagnosticManager.cpp.o.provides.build: src/util/CMakeFiles/util.dir/src/DiagnosticManager.cpp.o

src/util/CMakeFiles/util.dir/src/StreamManager.cpp.o: src/util/CMakeFiles/util.dir/flags.make
src/util/CMakeFiles/util.dir/src/StreamManager.cpp.o: ../src/util/src/StreamManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/deploy/src/libsourcey/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/util/CMakeFiles/util.dir/src/StreamManager.cpp.o"
	cd /home/deploy/src/libsourcey/build/src/util && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/util.dir/src/StreamManager.cpp.o -c /home/deploy/src/libsourcey/src/util/src/StreamManager.cpp

src/util/CMakeFiles/util.dir/src/StreamManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/util.dir/src/StreamManager.cpp.i"
	cd /home/deploy/src/libsourcey/build/src/util && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/deploy/src/libsourcey/src/util/src/StreamManager.cpp > CMakeFiles/util.dir/src/StreamManager.cpp.i

src/util/CMakeFiles/util.dir/src/StreamManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/util.dir/src/StreamManager.cpp.s"
	cd /home/deploy/src/libsourcey/build/src/util && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/deploy/src/libsourcey/src/util/src/StreamManager.cpp -o CMakeFiles/util.dir/src/StreamManager.cpp.s

src/util/CMakeFiles/util.dir/src/StreamManager.cpp.o.requires:
.PHONY : src/util/CMakeFiles/util.dir/src/StreamManager.cpp.o.requires

src/util/CMakeFiles/util.dir/src/StreamManager.cpp.o.provides: src/util/CMakeFiles/util.dir/src/StreamManager.cpp.o.requires
	$(MAKE) -f src/util/CMakeFiles/util.dir/build.make src/util/CMakeFiles/util.dir/src/StreamManager.cpp.o.provides.build
.PHONY : src/util/CMakeFiles/util.dir/src/StreamManager.cpp.o.provides

src/util/CMakeFiles/util.dir/src/StreamManager.cpp.o.provides.build: src/util/CMakeFiles/util.dir/src/StreamManager.cpp.o

# Object files for target util
util_OBJECTS = \
"CMakeFiles/util.dir/src/ScopedConfiguration.cpp.o" \
"CMakeFiles/util.dir/src/DiagnosticManager.cpp.o" \
"CMakeFiles/util.dir/src/StreamManager.cpp.o"

# External object files for target util
util_EXTERNAL_OBJECTS =

src/util/libscy_util.a: src/util/CMakeFiles/util.dir/src/ScopedConfiguration.cpp.o
src/util/libscy_util.a: src/util/CMakeFiles/util.dir/src/DiagnosticManager.cpp.o
src/util/libscy_util.a: src/util/CMakeFiles/util.dir/src/StreamManager.cpp.o
src/util/libscy_util.a: src/util/CMakeFiles/util.dir/build.make
src/util/libscy_util.a: src/util/CMakeFiles/util.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libscy_util.a"
	cd /home/deploy/src/libsourcey/build/src/util && $(CMAKE_COMMAND) -P CMakeFiles/util.dir/cmake_clean_target.cmake
	cd /home/deploy/src/libsourcey/build/src/util && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/util.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/util/CMakeFiles/util.dir/build: src/util/libscy_util.a
.PHONY : src/util/CMakeFiles/util.dir/build

src/util/CMakeFiles/util.dir/requires: src/util/CMakeFiles/util.dir/src/ScopedConfiguration.cpp.o.requires
src/util/CMakeFiles/util.dir/requires: src/util/CMakeFiles/util.dir/src/DiagnosticManager.cpp.o.requires
src/util/CMakeFiles/util.dir/requires: src/util/CMakeFiles/util.dir/src/StreamManager.cpp.o.requires
.PHONY : src/util/CMakeFiles/util.dir/requires

src/util/CMakeFiles/util.dir/clean:
	cd /home/deploy/src/libsourcey/build/src/util && $(CMAKE_COMMAND) -P CMakeFiles/util.dir/cmake_clean.cmake
.PHONY : src/util/CMakeFiles/util.dir/clean

src/util/CMakeFiles/util.dir/depend:
	cd /home/deploy/src/libsourcey/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/deploy/src/libsourcey /home/deploy/src/libsourcey/src/util /home/deploy/src/libsourcey/build /home/deploy/src/libsourcey/build/src/util /home/deploy/src/libsourcey/build/src/util/CMakeFiles/util.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/util/CMakeFiles/util.dir/depend
