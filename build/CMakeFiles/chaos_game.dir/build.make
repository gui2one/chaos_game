# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_SOURCE_DIR = /home/pi/projects/chaos_game/build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/projects/chaos_game/build

# Include any dependencies generated for this target.
include CMakeFiles/chaos_game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chaos_game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chaos_game.dir/flags.make

CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.o: CMakeFiles/chaos_game.dir/flags.make
CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.o: /home/pi/projects/chaos_game/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/projects/chaos_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.o -c /home/pi/projects/chaos_game/src/main.cpp

CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/projects/chaos_game/src/main.cpp > CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.i

CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/projects/chaos_game/src/main.cpp -o CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.s

CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.o.requires:

.PHONY : CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.o.requires

CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.o.provides: CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/chaos_game.dir/build.make CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.o.provides

CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.o.provides.build: CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.o


# Object files for target chaos_game
chaos_game_OBJECTS = \
"CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.o"

# External object files for target chaos_game
chaos_game_EXTERNAL_OBJECTS =

chaos_game: CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.o
chaos_game: CMakeFiles/chaos_game.dir/build.make
chaos_game: CMakeFiles/chaos_game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/projects/chaos_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chaos_game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chaos_game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chaos_game.dir/build: chaos_game

.PHONY : CMakeFiles/chaos_game.dir/build

CMakeFiles/chaos_game.dir/requires: CMakeFiles/chaos_game.dir/home/pi/projects/chaos_game/src/main.cpp.o.requires

.PHONY : CMakeFiles/chaos_game.dir/requires

CMakeFiles/chaos_game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chaos_game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chaos_game.dir/clean

CMakeFiles/chaos_game.dir/depend:
	cd /home/pi/projects/chaos_game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/projects/chaos_game/build /home/pi/projects/chaos_game/build /home/pi/projects/chaos_game/build /home/pi/projects/chaos_game/build /home/pi/projects/chaos_game/build/CMakeFiles/chaos_game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chaos_game.dir/depend

