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
