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
CMAKE_SOURCE_DIR = D:\CLionProjects\Adja_List_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\Adja_List_2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Adja_List_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Adja_List_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Adja_List_2.dir/flags.make

CMakeFiles/Adja_List_2.dir/main.cpp.obj: CMakeFiles/Adja_List_2.dir/flags.make
CMakeFiles/Adja_List_2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\Adja_List_2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Adja_List_2.dir/main.cpp.obj"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Adja_List_2.dir\main.cpp.obj -c D:\CLionProjects\Adja_List_2\main.cpp

CMakeFiles/Adja_List_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Adja_List_2.dir/main.cpp.i"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProjects\Adja_List_2\main.cpp > CMakeFiles\Adja_List_2.dir\main.cpp.i

CMakeFiles/Adja_List_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Adja_List_2.dir/main.cpp.s"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLionProjects\Adja_List_2\main.cpp -o CMakeFiles\Adja_List_2.dir\main.cpp.s

CMakeFiles/Adja_List_2.dir/adja_list.cpp.obj: CMakeFiles/Adja_List_2.dir/flags.make
CMakeFiles/Adja_List_2.dir/adja_list.cpp.obj: ../adja_list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\Adja_List_2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Adja_List_2.dir/adja_list.cpp.obj"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Adja_List_2.dir\adja_list.cpp.obj -c D:\CLionProjects\Adja_List_2\adja_list.cpp

CMakeFiles/Adja_List_2.dir/adja_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Adja_List_2.dir/adja_list.cpp.i"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProjects\Adja_List_2\adja_list.cpp > CMakeFiles\Adja_List_2.dir\adja_list.cpp.i

CMakeFiles/Adja_List_2.dir/adja_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Adja_List_2.dir/adja_list.cpp.s"
	C:\PROGRA~1\TOOLCH~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLionProjects\Adja_List_2\adja_list.cpp -o CMakeFiles\Adja_List_2.dir\adja_list.cpp.s

# Object files for target Adja_List_2
Adja_List_2_OBJECTS = \
"CMakeFiles/Adja_List_2.dir/main.cpp.obj" \
"CMakeFiles/Adja_List_2.dir/adja_list.cpp.obj"

# External object files for target Adja_List_2
Adja_List_2_EXTERNAL_OBJECTS =

Adja_List_2.exe: CMakeFiles/Adja_List_2.dir/main.cpp.obj
Adja_List_2.exe: CMakeFiles/Adja_List_2.dir/adja_list.cpp.obj
Adja_List_2.exe: CMakeFiles/Adja_List_2.dir/build.make
Adja_List_2.exe: CMakeFiles/Adja_List_2.dir/linklibs.rsp
Adja_List_2.exe: CMakeFiles/Adja_List_2.dir/objects1.rsp
Adja_List_2.exe: CMakeFiles/Adja_List_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\Adja_List_2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Adja_List_2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Adja_List_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Adja_List_2.dir/build: Adja_List_2.exe

.PHONY : CMakeFiles/Adja_List_2.dir/build

CMakeFiles/Adja_List_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Adja_List_2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Adja_List_2.dir/clean

CMakeFiles/Adja_List_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProjects\Adja_List_2 D:\CLionProjects\Adja_List_2 D:\CLionProjects\Adja_List_2\cmake-build-debug D:\CLionProjects\Adja_List_2\cmake-build-debug D:\CLionProjects\Adja_List_2\cmake-build-debug\CMakeFiles\Adja_List_2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Adja_List_2.dir/depend
