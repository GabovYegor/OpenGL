# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/egor/Documents/OpenGL/camera

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/egor/Documents/OpenGL/camera/build

# Include any dependencies generated for this target.
include CMakeFiles/fun.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fun.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fun.dir/flags.make

CMakeFiles/fun.dir/functions.cpp.o: CMakeFiles/fun.dir/flags.make
CMakeFiles/fun.dir/functions.cpp.o: ../functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egor/Documents/OpenGL/camera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fun.dir/functions.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fun.dir/functions.cpp.o -c /home/egor/Documents/OpenGL/camera/functions.cpp

CMakeFiles/fun.dir/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fun.dir/functions.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egor/Documents/OpenGL/camera/functions.cpp > CMakeFiles/fun.dir/functions.cpp.i

CMakeFiles/fun.dir/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fun.dir/functions.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egor/Documents/OpenGL/camera/functions.cpp -o CMakeFiles/fun.dir/functions.cpp.s

CMakeFiles/fun.dir/functions.cpp.o.requires:

.PHONY : CMakeFiles/fun.dir/functions.cpp.o.requires

CMakeFiles/fun.dir/functions.cpp.o.provides: CMakeFiles/fun.dir/functions.cpp.o.requires
	$(MAKE) -f CMakeFiles/fun.dir/build.make CMakeFiles/fun.dir/functions.cpp.o.provides.build
.PHONY : CMakeFiles/fun.dir/functions.cpp.o.provides

CMakeFiles/fun.dir/functions.cpp.o.provides.build: CMakeFiles/fun.dir/functions.cpp.o


# Object files for target fun
fun_OBJECTS = \
"CMakeFiles/fun.dir/functions.cpp.o"

# External object files for target fun
fun_EXTERNAL_OBJECTS =

libfun.a: CMakeFiles/fun.dir/functions.cpp.o
libfun.a: CMakeFiles/fun.dir/build.make
libfun.a: CMakeFiles/fun.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/egor/Documents/OpenGL/camera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libfun.a"
	$(CMAKE_COMMAND) -P CMakeFiles/fun.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fun.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fun.dir/build: libfun.a

.PHONY : CMakeFiles/fun.dir/build

CMakeFiles/fun.dir/requires: CMakeFiles/fun.dir/functions.cpp.o.requires

.PHONY : CMakeFiles/fun.dir/requires

CMakeFiles/fun.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fun.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fun.dir/clean

CMakeFiles/fun.dir/depend:
	cd /home/egor/Documents/OpenGL/camera/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/egor/Documents/OpenGL/camera /home/egor/Documents/OpenGL/camera /home/egor/Documents/OpenGL/camera/build /home/egor/Documents/OpenGL/camera/build /home/egor/Documents/OpenGL/camera/build/CMakeFiles/fun.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fun.dir/depend

