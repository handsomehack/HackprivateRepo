# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\cmake-3.19.0-rc1-win64-x64\bin\cmake.exe

# The command to remove a file.
RM = D:\cmake-3.19.0-rc1-win64-x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\2020_20310895\Week3_4\Worksheet5\exercise2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\2020_20310895\Week3_4\Worksheet5\exercise2\build

# Utility rule file for hello_qt_autogen.

# Include the progress variables for this target.
include CMakeFiles/hello_qt_autogen.dir/progress.make

CMakeFiles/hello_qt_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=D:\2020_20310895\Week3_4\Worksheet5\exercise2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target hello_qt"
	D:\cmake-3.19.0-rc1-win64-x64\bin\cmake.exe -E cmake_autogen D:/2020_20310895/Week3_4/Worksheet5/exercise2/build/CMakeFiles/hello_qt_autogen.dir/AutogenInfo.json ""

hello_qt_autogen: CMakeFiles/hello_qt_autogen
hello_qt_autogen: CMakeFiles/hello_qt_autogen.dir/build.make

.PHONY : hello_qt_autogen

# Rule to build all files generated by this target.
CMakeFiles/hello_qt_autogen.dir/build: hello_qt_autogen

.PHONY : CMakeFiles/hello_qt_autogen.dir/build

CMakeFiles/hello_qt_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hello_qt_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/hello_qt_autogen.dir/clean

CMakeFiles/hello_qt_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\2020_20310895\Week3_4\Worksheet5\exercise2 D:\2020_20310895\Week3_4\Worksheet5\exercise2 D:\2020_20310895\Week3_4\Worksheet5\exercise2\build D:\2020_20310895\Week3_4\Worksheet5\exercise2\build D:\2020_20310895\Week3_4\Worksheet5\exercise2\build\CMakeFiles\hello_qt_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello_qt_autogen.dir/depend

