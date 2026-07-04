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
