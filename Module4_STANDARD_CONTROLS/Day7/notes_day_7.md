# Handling Buttons
___

Today's Goal
 - WM_COMMAND
 - LOWORD(wParam)
 - Control IDs
 - Showing a MessageBox
 - How windows tells us which control is clicked
  

#### Theory

```cpp
CreateWindowExW(
    ...
    (HMENU)ID_BUTTON,
    ...
)
```
There is a Question How we Know that which button is clicked

Your Answer is

    WM_COMMAND

Whenever a standard control notify some activity to your program, Windows Send WM_COMMAND to your window procedure

#### FLOW
    User Clicks Button
        │
        ▼
    Windows Creates WM_COMMAND
        │
        ▼
    wParam contains Control ID
        │
        ▼
    Window Procedure
        │
        ▼
    Your Code Runs

#### UNDERSTANDING wParam

we have two types of infromtaion 
 - Low Word
 - High Word
  
LOWORD(wParam) gives you the Button ID integer


##### Here is the Code Snippet

```cpp
switch(LOWORD(wParam)){
    case ID_BUTTON:
    //do something 
    break;
}
```

____


### BUTTON CREATION RECAP

This is the method to create a button on his parent window

```cpp
CreateWindowExW(
    0,
    L"BUTTON",   //Button Class
    L"Click Me",
    WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
    50,
    50,
    150,
    40,
    hwnd,               // ← Parent Window
    (HMENU)ID_BUTTON,
    hInstance,
    nullptr
);

```

**WS CHILD** - a child window must have a parent. Passing nullptr here would cause the button creation to fail.


Here is the today lecture Now ujust run this code

```cpp

#include <windows.h>

#define ID_BUTTON 101

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_COMMAND:
        {
            switch(LOWORD(wParam))
            {
                case ID_BUTTON:

                    MessageBoxW(
                        hwnd,
                        L"Button Clicked!",
                        L"Success",
                        MB_OK | MB_ICONINFORMATION
                    );

                    return 0;
            }

            break;
        }

        case WM_DESTROY:

            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProcW(hwnd,msg,wParam,lParam);
}

int WINAPI wWinMain(
    HINSTANCE hInstance,
    HINSTANCE,
    PWSTR,
    int nCmdShow
)
{
    WNDCLASSW wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"MyWindowClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);

    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
        0,
        L"MyWindowClass",
        L"Day 7 - WM_COMMAND",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        800,
        600,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );

    CreateWindowExW(
        0,
        L"BUTTON",
        L"Click Me",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        50,
        50,
        150,
        40,
        hwnd,
        (HMENU)ID_BUTTON,
        hInstance,
        nullptr
    );

    ShowWindow(hwnd,nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;

    while(GetMessageW(&msg,nullptr,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}

```


>Here is teh Command We have to use cause we are performing the UniCode 

>g++ day_7_code.cpp -o day_7_code.exe -mwindows -municode

>./day_7_code.exe


Let me See you on the Day 8 with More detail about this module its definatley a bigger one 