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
CMAKE_SOURCE_DIR = D:\CLionProjects\MyShell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\MyShell\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MyShell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyShell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyShell.dir/flags.make

CMakeFiles/MyShell.dir/main.c.obj: CMakeFiles/MyShell.dir/flags.make
CMakeFiles/MyShell.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\MyShell\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MyShell.dir/main.c.obj"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MyShell.dir\main.c.obj   -c D:\CLionProjects\MyShell\main.c

CMakeFiles/MyShell.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyShell.dir/main.c.i"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionProjects\MyShell\main.c > CMakeFiles\MyShell.dir\main.c.i

CMakeFiles/MyShell.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyShell.dir/main.c.s"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CLionProjects\MyShell\main.c -o CMakeFiles\MyShell.dir\main.c.s

CMakeFiles/MyShell.dir/procs1.c.obj: CMakeFiles/MyShell.dir/flags.make
CMakeFiles/MyShell.dir/procs1.c.obj: ../procs1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\MyShell\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MyShell.dir/procs1.c.obj"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MyShell.dir\procs1.c.obj   -c D:\CLionProjects\MyShell\procs1.c

CMakeFiles/MyShell.dir/procs1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyShell.dir/procs1.c.i"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionProjects\MyShell\procs1.c > CMakeFiles\MyShell.dir\procs1.c.i

CMakeFiles/MyShell.dir/procs1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyShell.dir/procs1.c.s"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CLionProjects\MyShell\procs1.c -o CMakeFiles\MyShell.dir\procs1.c.s

# Object files for target MyShell
MyShell_OBJECTS = \
"CMakeFiles/MyShell.dir/main.c.obj" \
"CMakeFiles/MyShell.dir/procs1.c.obj"

# External object files for target MyShell
MyShell_EXTERNAL_OBJECTS =

MyShell.exe: CMakeFiles/MyShell.dir/main.c.obj
MyShell.exe: CMakeFiles/MyShell.dir/procs1.c.obj
MyShell.exe: CMakeFiles/MyShell.dir/build.make
MyShell.exe: CMakeFiles/MyShell.dir/linklibs.rsp
MyShell.exe: CMakeFiles/MyShell.dir/objects1.rsp
MyShell.exe: CMakeFiles/MyShell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\MyShell\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable MyShell.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MyShell.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyShell.dir/build: MyShell.exe

.PHONY : CMakeFiles/MyShell.dir/build

CMakeFiles/MyShell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MyShell.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MyShell.dir/clean

CMakeFiles/MyShell.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProjects\MyShell D:\CLionProjects\MyShell D:\CLionProjects\MyShell\cmake-build-debug D:\CLionProjects\MyShell\cmake-build-debug D:\CLionProjects\MyShell\cmake-build-debug\CMakeFiles\MyShell.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyShell.dir/depend

