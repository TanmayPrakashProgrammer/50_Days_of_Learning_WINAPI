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