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
CMAKE_SOURCE_DIR = /home/egor/Documents/OpenGL/severalTexture

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/egor/Documents/OpenGL/severalTexture/build

# Include any dependencies generated for this target.
include CMakeFiles/lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lib.dir/flags.make

CMakeFiles/lib.dir/ShaderClass/Shader.cpp.o: CMakeFiles/lib.dir/flags.make
CMakeFiles/lib.dir/ShaderClass/Shader.cpp.o: ../ShaderClass/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/egor/Documents/OpenGL/severalTexture/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lib.dir/ShaderClass/Shader.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib.dir/ShaderClass/Shader.cpp.o -c /home/egor/Documents/OpenGL/severalTexture/ShaderClass/Shader.cpp

CMakeFiles/lib.dir/ShaderClass/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/ShaderClass/Shader.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egor/Documents/OpenGL/severalTexture/ShaderClass/Shader.cpp > CMakeFiles/lib.dir/ShaderClass/Shader.cpp.i

CMakeFiles/lib.dir/ShaderClass/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/ShaderClass/Shader.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egor/Documents/OpenGL/severalTexture/ShaderClass/Shader.cpp -o CMakeFiles/lib.dir/ShaderClass/Shader.cpp.s

CMakeFiles/lib.dir/ShaderClass/Shader.cpp.o.requires:

.PHONY : CMakeFiles/lib.dir/ShaderClass/Shader.cpp.o.requires

CMakeFiles/lib.dir/ShaderClass/Shader.cpp.o.provides: CMakeFiles/lib.dir/ShaderClass/Shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/ShaderClass/Shader.cpp.o.provides.build
.PHONY : CMakeFiles/lib.dir/ShaderClass/Shader.cpp.o.provides

CMakeFiles/lib.dir/ShaderClass/Shader.cpp.o.provides.build: CMakeFiles/lib.dir/ShaderClass/Shader.cpp.o


# Object files for target lib
lib_OBJECTS = \
"CMakeFiles/lib.dir/ShaderClass/Shader.cpp.o"

# External object files for target lib
lib_EXTERNAL_OBJECTS =

liblib.a: CMakeFiles/lib.dir/ShaderClass/Shader.cpp.o
liblib.a: CMakeFiles/lib.dir/build.make
liblib.a: CMakeFiles/lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/egor/Documents/OpenGL/severalTexture/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lib.dir/build: liblib.a

.PHONY : CMakeFiles/lib.dir/build

CMakeFiles/lib.dir/requires: CMakeFiles/lib.dir/ShaderClass/Shader.cpp.o.requires

.PHONY : CMakeFiles/lib.dir/requires

CMakeFiles/lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lib.dir/clean

CMakeFiles/lib.dir/depend:
	cd /home/egor/Documents/OpenGL/severalTexture/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/egor/Documents/OpenGL/severalTexture /home/egor/Documents/OpenGL/severalTexture /home/egor/Documents/OpenGL/severalTexture/build /home/egor/Documents/OpenGL/severalTexture/build /home/egor/Documents/OpenGL/severalTexture/build/CMakeFiles/lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lib.dir/depend

