# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/164/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/164/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xenon/CLionProjects/Chess-Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xenon/CLionProjects/Chess-Engine/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Chess_Engine.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Chess_Engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Chess_Engine.dir/flags.make

CMakeFiles/Chess_Engine.dir/board.cpp.o: CMakeFiles/Chess_Engine.dir/flags.make
CMakeFiles/Chess_Engine.dir/board.cpp.o: ../board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xenon/CLionProjects/Chess-Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Chess_Engine.dir/board.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Chess_Engine.dir/board.cpp.o -c /home/xenon/CLionProjects/Chess-Engine/board.cpp

CMakeFiles/Chess_Engine.dir/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess_Engine.dir/board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xenon/CLionProjects/Chess-Engine/board.cpp > CMakeFiles/Chess_Engine.dir/board.cpp.i

CMakeFiles/Chess_Engine.dir/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess_Engine.dir/board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xenon/CLionProjects/Chess-Engine/board.cpp -o CMakeFiles/Chess_Engine.dir/board.cpp.s

CMakeFiles/Chess_Engine.dir/main.cpp.o: CMakeFiles/Chess_Engine.dir/flags.make
CMakeFiles/Chess_Engine.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xenon/CLionProjects/Chess-Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Chess_Engine.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Chess_Engine.dir/main.cpp.o -c /home/xenon/CLionProjects/Chess-Engine/main.cpp

CMakeFiles/Chess_Engine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess_Engine.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xenon/CLionProjects/Chess-Engine/main.cpp > CMakeFiles/Chess_Engine.dir/main.cpp.i

CMakeFiles/Chess_Engine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess_Engine.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xenon/CLionProjects/Chess-Engine/main.cpp -o CMakeFiles/Chess_Engine.dir/main.cpp.s

CMakeFiles/Chess_Engine.dir/pieces.cpp.o: CMakeFiles/Chess_Engine.dir/flags.make
CMakeFiles/Chess_Engine.dir/pieces.cpp.o: ../pieces.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xenon/CLionProjects/Chess-Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Chess_Engine.dir/pieces.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Chess_Engine.dir/pieces.cpp.o -c /home/xenon/CLionProjects/Chess-Engine/pieces.cpp

CMakeFiles/Chess_Engine.dir/pieces.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess_Engine.dir/pieces.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xenon/CLionProjects/Chess-Engine/pieces.cpp > CMakeFiles/Chess_Engine.dir/pieces.cpp.i

CMakeFiles/Chess_Engine.dir/pieces.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess_Engine.dir/pieces.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xenon/CLionProjects/Chess-Engine/pieces.cpp -o CMakeFiles/Chess_Engine.dir/pieces.cpp.s

CMakeFiles/Chess_Engine.dir/Move.cpp.o: CMakeFiles/Chess_Engine.dir/flags.make
CMakeFiles/Chess_Engine.dir/Move.cpp.o: ../Move.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xenon/CLionProjects/Chess-Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Chess_Engine.dir/Move.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Chess_Engine.dir/Move.cpp.o -c /home/xenon/CLionProjects/Chess-Engine/Move.cpp

CMakeFiles/Chess_Engine.dir/Move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess_Engine.dir/Move.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xenon/CLionProjects/Chess-Engine/Move.cpp > CMakeFiles/Chess_Engine.dir/Move.cpp.i

CMakeFiles/Chess_Engine.dir/Move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess_Engine.dir/Move.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xenon/CLionProjects/Chess-Engine/Move.cpp -o CMakeFiles/Chess_Engine.dir/Move.cpp.s

# Object files for target Chess_Engine
Chess_Engine_OBJECTS = \
"CMakeFiles/Chess_Engine.dir/board.cpp.o" \
"CMakeFiles/Chess_Engine.dir/main.cpp.o" \
"CMakeFiles/Chess_Engine.dir/pieces.cpp.o" \
"CMakeFiles/Chess_Engine.dir/Move.cpp.o"

# External object files for target Chess_Engine
Chess_Engine_EXTERNAL_OBJECTS =

Chess_Engine: CMakeFiles/Chess_Engine.dir/board.cpp.o
Chess_Engine: CMakeFiles/Chess_Engine.dir/main.cpp.o
Chess_Engine: CMakeFiles/Chess_Engine.dir/pieces.cpp.o
Chess_Engine: CMakeFiles/Chess_Engine.dir/Move.cpp.o
Chess_Engine: CMakeFiles/Chess_Engine.dir/build.make
Chess_Engine: CMakeFiles/Chess_Engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xenon/CLionProjects/Chess-Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Chess_Engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Chess_Engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Chess_Engine.dir/build: Chess_Engine
.PHONY : CMakeFiles/Chess_Engine.dir/build

CMakeFiles/Chess_Engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Chess_Engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Chess_Engine.dir/clean

CMakeFiles/Chess_Engine.dir/depend:
	cd /home/xenon/CLionProjects/Chess-Engine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xenon/CLionProjects/Chess-Engine /home/xenon/CLionProjects/Chess-Engine /home/xenon/CLionProjects/Chess-Engine/cmake-build-debug /home/xenon/CLionProjects/Chess-Engine/cmake-build-debug /home/xenon/CLionProjects/Chess-Engine/cmake-build-debug/CMakeFiles/Chess_Engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Chess_Engine.dir/depend

