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
include rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/depend.make

# Include the progress variables for this target.
include rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/progress.make

# Include the compile flags for this target's objects.
include rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/flags.make

rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/nested_server.c.o: rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/flags.make
rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/nested_server.c.o: ../rbus-core/test/nested_server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/vagrant/rbuscore_sprint_2010/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/nested_server.c.o"
	cd /vagrant/rbuscore_sprint_2010/build/rbus-core/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rbus_nested_test_server.dir/nested_server.c.o   -c /vagrant/rbuscore_sprint_2010/rbus-core/test/nested_server.c

rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/nested_server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rbus_nested_test_server.dir/nested_server.c.i"
	cd /vagrant/rbuscore_sprint_2010/build/rbus-core/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /vagrant/rbuscore_sprint_2010/rbus-core/test/nested_server.c > CMakeFiles/rbus_nested_test_server.dir/nested_server.c.i

rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/nested_server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rbus_nested_test_server.dir/nested_server.c.s"
	cd /vagrant/rbuscore_sprint_2010/build/rbus-core/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /vagrant/rbuscore_sprint_2010/rbus-core/test/nested_server.c -o CMakeFiles/rbus_nested_test_server.dir/nested_server.c.s

rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/nested_server.c.o.requires:

.PHONY : rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/nested_server.c.o.requires

rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/nested_server.c.o.provides: rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/nested_server.c.o.requires
	$(MAKE) -f rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/build.make rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/nested_server.c.o.provides.build
.PHONY : rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/nested_server.c.o.provides

rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/nested_server.c.o.provides.build: rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/nested_server.c.o


# Object files for target rbus_nested_test_server
rbus_nested_test_server_OBJECTS = \
"CMakeFiles/rbus_nested_test_server.dir/nested_server.c.o"

# External object files for target rbus_nested_test_server
rbus_nested_test_server_EXTERNAL_OBJECTS =

rbus-core/test/rbus_nested_test_server: rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/nested_server.c.o
rbus-core/test/rbus_nested_test_server: rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/build.make
rbus-core/test/rbus_nested_test_server: rbus-core/lib/librbus-core.so.0.0.0
rbus-core/test/rbus_nested_test_server: librtMessage.so.0.1.0
rbus-core/test/rbus_nested_test_server: rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/vagrant/rbuscore_sprint_2010/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable rbus_nested_test_server"
	cd /vagrant/rbuscore_sprint_2010/build/rbus-core/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rbus_nested_test_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/build: rbus-core/test/rbus_nested_test_server

.PHONY : rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/build

rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/requires: rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/nested_server.c.o.requires

.PHONY : rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/requires

rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/clean:
	cd /vagrant/rbuscore_sprint_2010/build/rbus-core/test && $(CMAKE_COMMAND) -P CMakeFiles/rbus_nested_test_server.dir/cmake_clean.cmake
.PHONY : rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/clean

rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/depend:
	cd /vagrant/rbuscore_sprint_2010/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /vagrant/rbuscore_sprint_2010 /vagrant/rbuscore_sprint_2010/rbus-core/test /vagrant/rbuscore_sprint_2010/build /vagrant/rbuscore_sprint_2010/build/rbus-core/test /vagrant/rbuscore_sprint_2010/build/rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : rbus-core/test/CMakeFiles/rbus_nested_test_server.dir/depend

