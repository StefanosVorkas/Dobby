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
include sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/depend.make

# Include the progress variables for this target.
include sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/progress.make

# Include the compile flags for this target's objects.
include sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/flags.make

sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.o: sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/flags.make
sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.o: ../sampleapps/provider/mta_proxy_tr104.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/vagrant/rbus_sprint_2010/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.o"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.o   -c /vagrant/rbus_sprint_2010/sampleapps/provider/mta_proxy_tr104.c

sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.i"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /vagrant/rbus_sprint_2010/sampleapps/provider/mta_proxy_tr104.c > CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.i

sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.s"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /vagrant/rbus_sprint_2010/sampleapps/provider/mta_proxy_tr104.c -o CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.s

sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.o.requires:

.PHONY : sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.o.requires

sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.o.provides: sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.o.requires
	$(MAKE) -f sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/build.make sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.o.provides.build
.PHONY : sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.o.provides

sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.o.provides.build: sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.o


sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.o: sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/flags.make
sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.o: ../sampleapps/provider/mta_hal_tr104.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/vagrant/rbus_sprint_2010/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.o"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.o   -c /vagrant/rbus_sprint_2010/sampleapps/provider/mta_hal_tr104.c

sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.i"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /vagrant/rbus_sprint_2010/sampleapps/provider/mta_hal_tr104.c > CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.i

sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.s"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /vagrant/rbus_sprint_2010/sampleapps/provider/mta_hal_tr104.c -o CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.s

sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.o.requires:

.PHONY : sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.o.requires

sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.o.provides: sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.o.requires
	$(MAKE) -f sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/build.make sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.o.provides.build
.PHONY : sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.o.provides

sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.o.provides.build: sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.o


# Object files for target rbusTR104MtaAgentApp
rbusTR104MtaAgentApp_OBJECTS = \
"CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.o" \
"CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.o"

# External object files for target rbusTR104MtaAgentApp
rbusTR104MtaAgentApp_EXTERNAL_OBJECTS =

sampleapps/rbusTR104MtaAgentApp: sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.o
sampleapps/rbusTR104MtaAgentApp: sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.o
sampleapps/rbusTR104MtaAgentApp: sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/build.make
sampleapps/rbusTR104MtaAgentApp: src/librbus.so.2.0.0
sampleapps/rbusTR104MtaAgentApp: /lib/librtMessage.so
sampleapps/rbusTR104MtaAgentApp: /lib/librbus-core.so
sampleapps/rbusTR104MtaAgentApp: sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/vagrant/rbus_sprint_2010/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable rbusTR104MtaAgentApp"
	cd /vagrant/rbus_sprint_2010/build/sampleapps && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rbusTR104MtaAgentApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/build: sampleapps/rbusTR104MtaAgentApp

.PHONY : sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/build

sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/requires: sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_proxy_tr104.c.o.requires
sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/requires: sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/provider/mta_hal_tr104.c.o.requires

.PHONY : sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/requires

sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/clean:
	cd /vagrant/rbus_sprint_2010/build/sampleapps && $(CMAKE_COMMAND) -P CMakeFiles/rbusTR104MtaAgentApp.dir/cmake_clean.cmake
.PHONY : sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/clean

sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/depend:
	cd /vagrant/rbus_sprint_2010/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /vagrant/rbus_sprint_2010 /vagrant/rbus_sprint_2010/sampleapps /vagrant/rbus_sprint_2010/build /vagrant/rbus_sprint_2010/build/sampleapps /vagrant/rbus_sprint_2010/build/sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sampleapps/CMakeFiles/rbusTR104MtaAgentApp.dir/depend

