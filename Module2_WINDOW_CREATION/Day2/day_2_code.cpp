#include<windows.h>

LRESULT CALLBACK WindowProcedureFunction(
    HWND hwnd, UINT uMsg ,WPARAM wparam ,LPARAM lparam
){
    //Write here the Procedure beahivour 
    //using switch Case Statements::

    //then in the END
    return DefWindowProc(hwnd,uMsg, wparam,lparam);
}

int WINAPI WinMain(
    HINSTANCE hinstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine , int nCmdShow
){

    //You Creatin Objects like Create Window here
    // You resgister the Window Class
    //and you also Calls the Window Procedure Funtion to
    //Give the Beahiviour to my Window ;)

    return 0;
}

//Don Not Run this code it will give errors cause its structure not the Complete Runnable code 