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
CMAKE_SOURCE_DIR = /vagrant/rbus_sprint_2010

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /vagrant/rbus_sprint_2010/build

# Include any dependencies generated for this target.
include sampleapps/CMakeFiles/rbusSampleProvider.dir/depend.make

# Include the progress variables for this target.
include sampleapps/CMakeFiles/rbusSampleProvider.dir/progress.make

# Include the compile flags for this target's objects.
include sampleapps/CMakeFiles/rbusSampleProvider.dir/flags.make

sampleapps/CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.o: sampleapps/CMakeFiles/rbusSampleProvider.dir/flags.make
sampleapps/CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.o: ../sampleapps/provider/rbusSampleProvider.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/vagrant/rbus_sprint_2010/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object sampleapps/CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.o"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.o   -c /vagrant/rbus_sprint_2010/sampleapps/provider/rbusSampleProvider.c

sampleapps/CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.i"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /vagrant/rbus_sprint_2010/sampleapps/provider/rbusSampleProvider.c > CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.i

sampleapps/CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.s"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /vagrant/rbus_sprint_2010/sampleapps/provider/rbusSampleProvider.c -o CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.s

sampleapps/CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.o.requires:

.PHONY : sampleapps/CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.o.requires

sampleapps/CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.o.provides: sampleapps/CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.o.requires
	$(MAKE) -f sampleapps/CMakeFiles/rbusSampleProvider.dir/build.make sampleapps/CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.o.provides.build
.PHONY : sampleapps/CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.o.provides

sampleapps/CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.o.provides.build: sampleapps/CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.o


# Object files for target rbusSampleProvider
rbusSampleProvider_OBJECTS = \
"CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.o"

# External object files for target rbusSampleProvider
rbusSampleProvider_EXTERNAL_OBJECTS =

sampleapps/rbusSampleProvider: sampleapps/CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.o
sampleapps/rbusSampleProvider: sampleapps/CMakeFiles/rbusSampleProvider.dir/build.make
sampleapps/rbusSampleProvider: src/librbus.so.2.0.0
sampleapps/rbusSampleProvider: /lib/librtMessage.so
sampleapps/rbusSampleProvider: /lib/librbus-core.so
sampleapps/rbusSampleProvider: sampleapps/CMakeFiles/rbusSampleProvider.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/vagrant/rbus_sprint_2010/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable rbusSampleProvider"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rbusSampleProvider.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sampleapps/CMakeFiles/rbusSampleProvider.dir/build: sampleapps/rbusSampleProvider

.PHONY : sampleapps/CMakeFiles/rbusSampleProvider.dir/build

sampleapps/CMakeFiles/rbusSampleProvider.dir/requires: sampleapps/CMakeFiles/rbusSampleProvider.dir/provider/rbusSampleProvider.c.o.requires

.PHONY : sampleapps/CMakeFiles/rbusSampleProvider.dir/requires

sampleapps/CMakeFiles/rbusSampleProvider.dir/clean:
	cd /vagrant/rbus_sprint_2010/build/sampleapps && $(CMAKE_COMMAND) -P CMakeFiles/rbusSampleProvider.dir/cmake_clean.cmake
.PHONY : sampleapps/CMakeFiles/rbusSampleProvider.dir/clean

sampleapps/CMakeFiles/rbusSampleProvider.dir/depend:
	cd /vagrant/rbus_sprint_2010/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /vagrant/rbus_sprint_2010 /vagrant/rbus_sprint_2010/sampleapps /vagrant/rbus_sprint_2010/build /vagrant/rbus_sprint_2010/build/sampleapps /vagrant/rbus_sprint_2010/build/sampleapps/CMakeFiles/rbusSampleProvider.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sampleapps/CMakeFiles/rbusSampleProvider.dir/depend

