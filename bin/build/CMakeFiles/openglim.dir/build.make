# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/kali-smily/openglim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kali-smily/openglim/build

# Include any dependencies generated for this target.
include CMakeFiles/openglim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/openglim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/openglim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/openglim.dir/flags.make

CMakeFiles/openglim.dir/imgui/imgui.cpp.o: CMakeFiles/openglim.dir/flags.make
CMakeFiles/openglim.dir/imgui/imgui.cpp.o: /home/kali-smily/openglim/imgui/imgui.cpp
CMakeFiles/openglim.dir/imgui/imgui.cpp.o: CMakeFiles/openglim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali-smily/openglim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/openglim.dir/imgui/imgui.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/openglim.dir/imgui/imgui.cpp.o -MF CMakeFiles/openglim.dir/imgui/imgui.cpp.o.d -o CMakeFiles/openglim.dir/imgui/imgui.cpp.o -c /home/kali-smily/openglim/imgui/imgui.cpp

CMakeFiles/openglim.dir/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglim.dir/imgui/imgui.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali-smily/openglim/imgui/imgui.cpp > CMakeFiles/openglim.dir/imgui/imgui.cpp.i

CMakeFiles/openglim.dir/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglim.dir/imgui/imgui.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali-smily/openglim/imgui/imgui.cpp -o CMakeFiles/openglim.dir/imgui/imgui.cpp.s

CMakeFiles/openglim.dir/imgui/imgui_demo.cpp.o: CMakeFiles/openglim.dir/flags.make
CMakeFiles/openglim.dir/imgui/imgui_demo.cpp.o: /home/kali-smily/openglim/imgui/imgui_demo.cpp
CMakeFiles/openglim.dir/imgui/imgui_demo.cpp.o: CMakeFiles/openglim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali-smily/openglim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/openglim.dir/imgui/imgui_demo.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/openglim.dir/imgui/imgui_demo.cpp.o -MF CMakeFiles/openglim.dir/imgui/imgui_demo.cpp.o.d -o CMakeFiles/openglim.dir/imgui/imgui_demo.cpp.o -c /home/kali-smily/openglim/imgui/imgui_demo.cpp

CMakeFiles/openglim.dir/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglim.dir/imgui/imgui_demo.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali-smily/openglim/imgui/imgui_demo.cpp > CMakeFiles/openglim.dir/imgui/imgui_demo.cpp.i

CMakeFiles/openglim.dir/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglim.dir/imgui/imgui_demo.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali-smily/openglim/imgui/imgui_demo.cpp -o CMakeFiles/openglim.dir/imgui/imgui_demo.cpp.s

CMakeFiles/openglim.dir/imgui/imgui_draw.cpp.o: CMakeFiles/openglim.dir/flags.make
CMakeFiles/openglim.dir/imgui/imgui_draw.cpp.o: /home/kali-smily/openglim/imgui/imgui_draw.cpp
CMakeFiles/openglim.dir/imgui/imgui_draw.cpp.o: CMakeFiles/openglim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali-smily/openglim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/openglim.dir/imgui/imgui_draw.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/openglim.dir/imgui/imgui_draw.cpp.o -MF CMakeFiles/openglim.dir/imgui/imgui_draw.cpp.o.d -o CMakeFiles/openglim.dir/imgui/imgui_draw.cpp.o -c /home/kali-smily/openglim/imgui/imgui_draw.cpp

CMakeFiles/openglim.dir/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglim.dir/imgui/imgui_draw.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali-smily/openglim/imgui/imgui_draw.cpp > CMakeFiles/openglim.dir/imgui/imgui_draw.cpp.i

CMakeFiles/openglim.dir/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglim.dir/imgui/imgui_draw.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali-smily/openglim/imgui/imgui_draw.cpp -o CMakeFiles/openglim.dir/imgui/imgui_draw.cpp.s

CMakeFiles/openglim.dir/imgui/imgui_tables.cpp.o: CMakeFiles/openglim.dir/flags.make
CMakeFiles/openglim.dir/imgui/imgui_tables.cpp.o: /home/kali-smily/openglim/imgui/imgui_tables.cpp
CMakeFiles/openglim.dir/imgui/imgui_tables.cpp.o: CMakeFiles/openglim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali-smily/openglim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/openglim.dir/imgui/imgui_tables.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/openglim.dir/imgui/imgui_tables.cpp.o -MF CMakeFiles/openglim.dir/imgui/imgui_tables.cpp.o.d -o CMakeFiles/openglim.dir/imgui/imgui_tables.cpp.o -c /home/kali-smily/openglim/imgui/imgui_tables.cpp

CMakeFiles/openglim.dir/imgui/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglim.dir/imgui/imgui_tables.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali-smily/openglim/imgui/imgui_tables.cpp > CMakeFiles/openglim.dir/imgui/imgui_tables.cpp.i

CMakeFiles/openglim.dir/imgui/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglim.dir/imgui/imgui_tables.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali-smily/openglim/imgui/imgui_tables.cpp -o CMakeFiles/openglim.dir/imgui/imgui_tables.cpp.s

CMakeFiles/openglim.dir/imgui/imgui_widgets.cpp.o: CMakeFiles/openglim.dir/flags.make
CMakeFiles/openglim.dir/imgui/imgui_widgets.cpp.o: /home/kali-smily/openglim/imgui/imgui_widgets.cpp
CMakeFiles/openglim.dir/imgui/imgui_widgets.cpp.o: CMakeFiles/openglim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali-smily/openglim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/openglim.dir/imgui/imgui_widgets.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/openglim.dir/imgui/imgui_widgets.cpp.o -MF CMakeFiles/openglim.dir/imgui/imgui_widgets.cpp.o.d -o CMakeFiles/openglim.dir/imgui/imgui_widgets.cpp.o -c /home/kali-smily/openglim/imgui/imgui_widgets.cpp

CMakeFiles/openglim.dir/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglim.dir/imgui/imgui_widgets.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali-smily/openglim/imgui/imgui_widgets.cpp > CMakeFiles/openglim.dir/imgui/imgui_widgets.cpp.i

CMakeFiles/openglim.dir/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglim.dir/imgui/imgui_widgets.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali-smily/openglim/imgui/imgui_widgets.cpp -o CMakeFiles/openglim.dir/imgui/imgui_widgets.cpp.s

CMakeFiles/openglim.dir/imgui/backends/imgui_impl_glfw.cpp.o: CMakeFiles/openglim.dir/flags.make
CMakeFiles/openglim.dir/imgui/backends/imgui_impl_glfw.cpp.o: /home/kali-smily/openglim/imgui/backends/imgui_impl_glfw.cpp
CMakeFiles/openglim.dir/imgui/backends/imgui_impl_glfw.cpp.o: CMakeFiles/openglim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali-smily/openglim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/openglim.dir/imgui/backends/imgui_impl_glfw.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/openglim.dir/imgui/backends/imgui_impl_glfw.cpp.o -MF CMakeFiles/openglim.dir/imgui/backends/imgui_impl_glfw.cpp.o.d -o CMakeFiles/openglim.dir/imgui/backends/imgui_impl_glfw.cpp.o -c /home/kali-smily/openglim/imgui/backends/imgui_impl_glfw.cpp

CMakeFiles/openglim.dir/imgui/backends/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglim.dir/imgui/backends/imgui_impl_glfw.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali-smily/openglim/imgui/backends/imgui_impl_glfw.cpp > CMakeFiles/openglim.dir/imgui/backends/imgui_impl_glfw.cpp.i

CMakeFiles/openglim.dir/imgui/backends/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglim.dir/imgui/backends/imgui_impl_glfw.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali-smily/openglim/imgui/backends/imgui_impl_glfw.cpp -o CMakeFiles/openglim.dir/imgui/backends/imgui_impl_glfw.cpp.s

CMakeFiles/openglim.dir/imgui/backends/imgui_impl_opengl3.cpp.o: CMakeFiles/openglim.dir/flags.make
CMakeFiles/openglim.dir/imgui/backends/imgui_impl_opengl3.cpp.o: /home/kali-smily/openglim/imgui/backends/imgui_impl_opengl3.cpp
CMakeFiles/openglim.dir/imgui/backends/imgui_impl_opengl3.cpp.o: CMakeFiles/openglim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali-smily/openglim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/openglim.dir/imgui/backends/imgui_impl_opengl3.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/openglim.dir/imgui/backends/imgui_impl_opengl3.cpp.o -MF CMakeFiles/openglim.dir/imgui/backends/imgui_impl_opengl3.cpp.o.d -o CMakeFiles/openglim.dir/imgui/backends/imgui_impl_opengl3.cpp.o -c /home/kali-smily/openglim/imgui/backends/imgui_impl_opengl3.cpp

CMakeFiles/openglim.dir/imgui/backends/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglim.dir/imgui/backends/imgui_impl_opengl3.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali-smily/openglim/imgui/backends/imgui_impl_opengl3.cpp > CMakeFiles/openglim.dir/imgui/backends/imgui_impl_opengl3.cpp.i

CMakeFiles/openglim.dir/imgui/backends/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglim.dir/imgui/backends/imgui_impl_opengl3.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali-smily/openglim/imgui/backends/imgui_impl_opengl3.cpp -o CMakeFiles/openglim.dir/imgui/backends/imgui_impl_opengl3.cpp.s

CMakeFiles/openglim.dir/src/linux/glad.c.o: CMakeFiles/openglim.dir/flags.make
CMakeFiles/openglim.dir/src/linux/glad.c.o: /home/kali-smily/openglim/src/linux/glad.c
CMakeFiles/openglim.dir/src/linux/glad.c.o: CMakeFiles/openglim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali-smily/openglim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/openglim.dir/src/linux/glad.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/openglim.dir/src/linux/glad.c.o -MF CMakeFiles/openglim.dir/src/linux/glad.c.o.d -o CMakeFiles/openglim.dir/src/linux/glad.c.o -c /home/kali-smily/openglim/src/linux/glad.c

CMakeFiles/openglim.dir/src/linux/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/openglim.dir/src/linux/glad.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kali-smily/openglim/src/linux/glad.c > CMakeFiles/openglim.dir/src/linux/glad.c.i

CMakeFiles/openglim.dir/src/linux/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/openglim.dir/src/linux/glad.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kali-smily/openglim/src/linux/glad.c -o CMakeFiles/openglim.dir/src/linux/glad.c.s

CMakeFiles/openglim.dir/src/linux/main.cpp.o: CMakeFiles/openglim.dir/flags.make
CMakeFiles/openglim.dir/src/linux/main.cpp.o: /home/kali-smily/openglim/src/linux/main.cpp
CMakeFiles/openglim.dir/src/linux/main.cpp.o: CMakeFiles/openglim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali-smily/openglim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/openglim.dir/src/linux/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/openglim.dir/src/linux/main.cpp.o -MF CMakeFiles/openglim.dir/src/linux/main.cpp.o.d -o CMakeFiles/openglim.dir/src/linux/main.cpp.o -c /home/kali-smily/openglim/src/linux/main.cpp

CMakeFiles/openglim.dir/src/linux/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglim.dir/src/linux/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali-smily/openglim/src/linux/main.cpp > CMakeFiles/openglim.dir/src/linux/main.cpp.i

CMakeFiles/openglim.dir/src/linux/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglim.dir/src/linux/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali-smily/openglim/src/linux/main.cpp -o CMakeFiles/openglim.dir/src/linux/main.cpp.s

CMakeFiles/openglim.dir/src/linux/xxx.cpp.o: CMakeFiles/openglim.dir/flags.make
CMakeFiles/openglim.dir/src/linux/xxx.cpp.o: /home/kali-smily/openglim/src/linux/xxx.cpp
CMakeFiles/openglim.dir/src/linux/xxx.cpp.o: CMakeFiles/openglim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali-smily/openglim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/openglim.dir/src/linux/xxx.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/openglim.dir/src/linux/xxx.cpp.o -MF CMakeFiles/openglim.dir/src/linux/xxx.cpp.o.d -o CMakeFiles/openglim.dir/src/linux/xxx.cpp.o -c /home/kali-smily/openglim/src/linux/xxx.cpp

CMakeFiles/openglim.dir/src/linux/xxx.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglim.dir/src/linux/xxx.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali-smily/openglim/src/linux/xxx.cpp > CMakeFiles/openglim.dir/src/linux/xxx.cpp.i

CMakeFiles/openglim.dir/src/linux/xxx.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglim.dir/src/linux/xxx.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali-smily/openglim/src/linux/xxx.cpp -o CMakeFiles/openglim.dir/src/linux/xxx.cpp.s

# Object files for target openglim
openglim_OBJECTS = \
"CMakeFiles/openglim.dir/imgui/imgui.cpp.o" \
"CMakeFiles/openglim.dir/imgui/imgui_demo.cpp.o" \
"CMakeFiles/openglim.dir/imgui/imgui_draw.cpp.o" \
"CMakeFiles/openglim.dir/imgui/imgui_tables.cpp.o" \
"CMakeFiles/openglim.dir/imgui/imgui_widgets.cpp.o" \
"CMakeFiles/openglim.dir/imgui/backends/imgui_impl_glfw.cpp.o" \
"CMakeFiles/openglim.dir/imgui/backends/imgui_impl_opengl3.cpp.o" \
"CMakeFiles/openglim.dir/src/linux/glad.c.o" \
"CMakeFiles/openglim.dir/src/linux/main.cpp.o" \
"CMakeFiles/openglim.dir/src/linux/xxx.cpp.o"

# External object files for target openglim
openglim_EXTERNAL_OBJECTS =

openglim: CMakeFiles/openglim.dir/imgui/imgui.cpp.o
openglim: CMakeFiles/openglim.dir/imgui/imgui_demo.cpp.o
openglim: CMakeFiles/openglim.dir/imgui/imgui_draw.cpp.o
openglim: CMakeFiles/openglim.dir/imgui/imgui_tables.cpp.o
openglim: CMakeFiles/openglim.dir/imgui/imgui_widgets.cpp.o
openglim: CMakeFiles/openglim.dir/imgui/backends/imgui_impl_glfw.cpp.o
openglim: CMakeFiles/openglim.dir/imgui/backends/imgui_impl_opengl3.cpp.o
openglim: CMakeFiles/openglim.dir/src/linux/glad.c.o
openglim: CMakeFiles/openglim.dir/src/linux/main.cpp.o
openglim: CMakeFiles/openglim.dir/src/linux/xxx.cpp.o
openglim: CMakeFiles/openglim.dir/build.make
openglim: /usr/lib/x86_64-linux-gnu/libglfw.so.3
openglim: /usr/lib/libopencv_gapi.so.4.7.0
openglim: /usr/lib/libopencv_highgui.so.4.7.0
openglim: /usr/lib/libopencv_ml.so.4.7.0
openglim: /usr/lib/libopencv_objdetect.so.4.7.0
openglim: /usr/lib/libopencv_photo.so.4.7.0
openglim: /usr/lib/libopencv_stitching.so.4.7.0
openglim: /usr/lib/libopencv_video.so.4.7.0
openglim: /usr/lib/libopencv_videoio.so.4.7.0
openglim: /usr/lib/libopencv_imgcodecs.so.4.7.0
openglim: /usr/lib/libopencv_dnn.so.4.7.0
openglim: /usr/lib/libopencv_calib3d.so.4.7.0
openglim: /usr/lib/libopencv_features2d.so.4.7.0
openglim: /usr/lib/libopencv_flann.so.4.7.0
openglim: /usr/lib/libopencv_imgproc.so.4.7.0
openglim: /usr/lib/libopencv_core.so.4.7.0
openglim: CMakeFiles/openglim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kali-smily/openglim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable openglim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/openglim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/openglim.dir/build: openglim
.PHONY : CMakeFiles/openglim.dir/build

CMakeFiles/openglim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/openglim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/openglim.dir/clean

CMakeFiles/openglim.dir/depend:
	cd /home/kali-smily/openglim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kali-smily/openglim /home/kali-smily/openglim /home/kali-smily/openglim/build /home/kali-smily/openglim/build /home/kali-smily/openglim/build/CMakeFiles/openglim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/openglim.dir/depend

