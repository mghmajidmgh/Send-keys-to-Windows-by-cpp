#define WINVER 0x0500
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

//compile with below command:
//g++.exe --std c++17 -fdiagnostics-color=always -static-libgcc -static-libstdc++ -L. -lwinpthread -llibwinpthread  main.cpp -g -o main.exe -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive

void setInput(INPUT * inp,unsigned int index, WORD keycode,BOOL kUp)
{
    inp[index].type = INPUT_KEYBOARD;
    inp[index].ki.wVk = keycode;
    inp[index].ki.wScan = MapVirtualKey(keycode, 0);
    inp[index].ki.time = 0;
    inp[index].ki.dwExtraInfo = 0;

    if (kUp == 1)
    {
        inp[index].ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_EXTENDEDKEY;
    }else
    {
        inp[index].ki.dwFlags =  0 | KEYEVENTF_EXTENDEDKEY;
    }
}

 
 void pressKey( WORD keycode)
{
   INPUT *inp = (INPUT*) malloc(sizeof(INPUT) * 2);
    memset(inp,0,sizeof(INPUT));

    setInput(inp,0,keycode,0);
    setInput(inp,1,keycode,1);

    SendInput(2,inp,sizeof(INPUT));

    free(inp);
}

 
int main(int argc, char const *argv[])
{ 
     while (true)
     {
        pressKey(VK_NUMLOCK);        

        time_t my_time = time(NULL);  
        std::cout<<"key pressed "<<std::endl;
        
        Sleep(60000);
     }
}     