# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/cgev/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/cgev/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cgev/Desktop/CS/C/IPP/forests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cgev/Desktop/CS/C/IPP/forests/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/forests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/forests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/forests.dir/flags.make

CMakeFiles/forests.dir/main.c.o: CMakeFiles/forests.dir/flags.make
CMakeFiles/forests.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cgev/Desktop/CS/C/IPP/forests/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/forests.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/forests.dir/main.c.o   -c /home/cgev/Desktop/CS/C/IPP/forests/main.c

CMakeFiles/forests.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/forests.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cgev/Desktop/CS/C/IPP/forests/main.c > CMakeFiles/forests.dir/main.c.i

CMakeFiles/forests.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/forests.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cgev/Desktop/CS/C/IPP/forests/main.c -o CMakeFiles/forests.dir/main.c.s

CMakeFiles/forests.dir/trie.c.o: CMakeFiles/forests.dir/flags.make
CMakeFiles/forests.dir/trie.c.o: ../trie.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cgev/Desktop/CS/C/IPP/forests/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/forests.dir/trie.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/forests.dir/trie.c.o   -c /home/cgev/Desktop/CS/C/IPP/forests/trie.c

CMakeFiles/forests.dir/trie.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/forests.dir/trie.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cgev/Desktop/CS/C/IPP/forests/trie.c > CMakeFiles/forests.dir/trie.c.i

CMakeFiles/forests.dir/trie.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/forests.dir/trie.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cgev/Desktop/CS/C/IPP/forests/trie.c -o CMakeFiles/forests.dir/trie.c.s

CMakeFiles/forests.dir/safe_malloc.c.o: CMakeFiles/forests.dir/flags.make
CMakeFiles/forests.dir/safe_malloc.c.o: ../safe_malloc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cgev/Desktop/CS/C/IPP/forests/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/forests.dir/safe_malloc.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/forests.dir/safe_malloc.c.o   -c /home/cgev/Desktop/CS/C/IPP/forests/safe_malloc.c

CMakeFiles/forests.dir/safe_malloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/forests.dir/safe_malloc.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cgev/Desktop/CS/C/IPP/forests/safe_malloc.c > CMakeFiles/forests.dir/safe_malloc.c.i

CMakeFiles/forests.dir/safe_malloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/forests.dir/safe_malloc.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cgev/Desktop/CS/C/IPP/forests/safe_malloc.c -o CMakeFiles/forests.dir/safe_malloc.c.s

CMakeFiles/forests.dir/parser.c.o: CMakeFiles/forests.dir/flags.make
CMakeFiles/forests.dir/parser.c.o: ../parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cgev/Desktop/CS/C/IPP/forests/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/forests.dir/parser.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/forests.dir/parser.c.o   -c /home/cgev/Desktop/CS/C/IPP/forests/parser.c

CMakeFiles/forests.dir/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/forests.dir/parser.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cgev/Desktop/CS/C/IPP/forests/parser.c > CMakeFiles/forests.dir/parser.c.i

CMakeFiles/forests.dir/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/forests.dir/parser.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cgev/Desktop/CS/C/IPP/forests/parser.c -o CMakeFiles/forests.dir/parser.c.s

# Object files for target forests
forests_OBJECTS = \
"CMakeFiles/forests.dir/main.c.o" \
"CMakeFiles/forests.dir/trie.c.o" \
"CMakeFiles/forests.dir/safe_malloc.c.o" \
"CMakeFiles/forests.dir/parser.c.o"

# External object files for target forests
forests_EXTERNAL_OBJECTS =

forests: CMakeFiles/forests.dir/main.c.o
forests: CMakeFiles/forests.dir/trie.c.o
forests: CMakeFiles/forests.dir/safe_malloc.c.o
forests: CMakeFiles/forests.dir/parser.c.o
forests: CMakeFiles/forests.dir/build.make
forests: CMakeFiles/forests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cgev/Desktop/CS/C/IPP/forests/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable forests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/forests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/forests.dir/build: forests

.PHONY : CMakeFiles/forests.dir/build

CMakeFiles/forests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/forests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/forests.dir/clean

CMakeFiles/forests.dir/depend:
	cd /home/cgev/Desktop/CS/C/IPP/forests/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cgev/Desktop/CS/C/IPP/forests /home/cgev/Desktop/CS/C/IPP/forests /home/cgev/Desktop/CS/C/IPP/forests/cmake-build-debug /home/cgev/Desktop/CS/C/IPP/forests/cmake-build-debug /home/cgev/Desktop/CS/C/IPP/forests/cmake-build-debug/CMakeFiles/forests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/forests.dir/depend
