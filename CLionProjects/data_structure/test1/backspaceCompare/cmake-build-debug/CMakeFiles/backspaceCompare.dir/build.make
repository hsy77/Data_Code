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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\rain\CLionProjects\backspaceCompare

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\rain\CLionProjects\backspaceCompare\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/backspaceCompare.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/backspaceCompare.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/backspaceCompare.dir/flags.make

CMakeFiles/backspaceCompare.dir/main.cpp.obj: CMakeFiles/backspaceCompare.dir/flags.make
CMakeFiles/backspaceCompare.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\rain\CLionProjects\backspaceCompare\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/backspaceCompare.dir/main.cpp.obj"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\backspaceCompare.dir\main.cpp.obj -c C:\Users\rain\CLionProjects\backspaceCompare\main.cpp

CMakeFiles/backspaceCompare.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/backspaceCompare.dir/main.cpp.i"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rain\CLionProjects\backspaceCompare\main.cpp > CMakeFiles\backspaceCompare.dir\main.cpp.i

CMakeFiles/backspaceCompare.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/backspaceCompare.dir/main.cpp.s"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rain\CLionProjects\backspaceCompare\main.cpp -o CMakeFiles\backspaceCompare.dir\main.cpp.s

# Object files for target backspaceCompare
backspaceCompare_OBJECTS = \
"CMakeFiles/backspaceCompare.dir/main.cpp.obj"

# External object files for target backspaceCompare
backspaceCompare_EXTERNAL_OBJECTS =

backspaceCompare.exe: CMakeFiles/backspaceCompare.dir/main.cpp.obj
backspaceCompare.exe: CMakeFiles/backspaceCompare.dir/build.make
backspaceCompare.exe: CMakeFiles/backspaceCompare.dir/linklibs.rsp
backspaceCompare.exe: CMakeFiles/backspaceCompare.dir/objects1.rsp
backspaceCompare.exe: CMakeFiles/backspaceCompare.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\rain\CLionProjects\backspaceCompare\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable backspaceCompare.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\backspaceCompare.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/backspaceCompare.dir/build: backspaceCompare.exe

.PHONY : CMakeFiles/backspaceCompare.dir/build

CMakeFiles/backspaceCompare.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\backspaceCompare.dir\cmake_clean.cmake
.PHONY : CMakeFiles/backspaceCompare.dir/clean

CMakeFiles/backspaceCompare.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\rain\CLionProjects\backspaceCompare C:\Users\rain\CLionProjects\backspaceCompare C:\Users\rain\CLionProjects\backspaceCompare\cmake-build-debug C:\Users\rain\CLionProjects\backspaceCompare\cmake-build-debug C:\Users\rain\CLionProjects\backspaceCompare\cmake-build-debug\CMakeFiles\backspaceCompare.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/backspaceCompare.dir/depend

