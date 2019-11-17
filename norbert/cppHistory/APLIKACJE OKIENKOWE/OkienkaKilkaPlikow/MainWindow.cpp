#include<windows.h>
#include "MainWindow.h"
#include "resource.h"
//----------------------------------------------------------------------------------------
char MainWindow::m_szClassName[] = "Wieloplikowiec";

//----------------------------------------------------------------------------------------
MainWindow::MainWindow(HINSTANCE hInstance)//konstruktor
{
    m_hInstance = hInstance;
    m_wndClass.cbSize = sizeof(WNDCLASSEX);
    m_wndClass.style = CS_DBLCLKS;
    m_wndClass.lpfnWndProc = MainWindowProc;//pointer to callback procedure
    m_wndClass.lpszMenuName  = MAKEINTRESOURCE(IDR_MYMENU);
    m_wndClass.cbClsExtra = 0;
    m_wndClass.cbWndExtra = 0;
    m_wndClass.hInstance = hInstance;
    m_wndClass.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON));
    m_wndClass.hCursor =LoadCursor(NULL, IDC_ARROW);
    m_wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    m_wndClass.lpszClassName = m_szClassName;
    m_wndClass.hIconSm = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON), IMAGE_ICON, 16, 16, 0);
}
MainWindow::~MainWindow()
{

}
//----------------------------------------------------------------------------------------
LRESULT CALLBACK MainWindow::MainWindowProc(HWND hwnd, UINT msg, WPARAM wPa, LPARAM lPa)
{
    switch(msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wPa, lPa);
    }
    return 0;
}
//----------------------------------------------------------------------------------------
bool MainWindow::Run(int nCmdShow)
{
    if(!RegisterClassEx(&m_wndClass))
        return false;
    m_hwnd = CreateWindowEx(
                0,
                m_szClassName,
                "Wieloplikowiec",
                WS_OVERLAPPEDWINDOW,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                500,
                400,
                NULL,
                NULL,
                m_hInstance,
                NULL
                );
    if(!m_hwnd)
        return false;
    ShowWindow(m_hwnd, nCmdShow);
    return true;
}
