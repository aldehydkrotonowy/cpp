#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED



#include<windows.h>
/*a non-const static member variable that is declared in a class definition
must be defined outside of the class definition, in exactly one translation unit.
The same applies to const static member variables, with the exception that such
variables of integer type can be defined in the class definition by initialising
them to a constant there.*/
static HINSTANCE m_hInstance;
class MainWindow
{
public:
    MainWindow(HINSTANCE hInstance);
    ~MainWindow();
    static LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    bool Run(int nCmdShow);

private:
    WNDCLASSEX m_wndClass;
    HWND m_hwnd;
    static char m_szClassName[];
};

#endif // MAINWINDOW_H_INCLUDED
