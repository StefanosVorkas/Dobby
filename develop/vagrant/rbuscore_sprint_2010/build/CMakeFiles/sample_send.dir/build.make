# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /vagrant/rbuscore_sprint_2010

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /vagrant/rbuscore_sprint_2010/build

# Include any dependencies generated for this target.
include CMakeFiles/sample_send.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sample_send.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sample_send.dir/flags.make

CMakeFiles/sample_send.dir/sample_send.c.o: CMakeFiles/sample_send.dir/flags.make
CMakeFiles/sample_send.dir/sample_send.c.o: ../sample_send.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/vagrant/rbuscore_sprint_2010/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sample_send.dir/sample_send.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sample_send.dir/sample_send.c.o   -c /vagrant/rbuscore_sprint_2010/sample_send.c

CMakeFiles/sample_send.dir/sample_send.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sample_send.dir/sample_send.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /vagrant/rbuscore_sprint_2010/sample_send.c > CMakeFiles/sample_send.dir/sample_send.c.i

CMakeFiles/sample_send.dir/sample_send.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sample_send.dir/sample_send.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /vagrant/rbuscore_sprint_2010/sample_send.c -o CMakeFiles/sample_send.dir/sample_send.c.s

CMakeFiles/sample_send.dir/sample_send.c.o.requires:

.PHONY : CMakeFiles/sample_send.dir/sample_send.c.o.requires

CMakeFiles/sample_send.dir/sample_send.c.o.provides: CMakeFiles/sample_send.dir/sample_send.c.o.requires
	$(MAKE) -f CMakeFiles/sample_send.dir/build.make CMakeFiles/sample_send.dir/sample_send.c.o.provides.build
.PHONY : CMakeFiles/sample_send.dir/sample_send.c.o.provides

CMakeFiles/sample_send.dir/sample_send.c.o.provides.build: CMakeFiles/sample_send.dir/sample_send.c.o


# Object files for target sample_send
sample_send_OBJECTS = \
"CMakeFiles/sample_send.dir/sample_send.c.o"

# External object files for target sample_send
sample_send_EXTERNAL_OBJECTS =

sample_send: CMakeFiles/sample_send.dir/sample_send.c.o
sample_send: CMakeFiles/sample_send.dir/build.make
sample_send: librtMessage.so.0.1.0
sample_send: CMakeFiles/sample_send.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/vagrant/rbuscore_sprint_2010/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sample_send"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sample_send.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sample_send.dir/build: sample_send

.PHONY : CMakeFiles/sample_send.dir/build

CMakeFiles/sample_send.dir/requires: CMakeFiles/sample_send.dir/sample_send.c.o.requires

.PHONY : CMakeFiles/sample_send.dir/requires

CMakeFiles/sample_send.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sample_send.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sample_send.dir/clean

CMakeFiles/sample_send.dir/depend:
	cd /vagrant/rbuscore_sprint_2010/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /vagrant/rbuscore_sprint_2010 /vagrant/rbuscore_sprint_2010 /vagrant/rbuscore_sprint_2010/build /vagrant/rbuscore_sprint_2010/build /vagrant/rbuscore_sprint_2010/build/CMakeFiles/sample_send.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sample_send.dir/depend

