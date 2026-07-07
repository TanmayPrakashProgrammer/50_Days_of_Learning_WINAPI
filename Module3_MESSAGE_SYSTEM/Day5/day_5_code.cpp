#include <windows.h>

// Window Procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_LBUTTONDOWN:
        {
            int x = (short)LOWORD(lParam);
            int y = (short)HIWORD(lParam);

            wchar_t buffer[100];

            wsprintfW(
                buffer,
                L"Mouse Clicked!\n\nX = %d\nY = %d",
                x,
                y
            );

            MessageBoxW(
                hwnd,
                buffer,
                L"LPARAM Example",
                MB_OK
            );

            return 0;
        }

        case WM_KEYDOWN:
        {
            wchar_t buffer[100];

            wsprintfW(
                buffer,
                L"Virtual Key Code = %u",
                (UINT)wParam
            );

            MessageBoxW(
                hwnd,
                buffer,
                L"WPARAM Example",
                MB_OK
            );

            return 0;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

// Entry Point
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
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
        0,
        L"MyWindowClass",
        L"Day 5 - WPARAM and LPARAM",
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

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;

    while (GetMessageW(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}