# STANDARD CONTROLS
___

Till Now we now How to handle inputs and ouput in this Sections we will gonnar learn about a More Important GUI Elements like the **"Building of a Form"**

This will be very intersting and it feels like we finally creating a Real World Basic Mechanism 

___
In Short 

**Our Goal:**
>Learn how to create and interact with the built-in controls provided by the Win32 API, including buttons, edit boxes, static text, check boxes, radio buttons, combo boxes, and list boxes. By the end of this module, you'll be able to build interactive desktop application interfaces without custom graphics.

.

___

#### Q. What is Standard Controls

Imagine you have a Notepad
You would see Menu Bar and Text Area 

or

Imagine you have a Calculator
it has buttons and display

or
A google Form contians
Username Text Box and Password Text Box

These are teh standard Controls 

#### FACT :)
___
Every Standard Controls is actually a Window too

cause these all have their *HWND*

The Main Window is a Parent Window
The Controls are the Child Windows

    Parent Window
    │
    ├── Button
    ├── Edit Box
    ├── Static Text
    ├── Check Box
    └── Radio Button

___

#### Creating Controls

We use the same function that created our main window:

```cpp
CreateWindowExW(...);
```

The Only thing will change is teh CLASS NAME

>For Example:

| Control | Class Name |
|----------|------------|
| Button | `L"BUTTON"` |
| Edit Box | `L"EDIT"` |
| Label (Static Text) | `L"STATIC"` |
| List Box | `L"LISTBOX"` |
| Combo Box | `L"COMBOBOX"` |

___

Whenever We Use L"BUTTON"

windows Replies
>Go It! I"ll Create a standard push button
___

#### Parent vs Child Window

When we create Our Main Window its paret was **nullptr**

But a Button is different 
its parent window is hwnd

Also Every Control has an ID
Suppose 
Our Application has 

 - LOGIN
 - CANCEL
 - REGISTER

if you click one of them...
How does Windows know which button was clicked?
Each control gets a unique integer ID.

**Here is the Code**

```cpp
#define ID_LOGIN     101
#define ID_CANCEL    102
#define ID_REGISTER  103
```
___


>Here is teh Command We have to use cause we are performing the UniCode 

>g++ day_6_code.cpp -o day_6_code.exe -mwindows -municode

>./day_6_code.exe


>Later, you'll use these IDs inside WM_COMMAND to determine which control generated the message.
For Today this Will Gonna Work but Next the Day 7 We Will learn the remaing Part to make a First User Login Form 

___