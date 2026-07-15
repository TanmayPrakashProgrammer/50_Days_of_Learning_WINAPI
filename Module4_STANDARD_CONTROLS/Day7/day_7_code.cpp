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