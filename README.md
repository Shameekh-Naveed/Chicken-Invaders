
Copy of the popular game called Chicken Invader

![alt text](https://github.com/Shameekh-Naveed/Chicken-Invaders/blob/main/Screenshot%20(6).png)
![alt text](https://github.com/Shameekh-Naveed/Chicken-Invaders/blob/main/Screenshot%20(7).png)

<h3>Images of Gameplay</h3>


<h1>Requirements</h1>
<h3>Must Have (dependencies)</h3>

    SFML 2.4.1 or above - http://www.sfml-dev.org/


<h3>Windows</h3>

    Vist www.sfml-dev.org and download the lastest version of the library.
    In project settings,

    Add the </path/to/sfml/>/include to your c++ include path.
    Then add </path/to/sfml/>/lib to the linker extra library path.

    GameMenu library : Link : https://github.com/ParadoxZero/GameMenu-cpp



Building from source
 <h3> First Method </h3>

    Download the source code.

    Import into Visual Studio

    Build according to your need (x64 or x86 or whatever)

    Don't forget to link the sfml libraries - graphics, window and system.
    put the following files in linker input:
     sfml-system-d.lib, sfml-window-d.lib, sfml-graphics-d.lib and GameMenu.lib

    Copy the sfml dlls (window, graphics and system) along with the executable

    Then Run and enjoy

 <h3>Second Method Makefile </h3>

(Build will work, but the application is untested)

    Download source code
    cd to directory eg

 $ cd sfml-snake

    Run make

 $ make

    the exectable bin/game should apear. The directory will be created if doesn't exist.
    Run and enjoy
