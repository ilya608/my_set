# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /snap/clion/73/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/73/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ilya/1course_cpp/set_testing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/1course_cpp/set_testing

# Include any dependencies generated for this target.
include gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include gtest/CMakeFiles/gtest.dir/flags.make

gtest/CMakeFiles/gtest.dir/gtest-all.cc.o: gtest/CMakeFiles/gtest.dir/flags.make
gtest/CMakeFiles/gtest.dir/gtest-all.cc.o: gtest/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/1course_cpp/set_testing/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object gtest/CMakeFiles/gtest.dir/gtest-all.cc.o"
	cd /home/ilya/1course_cpp/set_testing/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/gtest-all.cc.o -c /home/ilya/1course_cpp/set_testing/gtest/gtest-all.cc

gtest/CMakeFiles/gtest.dir/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/gtest-all.cc.i"
	cd /home/ilya/1course_cpp/set_testing/gtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/1course_cpp/set_testing/gtest/gtest-all.cc > CMakeFiles/gtest.dir/gtest-all.cc.i

gtest/CMakeFiles/gtest.dir/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/gtest-all.cc.s"
	cd /home/ilya/1course_cpp/set_testing/gtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/1course_cpp/set_testing/gtest/gtest-all.cc -o CMakeFiles/gtest.dir/gtest-all.cc.s

gtest/CMakeFiles/gtest.dir/gtest_main.cc.o: gtest/CMakeFiles/gtest.dir/flags.make
gtest/CMakeFiles/gtest.dir/gtest_main.cc.o: gtest/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/1course_cpp/set_testing/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object gtest/CMakeFiles/gtest.dir/gtest_main.cc.o"
	cd /home/ilya/1course_cpp/set_testing/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/gtest_main.cc.o -c /home/ilya/1course_cpp/set_testing/gtest/gtest_main.cc

gtest/CMakeFiles/gtest.dir/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/gtest_main.cc.i"
	cd /home/ilya/1course_cpp/set_testing/gtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/1course_cpp/set_testing/gtest/gtest_main.cc > CMakeFiles/gtest.dir/gtest_main.cc.i

gtest/CMakeFiles/gtest.dir/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/gtest_main.cc.s"
	cd /home/ilya/1course_cpp/set_testing/gtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/1course_cpp/set_testing/gtest/gtest_main.cc -o CMakeFiles/gtest.dir/gtest_main.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/gtest-all.cc.o" \
"CMakeFiles/gtest.dir/gtest_main.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

gtest/libgtest.a: gtest/CMakeFiles/gtest.dir/gtest-all.cc.o
gtest/libgtest.a: gtest/CMakeFiles/gtest.dir/gtest_main.cc.o
gtest/libgtest.a: gtest/CMakeFiles/gtest.dir/build.make
gtest/libgtest.a: gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/1course_cpp/set_testing/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libgtest.a"
	cd /home/ilya/1course_cpp/set_testing/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/ilya/1course_cpp/set_testing/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gtest/CMakeFiles/gtest.dir/build: gtest/libgtest.a

.PHONY : gtest/CMakeFiles/gtest.dir/build

gtest/CMakeFiles/gtest.dir/clean:
	cd /home/ilya/1course_cpp/set_testing/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : gtest/CMakeFiles/gtest.dir/clean

gtest/CMakeFiles/gtest.dir/depend:
	cd /home/ilya/1course_cpp/set_testing && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/1course_cpp/set_testing /home/ilya/1course_cpp/set_testing/gtest /home/ilya/1course_cpp/set_testing /home/ilya/1course_cpp/set_testing/gtest /home/ilya/1course_cpp/set_testing/gtest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gtest/CMakeFiles/gtest.dir/depend
