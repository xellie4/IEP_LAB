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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ellie/Desktop/lucrarea7_s8_done

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ellie/Desktop/lucrarea7_s8_done/build

# Include any dependencies generated for this target.
include CMakeFiles/lucrarea7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lucrarea7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lucrarea7.dir/flags.make

CMakeFiles/lucrarea7.dir/main.cpp.o: CMakeFiles/lucrarea7.dir/flags.make
CMakeFiles/lucrarea7.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ellie/Desktop/lucrarea7_s8_done/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lucrarea7.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lucrarea7.dir/main.cpp.o -c /home/ellie/Desktop/lucrarea7_s8_done/main.cpp

CMakeFiles/lucrarea7.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lucrarea7.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ellie/Desktop/lucrarea7_s8_done/main.cpp > CMakeFiles/lucrarea7.dir/main.cpp.i

CMakeFiles/lucrarea7.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lucrarea7.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ellie/Desktop/lucrarea7_s8_done/main.cpp -o CMakeFiles/lucrarea7.dir/main.cpp.s

# Object files for target lucrarea7
lucrarea7_OBJECTS = \
"CMakeFiles/lucrarea7.dir/main.cpp.o"

# External object files for target lucrarea7
lucrarea7_EXTERNAL_OBJECTS =

lucrarea7: CMakeFiles/lucrarea7.dir/main.cpp.o
lucrarea7: CMakeFiles/lucrarea7.dir/build.make
lucrarea7: CMakeFiles/lucrarea7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ellie/Desktop/lucrarea7_s8_done/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lucrarea7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lucrarea7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lucrarea7.dir/build: lucrarea7

.PHONY : CMakeFiles/lucrarea7.dir/build

CMakeFiles/lucrarea7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lucrarea7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lucrarea7.dir/clean

CMakeFiles/lucrarea7.dir/depend:
	cd /home/ellie/Desktop/lucrarea7_s8_done/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ellie/Desktop/lucrarea7_s8_done /home/ellie/Desktop/lucrarea7_s8_done /home/ellie/Desktop/lucrarea7_s8_done/build /home/ellie/Desktop/lucrarea7_s8_done/build /home/ellie/Desktop/lucrarea7_s8_done/build/CMakeFiles/lucrarea7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lucrarea7.dir/depend

