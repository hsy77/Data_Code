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
CMAKE_COMMAND = "C:\Program Files\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLionProjects\Skiing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\Skiing\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Skiing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Skiing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Skiing.dir/flags.make

CMakeFiles/Skiing.dir/main.cpp.obj: CMakeFiles/Skiing.dir/flags.make
CMakeFiles/Skiing.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\Skiing\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Skiing.dir/main.cpp.obj"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Skiing.dir\main.cpp.obj -c D:\CLionProjects\Skiing\main.cpp

CMakeFiles/Skiing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Skiing.dir/main.cpp.i"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProjects\Skiing\main.cpp > CMakeFiles\Skiing.dir\main.cpp.i

CMakeFiles/Skiing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Skiing.dir/main.cpp.s"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLionProjects\Skiing\main.cpp -o CMakeFiles\Skiing.dir\main.cpp.s

CMakeFiles/Skiing.dir/Skiing.cpp.obj: CMakeFiles/Skiing.dir/flags.make
CMakeFiles/Skiing.dir/Skiing.cpp.obj: ../Skiing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\Skiing\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Skiing.dir/Skiing.cpp.obj"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Skiing.dir\Skiing.cpp.obj -c D:\CLionProjects\Skiing\Skiing.cpp

CMakeFiles/Skiing.dir/Skiing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Skiing.dir/Skiing.cpp.i"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProjects\Skiing\Skiing.cpp > CMakeFiles\Skiing.dir\Skiing.cpp.i

CMakeFiles/Skiing.dir/Skiing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Skiing.dir/Skiing.cpp.s"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLionProjects\Skiing\Skiing.cpp -o CMakeFiles\Skiing.dir\Skiing.cpp.s

# Object files for target Skiing
Skiing_OBJECTS = \
"CMakeFiles/Skiing.dir/main.cpp.obj" \
"CMakeFiles/Skiing.dir/Skiing.cpp.obj"

# External object files for target Skiing
Skiing_EXTERNAL_OBJECTS =

Skiing.exe: CMakeFiles/Skiing.dir/main.cpp.obj
Skiing.exe: CMakeFiles/Skiing.dir/Skiing.cpp.obj
Skiing.exe: CMakeFiles/Skiing.dir/build.make
Skiing.exe: CMakeFiles/Skiing.dir/linklibs.rsp
Skiing.exe: CMakeFiles/Skiing.dir/objects1.rsp
Skiing.exe: CMakeFiles/Skiing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\Skiing\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Skiing.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Skiing.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Skiing.dir/build: Skiing.exe

.PHONY : CMakeFiles/Skiing.dir/build

CMakeFiles/Skiing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Skiing.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Skiing.dir/clean

CMakeFiles/Skiing.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProjects\Skiing D:\CLionProjects\Skiing D:\CLionProjects\Skiing\cmake-build-debug D:\CLionProjects\Skiing\cmake-build-debug D:\CLionProjects\Skiing\cmake-build-debug\CMakeFiles\Skiing.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Skiing.dir/depend

