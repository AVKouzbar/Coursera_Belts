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
CMAKE_SOURCE_DIR = C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Prog_6_Reverse.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Prog_6_Reverse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Prog_6_Reverse.dir/flags.make

CMakeFiles/Prog_6_Reverse.dir/main.cpp.obj: CMakeFiles/Prog_6_Reverse.dir/flags.make
CMakeFiles/Prog_6_Reverse.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Prog_6_Reverse.dir/main.cpp.obj"
	C:\dev\mingw-w64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Prog_6_Reverse.dir\main.cpp.obj -c C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse\main.cpp

CMakeFiles/Prog_6_Reverse.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Prog_6_Reverse.dir/main.cpp.i"
	C:\dev\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse\main.cpp > CMakeFiles\Prog_6_Reverse.dir\main.cpp.i

CMakeFiles/Prog_6_Reverse.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Prog_6_Reverse.dir/main.cpp.s"
	C:\dev\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse\main.cpp -o CMakeFiles\Prog_6_Reverse.dir\main.cpp.s

CMakeFiles/Prog_6_Reverse.dir/reverse.cpp.obj: CMakeFiles/Prog_6_Reverse.dir/flags.make
CMakeFiles/Prog_6_Reverse.dir/reverse.cpp.obj: ../reverse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Prog_6_Reverse.dir/reverse.cpp.obj"
	C:\dev\mingw-w64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Prog_6_Reverse.dir\reverse.cpp.obj -c C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse\reverse.cpp

CMakeFiles/Prog_6_Reverse.dir/reverse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Prog_6_Reverse.dir/reverse.cpp.i"
	C:\dev\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse\reverse.cpp > CMakeFiles\Prog_6_Reverse.dir\reverse.cpp.i

CMakeFiles/Prog_6_Reverse.dir/reverse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Prog_6_Reverse.dir/reverse.cpp.s"
	C:\dev\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse\reverse.cpp -o CMakeFiles\Prog_6_Reverse.dir\reverse.cpp.s

# Object files for target Prog_6_Reverse
Prog_6_Reverse_OBJECTS = \
"CMakeFiles/Prog_6_Reverse.dir/main.cpp.obj" \
"CMakeFiles/Prog_6_Reverse.dir/reverse.cpp.obj"

# External object files for target Prog_6_Reverse
Prog_6_Reverse_EXTERNAL_OBJECTS =

Prog_6_Reverse.exe: CMakeFiles/Prog_6_Reverse.dir/main.cpp.obj
Prog_6_Reverse.exe: CMakeFiles/Prog_6_Reverse.dir/reverse.cpp.obj
Prog_6_Reverse.exe: CMakeFiles/Prog_6_Reverse.dir/build.make
Prog_6_Reverse.exe: CMakeFiles/Prog_6_Reverse.dir/linklibs.rsp
Prog_6_Reverse.exe: CMakeFiles/Prog_6_Reverse.dir/objects1.rsp
Prog_6_Reverse.exe: CMakeFiles/Prog_6_Reverse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Prog_6_Reverse.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Prog_6_Reverse.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Prog_6_Reverse.dir/build: Prog_6_Reverse.exe

.PHONY : CMakeFiles/Prog_6_Reverse.dir/build

CMakeFiles/Prog_6_Reverse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Prog_6_Reverse.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Prog_6_Reverse.dir/clean

CMakeFiles/Prog_6_Reverse.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse\cmake-build-debug C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse\cmake-build-debug C:\Users\Loathem\CLionProjects\Week_2\Prog_6_Reverse\cmake-build-debug\CMakeFiles\Prog_6_Reverse.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Prog_6_Reverse.dir/depend
