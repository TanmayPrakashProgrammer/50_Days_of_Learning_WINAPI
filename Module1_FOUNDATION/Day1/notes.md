# What is the Windows API?
____
The Windows API (WinAPI) is Microsoft's native programming interface for Windows

    Here are the Feautres of it

1. Create windows
2. Display buttons
3. Read keyboard input
4. Handle mouse events
5. Create menus
6. Open files
7. Draw graphics
8. Use timers
9. Create threads
10. Access the clipboard

**And So Much More its just an Overview**
___

So We can use ShowWindow(); to SHOW the Windows 

But how Does your Program that How should I show the Window you First need to give a Set of Instrction 

>This is the Core Idea of Win API

## Is WinAPI a library?

May be Not Exactly...

    it's more accurate to think of it as a set of APIs provided by Windows.
But the Declaration will be done by
```
#include <windows.h>
```
But We have an another Question why its Fast!?

## Why is WinAPI fast?
Because it communicates directly with Windows using native system calls and libraries.

Frameworks like Qt, wxWidgets, or other GUI toolkits often build on top of the Windows API, adding extra layers of abstraction.

Win32 gives you more direct control.

## What can we build?

We can Build Many Things Such as

    Text editors
    Paint programs
    File explorers
    Media players
    Calculator apps
    Desktop utilities
    System tools
    Launchers
    Many traditional Windows desktop applications

So for Today We Learn 



- [x] Day 1 – What is WinAPI?
- [x] Day 2 – what is windows.h
- [x] Day 3 – Why Application need the windows API


Now From Next We create a Simple Code to Make the Hello World Ritual but We do the Introduction Here So I will make a Simple C++ hello World should do to Understand the Basics

```cpp
#include <iostream>
#include <cstdlib>

int main(){
    //Main Function Runs
    std::cout<<"Hello World";

    return EXIT_SUCCESS;
}
```



Use The Command 
>g++ day_1_code.cpp -o day_1_code.exe

and the Run it by 
>./day_1_code.exe

    And Revise the Basics C++ for Tommororw We 
    will Next do the Very Fundamental Structure
    of WinAPI window Tranformation

    Dont Scared that If my C++ is week So I
    would Not do this I would Say if you Learn
    the Basics You still be able to learn Just
    keep consistent but if You already know
    the Basics so its So Easy for You too

See Ya On Day 2 in Module 1 ;)