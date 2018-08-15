# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = /u/magina/Documents/lehrfempp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /u/magina/Documents/lehrfempp/lib

# Include any dependencies generated for this target.
include lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/depend.make

# Include the progress variables for this target.
include lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/progress.make

# Include the compile flags for this target's objects.
include lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/flags.make

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_entity_indexing.cc.o: lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/flags.make
lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_entity_indexing.cc.o: lf/mesh/test_utils/check_entity_indexing.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/u/magina/Documents/lehrfempp/lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_entity_indexing.cc.o"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && /usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lf.mesh.test_utils.dir/check_entity_indexing.cc.o -c /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils/check_entity_indexing.cc

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_entity_indexing.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lf.mesh.test_utils.dir/check_entity_indexing.cc.i"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils/check_entity_indexing.cc > CMakeFiles/lf.mesh.test_utils.dir/check_entity_indexing.cc.i

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_entity_indexing.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lf.mesh.test_utils.dir/check_entity_indexing.cc.s"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils/check_entity_indexing.cc -o CMakeFiles/lf.mesh.test_utils.dir/check_entity_indexing.cc.s

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_geometry_orientation.cc.o: lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/flags.make
lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_geometry_orientation.cc.o: lf/mesh/test_utils/check_geometry_orientation.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/u/magina/Documents/lehrfempp/lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_geometry_orientation.cc.o"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && /usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lf.mesh.test_utils.dir/check_geometry_orientation.cc.o -c /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils/check_geometry_orientation.cc

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_geometry_orientation.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lf.mesh.test_utils.dir/check_geometry_orientation.cc.i"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils/check_geometry_orientation.cc > CMakeFiles/lf.mesh.test_utils.dir/check_geometry_orientation.cc.i

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_geometry_orientation.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lf.mesh.test_utils.dir/check_geometry_orientation.cc.s"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils/check_geometry_orientation.cc -o CMakeFiles/lf.mesh.test_utils.dir/check_geometry_orientation.cc.s

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_local_topology.cc.o: lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/flags.make
lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_local_topology.cc.o: lf/mesh/test_utils/check_local_topology.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/u/magina/Documents/lehrfempp/lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_local_topology.cc.o"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && /usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lf.mesh.test_utils.dir/check_local_topology.cc.o -c /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils/check_local_topology.cc

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_local_topology.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lf.mesh.test_utils.dir/check_local_topology.cc.i"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils/check_local_topology.cc > CMakeFiles/lf.mesh.test_utils.dir/check_local_topology.cc.i

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_local_topology.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lf.mesh.test_utils.dir/check_local_topology.cc.s"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils/check_local_topology.cc -o CMakeFiles/lf.mesh.test_utils.dir/check_local_topology.cc.s

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_mesh_completeness.cc.o: lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/flags.make
lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_mesh_completeness.cc.o: lf/mesh/test_utils/check_mesh_completeness.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/u/magina/Documents/lehrfempp/lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_mesh_completeness.cc.o"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && /usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lf.mesh.test_utils.dir/check_mesh_completeness.cc.o -c /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils/check_mesh_completeness.cc

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_mesh_completeness.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lf.mesh.test_utils.dir/check_mesh_completeness.cc.i"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils/check_mesh_completeness.cc > CMakeFiles/lf.mesh.test_utils.dir/check_mesh_completeness.cc.i

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_mesh_completeness.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lf.mesh.test_utils.dir/check_mesh_completeness.cc.s"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils/check_mesh_completeness.cc -o CMakeFiles/lf.mesh.test_utils.dir/check_mesh_completeness.cc.s

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/test_meshes.cc.o: lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/flags.make
lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/test_meshes.cc.o: lf/mesh/test_utils/test_meshes.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/u/magina/Documents/lehrfempp/lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/test_meshes.cc.o"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && /usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lf.mesh.test_utils.dir/test_meshes.cc.o -c /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils/test_meshes.cc

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/test_meshes.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lf.mesh.test_utils.dir/test_meshes.cc.i"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils/test_meshes.cc > CMakeFiles/lf.mesh.test_utils.dir/test_meshes.cc.i

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/test_meshes.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lf.mesh.test_utils.dir/test_meshes.cc.s"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils/test_meshes.cc -o CMakeFiles/lf.mesh.test_utils.dir/test_meshes.cc.s

# Object files for target lf.mesh.test_utils
lf_mesh_test_utils_OBJECTS = \
"CMakeFiles/lf.mesh.test_utils.dir/check_entity_indexing.cc.o" \
"CMakeFiles/lf.mesh.test_utils.dir/check_geometry_orientation.cc.o" \
"CMakeFiles/lf.mesh.test_utils.dir/check_local_topology.cc.o" \
"CMakeFiles/lf.mesh.test_utils.dir/check_mesh_completeness.cc.o" \
"CMakeFiles/lf.mesh.test_utils.dir/test_meshes.cc.o"

# External object files for target lf.mesh.test_utils
lf_mesh_test_utils_EXTERNAL_OBJECTS =

lib/lf/mesh/test_utils/liblf.mesh.test_utils.a: lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_entity_indexing.cc.o
lib/lf/mesh/test_utils/liblf.mesh.test_utils.a: lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_geometry_orientation.cc.o
lib/lf/mesh/test_utils/liblf.mesh.test_utils.a: lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_local_topology.cc.o
lib/lf/mesh/test_utils/liblf.mesh.test_utils.a: lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/check_mesh_completeness.cc.o
lib/lf/mesh/test_utils/liblf.mesh.test_utils.a: lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/test_meshes.cc.o
lib/lf/mesh/test_utils/liblf.mesh.test_utils.a: lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/build.make
lib/lf/mesh/test_utils/liblf.mesh.test_utils.a: lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/u/magina/Documents/lehrfempp/lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library liblf.mesh.test_utils.a"
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && $(CMAKE_COMMAND) -P CMakeFiles/lf.mesh.test_utils.dir/cmake_clean_target.cmake
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lf.mesh.test_utils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/build: lib/lf/mesh/test_utils/liblf.mesh.test_utils.a

.PHONY : lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/build

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/clean:
	cd /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils && $(CMAKE_COMMAND) -P CMakeFiles/lf.mesh.test_utils.dir/cmake_clean.cmake
.PHONY : lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/clean

lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/depend:
	cd /u/magina/Documents/lehrfempp/lib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /u/magina/Documents/lehrfempp /u/magina/Documents/lehrfempp/lib/lf/mesh/test_utils /u/magina/Documents/lehrfempp/lib /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils /u/magina/Documents/lehrfempp/lib/lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/lf/mesh/test_utils/CMakeFiles/lf.mesh.test_utils.dir/depend

