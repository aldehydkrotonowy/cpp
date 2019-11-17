#include <windows.h>
const char g_szClassName[] = "MyWindowClass";
//Windows Procedure
LRESULT CALLBACK WndProc (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
        {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc (hwnd, msg, wParam, lParam);
        }
        return 0;
}
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Registering
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Faild!", "Error!", MB_ICONEXCLAMATION|MB_OK);
        return 0;
    }
    //Create Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "The title of my window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
        NULL, NULL, hInstance, NULL);
    if(hwnd==NULL)
    {
        MessageBox(NULL, "Window Creation Faild", "ERROR!", MB_ICONEXCLAMATION|MB_OK);
        return 0;
    }
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    //Loop message
    //GetMessage() gets a message from your application's message queue.
    while(GetMessage(&Msg, NULL, 0, 0)>0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    /*When either GetMessage and PeekMessage see a WM_QUIT message,
     they will return zero, and you can check for the exit code in
     the WPARAM part of the LPMSG parameter.*/
    return Msg.wParam;
}
