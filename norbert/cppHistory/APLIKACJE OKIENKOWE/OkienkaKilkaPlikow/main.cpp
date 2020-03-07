#include <windows.h>
#include "MainWindow.h"

int WINAPI WinMain (HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
    MSG message;
    MainWindow *mainWindow = new MainWindow(hInst);
    if(!mainWindow->Run(nCmdShow))
    {
        delete mainWindow;
        return 1;
    }
    while(GetMessage(&message, NULL, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
    delete mainWindow;
    return message.wParam;
}
