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
include CMakeFiles/DB_LinHash.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DB_LinHash.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DB_LinHash.dir/flags.make

CMakeFiles/DB_LinHash.dir/main.cpp.o: CMakeFiles/DB_LinHash.dir/flags.make
CMakeFiles/DB_LinHash.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DB_LinHash.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DB_LinHash.dir/main.cpp.o -c /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/main.cpp

CMakeFiles/DB_LinHash.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DB_LinHash.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/main.cpp > CMakeFiles/DB_LinHash.dir/main.cpp.i

CMakeFiles/DB_LinHash.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DB_LinHash.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/main.cpp -o CMakeFiles/DB_LinHash.dir/main.cpp.s

# Object files for target DB_LinHash
DB_LinHash_OBJECTS = \
"CMakeFiles/DB_LinHash.dir/main.cpp.o"

# External object files for target DB_LinHash
DB_LinHash_EXTERNAL_OBJECTS =

DB_LinHash: CMakeFiles/DB_LinHash.dir/main.cpp.o
DB_LinHash: CMakeFiles/DB_LinHash.dir/build.make
DB_LinHash: CMakeFiles/DB_LinHash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DB_LinHash"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DB_LinHash.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DB_LinHash.dir/build: DB_LinHash

.PHONY : CMakeFiles/DB_LinHash.dir/build

CMakeFiles/DB_LinHash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DB_LinHash.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DB_LinHash.dir/clean

CMakeFiles/DB_LinHash.dir/depend:
	cd /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/CMakeFiles/DB_LinHash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DB_LinHash.dir/depend

