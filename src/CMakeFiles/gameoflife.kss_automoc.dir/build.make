# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/justyna/PJC/PJC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/justyna/PJC/PJC

# Utility rule file for gameoflife.kss_automoc.

# Include the progress variables for this target.
include src/CMakeFiles/gameoflife.kss_automoc.dir/progress.make

src/CMakeFiles/gameoflife.kss_automoc:
	cd /home/justyna/PJC/PJC/src && /usr/bin/automoc4 /home/justyna/PJC/PJC/src/gameoflife.kss_automoc.cpp /home/justyna/PJC/PJC/src /home/justyna/PJC/PJC/src /usr/bin/moc-qt4 /usr/bin/cmake

gameoflife.kss_automoc: src/CMakeFiles/gameoflife.kss_automoc
gameoflife.kss_automoc: src/CMakeFiles/gameoflife.kss_automoc.dir/build.make
.PHONY : gameoflife.kss_automoc

# Rule to build all files generated by this target.
src/CMakeFiles/gameoflife.kss_automoc.dir/build: gameoflife.kss_automoc
.PHONY : src/CMakeFiles/gameoflife.kss_automoc.dir/build

src/CMakeFiles/gameoflife.kss_automoc.dir/clean:
	cd /home/justyna/PJC/PJC/src && $(CMAKE_COMMAND) -P CMakeFiles/gameoflife.kss_automoc.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/gameoflife.kss_automoc.dir/clean

src/CMakeFiles/gameoflife.kss_automoc.dir/depend:
	cd /home/justyna/PJC/PJC && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/justyna/PJC/PJC /home/justyna/PJC/PJC/src /home/justyna/PJC/PJC /home/justyna/PJC/PJC/src /home/justyna/PJC/PJC/src/CMakeFiles/gameoflife.kss_automoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/gameoflife.kss_automoc.dir/depend

