# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/sam/CSE180/src/final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sam/CSE180/build/final

# Include any dependencies generated for this target.
include CMakeFiles/navigator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/navigator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/navigator.dir/flags.make

CMakeFiles/navigator.dir/src/navigation.cpp.o: CMakeFiles/navigator.dir/flags.make
CMakeFiles/navigator.dir/src/navigation.cpp.o: /home/sam/CSE180/src/final/src/navigation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sam/CSE180/build/final/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/navigator.dir/src/navigation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/navigator.dir/src/navigation.cpp.o -c /home/sam/CSE180/src/final/src/navigation.cpp

CMakeFiles/navigator.dir/src/navigation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/navigator.dir/src/navigation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sam/CSE180/src/final/src/navigation.cpp > CMakeFiles/navigator.dir/src/navigation.cpp.i

CMakeFiles/navigator.dir/src/navigation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/navigator.dir/src/navigation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sam/CSE180/src/final/src/navigation.cpp -o CMakeFiles/navigator.dir/src/navigation.cpp.s

# Object files for target navigator
navigator_OBJECTS = \
"CMakeFiles/navigator.dir/src/navigation.cpp.o"

# External object files for target navigator
navigator_EXTERNAL_OBJECTS =

libnavigator.a: CMakeFiles/navigator.dir/src/navigation.cpp.o
libnavigator.a: CMakeFiles/navigator.dir/build.make
libnavigator.a: CMakeFiles/navigator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sam/CSE180/build/final/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libnavigator.a"
	$(CMAKE_COMMAND) -P CMakeFiles/navigator.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/navigator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/navigator.dir/build: libnavigator.a

.PHONY : CMakeFiles/navigator.dir/build

CMakeFiles/navigator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/navigator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/navigator.dir/clean

CMakeFiles/navigator.dir/depend:
	cd /home/sam/CSE180/build/final && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sam/CSE180/src/final /home/sam/CSE180/src/final /home/sam/CSE180/build/final /home/sam/CSE180/build/final /home/sam/CSE180/build/final/CMakeFiles/navigator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/navigator.dir/depend

