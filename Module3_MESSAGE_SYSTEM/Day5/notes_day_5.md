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
