# 50 Days of Windows API

## INTRODUCTION

WinAPI is Microsoft's native API for developing Windows desktop applications in C and C++. It provides direct access to many operating system features, making it lower level than modern GUI frameworks which give a very strong point.


C++ itself a very Low Level Language and I am actually Just Finished my First Year So its Like My first time to writing a Documentation of My Work , I hope I will write it so Clean so that it will become easier to Understand

Its Just a Series which is I am creating to Learn The WinAPI in 50 Days basic to Intermediate Level

____
**This Course Contain 12 Modules and I will try to Finish this in 50 days with Best Human Friendly Language**
____


#### Here Are the Modules

1. Module 1 - Foundations
2. Module 2 - Window Creation
3. Module 3 - Message System
4. Module 4 - Standard Controls
5. Module 5 - Menus & Dialougs
6. Module 6 - GDI Graphics
7. Module 7 - User Input
8. Module 8 - File System
9. Module 9 - Advanced Controls 
10. Module 10 - Windows Features
11. Module 11 - Multithreading
12. Module 12 - Advanced Win32

.
>*Every Module may consits of 4-6 Days Starting Ones are Short but as we Go Further It will be Longer to Grasp but I will make You Crystals Clear*

.
### Hers is the Official Text About WinAPI from Microsft Website



*The Windows UI API creates and uses windows to display output, prompt for user input, and carry out the other tasks that support interaction with the user. Most applications create at least one window.*


> Windows is message-driven.


Now You Can think What is windows.h and WinAPI difference and it should Be Cleared too
__________________________________________________
#### Difference: WINAPI vs WINDOWS.H

**The Windows API:**(WinAPI) is the core set of functions, data types, and protocols provided by Microsoft for interacting with the Windows operating system

where

**Windows.h:**  It is a C/C++ source file containing all the necessary declarations, macros, and typedefs required by the compiler to understand WinAPI functions
_______
### THE VERY FUNDADAMENTAL PROGRAM LOOKS LIKE

```cpp
int WINAPI WinMain(...)
{
    //Here you will written the Code
    return 0;
}
```

Now this is Only a Instroduction Module So it just an Idea that what we can do by this API but How SetUp please fo to Setup.md File .
>It will Show you , How will you able to use the API Functions in the VS CODE easily :) All the Best!


___
## DAY 1
___
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



- [x] What is WinAPI?
- [x] what is windows.h
- [x] Why Application need the windows API


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

See Ya On Day 2 in Module 2 ;)
___
## DAY 2
___
# Window Structure
___

## The Fundamental Structure of a Win32 Application
___

in a console Application we always used Headerfile in the Top of the Code and then Writes our **int Main()** Functinon
But in this we are not Running the Program in the Console we Want to Go with the *Window Creation Object*.

#### So Our Normal Strucutre

```cpp
#include<files>
//Classes and Object if needed
//Function Declartion

int main(){
    //Code Starts Here::

  /*  The operating system starts your program by calling
   main(), and a console window is available for input 
   and output  */

    return 0;
}
```

___

## Windows GUI application is different.

There is no Default Console!
&
Window also need more Information and Declartion
Like

- Which Application in RUNNING?
- What Command line argument is Passed?
- How should Exactly Firrst Window Appeard?
  
Thats the Reason WinAPI dont use main its used WinMain()

    WinMain()


For the First You Need To Wrote TWO things:-

    LRESULT CALLBACK function()
    and 
    int WINAPI WinMain()

The **LRESULT CALLBACK** function is a Window Procedure Function which is Used to give a Set of Behaviour towards the window like how t draws and How it Shows .

While the **int WINAPI WinMain()** is a Main Function which is going to used the LRESULT CALLBACK function to handle the **Create Window Object**
___

    I Know its looks Scary but its not that tough Just 
    dont Loose Hope ;)
___


The Basic Code of Win main looks Like 
```cpp
#include<windows.h>

LRESULT CALLBACK WindowProcedureFunction(
    HWND hwnd, UINT uMsg ,WPARAM wparam ,LPARAM lparam
){
    //Write here the Procedure beahivour 
    //using switch Case Statements::

    //then in the END
    return DefWindowProc(hwnd,umsg,wparam,lparam);
}

int WINAPI WinMain(
    HINSTANCE hinstance , HISNTANCE hPrevInstance , LPSTR lpCmdLine , int nCmdShow
){

    //You Creatin Objects like Create Window here
    // You resgister the Window Class
    //and you also Calls the Window Procedure Funtion to
    //Give the Beahiviour to my Window ;)

    return 0;
}
```
___
### LETS DISSCUSS THE KEYWORDS HERE

.
**LRESULT CALLBACK Function()**

    See
    LRESULT  -> Return type
    CALLBACK -> Calling convention
    WindowProc -> Function name

- L is used to say 32 bit long interger but it old now its used 64 bits in 64 bits Systems
- RESULT means Return Value
- It Return the Value in according to the Switch Case of whar operation is taken by the windows class which are placed in WinMain()

>But How this Function Understand that What Type of Activity is Just Occured ?

Thats Why we have Some Parameters init :)

    HWND
    UINT
    WPARAM
    LPARAM

**HWND** : Handle - Window 
- Its an Pointer But You cant dereference it ;) Hence opaque
- Its A Unique Identifier which give the Window ID which will used to give the Identification of a Specific Window to The WINDOW API
- HWND is a handle to a window. Internally it's an opaque type. You use it to identify a specific window, but you don't access its internal data directl

**UINT** : Hence UnSigned Int 32 bit
- It tell you What Heppend ? 
- Like which is Created 
- Which is Destoryed
- Which Window Needs Redrawing 

**WPARAM** : Remember the W means Word 
- A 32/64 bit Unsigned Integer
- It Mostly Connected With Keyboard Inputs
- Which word is type 
- Which Number is typed
 
**LPARAM** : Almost same but Secondary
- A 32/64 bit Unsigned Integer
- It Mostly Connected With Mouse Inputs
- Which Coordinates is in Cursor
- It contain Buffer Size too
- It carries additional message-specific information. For mouse messages it often contains the cursor coordinates, but its meaning depends on the message.

___


**int WINAPI WinMain()**

    The Parameters are :
    Hinstance
    hPreInstane (not neccessary in Modern Systems)
    PWSTR
    int CmdShow

**HINSTANCE** : Handle the Insantce 
- It is Used to Define the Window Executable in Memory
- It Also Called Module Handle or Base Address

**hPrevInstance** : It is also a Type of HINSTANCE 
but 
- it Handle the Previous Instance
- Always NULL on Modern Windows
- Historically 16 bit Windows and used to check the program is already runnning or not
- Now Ignore it Completely
- do not Write HINSTANCE hPrevInstance just Simpy leave by Writing the Second Parameter as HINSTANCE
  
**LPSTR** : Long Pointer to STRing (ANSI)

It is a pointer to a null-terminated ANSI character string.
- Contains the command-line arguments passed to the application.
- Does not include the program name.
- In modern Windows applications, Unicode is preferred, so you'll often see `LPWSTR` instead. We'll learn about Unicode in a later module.

**int nCmdShow** : n is for Integer jsut a simply variable name what its place in the function makes it more valueable

- It tells you How the Window Should be Intially Shown 
- its Purpose is RESPECT THE USER'S PREFERNCE like
   - Nomral 
   - Minimized 
   - Maximized

So let Me Show you A basic Code which does not do anything write now cause these are two fundamentals to do everytime within the WinMain then we have to Start Registring the Window Class and Other Stuff which we will do in Day 2

___
```cpp
#include <windows.h>

// Window Procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    //Swtich Case Ladder

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

// Entry Point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    // Define the Window Class
    // Create the Window
    // Show the Window
    // Message Loop

    return 0;
}
```
___


## Here is The FLOW 
    WINDOW PROCEDURE

    HWND - which window?
    UINT - What Happend?
    WPARAN - Extra Info I
    LPARAM - EXTRA Info II

    Then Return LRESULT 


.


    WINDOW ENTRY POINT WinMain

    HINSTANCE - You Program Identity
    hPrevInstance - Always Null (Ignore It)
    PWWSTR - Command Line Arguments
    int nCmdshown - How to Show Window

    Then Return int (Exit Codes if 0 hence Success) 
.
___


Use The Command 
>g++ day_2_code.cpp -o day_2_code.exe -mwindows

and the Run it by 
>./day_2_code.exe

___
>So Lets Meet On Day 3 in Module 2 To Creae a Very First Window in C++ Using WinAPI I already Said that its not going to Rush it will be easy and Understandable :) 

>Just Dont Give UP be Consistent The Hardest things is Easy to Grasp for Individual if it in his Pace!

___
## Day 3
___

# Understanding Window Class
___

You may think thats we still have No window Yet 
the process is like

    Create int WINAPI WinMain()           First
    Create Window Procedure               Second
    Create WNDCLASS                       Third
    Create window Object                  Fourth
    Show Window                           Last!

So First We know to declare the LRESULT CALLBACK Function() but we still
not do the coding Inside today we Create Our First Window 
so 
Lets Disscuss about WNDCLASS

**Defination**
>is a configuration structure that acts as a blueprint or template for creating a window.

Its is a structure Data Type 

Here are The steps 

    WNDCLASS wc_name = {};  //Here We Define 

Then

    wc_name.lpfnWndProc = WindowProceudreFunction;
    wc_name.hInstance = hInstance;
    wc_name.lpszClassName = "My First Window Class";
    wc_name.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

___

### Now What are these

- lpfnWndProc
- hInstance 
- lpszClassName
- hbrBackground

*These are the members inside this struct which you have to define*

#### hbrBackground 

The HBRUSH means Handle to Brush
which is  used to fill the color in the Window

Now What is **COLOR_WINDOW**

This represents a predefined system color used to paint the window background.

    COLOR_BTNFACE      // Button background
    COLOR_MENU         // Menu background
    COLOR_WINDOWTEXT   // Window text color
    COLOR_GRAYTEXT     // Disabled text


## Registering the Window Class

After filling the WNDCLASS structure, we must register it.

RegisterClass(&wc);

This tells Windows:

"Please remember this window class so I can create windows from it later."

Without registering the class, CreateWindowEx() will fail because Windows doesn't know what "MyWindowClass" is.


>In further in GDI module will learn the RGB colors too

Write Just leave it to Default!

___
## Now WINDOW PROCEDURES !
___

Lets Define Our Window Procedure Function to Handle Events
>We have to Use switch Case System to Implement on the Different Cases

Today we are just creating Window So we need the case for destroyig ;)
cause if we are not able to close the window It will be Problamatic

here is the switch case Structure
```cpp
switch(msg){
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
}
```

*Inside the Function Window Procedure*

___
## Creating WINDOW OBJECT
___

Now we have to Create the Object of Window
after Making the Procedures
and the Class 

    HWND hwindow = CreateWindowEx(.....);

Now it has contain Many Perimeters Inside it Do not wrote Just Understand and Implement it 
```cpp
HWND Window_Name = CreateWindowEx(
    0,
    "MyWindowClass",
    "My First Win32 Window",
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    800,
    600,
    NULL,
    NULL,
    hInstance,
    NULL
);

```

**Here are the Information**
- 0 → No extended style.
- "MyWindowClass" → Use the class we registered.
- "My First Win32 Window" → Title bar text.
- WS_OVERLAPPEDWINDOW → Standard window with title bar, border, minimize/maximize buttons.
- CW_USEDEFAULT → Let Windows choose the initial X position.
- CW_USEDEFAULT → Let Windows choose the initial Y position.
- 800 → Width.
- 600 → Height.
- NULL → No parent window.
- NULL → No menu.
- hInstance → This application instance.
- NULL → No extra creation data

___
## Showing the WINDOW!
___

```cpp
ShowWindow(hwnd, nCmdShow);
UpdateWindow(hwnd);
```

### Message Loop and Return 0;

```cpp
MSG msg;

while (GetMessage(&msg, NULL, 0, 0))
{
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
```
The message loop keeps the application alive. It continuously receives messages from Windows and dispatches them to the Window Procedure. Without it, the program would exit immediately after creating the window
.


and in the End !

    return 0;


___
## The Whole Code would be 

```cpp
#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);  //Here we have to 
    //Return the Procedure Functions
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyWindowClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    HWND MyWindow = CreateWindowEx(
        0,
        "MyWindowClass",
        "My First Win32 Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        800,
        600,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    ShowWindow(MyWindow, nCmdShow);
    UpdateWindow(MyWindow);

    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

```

>You can Use L"text" type string these are better to use We will disscuss it in the day 4 with the new module
____

Use The Command 
>g++ day_3_code.cpp -o day_3_code.exe -mwindows

and the Run it by 
>./day_3_code.exe

Now Lets Meet you on Day 4 with the New Module Our Window is now Fully Created . Today we created our first native Win32 window and handled our first message (WM_DESTROY). In the next lesson, we'll explore the Windows message system in much greater detail. Cause our Window is Event Driven ;)


___
___

## DAY 4
___
# The Window Message System
___

Here we will gonna start something interesting which is the Heart of You WinApi native app 
its the *window message system*.

### Imagine Like
you had create you First Window Already!
and then

    You move the mouse
    You presss the key
    you resize the window
    you click the button
    Another Application overlaps with your Window

These are Some events which Your Program should be tackle and Our Window(Operating System) keeps sending these messages to us to understand the Current Situation

#### Q. What is a Message?
Ans : You can say its a Notification sent by the Windows(OS)

Hence Everything will be happening is all in the surrvelliance of our Windows So Windows Sent the Messages or Events Lists which are take place when the program is running 

;) So Remember We are not Creating a Window Actually We are mostly Using it by calling them 
Like
>Hey Lord Window Please Hear my Thoughts and give me a Window and notifications so that I can make happy my Users

You Can Understand by this More Clearly

    User clicks mouse
        ↓
    Windows creates a message
        ↓
    Message goes into the message queue
        ↓
    Your program receives it
        ↓
    Window Procedure handles it

    
___


#### Note from The Tanmay Prakash 

You May think that How I was Learn these things and How am I explaing to You so its off the topic but I am so Beginner too I am just Learn Daily and Explains to Yourself for my Revsion and Makes notes so that I will Use it in Future :) 
And Yes I use ChatGPT to Learn the Functions of WinAPI too there is not Problem The tool is a Very Good Learnign Resource What I am doing is Making More Clear and Human Like So that these Hard Topics become Easier to Digest.
___

Now Remeber We Have a Code Snippet Like of switch Case::

```cpp
switch(operation){
    case THE_CASE_1:{
        //Running Code
    }
    Case THE_CASE_2:{
        //Running Code
    }
    //And So on
}
```

But :) We are talking about WinApi so now our Switch Case will be Changed by using Parameters

```cpp
switch(msg){
    case WM_CASE_1:{
        //Running Code
    }
    Case WM_CASE_2:{
        //Running Code
    }
    //And So on
}
```

That Code will Lie in our Window Procedure Function and we Have Muliple Cases to Handle we know that Our Function takes Parameter linke UINT msg,HWND hwnd,LPARAM lparam,WPARAM wparam these are the Infromations Collecting variables which will give use a value in a Particular Situation 

Here Like WM_Case is done then we will use these 4 parameters to handle Every Event 

Ahhh Its Looks Kind of So Confusing But her is this Our WinApi but Dont Looks Hope its Simple When You get the Intuation First!

### Some Most Popular WM_CASES

>We Have 100 of Cases but I am showing only Few cause they are Basic and Widely Used

 - WM_CREATE : Window is Being Create
 - WM_PAINT : Window  Needs Painting
 - WM_SIZE : Window Size Changed!
 - WM_MOVE : Window Moved!
 - WM_CLOSE : User Clicked the Close Button
 - WM_DESTROY : Window is begin Destroyed
 - WM_KEYDOWN : Keyboard key is pressed
 - WM_KEYUP : Keyboard key is released
 - WM_LBUTTONDOWN : Left Mouse button Pressed
 - WM_MOUSEMOVE : Mouse Moved
  
Okay Now I am tired of Typing I think these are Enough!
there are 100s Search and Use ;)

___

### Theory

First Window Checks that what is the Notification I have to Sent to the Program and these Notification are Goes in **Queue!**

These Meessage was given by the GetMessage Function
```cpp  

while(GetMessage(&MESSAGE_VAR,nullptr,0,0)){
    TranslateMessage(&MESSAGE_VAR);
    DispatchMessage(&MESSAGE_VAR);
}
```


TranslateMessage : This does not send the message to your window,Its job is mainly to help with keyboard input.

DispatchMessage : This take this message and send it to the correct Window Procedure.

> If you don't care about typing text, you could ignore TranslateMessage(), but almost every Win32 program includes it because it's the standard pattern.


___
## Here is the Todays Activity By Using WM_LBUTTONDOWN

We will pop up a Message by this Code

```cpp
case WM_LBUTTONDOWN:
    MessageBoxW(
        hwnd,
        L"You clicked the left mouse button!",
        L"Mouse Event",
        MB_OK
    );
    return 0;
```
Here MessageBoxW is here to Put Wide String 
The Use of MessageBox is Displaying a Message Box where the W means Wide (UNICODE)

Hwnd is the handle of you Window
it tells the window
>Show this Message Box for this Window

In Case of Multiple Windows, Windows know which one owns the Message Box

And this MB_OK : This tells Windows what kind of message box to create 
There are Many Options too But let them leave for tommorow

.
**Here is the Syntax**
```cpp
//Here is the Syntax
MessageBoxW(
    HWND,
    LPCWSTR Text,
    LPCWSTR Caption,
    UINT Type
);
```


Compile this Program by this Command
> g++ day_4_code.cpp -o day_4_code.exe -mwindows

and Run by
>./day_4_code.exe


### SUMMARY

    User Action
      │
      ▼
    Windows
      │
      ▼
    Message Queue
      │
      ▼
    GetMessage()
      │
      ▼
    TranslateMessage()
      │
      ▼
    DispatchMessage()
      │
      ▼
    WindowProc()
      │
      ▼
    Your Code Executes

I hope today Lecture was nice and Interactive and tommorow We will Dive Deeper into this Module Cause its Basic Right Now , For today Just Left Click the Mouse and Be Hapy :) Tommorow is Having More Fun!



___
___

# DAY 5
___

# Message System 
___

We already disscuss the message system Earlier , Now we will disscuss Some more utilities of it 

but till now You have to Answerd these Quesetion

 - What is HWND?
 - What is msg?
 - What is lparam?
 - What is wparam?
  

**Now this is Important**

>wParam and lParam do not always mean the same thing
    Their meaning depends on the message being handled.


___

### Reading Keyboard Input


>WM_KEYDOWN

```cpp
case WM_KEYDOWN:
    if (wParam == 'A') // Here is wparam is your variable created
    {
        MessageBoxW(
            hwnd,
            L"You pressed A!",
            L"Keyboard",
            MB_OK
        );
    }
    return 0;
```

Here wParam is use as a keyboard info

### Read Mouse Coordinates
> WM_MOUSEMOVE

```cpp
int x = (short)LOWORD(lParam);
int y = (short)HIWORD(lParam);
```

So there is Many things that wparam and lparam will give use but its better to give a table So that it become easy


___

Be careful that what are lparam is being used in which WM_CASES cause every has different names

#### TABLE FOR INFORMATION

| MESSAFGE | WPARAM | LPARAM |
|----------|----------|----------|
| WM_KEYDOWN   | Which key is pressed   | Scan Code,repeat Count,key state   |
| WM_KEYUP   | Which key was released   | Key Information   |
| WM_CHAR   | The typed character | repeat count |
| WM_MOUSEMOVE | Which mouse button are held | Mouse x,y coordinates |
| WM_LBUTTONDOWN | Ctrl/Shift Status | Mouse x,y coordinates |
| WM_RBUTTONDOWN | Ctrl/Shift Status | Mouse x,y coordinates |
| WM_MOUSEWHEEL | Wheel Scroll Amount + Modifer Keys | Mouse Postion |
| WM_SIZE | Resize type | new width and height  |
| WM_MOVE | **Not Used** | New X and Y position  |
| WM_COMMAND | Control/Menu ID + Notification Code | Handle of the Control |
| WM_TIMER | Timer ID | Usually 0 |
| WM_HSCROLL | Scroll Code | Scrollbar Handle |
| WM_VSCROLL | Scroll Code | Scrollbar Handle |
| WM_NOTIFY | Control ID | Pointer to a Notification structure |



oday's lesson focused on understanding how WPARAM and LPARAM carry additional information for different Windows messages. The documentation is intentionally concise because the goal was to build intuition before exploring more advanced messages in the next lesson.
___
