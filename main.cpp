#include <windows.h>
#include <unistd.h>
#include <iostream>

using namespace std;

DWORD GetIdle() //Windows native C++ code for getting idle progress information
{
    LASTINPUTINFO lastII;
    lastII.cbSize = sizeof (lastII);
    GetLastInputInfo(&lastII);

    return (GetTickCount() - lastII.dwTime)/1000;
}

int main()
{
    while (true) //performing endless loop to GetIdle
    {
        cout<<GetIdle()<<" "; //print idle progress information
        Sleep(1000); //loop rest in a second
    }

    return 0;
}
