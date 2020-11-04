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
include sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/depend.make

# Include the progress variables for this target.
include sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/progress.make

# Include the compile flags for this target's objects.
include sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/flags.make

sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.o: sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/flags.make
sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.o: ../sampleapps/consumer/rbusGeneralEventConsumer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/vagrant/rbus_sprint_2010/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.o"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.o   -c /vagrant/rbus_sprint_2010/sampleapps/consumer/rbusGeneralEventConsumer.c

sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.i"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /vagrant/rbus_sprint_2010/sampleapps/consumer/rbusGeneralEventConsumer.c > CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.i

sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.s"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /vagrant/rbus_sprint_2010/sampleapps/consumer/rbusGeneralEventConsumer.c -o CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.s

sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.o.requires:

.PHONY : sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.o.requires

sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.o.provides: sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.o.requires
	$(MAKE) -f sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/build.make sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.o.provides.build
.PHONY : sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.o.provides

sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.o.provides.build: sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.o


# Object files for target rbusGeneralEventConsumer
rbusGeneralEventConsumer_OBJECTS = \
"CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.o"

# External object files for target rbusGeneralEventConsumer
rbusGeneralEventConsumer_EXTERNAL_OBJECTS =

sampleapps/rbusGeneralEventConsumer: sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.o
sampleapps/rbusGeneralEventConsumer: sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/build.make
sampleapps/rbusGeneralEventConsumer: src/librbus.so.2.0.0
sampleapps/rbusGeneralEventConsumer: /lib/librtMessage.so
sampleapps/rbusGeneralEventConsumer: /lib/librbus-core.so
sampleapps/rbusGeneralEventConsumer: sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/vagrant/rbus_sprint_2010/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable rbusGeneralEventConsumer"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rbusGeneralEventConsumer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/build: sampleapps/rbusGeneralEventConsumer

.PHONY : sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/build

sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/requires: sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/consumer/rbusGeneralEventConsumer.c.o.requires

.PHONY : sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/requires

sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/clean:
	cd /vagrant/rbus_sprint_2010/build/sampleapps && $(CMAKE_COMMAND) -P CMakeFiles/rbusGeneralEventConsumer.dir/cmake_clean.cmake
.PHONY : sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/clean

sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/depend:
	cd /vagrant/rbus_sprint_2010/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /vagrant/rbus_sprint_2010 /vagrant/rbus_sprint_2010/sampleapps /vagrant/rbus_sprint_2010/build /vagrant/rbus_sprint_2010/build/sampleapps /vagrant/rbus_sprint_2010/build/sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sampleapps/CMakeFiles/rbusGeneralEventConsumer.dir/depend

