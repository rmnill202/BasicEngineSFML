# Basic Engine (SFML)

What Is This?
-------------------
 A very simple application/game engine written in C++, using the Simple and Fast Multimedia Library (SFML) 
  framework. More info on SFML is available here: http://www.sfml-dev.org/. The engine was written as a way
  to familiarize myself with C++, Github and SFML. 
 
Installation
-------------------
 If you aren't already familiar with SFML, I'd suggest taking a glance at http://www.sfml-dev.org/tutorials/2.4/
  You can find various guides regarding specific modules, as well as a variety of guides for installation. I 
  use the Visual Sudio 2015 version and have been compiling the project as x64 release on Windows 7. 
  
Basic Use
-------------------
Once you have SFML imported into a new project and have dropped the engine files in, you're ready to start!

1. To create a simple application, include the Engine.h file, create a new Engine object and call the run() 
 function from the object. 
2. From this point, you are free to create your own application states using the abstract State class. The
 StateManager and Engine files provide comments to guide you through how you should implement your own states.
 A more in-depth guide will be provided with documentation soon.
