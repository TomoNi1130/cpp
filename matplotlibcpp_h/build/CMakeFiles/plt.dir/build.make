# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/study/language/cpp/matplotlibcpp_h

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/study/language/cpp/matplotlibcpp_h/build

# Include any dependencies generated for this target.
include CMakeFiles/plt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/plt.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/plt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/plt.dir/flags.make

CMakeFiles/plt.dir/matplotlibcpp_h.cpp.o: CMakeFiles/plt.dir/flags.make
CMakeFiles/plt.dir/matplotlibcpp_h.cpp.o: /mnt/c/study/language/cpp/matplotlibcpp_h/matplotlibcpp_h.cpp
CMakeFiles/plt.dir/matplotlibcpp_h.cpp.o: CMakeFiles/plt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/study/language/cpp/matplotlibcpp_h/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/plt.dir/matplotlibcpp_h.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/plt.dir/matplotlibcpp_h.cpp.o -MF CMakeFiles/plt.dir/matplotlibcpp_h.cpp.o.d -o CMakeFiles/plt.dir/matplotlibcpp_h.cpp.o -c /mnt/c/study/language/cpp/matplotlibcpp_h/matplotlibcpp_h.cpp

CMakeFiles/plt.dir/matplotlibcpp_h.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/plt.dir/matplotlibcpp_h.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/study/language/cpp/matplotlibcpp_h/matplotlibcpp_h.cpp > CMakeFiles/plt.dir/matplotlibcpp_h.cpp.i

CMakeFiles/plt.dir/matplotlibcpp_h.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/plt.dir/matplotlibcpp_h.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/study/language/cpp/matplotlibcpp_h/matplotlibcpp_h.cpp -o CMakeFiles/plt.dir/matplotlibcpp_h.cpp.s

# Object files for target plt
plt_OBJECTS = \
"CMakeFiles/plt.dir/matplotlibcpp_h.cpp.o"

# External object files for target plt
plt_EXTERNAL_OBJECTS =

plt: CMakeFiles/plt.dir/matplotlibcpp_h.cpp.o
plt: CMakeFiles/plt.dir/build.make
plt: /usr/lib/x86_64-linux-gnu/libpython3.12.so
plt: CMakeFiles/plt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/c/study/language/cpp/matplotlibcpp_h/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable plt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/plt.dir/build: plt
.PHONY : CMakeFiles/plt.dir/build

CMakeFiles/plt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/plt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/plt.dir/clean

CMakeFiles/plt.dir/depend:
	cd /mnt/c/study/language/cpp/matplotlibcpp_h/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/study/language/cpp/matplotlibcpp_h /mnt/c/study/language/cpp/matplotlibcpp_h /mnt/c/study/language/cpp/matplotlibcpp_h/build /mnt/c/study/language/cpp/matplotlibcpp_h/build /mnt/c/study/language/cpp/matplotlibcpp_h/build/CMakeFiles/plt.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/plt.dir/depend

