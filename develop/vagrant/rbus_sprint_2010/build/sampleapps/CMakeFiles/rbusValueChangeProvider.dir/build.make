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
include sampleapps/CMakeFiles/rbusValueChangeProvider.dir/depend.make

# Include the progress variables for this target.
include sampleapps/CMakeFiles/rbusValueChangeProvider.dir/progress.make

# Include the compile flags for this target's objects.
include sampleapps/CMakeFiles/rbusValueChangeProvider.dir/flags.make

sampleapps/CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.o: sampleapps/CMakeFiles/rbusValueChangeProvider.dir/flags.make
sampleapps/CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.o: ../sampleapps/provider/rbusValueChangeProvider.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/vagrant/rbus_sprint_2010/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object sampleapps/CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.o"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.o   -c /vagrant/rbus_sprint_2010/sampleapps/provider/rbusValueChangeProvider.c

sampleapps/CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.i"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /vagrant/rbus_sprint_2010/sampleapps/provider/rbusValueChangeProvider.c > CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.i

sampleapps/CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.s"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /vagrant/rbus_sprint_2010/sampleapps/provider/rbusValueChangeProvider.c -o CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.s

sampleapps/CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.o.requires:

.PHONY : sampleapps/CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.o.requires

sampleapps/CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.o.provides: sampleapps/CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.o.requires
	$(MAKE) -f sampleapps/CMakeFiles/rbusValueChangeProvider.dir/build.make sampleapps/CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.o.provides.build
.PHONY : sampleapps/CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.o.provides

sampleapps/CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.o.provides.build: sampleapps/CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.o


# Object files for target rbusValueChangeProvider
rbusValueChangeProvider_OBJECTS = \
"CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.o"

# External object files for target rbusValueChangeProvider
rbusValueChangeProvider_EXTERNAL_OBJECTS =

sampleapps/rbusValueChangeProvider: sampleapps/CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.o
sampleapps/rbusValueChangeProvider: sampleapps/CMakeFiles/rbusValueChangeProvider.dir/build.make
sampleapps/rbusValueChangeProvider: src/librbus.so.2.0.0
sampleapps/rbusValueChangeProvider: /lib/librtMessage.so
sampleapps/rbusValueChangeProvider: /lib/librbus-core.so
sampleapps/rbusValueChangeProvider: sampleapps/CMakeFiles/rbusValueChangeProvider.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/vagrant/rbus_sprint_2010/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable rbusValueChangeProvider"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rbusValueChangeProvider.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sampleapps/CMakeFiles/rbusValueChangeProvider.dir/build: sampleapps/rbusValueChangeProvider

.PHONY : sampleapps/CMakeFiles/rbusValueChangeProvider.dir/build

sampleapps/CMakeFiles/rbusValueChangeProvider.dir/requires: sampleapps/CMakeFiles/rbusValueChangeProvider.dir/provider/rbusValueChangeProvider.c.o.requires

.PHONY : sampleapps/CMakeFiles/rbusValueChangeProvider.dir/requires

sampleapps/CMakeFiles/rbusValueChangeProvider.dir/clean:
	cd /vagrant/rbus_sprint_2010/build/sampleapps && $(CMAKE_COMMAND) -P CMakeFiles/rbusValueChangeProvider.dir/cmake_clean.cmake
.PHONY : sampleapps/CMakeFiles/rbusValueChangeProvider.dir/clean

sampleapps/CMakeFiles/rbusValueChangeProvider.dir/depend:
	cd /vagrant/rbus_sprint_2010/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /vagrant/rbus_sprint_2010 /vagrant/rbus_sprint_2010/sampleapps /vagrant/rbus_sprint_2010/build /vagrant/rbus_sprint_2010/build/sampleapps /vagrant/rbus_sprint_2010/build/sampleapps/CMakeFiles/rbusValueChangeProvider.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sampleapps/CMakeFiles/rbusValueChangeProvider.dir/depend

