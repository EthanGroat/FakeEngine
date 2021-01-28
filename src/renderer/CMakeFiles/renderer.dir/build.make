# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/iisan/CLionProjects/FakeEngine/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/iisan/CLionProjects/FakeEngine/src

# Include any dependencies generated for this target.
include renderer/CMakeFiles/renderer.dir/depend.make

# Include the progress variables for this target.
include renderer/CMakeFiles/renderer.dir/progress.make

# Include the compile flags for this target's objects.
include renderer/CMakeFiles/renderer.dir/flags.make

renderer/CMakeFiles/renderer.dir/renderer.cpp.o: renderer/CMakeFiles/renderer.dir/flags.make
renderer/CMakeFiles/renderer.dir/renderer.cpp.o: renderer/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/iisan/CLionProjects/FakeEngine/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object renderer/CMakeFiles/renderer.dir/renderer.cpp.o"
	cd /home/iisan/CLionProjects/FakeEngine/src/renderer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/renderer.dir/renderer.cpp.o -c /home/iisan/CLionProjects/FakeEngine/src/renderer/renderer.cpp

renderer/CMakeFiles/renderer.dir/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/renderer.dir/renderer.cpp.i"
	cd /home/iisan/CLionProjects/FakeEngine/src/renderer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/iisan/CLionProjects/FakeEngine/src/renderer/renderer.cpp > CMakeFiles/renderer.dir/renderer.cpp.i

renderer/CMakeFiles/renderer.dir/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/renderer.dir/renderer.cpp.s"
	cd /home/iisan/CLionProjects/FakeEngine/src/renderer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/iisan/CLionProjects/FakeEngine/src/renderer/renderer.cpp -o CMakeFiles/renderer.dir/renderer.cpp.s

# Object files for target renderer
renderer_OBJECTS = \
"CMakeFiles/renderer.dir/renderer.cpp.o"

# External object files for target renderer
renderer_EXTERNAL_OBJECTS =

renderer/librenderer.so: renderer/CMakeFiles/renderer.dir/renderer.cpp.o
renderer/librenderer.so: renderer/CMakeFiles/renderer.dir/build.make
renderer/librenderer.so: renderer/CMakeFiles/renderer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/iisan/CLionProjects/FakeEngine/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library librenderer.so"
	cd /home/iisan/CLionProjects/FakeEngine/src/renderer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/renderer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
renderer/CMakeFiles/renderer.dir/build: renderer/librenderer.so

.PHONY : renderer/CMakeFiles/renderer.dir/build

renderer/CMakeFiles/renderer.dir/clean:
	cd /home/iisan/CLionProjects/FakeEngine/src/renderer && $(CMAKE_COMMAND) -P CMakeFiles/renderer.dir/cmake_clean.cmake
.PHONY : renderer/CMakeFiles/renderer.dir/clean

renderer/CMakeFiles/renderer.dir/depend:
	cd /home/iisan/CLionProjects/FakeEngine/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/iisan/CLionProjects/FakeEngine/src /home/iisan/CLionProjects/FakeEngine/src/renderer /home/iisan/CLionProjects/FakeEngine/src /home/iisan/CLionProjects/FakeEngine/src/renderer /home/iisan/CLionProjects/FakeEngine/src/renderer/CMakeFiles/renderer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : renderer/CMakeFiles/renderer.dir/depend

