# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\dev\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\dev\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Loathem\CLionProjects\Week_2\Prog_4_Maximazer\UpdateIfGreater

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Loathem\CLionProjects\Week_2\Prog_4_Maximazer\UpdateIfGreater\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/UpdateIfGreater.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UpdateIfGreater.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UpdateIfGreater.dir/flags.make

CMakeFiles/UpdateIfGreater.dir/main.cpp.obj: CMakeFiles/UpdateIfGreater.dir/flags.make
CMakeFiles/UpdateIfGreater.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Loathem\CLionProjects\Week_2\Prog_4_Maximazer\UpdateIfGreater\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UpdateIfGreater.dir/main.cpp.obj"
	C:\dev\mingw-w64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\UpdateIfGreater.dir\main.cpp.obj -c C:\Users\Loathem\CLionProjects\Week_2\Prog_4_Maximazer\UpdateIfGreater\main.cpp

CMakeFiles/UpdateIfGreater.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UpdateIfGreater.dir/main.cpp.i"
	C:\dev\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Loathem\CLionProjects\Week_2\Prog_4_Maximazer\UpdateIfGreater\main.cpp > CMakeFiles\UpdateIfGreater.dir\main.cpp.i

CMakeFiles/UpdateIfGreater.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UpdateIfGreater.dir/main.cpp.s"
	C:\dev\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Loathem\CLionProjects\Week_2\Prog_4_Maximazer\UpdateIfGreater\main.cpp -o CMakeFiles\UpdateIfGreater.dir\main.cpp.s

# Object files for target UpdateIfGreater
UpdateIfGreater_OBJECTS = \
"CMakeFiles/UpdateIfGreater.dir/main.cpp.obj"

# External object files for target UpdateIfGreater
UpdateIfGreater_EXTERNAL_OBJECTS =

UpdateIfGreater.exe: CMakeFiles/UpdateIfGreater.dir/main.cpp.obj
UpdateIfGreater.exe: CMakeFiles/UpdateIfGreater.dir/build.make
UpdateIfGreater.exe: CMakeFiles/UpdateIfGreater.dir/linklibs.rsp
UpdateIfGreater.exe: CMakeFiles/UpdateIfGreater.dir/objects1.rsp
UpdateIfGreater.exe: CMakeFiles/UpdateIfGreater.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Loathem\CLionProjects\Week_2\Prog_4_Maximazer\UpdateIfGreater\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable UpdateIfGreater.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\UpdateIfGreater.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UpdateIfGreater.dir/build: UpdateIfGreater.exe

.PHONY : CMakeFiles/UpdateIfGreater.dir/build

CMakeFiles/UpdateIfGreater.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\UpdateIfGreater.dir\cmake_clean.cmake
.PHONY : CMakeFiles/UpdateIfGreater.dir/clean

CMakeFiles/UpdateIfGreater.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Loathem\CLionProjects\Week_2\Prog_4_Maximazer\UpdateIfGreater C:\Users\Loathem\CLionProjects\Week_2\Prog_4_Maximazer\UpdateIfGreater C:\Users\Loathem\CLionProjects\Week_2\Prog_4_Maximazer\UpdateIfGreater\cmake-build-debug C:\Users\Loathem\CLionProjects\Week_2\Prog_4_Maximazer\UpdateIfGreater\cmake-build-debug C:\Users\Loathem\CLionProjects\Week_2\Prog_4_Maximazer\UpdateIfGreater\cmake-build-debug\CMakeFiles\UpdateIfGreater.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UpdateIfGreater.dir/depend

