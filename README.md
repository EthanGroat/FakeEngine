# FakeEngine

This is my 3D game engine from scratch! I'm fooling around with C++ in the
hopes of making an engine in the hopes of making some fun games out of it. 
I intend to make it cross-platform eventually, and portability is ingrained 
into my decisions for this project, but for the moment, this is a Linux-first 
project and I will only be developing on and testing for Linux until a later 
date when I can be bothered to make sure it compiles on other OSs.

Speaking of portability, assuming I didn't miss anything, all dependencies of 
FakeEngine are included in the source code. You just need up-to-date versions 
of CMake, Make, and a C++ compiler to make it happen. No pun intended.


## The project roadmap:

* |DONE| Set up project with build system, git, license, gl loaders and all

* |Done| Custom logger

* |Done| Custom generic list data structures

* |Done| Event message system

* Handle keys (generate keypressed events every frame via a generic 
  get_input() method which calls a get_keys_pressed() method)

* Build a damn renderer

    * OpenGL vs Vulkan: I want it to be performant but also want to get started 
      quickly. Not sure here. Will try OpenGL first and maybe add Vulkan later.
      This may require refactoring into an abstraction. Further 
      consideration required.

* Build a damn component system framework

    * Components will all have a transform attribute 
      (or assumed transform of 0)

    * Components can include containers, obj models, sprites, light sources, 
      C++ scripts, Python scripts (eventually), etc.

        * Kinematics can be applied to things by use of a KinematicComponent 
          C++ class which gets applied to all kinematic objects, and 
          Parameters on the KinematicComponent specify physical attributes
    
    * Components will talk to each other through the event system but also have 
      some things which bypass the generation of events (like local world 
      transform updates of a component when its containing component's 
      transform is updated?); must decide on the detail of this

Once that's all done, then the whole damn thing might work! I actually only 
need some rudimentary working version of these three things to begin with, and 
then I can proceed to iterate through better and better versions of a working 
game engine. Sort of a one-man agile methodology.


## Compiling and running:

The engine is compiled as a shared library that in turn depends on other 
libraries. The sandbox already has FakeEngine set up as a dependency with 
CMake, so when compiling the sandbox environment, these libraries are 
automatically generated and stored in a subdirectory of the binaries folder, 
so compiling the sandbox is the easiest way to get up and running.
The preferred path for binaries is `bin`.

The following terminal instructions assume starting from the project 
directory.

### Quickstart (compile the sandbox for the first time and run it):
```bash
cmake -S sandbox -B bin
cd bin
make
./Sandbox  # or just click on it from the newly generated bin folder.
```

### Subsequent compilations can usually be done with just make:
```bash
cd bin
make
```
or simply
```bash
make -C bin
```

### To run the sandbox from terminal (assuming it's already compiled):
```bash
cd bin
./Sandbox
```

### To recompile and rerun in one command:
```bash
cd bin
make && ./Sandbox
```

The Sandbox serves as an example starting point to develop an app with 
FakeEngine. Feel free to edit its code and play around in it, but if you 
want you may create an entirely new directory, following the sandbox 
directory and all the files within as a template.


## Notes on Development Setup

Here are some additional notes for getting started programming your games with 
FakeEngine, as well as tweaking or extending the FakeEngine code yourself.

### Precompiled headers:

All external standard libraries the engine uses are put into a precompiled 
header file. To ensure your IDE intellisense parses that, include the 
ExternalLibraries.h file in your intellisense settings.

In Visual Studio code, you would simply put 
```json
"forcedInclude": ["${workspaceFolder}/src/ExternalLibraries.h"]
```
into .vscode/c_cpp_properties.json under `"configurations"`.

Be sure to use this precompiled header in your games via 
`target_precompile_headers` in your CMakeLists.txt just like in the Sandbox; 
or you may simply uncomment the `#include "ExternalLibraries.h"` at the top of 
FakeEngine.h to have the compiler simply include the header the old fashioned 
way when you include that file. 
(I might choose later to make this the default to simplify development setup).

### Memory leaks:

I use valgrind to check for memory mismanagement. Just run
`valgrind --leak-check=full ./Sandbox` from bin and you're good to go.

Of note: valgrind detects memory leaks in the libX11 code itself:
```
==18749== 408 bytes in 1 blocks are definitely lost in loss record 2,180 of 2,213
==18749==    at 0x4840B65: calloc (vg_replace_malloc.c:760)
==18749==    by 0x58EE52C: _XimOpenIM (in /usr/lib/libX11.so.6.4.0)
```
This might be an error in the X11 libraries, or it may be intended behavior, 
but either way not an issue with my code. So no leaks so far, yay!

