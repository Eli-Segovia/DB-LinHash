# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/lib/clion-2019.3.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/clion-2019.3.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/RTests.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/RTests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/RTests.dir/flags.make

test/CMakeFiles/RTests.dir/Counting.cpp.o: test/CMakeFiles/RTests.dir/flags.make
test/CMakeFiles/RTests.dir/Counting.cpp.o: ../test/Counting.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/RTests.dir/Counting.cpp.o"
	cd /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RTests.dir/Counting.cpp.o -c /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/test/Counting.cpp

test/CMakeFiles/RTests.dir/Counting.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTests.dir/Counting.cpp.i"
	cd /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/test/Counting.cpp > CMakeFiles/RTests.dir/Counting.cpp.i

test/CMakeFiles/RTests.dir/Counting.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTests.dir/Counting.cpp.s"
	cd /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/test/Counting.cpp -o CMakeFiles/RTests.dir/Counting.cpp.s

# Object files for target RTests
RTests_OBJECTS = \
"CMakeFiles/RTests.dir/Counting.cpp.o"

# External object files for target RTests
RTests_EXTERNAL_OBJECTS =

test/RTests: test/CMakeFiles/RTests.dir/Counting.cpp.o
test/RTests: test/CMakeFiles/RTests.dir/build.make
test/RTests: test/CMakeFiles/RTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RTests"
	cd /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/RTests.dir/build: test/RTests

.PHONY : test/CMakeFiles/RTests.dir/build

test/CMakeFiles/RTests.dir/clean:
	cd /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/RTests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/RTests.dir/clean

test/CMakeFiles/RTests.dir/depend:
	cd /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/test /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/test /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/test/CMakeFiles/RTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/RTests.dir/depend
