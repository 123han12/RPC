# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/masplove/Project/RPC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/masplove/Project/RPC/build

# Include any dependencies generated for this target.
include src/CMakeFiles/rpc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/rpc.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/rpc.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/rpc.dir/flags.make

src/CMakeFiles/rpc.dir/protocol.pb.cc.o: src/CMakeFiles/rpc.dir/flags.make
src/CMakeFiles/rpc.dir/protocol.pb.cc.o: ../src/protocol.pb.cc
src/CMakeFiles/rpc.dir/protocol.pb.cc.o: src/CMakeFiles/rpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/masplove/Project/RPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/rpc.dir/protocol.pb.cc.o"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/rpc.dir/protocol.pb.cc.o -MF CMakeFiles/rpc.dir/protocol.pb.cc.o.d -o CMakeFiles/rpc.dir/protocol.pb.cc.o -c /home/masplove/Project/RPC/src/protocol.pb.cc

src/CMakeFiles/rpc.dir/protocol.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc.dir/protocol.pb.cc.i"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/masplove/Project/RPC/src/protocol.pb.cc > CMakeFiles/rpc.dir/protocol.pb.cc.i

src/CMakeFiles/rpc.dir/protocol.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/protocol.pb.cc.s"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/masplove/Project/RPC/src/protocol.pb.cc -o CMakeFiles/rpc.dir/protocol.pb.cc.s

src/CMakeFiles/rpc.dir/rpcapplication.cpp.o: src/CMakeFiles/rpc.dir/flags.make
src/CMakeFiles/rpc.dir/rpcapplication.cpp.o: ../src/rpcapplication.cpp
src/CMakeFiles/rpc.dir/rpcapplication.cpp.o: src/CMakeFiles/rpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/masplove/Project/RPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/rpc.dir/rpcapplication.cpp.o"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/rpc.dir/rpcapplication.cpp.o -MF CMakeFiles/rpc.dir/rpcapplication.cpp.o.d -o CMakeFiles/rpc.dir/rpcapplication.cpp.o -c /home/masplove/Project/RPC/src/rpcapplication.cpp

src/CMakeFiles/rpc.dir/rpcapplication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc.dir/rpcapplication.cpp.i"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/masplove/Project/RPC/src/rpcapplication.cpp > CMakeFiles/rpc.dir/rpcapplication.cpp.i

src/CMakeFiles/rpc.dir/rpcapplication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/rpcapplication.cpp.s"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/masplove/Project/RPC/src/rpcapplication.cpp -o CMakeFiles/rpc.dir/rpcapplication.cpp.s

src/CMakeFiles/rpc.dir/rpcchannel.cpp.o: src/CMakeFiles/rpc.dir/flags.make
src/CMakeFiles/rpc.dir/rpcchannel.cpp.o: ../src/rpcchannel.cpp
src/CMakeFiles/rpc.dir/rpcchannel.cpp.o: src/CMakeFiles/rpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/masplove/Project/RPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/rpc.dir/rpcchannel.cpp.o"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/rpc.dir/rpcchannel.cpp.o -MF CMakeFiles/rpc.dir/rpcchannel.cpp.o.d -o CMakeFiles/rpc.dir/rpcchannel.cpp.o -c /home/masplove/Project/RPC/src/rpcchannel.cpp

src/CMakeFiles/rpc.dir/rpcchannel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc.dir/rpcchannel.cpp.i"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/masplove/Project/RPC/src/rpcchannel.cpp > CMakeFiles/rpc.dir/rpcchannel.cpp.i

src/CMakeFiles/rpc.dir/rpcchannel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/rpcchannel.cpp.s"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/masplove/Project/RPC/src/rpcchannel.cpp -o CMakeFiles/rpc.dir/rpcchannel.cpp.s

src/CMakeFiles/rpc.dir/rpcconfig.cpp.o: src/CMakeFiles/rpc.dir/flags.make
src/CMakeFiles/rpc.dir/rpcconfig.cpp.o: ../src/rpcconfig.cpp
src/CMakeFiles/rpc.dir/rpcconfig.cpp.o: src/CMakeFiles/rpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/masplove/Project/RPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/rpc.dir/rpcconfig.cpp.o"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/rpc.dir/rpcconfig.cpp.o -MF CMakeFiles/rpc.dir/rpcconfig.cpp.o.d -o CMakeFiles/rpc.dir/rpcconfig.cpp.o -c /home/masplove/Project/RPC/src/rpcconfig.cpp

src/CMakeFiles/rpc.dir/rpcconfig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc.dir/rpcconfig.cpp.i"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/masplove/Project/RPC/src/rpcconfig.cpp > CMakeFiles/rpc.dir/rpcconfig.cpp.i

src/CMakeFiles/rpc.dir/rpcconfig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/rpcconfig.cpp.s"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/masplove/Project/RPC/src/rpcconfig.cpp -o CMakeFiles/rpc.dir/rpcconfig.cpp.s

src/CMakeFiles/rpc.dir/rpccontroller.cc.o: src/CMakeFiles/rpc.dir/flags.make
src/CMakeFiles/rpc.dir/rpccontroller.cc.o: ../src/rpccontroller.cc
src/CMakeFiles/rpc.dir/rpccontroller.cc.o: src/CMakeFiles/rpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/masplove/Project/RPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/rpc.dir/rpccontroller.cc.o"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/rpc.dir/rpccontroller.cc.o -MF CMakeFiles/rpc.dir/rpccontroller.cc.o.d -o CMakeFiles/rpc.dir/rpccontroller.cc.o -c /home/masplove/Project/RPC/src/rpccontroller.cc

src/CMakeFiles/rpc.dir/rpccontroller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc.dir/rpccontroller.cc.i"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/masplove/Project/RPC/src/rpccontroller.cc > CMakeFiles/rpc.dir/rpccontroller.cc.i

src/CMakeFiles/rpc.dir/rpccontroller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/rpccontroller.cc.s"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/masplove/Project/RPC/src/rpccontroller.cc -o CMakeFiles/rpc.dir/rpccontroller.cc.s

src/CMakeFiles/rpc.dir/rpcprovider.cc.o: src/CMakeFiles/rpc.dir/flags.make
src/CMakeFiles/rpc.dir/rpcprovider.cc.o: ../src/rpcprovider.cc
src/CMakeFiles/rpc.dir/rpcprovider.cc.o: src/CMakeFiles/rpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/masplove/Project/RPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/rpc.dir/rpcprovider.cc.o"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/rpc.dir/rpcprovider.cc.o -MF CMakeFiles/rpc.dir/rpcprovider.cc.o.d -o CMakeFiles/rpc.dir/rpcprovider.cc.o -c /home/masplove/Project/RPC/src/rpcprovider.cc

src/CMakeFiles/rpc.dir/rpcprovider.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc.dir/rpcprovider.cc.i"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/masplove/Project/RPC/src/rpcprovider.cc > CMakeFiles/rpc.dir/rpcprovider.cc.i

src/CMakeFiles/rpc.dir/rpcprovider.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/rpcprovider.cc.s"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/masplove/Project/RPC/src/rpcprovider.cc -o CMakeFiles/rpc.dir/rpcprovider.cc.s

src/CMakeFiles/rpc.dir/rpcserverlog.cpp.o: src/CMakeFiles/rpc.dir/flags.make
src/CMakeFiles/rpc.dir/rpcserverlog.cpp.o: ../src/rpcserverlog.cpp
src/CMakeFiles/rpc.dir/rpcserverlog.cpp.o: src/CMakeFiles/rpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/masplove/Project/RPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/rpc.dir/rpcserverlog.cpp.o"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/rpc.dir/rpcserverlog.cpp.o -MF CMakeFiles/rpc.dir/rpcserverlog.cpp.o.d -o CMakeFiles/rpc.dir/rpcserverlog.cpp.o -c /home/masplove/Project/RPC/src/rpcserverlog.cpp

src/CMakeFiles/rpc.dir/rpcserverlog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc.dir/rpcserverlog.cpp.i"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/masplove/Project/RPC/src/rpcserverlog.cpp > CMakeFiles/rpc.dir/rpcserverlog.cpp.i

src/CMakeFiles/rpc.dir/rpcserverlog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/rpcserverlog.cpp.s"
	cd /home/masplove/Project/RPC/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/masplove/Project/RPC/src/rpcserverlog.cpp -o CMakeFiles/rpc.dir/rpcserverlog.cpp.s

# Object files for target rpc
rpc_OBJECTS = \
"CMakeFiles/rpc.dir/protocol.pb.cc.o" \
"CMakeFiles/rpc.dir/rpcapplication.cpp.o" \
"CMakeFiles/rpc.dir/rpcchannel.cpp.o" \
"CMakeFiles/rpc.dir/rpcconfig.cpp.o" \
"CMakeFiles/rpc.dir/rpccontroller.cc.o" \
"CMakeFiles/rpc.dir/rpcprovider.cc.o" \
"CMakeFiles/rpc.dir/rpcserverlog.cpp.o"

# External object files for target rpc
rpc_EXTERNAL_OBJECTS =

../lib/librpc.a: src/CMakeFiles/rpc.dir/protocol.pb.cc.o
../lib/librpc.a: src/CMakeFiles/rpc.dir/rpcapplication.cpp.o
../lib/librpc.a: src/CMakeFiles/rpc.dir/rpcchannel.cpp.o
../lib/librpc.a: src/CMakeFiles/rpc.dir/rpcconfig.cpp.o
../lib/librpc.a: src/CMakeFiles/rpc.dir/rpccontroller.cc.o
../lib/librpc.a: src/CMakeFiles/rpc.dir/rpcprovider.cc.o
../lib/librpc.a: src/CMakeFiles/rpc.dir/rpcserverlog.cpp.o
../lib/librpc.a: src/CMakeFiles/rpc.dir/build.make
../lib/librpc.a: src/CMakeFiles/rpc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/masplove/Project/RPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library ../../lib/librpc.a"
	cd /home/masplove/Project/RPC/build/src && $(CMAKE_COMMAND) -P CMakeFiles/rpc.dir/cmake_clean_target.cmake
	cd /home/masplove/Project/RPC/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rpc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/rpc.dir/build: ../lib/librpc.a
.PHONY : src/CMakeFiles/rpc.dir/build

src/CMakeFiles/rpc.dir/clean:
	cd /home/masplove/Project/RPC/build/src && $(CMAKE_COMMAND) -P CMakeFiles/rpc.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/rpc.dir/clean

src/CMakeFiles/rpc.dir/depend:
	cd /home/masplove/Project/RPC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/masplove/Project/RPC /home/masplove/Project/RPC/src /home/masplove/Project/RPC/build /home/masplove/Project/RPC/build/src /home/masplove/Project/RPC/build/src/CMakeFiles/rpc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/rpc.dir/depend

