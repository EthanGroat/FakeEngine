# FakeEngine

This is my 3D game engine to be. I'm fooling around with graphics APIs in the 
hopes of making an engine in the hopes of making some fun little things out of 
it. I hope to make it cross-platform, but for the moment, I will be developing 
on and testing for Linux.

## The project roadmap:

* Build a damn renderer

    * OpenGL vs Vulkan: I want it to be performant but also want to get started 
      quickly. Not sure here. Will try OpenGL first and maybe add Vulkan later.
      This may require refactoring into an abstraction. 

* Build a damn object association framework

    * Objects will all have a transform attribute (or assumed transform of 0)

    * Objects can include containers, obj models, sprites, light sources, 
      C++ scripts, Python scripts, etc.

* Write a damn API for objects in the tree to interact with each other

    * Kinematics can be applied to objects by use of (my own) kinematics C++ 
      script/library which gets applied to all kinematic objects

        * Parameters on the kinematic script component specify physical 
          attributes

Once that's all done, then the whole damn thing might work! I actually only 
need some rudimentary working version of these three things to begin with, and 
then I can proceed to iterate through better and better versions of a working 
game engine. Sort of a one-man agile methodology.

## Compiling and running:

The engine is compiled as a shared library that in turn depends on other 
libraries. When compiling the sandbox environment, these libraries are 
automatically generated and stored in a subdirectory in the binaries directory, 
so compiling the sandbox is the easiest way to get up and running.
The preferred path for binaries is `bin` or `sandbox/bin`.

The following terminal instructions assume starting from the project directory.

### Quickstart (compile the sandbox (and engine) for the first time and run it):
```bash
cmake -S sandbox -B bin  # or sandbox/bin
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

To instead compile only a specific component (like just the engine without the 
sandbox), substitute the source to that component after the `-S` flag in the 
instructions above, and ensure the binary path (`-B` option). Is to your liking.
