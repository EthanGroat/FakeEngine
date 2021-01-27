# FakeLara Engine

This is my 3D game engine to be. I'm fooling around with graphics APIs in the 
hopes of making an engine in the hopes of making some fun little things out of 
it. I hope to make it cross-platform, but for the moment, it will be for Linux.

### The project roadmap:

* Build a damn renderer

    * OpenGL vs Vulkan: I want it to be performant but also want to get started 
      quickly. Not sure here. Will try OpenGL first and maybe add Vulkan later.
      This may require refactoring into an abstraction. 

* Build a damn object association framework

    * Objects will all have a transform attribute (or assumed tranform of 0)

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
