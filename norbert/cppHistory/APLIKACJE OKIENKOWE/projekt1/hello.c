#include <windows.h>
#include "resources.h"

#pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"") 
#pragma comment(linker, "/SUBSYSTEM:WINDOWS")
const char g_szClassName[] = "myWindowClass";

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
		case WM_LBUTTONDOWN:
		{
			char szFileName[MAX_PATH];			
			HINSTANCE hInstance = GetModuleHandle(NULL);
			//HMODULE  - hInstance - Uchwyt do załadowanego modułu, którego chcemy odczytać ścieżkę. Jeśli wartość tego argumentu zostanie ustawiona na NULL to funkcja zwróci ścieżkę do pliku wykonywalnego aktualnego procesu.
			//LPTSTR  - szFileName - Wskaźnik na bufor do którego zostanie zapisana ścieżka.
			//DWORD  - Rozmiar bufora wyrażony w liczbie znaków (TCHAR).
			GetModuleFileName(hInstance, szFileName, MAX_PATH);
			MessageBox(hwnd, szFileName, "This program is:", MB_OK | MB_ICONEXCLAMATION);
		}
		break;
      case WM_CLOSE:
         DestroyWindow(hwnd);
			break;
      case WM_DESTROY:
          PostQuitMessage(0);
			break;
      default:
         return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Step 1: Registering the Window Class
	 //The size of the structure.
    wc.cbSize        = sizeof(WNDCLASSEX);
	 //Class Styles (CS_*), not to be confused with Window Styles (WS_*) This can usually be set to 0.
    wc.style         = 0;
	 //Pointer to the window procedure for this window class.
    wc.lpfnWndProc   = WndProc;
	 //Amount of extra data allocated for this class in memory. Usually 0.
    wc.cbClsExtra    = 0;
	 //Amount of extra data allocated in memory per window of this type. Usually 0.
    wc.cbWndExtra    = 0;
	 //Handle to application instance (that we got in the first parameter of WinMain()).
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON_ID));
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	 //Name of a menu resource to use for the windows with this class.
    wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MYMENU);
	 //Name to identify the class with.
    wc.lpszClassName = g_szClassName;
	 //small (usually 16x16) icon to show in the taskbar and in the top left corner of the window.
    wc.hIconSm       = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON_ID));

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "The title of my window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Step 3: The Message Loop
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}