# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ryan/Projects/tabula-rasa-engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug

# Include any dependencies generated for this target.
include Zombiez/CMakeFiles/zombiez.dir/depend.make

# Include the progress variables for this target.
include Zombiez/CMakeFiles/zombiez.dir/progress.make

# Include the compile flags for this target's objects.
include Zombiez/CMakeFiles/zombiez.dir/flags.make

Zombiez/CMakeFiles/zombiez.dir/src/main.cpp.o: Zombiez/CMakeFiles/zombiez.dir/flags.make
Zombiez/CMakeFiles/zombiez.dir/src/main.cpp.o: ../Zombiez/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Zombiez/CMakeFiles/zombiez.dir/src/main.cpp.o"
	cd /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/Zombiez && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zombiez.dir/src/main.cpp.o -c /Users/ryan/Projects/tabula-rasa-engine/Zombiez/src/main.cpp

Zombiez/CMakeFiles/zombiez.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zombiez.dir/src/main.cpp.i"
	cd /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/Zombiez && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ryan/Projects/tabula-rasa-engine/Zombiez/src/main.cpp > CMakeFiles/zombiez.dir/src/main.cpp.i

Zombiez/CMakeFiles/zombiez.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zombiez.dir/src/main.cpp.s"
	cd /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/Zombiez && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ryan/Projects/tabula-rasa-engine/Zombiez/src/main.cpp -o CMakeFiles/zombiez.dir/src/main.cpp.s

Zombiez/CMakeFiles/zombiez.dir/src/main.cpp.o.requires:

.PHONY : Zombiez/CMakeFiles/zombiez.dir/src/main.cpp.o.requires

Zombiez/CMakeFiles/zombiez.dir/src/main.cpp.o.provides: Zombiez/CMakeFiles/zombiez.dir/src/main.cpp.o.requires
	$(MAKE) -f Zombiez/CMakeFiles/zombiez.dir/build.make Zombiez/CMakeFiles/zombiez.dir/src/main.cpp.o.provides.build
.PHONY : Zombiez/CMakeFiles/zombiez.dir/src/main.cpp.o.provides

Zombiez/CMakeFiles/zombiez.dir/src/main.cpp.o.provides.build: Zombiez/CMakeFiles/zombiez.dir/src/main.cpp.o


Zombiez/CMakeFiles/zombiez.dir/src/MainGame.cpp.o: Zombiez/CMakeFiles/zombiez.dir/flags.make
Zombiez/CMakeFiles/zombiez.dir/src/MainGame.cpp.o: ../Zombiez/src/MainGame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Zombiez/CMakeFiles/zombiez.dir/src/MainGame.cpp.o"
	cd /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/Zombiez && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zombiez.dir/src/MainGame.cpp.o -c /Users/ryan/Projects/tabula-rasa-engine/Zombiez/src/MainGame.cpp

Zombiez/CMakeFiles/zombiez.dir/src/MainGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zombiez.dir/src/MainGame.cpp.i"
	cd /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/Zombiez && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ryan/Projects/tabula-rasa-engine/Zombiez/src/MainGame.cpp > CMakeFiles/zombiez.dir/src/MainGame.cpp.i

Zombiez/CMakeFiles/zombiez.dir/src/MainGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zombiez.dir/src/MainGame.cpp.s"
	cd /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/Zombiez && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ryan/Projects/tabula-rasa-engine/Zombiez/src/MainGame.cpp -o CMakeFiles/zombiez.dir/src/MainGame.cpp.s

Zombiez/CMakeFiles/zombiez.dir/src/MainGame.cpp.o.requires:

.PHONY : Zombiez/CMakeFiles/zombiez.dir/src/MainGame.cpp.o.requires

Zombiez/CMakeFiles/zombiez.dir/src/MainGame.cpp.o.provides: Zombiez/CMakeFiles/zombiez.dir/src/MainGame.cpp.o.requires
	$(MAKE) -f Zombiez/CMakeFiles/zombiez.dir/build.make Zombiez/CMakeFiles/zombiez.dir/src/MainGame.cpp.o.provides.build
.PHONY : Zombiez/CMakeFiles/zombiez.dir/src/MainGame.cpp.o.provides

Zombiez/CMakeFiles/zombiez.dir/src/MainGame.cpp.o.provides.build: Zombiez/CMakeFiles/zombiez.dir/src/MainGame.cpp.o


Zombiez/CMakeFiles/zombiez.dir/src/Bullet.cpp.o: Zombiez/CMakeFiles/zombiez.dir/flags.make
Zombiez/CMakeFiles/zombiez.dir/src/Bullet.cpp.o: ../Zombiez/src/Bullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Zombiez/CMakeFiles/zombiez.dir/src/Bullet.cpp.o"
	cd /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/Zombiez && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zombiez.dir/src/Bullet.cpp.o -c /Users/ryan/Projects/tabula-rasa-engine/Zombiez/src/Bullet.cpp

Zombiez/CMakeFiles/zombiez.dir/src/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zombiez.dir/src/Bullet.cpp.i"
	cd /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/Zombiez && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ryan/Projects/tabula-rasa-engine/Zombiez/src/Bullet.cpp > CMakeFiles/zombiez.dir/src/Bullet.cpp.i

Zombiez/CMakeFiles/zombiez.dir/src/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zombiez.dir/src/Bullet.cpp.s"
	cd /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/Zombiez && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ryan/Projects/tabula-rasa-engine/Zombiez/src/Bullet.cpp -o CMakeFiles/zombiez.dir/src/Bullet.cpp.s

Zombiez/CMakeFiles/zombiez.dir/src/Bullet.cpp.o.requires:

.PHONY : Zombiez/CMakeFiles/zombiez.dir/src/Bullet.cpp.o.requires

Zombiez/CMakeFiles/zombiez.dir/src/Bullet.cpp.o.provides: Zombiez/CMakeFiles/zombiez.dir/src/Bullet.cpp.o.requires
	$(MAKE) -f Zombiez/CMakeFiles/zombiez.dir/build.make Zombiez/CMakeFiles/zombiez.dir/src/Bullet.cpp.o.provides.build
.PHONY : Zombiez/CMakeFiles/zombiez.dir/src/Bullet.cpp.o.provides

Zombiez/CMakeFiles/zombiez.dir/src/Bullet.cpp.o.provides.build: Zombiez/CMakeFiles/zombiez.dir/src/Bullet.cpp.o


# Object files for target zombiez
zombiez_OBJECTS = \
"CMakeFiles/zombiez.dir/src/main.cpp.o" \
"CMakeFiles/zombiez.dir/src/MainGame.cpp.o" \
"CMakeFiles/zombiez.dir/src/Bullet.cpp.o"

# External object files for target zombiez
zombiez_EXTERNAL_OBJECTS =

Zombiez/zombiez: Zombiez/CMakeFiles/zombiez.dir/src/main.cpp.o
Zombiez/zombiez: Zombiez/CMakeFiles/zombiez.dir/src/MainGame.cpp.o
Zombiez/zombiez: Zombiez/CMakeFiles/zombiez.dir/src/Bullet.cpp.o
Zombiez/zombiez: Zombiez/CMakeFiles/zombiez.dir/build.make
Zombiez/zombiez: TabulaRasa/libtabula_rasa.a
Zombiez/zombiez: /usr/local/lib/libSDL2main.a
Zombiez/zombiez: /usr/local/lib/libSDL2.dylib
Zombiez/zombiez: /usr/local/lib/libSDL2_image.dylib
Zombiez/zombiez: /usr/local/lib/libSDL2_ttf.dylib
Zombiez/zombiez: /usr/local/lib/libSDL2_mixer.dylib
Zombiez/zombiez: Zombiez/CMakeFiles/zombiez.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable zombiez"
	cd /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/Zombiez && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zombiez.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Zombiez/CMakeFiles/zombiez.dir/build: Zombiez/zombiez

.PHONY : Zombiez/CMakeFiles/zombiez.dir/build

Zombiez/CMakeFiles/zombiez.dir/requires: Zombiez/CMakeFiles/zombiez.dir/src/main.cpp.o.requires
Zombiez/CMakeFiles/zombiez.dir/requires: Zombiez/CMakeFiles/zombiez.dir/src/MainGame.cpp.o.requires
Zombiez/CMakeFiles/zombiez.dir/requires: Zombiez/CMakeFiles/zombiez.dir/src/Bullet.cpp.o.requires

.PHONY : Zombiez/CMakeFiles/zombiez.dir/requires

Zombiez/CMakeFiles/zombiez.dir/clean:
	cd /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/Zombiez && $(CMAKE_COMMAND) -P CMakeFiles/zombiez.dir/cmake_clean.cmake
.PHONY : Zombiez/CMakeFiles/zombiez.dir/clean

Zombiez/CMakeFiles/zombiez.dir/depend:
	cd /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ryan/Projects/tabula-rasa-engine /Users/ryan/Projects/tabula-rasa-engine/Zombiez /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/Zombiez /Users/ryan/Projects/tabula-rasa-engine/cmake-build-debug/Zombiez/CMakeFiles/zombiez.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Zombiez/CMakeFiles/zombiez.dir/depend

