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
CMAKE_SOURCE_DIR = C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Decision_though_the_Struct.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Decision_though_the_Struct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Decision_though_the_Struct.dir/flags.make

CMakeFiles/Decision_though_the_Struct.dir/main.cpp.obj: CMakeFiles/Decision_though_the_Struct.dir/flags.make
CMakeFiles/Decision_though_the_Struct.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Decision_though_the_Struct.dir/main.cpp.obj"
	C:\dev\mingw-w64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Decision_though_the_Struct.dir\main.cpp.obj -c C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct\main.cpp

CMakeFiles/Decision_though_the_Struct.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Decision_though_the_Struct.dir/main.cpp.i"
	C:\dev\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct\main.cpp > CMakeFiles\Decision_though_the_Struct.dir\main.cpp.i

CMakeFiles/Decision_though_the_Struct.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Decision_though_the_Struct.dir/main.cpp.s"
	C:\dev\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct\main.cpp -o CMakeFiles\Decision_though_the_Struct.dir\main.cpp.s

CMakeFiles/Decision_though_the_Struct.dir/names1.cpp.obj: CMakeFiles/Decision_though_the_Struct.dir/flags.make
CMakeFiles/Decision_though_the_Struct.dir/names1.cpp.obj: ../names1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Decision_though_the_Struct.dir/names1.cpp.obj"
	C:\dev\mingw-w64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Decision_though_the_Struct.dir\names1.cpp.obj -c C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct\names1.cpp

CMakeFiles/Decision_though_the_Struct.dir/names1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Decision_though_the_Struct.dir/names1.cpp.i"
	C:\dev\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct\names1.cpp > CMakeFiles\Decision_though_the_Struct.dir\names1.cpp.i

CMakeFiles/Decision_though_the_Struct.dir/names1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Decision_though_the_Struct.dir/names1.cpp.s"
	C:\dev\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct\names1.cpp -o CMakeFiles\Decision_though_the_Struct.dir\names1.cpp.s

# Object files for target Decision_though_the_Struct
Decision_though_the_Struct_OBJECTS = \
"CMakeFiles/Decision_though_the_Struct.dir/main.cpp.obj" \
"CMakeFiles/Decision_though_the_Struct.dir/names1.cpp.obj"

# External object files for target Decision_though_the_Struct
Decision_though_the_Struct_EXTERNAL_OBJECTS =

Decision_though_the_Struct.exe: CMakeFiles/Decision_though_the_Struct.dir/main.cpp.obj
Decision_though_the_Struct.exe: CMakeFiles/Decision_though_the_Struct.dir/names1.cpp.obj
Decision_though_the_Struct.exe: CMakeFiles/Decision_though_the_Struct.dir/build.make
Decision_though_the_Struct.exe: CMakeFiles/Decision_though_the_Struct.dir/linklibs.rsp
Decision_though_the_Struct.exe: CMakeFiles/Decision_though_the_Struct.dir/objects1.rsp
Decision_though_the_Struct.exe: CMakeFiles/Decision_though_the_Struct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Decision_though_the_Struct.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Decision_though_the_Struct.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Decision_though_the_Struct.dir/build: Decision_though_the_Struct.exe

.PHONY : CMakeFiles/Decision_though_the_Struct.dir/build

CMakeFiles/Decision_though_the_Struct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Decision_though_the_Struct.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Decision_though_the_Struct.dir/clean

CMakeFiles/Decision_though_the_Struct.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct\cmake-build-debug C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct\cmake-build-debug C:\Users\Loathem\CLionProjects\Week_3\Prog_4_class_names_and_surnames\Decision_though_the_Struct\cmake-build-debug\CMakeFiles\Decision_though_the_Struct.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Decision_though_the_Struct.dir/depend

