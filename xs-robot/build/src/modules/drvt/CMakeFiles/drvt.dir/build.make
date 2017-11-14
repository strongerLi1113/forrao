# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/strong/source/xs-robot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/strong/source/xs-robot/build

# Include any dependencies generated for this target.
include src/modules/drvt/CMakeFiles/drvt.dir/depend.make

# Include the progress variables for this target.
include src/modules/drvt/CMakeFiles/drvt.dir/progress.make

# Include the compile flags for this target's objects.
include src/modules/drvt/CMakeFiles/drvt.dir/flags.make

src/modules/drvt/CMakeFiles/drvt.dir/codec.c.o: src/modules/drvt/CMakeFiles/drvt.dir/flags.make
src/modules/drvt/CMakeFiles/drvt.dir/codec.c.o: ../src/modules/drvt/codec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/strong/source/xs-robot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/modules/drvt/CMakeFiles/drvt.dir/codec.c.o"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/drvt.dir/codec.c.o   -c /home/strong/source/xs-robot/src/modules/drvt/codec.c

src/modules/drvt/CMakeFiles/drvt.dir/codec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/drvt.dir/codec.c.i"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/strong/source/xs-robot/src/modules/drvt/codec.c > CMakeFiles/drvt.dir/codec.c.i

src/modules/drvt/CMakeFiles/drvt.dir/codec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/drvt.dir/codec.c.s"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/strong/source/xs-robot/src/modules/drvt/codec.c -o CMakeFiles/drvt.dir/codec.c.s

src/modules/drvt/CMakeFiles/drvt.dir/codec.c.o.requires:

.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/codec.c.o.requires

src/modules/drvt/CMakeFiles/drvt.dir/codec.c.o.provides: src/modules/drvt/CMakeFiles/drvt.dir/codec.c.o.requires
	$(MAKE) -f src/modules/drvt/CMakeFiles/drvt.dir/build.make src/modules/drvt/CMakeFiles/drvt.dir/codec.c.o.provides.build
.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/codec.c.o.provides

src/modules/drvt/CMakeFiles/drvt.dir/codec.c.o.provides.build: src/modules/drvt/CMakeFiles/drvt.dir/codec.c.o


src/modules/drvt/CMakeFiles/drvt.dir/crc8.c.o: src/modules/drvt/CMakeFiles/drvt.dir/flags.make
src/modules/drvt/CMakeFiles/drvt.dir/crc8.c.o: ../src/modules/drvt/crc8.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/strong/source/xs-robot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/modules/drvt/CMakeFiles/drvt.dir/crc8.c.o"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/drvt.dir/crc8.c.o   -c /home/strong/source/xs-robot/src/modules/drvt/crc8.c

src/modules/drvt/CMakeFiles/drvt.dir/crc8.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/drvt.dir/crc8.c.i"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/strong/source/xs-robot/src/modules/drvt/crc8.c > CMakeFiles/drvt.dir/crc8.c.i

src/modules/drvt/CMakeFiles/drvt.dir/crc8.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/drvt.dir/crc8.c.s"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/strong/source/xs-robot/src/modules/drvt/crc8.c -o CMakeFiles/drvt.dir/crc8.c.s

src/modules/drvt/CMakeFiles/drvt.dir/crc8.c.o.requires:

.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/crc8.c.o.requires

src/modules/drvt/CMakeFiles/drvt.dir/crc8.c.o.provides: src/modules/drvt/CMakeFiles/drvt.dir/crc8.c.o.requires
	$(MAKE) -f src/modules/drvt/CMakeFiles/drvt.dir/build.make src/modules/drvt/CMakeFiles/drvt.dir/crc8.c.o.provides.build
.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/crc8.c.o.provides

src/modules/drvt/CMakeFiles/drvt.dir/crc8.c.o.provides.build: src/modules/drvt/CMakeFiles/drvt.dir/crc8.c.o


src/modules/drvt/CMakeFiles/drvt.dir/cssl.c.o: src/modules/drvt/CMakeFiles/drvt.dir/flags.make
src/modules/drvt/CMakeFiles/drvt.dir/cssl.c.o: ../src/modules/drvt/cssl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/strong/source/xs-robot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/modules/drvt/CMakeFiles/drvt.dir/cssl.c.o"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/drvt.dir/cssl.c.o   -c /home/strong/source/xs-robot/src/modules/drvt/cssl.c

src/modules/drvt/CMakeFiles/drvt.dir/cssl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/drvt.dir/cssl.c.i"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/strong/source/xs-robot/src/modules/drvt/cssl.c > CMakeFiles/drvt.dir/cssl.c.i

src/modules/drvt/CMakeFiles/drvt.dir/cssl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/drvt.dir/cssl.c.s"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/strong/source/xs-robot/src/modules/drvt/cssl.c -o CMakeFiles/drvt.dir/cssl.c.s

src/modules/drvt/CMakeFiles/drvt.dir/cssl.c.o.requires:

.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/cssl.c.o.requires

src/modules/drvt/CMakeFiles/drvt.dir/cssl.c.o.provides: src/modules/drvt/CMakeFiles/drvt.dir/cssl.c.o.requires
	$(MAKE) -f src/modules/drvt/CMakeFiles/drvt.dir/build.make src/modules/drvt/CMakeFiles/drvt.dir/cssl.c.o.provides.build
.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/cssl.c.o.provides

src/modules/drvt/CMakeFiles/drvt.dir/cssl.c.o.provides.build: src/modules/drvt/CMakeFiles/drvt.dir/cssl.c.o


src/modules/drvt/CMakeFiles/drvt.dir/drvt.c.o: src/modules/drvt/CMakeFiles/drvt.dir/flags.make
src/modules/drvt/CMakeFiles/drvt.dir/drvt.c.o: ../src/modules/drvt/drvt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/strong/source/xs-robot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/modules/drvt/CMakeFiles/drvt.dir/drvt.c.o"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/drvt.dir/drvt.c.o   -c /home/strong/source/xs-robot/src/modules/drvt/drvt.c

src/modules/drvt/CMakeFiles/drvt.dir/drvt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/drvt.dir/drvt.c.i"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/strong/source/xs-robot/src/modules/drvt/drvt.c > CMakeFiles/drvt.dir/drvt.c.i

src/modules/drvt/CMakeFiles/drvt.dir/drvt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/drvt.dir/drvt.c.s"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/strong/source/xs-robot/src/modules/drvt/drvt.c -o CMakeFiles/drvt.dir/drvt.c.s

src/modules/drvt/CMakeFiles/drvt.dir/drvt.c.o.requires:

.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/drvt.c.o.requires

src/modules/drvt/CMakeFiles/drvt.dir/drvt.c.o.provides: src/modules/drvt/CMakeFiles/drvt.dir/drvt.c.o.requires
	$(MAKE) -f src/modules/drvt/CMakeFiles/drvt.dir/build.make src/modules/drvt/CMakeFiles/drvt.dir/drvt.c.o.provides.build
.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/drvt.c.o.provides

src/modules/drvt/CMakeFiles/drvt.dir/drvt.c.o.provides.build: src/modules/drvt/CMakeFiles/drvt.dir/drvt.c.o


src/modules/drvt/CMakeFiles/drvt.dir/ISLink.c.o: src/modules/drvt/CMakeFiles/drvt.dir/flags.make
src/modules/drvt/CMakeFiles/drvt.dir/ISLink.c.o: ../src/modules/drvt/ISLink.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/strong/source/xs-robot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/modules/drvt/CMakeFiles/drvt.dir/ISLink.c.o"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/drvt.dir/ISLink.c.o   -c /home/strong/source/xs-robot/src/modules/drvt/ISLink.c

src/modules/drvt/CMakeFiles/drvt.dir/ISLink.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/drvt.dir/ISLink.c.i"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/strong/source/xs-robot/src/modules/drvt/ISLink.c > CMakeFiles/drvt.dir/ISLink.c.i

src/modules/drvt/CMakeFiles/drvt.dir/ISLink.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/drvt.dir/ISLink.c.s"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/strong/source/xs-robot/src/modules/drvt/ISLink.c -o CMakeFiles/drvt.dir/ISLink.c.s

src/modules/drvt/CMakeFiles/drvt.dir/ISLink.c.o.requires:

.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/ISLink.c.o.requires

src/modules/drvt/CMakeFiles/drvt.dir/ISLink.c.o.provides: src/modules/drvt/CMakeFiles/drvt.dir/ISLink.c.o.requires
	$(MAKE) -f src/modules/drvt/CMakeFiles/drvt.dir/build.make src/modules/drvt/CMakeFiles/drvt.dir/ISLink.c.o.provides.build
.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/ISLink.c.o.provides

src/modules/drvt/CMakeFiles/drvt.dir/ISLink.c.o.provides.build: src/modules/drvt/CMakeFiles/drvt.dir/ISLink.c.o


src/modules/drvt/CMakeFiles/drvt.dir/ISLinkSp.c.o: src/modules/drvt/CMakeFiles/drvt.dir/flags.make
src/modules/drvt/CMakeFiles/drvt.dir/ISLinkSp.c.o: ../src/modules/drvt/ISLinkSp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/strong/source/xs-robot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/modules/drvt/CMakeFiles/drvt.dir/ISLinkSp.c.o"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/drvt.dir/ISLinkSp.c.o   -c /home/strong/source/xs-robot/src/modules/drvt/ISLinkSp.c

src/modules/drvt/CMakeFiles/drvt.dir/ISLinkSp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/drvt.dir/ISLinkSp.c.i"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/strong/source/xs-robot/src/modules/drvt/ISLinkSp.c > CMakeFiles/drvt.dir/ISLinkSp.c.i

src/modules/drvt/CMakeFiles/drvt.dir/ISLinkSp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/drvt.dir/ISLinkSp.c.s"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && arm-linux-gnueabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/strong/source/xs-robot/src/modules/drvt/ISLinkSp.c -o CMakeFiles/drvt.dir/ISLinkSp.c.s

src/modules/drvt/CMakeFiles/drvt.dir/ISLinkSp.c.o.requires:

.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/ISLinkSp.c.o.requires

src/modules/drvt/CMakeFiles/drvt.dir/ISLinkSp.c.o.provides: src/modules/drvt/CMakeFiles/drvt.dir/ISLinkSp.c.o.requires
	$(MAKE) -f src/modules/drvt/CMakeFiles/drvt.dir/build.make src/modules/drvt/CMakeFiles/drvt.dir/ISLinkSp.c.o.provides.build
.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/ISLinkSp.c.o.provides

src/modules/drvt/CMakeFiles/drvt.dir/ISLinkSp.c.o.provides.build: src/modules/drvt/CMakeFiles/drvt.dir/ISLinkSp.c.o


# Object files for target drvt
drvt_OBJECTS = \
"CMakeFiles/drvt.dir/codec.c.o" \
"CMakeFiles/drvt.dir/crc8.c.o" \
"CMakeFiles/drvt.dir/cssl.c.o" \
"CMakeFiles/drvt.dir/drvt.c.o" \
"CMakeFiles/drvt.dir/ISLink.c.o" \
"CMakeFiles/drvt.dir/ISLinkSp.c.o"

# External object files for target drvt
drvt_EXTERNAL_OBJECTS =

src/modules/drvt/libdrvt.a: src/modules/drvt/CMakeFiles/drvt.dir/codec.c.o
src/modules/drvt/libdrvt.a: src/modules/drvt/CMakeFiles/drvt.dir/crc8.c.o
src/modules/drvt/libdrvt.a: src/modules/drvt/CMakeFiles/drvt.dir/cssl.c.o
src/modules/drvt/libdrvt.a: src/modules/drvt/CMakeFiles/drvt.dir/drvt.c.o
src/modules/drvt/libdrvt.a: src/modules/drvt/CMakeFiles/drvt.dir/ISLink.c.o
src/modules/drvt/libdrvt.a: src/modules/drvt/CMakeFiles/drvt.dir/ISLinkSp.c.o
src/modules/drvt/libdrvt.a: src/modules/drvt/CMakeFiles/drvt.dir/build.make
src/modules/drvt/libdrvt.a: src/modules/drvt/CMakeFiles/drvt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/strong/source/xs-robot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C static library libdrvt.a"
	cd /home/strong/source/xs-robot/build/src/modules/drvt && $(CMAKE_COMMAND) -P CMakeFiles/drvt.dir/cmake_clean_target.cmake
	cd /home/strong/source/xs-robot/build/src/modules/drvt && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/drvt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/modules/drvt/CMakeFiles/drvt.dir/build: src/modules/drvt/libdrvt.a

.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/build

src/modules/drvt/CMakeFiles/drvt.dir/requires: src/modules/drvt/CMakeFiles/drvt.dir/codec.c.o.requires
src/modules/drvt/CMakeFiles/drvt.dir/requires: src/modules/drvt/CMakeFiles/drvt.dir/crc8.c.o.requires
src/modules/drvt/CMakeFiles/drvt.dir/requires: src/modules/drvt/CMakeFiles/drvt.dir/cssl.c.o.requires
src/modules/drvt/CMakeFiles/drvt.dir/requires: src/modules/drvt/CMakeFiles/drvt.dir/drvt.c.o.requires
src/modules/drvt/CMakeFiles/drvt.dir/requires: src/modules/drvt/CMakeFiles/drvt.dir/ISLink.c.o.requires
src/modules/drvt/CMakeFiles/drvt.dir/requires: src/modules/drvt/CMakeFiles/drvt.dir/ISLinkSp.c.o.requires

.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/requires

src/modules/drvt/CMakeFiles/drvt.dir/clean:
	cd /home/strong/source/xs-robot/build/src/modules/drvt && $(CMAKE_COMMAND) -P CMakeFiles/drvt.dir/cmake_clean.cmake
.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/clean

src/modules/drvt/CMakeFiles/drvt.dir/depend:
	cd /home/strong/source/xs-robot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/strong/source/xs-robot /home/strong/source/xs-robot/src/modules/drvt /home/strong/source/xs-robot/build /home/strong/source/xs-robot/build/src/modules/drvt /home/strong/source/xs-robot/build/src/modules/drvt/CMakeFiles/drvt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/modules/drvt/CMakeFiles/drvt.dir/depend

