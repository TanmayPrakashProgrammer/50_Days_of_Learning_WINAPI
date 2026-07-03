# Setup Guide

## 🎯 Objective

This Guide Will show you How will you use the WinAPI features in your Local Devices . So we cannot do anything without any SetUp cause we have to prepare an Environment to Writea a Code and Run the Code.

---

## Required

- Windows 10 or Windows 11
- WinLibs (MinGW-w64 GCC)
- Visual Studio Code
- Git
- GitHub Account

## Optional

- Visual Studio 2022
- CMake

>Here are the Requirenments for The SetUp they are not too Much but I will Prefer that You atleast should Have the **VS CODE** and **Mingw Compiler by WindLibs**
---


If you want to use Visual studio

# Installing Visual Studio

Download the latest version of Visual Studio Community from Microsoft's official website.

During installation, select:

- ✅ Desktop development with C++

This workload installs:

- MSVC Compiler
- Windows SDK
- CMake Tools
- Debugger

---
> Simply we do the Simple winlibs C++ its easy to do and though out the course I will in GCC/G++ compiler you can set up the stuff of Visual studio if you want they both are correct But I am doing to make things Simple
# Verify the Installation

Create a new C++ project.

Compile and run:
then
1. Setupt the Environment Variables as you have saw in many videos 
2. Run the file using g++ File_Name.cpp
3. then run the file ./a.exe 
4. Write the Code Given Down Below
   

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello World!";
}
```

If it runs successfully, your compiler is working correctly.

---

# Creating a Win32 Project

1. Open Visual Studio.
2. Create a new project.
3. Select **Windows Desktop Application**.
4. Choose C++.
5. Create the project.

---

# Folder Structure

Each lesson in this repository follows this structure:

DayXX/

- README.md
- main.cpp
- Output.png

---

# Recommended VS Code Extensions

If you plan to edit the documentation, install:

- Markdown All in One
- Markdown Preview Enhanced
- Prettier

---

# Next Step

After completing the setup, continue with **Module 1 → Day 1 - Hello Window**.


Now For Evey time You want to Run The Program 
You Command should be

>g++ SourceCode.cpp -o YourAppName.exe -mwindows

but If its not Work
then Try

>g++ full/path/SourceCode.cpp -o full/path/YourAppName.exe -mwindows

then to run

>.\YourAppName.exe

lets Rock in Module 1 ;-)