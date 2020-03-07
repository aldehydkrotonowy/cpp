#include <windows.h>
#ifndef _WIN32_IE
#define _WIN32_IE 0x0500
#endif
#include <commctrl.h>
#include "res.h"



const char g_szClassName[] = "myWindowClass";
HWND g_hToolbar = NULL;
BOOL CALLBACK ToolbarDlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
	switch(message)
	{
			case WM_COMMAND:
				switch(LOWORD(wParam))
				{
					case ID_BUTTON_PRESS:
						MessageBox(hwnd, "Hi!", "This is a message", MB_OK | MB_ICONEXCLAMATION);
					break;
					case ID_BUTTON_OTHER:
						MessageBox(hwnd, "Bye!", "This is also a message", MB_OK | MB_ICONEXCLAMATION);
					break;
				}
				break;
				default:
					return FALSE;
	}
	return TRUE;
}
BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		case WM_INITDIALOG:
		return TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case IDOK:
					EndDialog(hwnd, IDOK);
				break;
				case IDCANCEL:
					EndDialog(hwnd, IDCANCEL);
				break;
			}
		break;
		default:
			return FALSE;
	}
	return TRUE;
}
// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
		case WM_CREATE:
		{
			//Top Menu creation
			HMENU hMenu, hSubMenu;
			HICON hIcon, hIconSm;
			hMenu = CreateMenu();
			hSubMenu = CreatePopupMenu();
			AppendMenu(hSubMenu, MF_STRING, ID_FILE_EXIT, "E&xit");
			AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&File");
			hSubMenu = CreatePopupMenu();
			AppendMenu(hSubMenu, MF_STRING, ID_STUFF_GO, "&Go");
			AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&Stuff");
			hSubMenu = CreatePopupMenu();
			AppendMenu(hSubMenu, MF_STRING, ID_HELP_ABOUT, "&About");
			AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&Help");
			//menu DIALOG (SHOW and HIDE)
			hSubMenu = CreatePopupMenu();
			AppendMenu(hSubMenu, MF_STRING, ID_DIALOG_SHOW, "&SHOW");
			AppendMenu(hSubMenu, MF_STRING, ID_DIALOG_HIDE, "&HIDE");
			AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&Dialog");
			SetMenu(hwnd, hMenu);
			hIcon = LoadImage(NULL, "icon.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
			if(hIcon){
				SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
			}else{
				MessageBox(hwnd, "could not load icon!", "Error", MB_OK | MB_ICONERROR);
			}
			hIconSm = LoadImage(NULL, "icon.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE);
			if(hIconSm){
				SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIconSm);
			}else{
				MessageBox(hwnd, "could not load the icon!", "Error", MB_OK | MB_ICONERROR);
			}			
			//Toolbar
			g_hToolbar = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_TOOLBAR), hwnd, ToolbarDlgProc);
			if(g_hToolbar!=NULL){
				ShowWindow(g_hToolbar, SW_HIDE);
			}else{
				MessageBox(hwnd, "g_hToolbar: CreateDialog return NULL", "Warning!", MB_OK | MB_ICONINFORMATION );
			}
			//creating edit window
			HWND hEdit;
			HFONT hfDefault;
			hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", 
            WS_CHILD | WS_BORDER | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 
            0, 0, 300, 300, hwnd, (HMENU)IDC_MAIN_EDIT, GetModuleHandle(NULL), NULL);
        if(hEdit == NULL)
            MessageBox(hwnd, "Could not create edit box.", "Error", MB_OK | MB_ICONERROR);
			//hfDefault = GetStockObject(DEFAULT_GUI_FONT);
			SendMessage(hEdit, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(FALSE, 0));
			//createButton
			HWND hButtonSomething;
			hButtonSomething = CreateWindowEx(0, "BUTTON", "Click me now",
				WS_CHILD|WS_BORDER|WS_VISIBLE,
				310, 10, 360, 60, hwnd, (HMENU)IDC_BUTTON_SOMETHING, GetModuleHandle(NULL), NULL);
			if(hButtonSomething == NULL)
				MessageBox(hwnd, "Could not create Button.", "Error", MB_OK | MB_ICONERROR);
			
			
		}
		break;
		case WM_SIZE:
		{
			HWND hEdit;
			//create RECT structure
			RECT rcClient;
			//fill in this rect with data
			GetClientRect(hwnd, &rcClient);
			hEdit = GetDlgItem(hwnd, IDC_MAIN_EDIT);
			//move and size window
			SetWindowPos(hEdit, NULL, 0, 0, rcClient.right*0.3, rcClient.bottom*0.3, SWP_NOZORDER);
			//resizing IDC_BUTTON_SOMETHING
			HWND hButtonSomething;
			hButtonSomething = GetDlgItem(hwnd, IDC_BUTTON_SOMETHING);
			SetWindowPos(hButtonSomething, NULL, 310, 10, rcClient.right*0.2, rcClient.bottom*0.1, SWP_NOZORDER);
			
		}
		break;
		case WM_COMMAND:
		{
			//lower word of wParam contains menu id
			switch(LOWORD(wParam))
			{
				case ID_HELP_ABOUT:
				{
					int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_ABOUT), hwnd, AboutDlgProc);
					if(ret == IDOK){
						MessageBox(hwnd, "Dialog exited with IDOK.", "Notice", MB_OK | MB_ICONINFORMATION );
					}
					else if(ret == IDCANCEL){
						MessageBox(hwnd, "Dialog exited with IDCANCEL.", "Notice", MB_OK | MB_ICONINFORMATION );
					}else if(ret == -1){
						MessageBox(hwnd, "Dialog feiled!", "Error", MB_OK | MB_ICONINFORMATION );
					}
				}break;				
				case ID_FILE_EXIT:
					PostMessage(hwnd, WM_CLOSE, 0, 0);
				break;
				case ID_STUFF_GO:
				break;
				case ID_DIALOG_SHOW:
					ShowWindow(g_hToolbar, SW_SHOW);
				break;
				case ID_DIALOG_HIDE:
					ShowWindow(g_hToolbar, SW_HIDE);
				break;
			}				
		}
		break;
		/*case WM_RBUTTONDOWN:
		{
			char szFileName[MAX_PATH];			
			HINSTANCE hInstance = GetModuleHandle(NULL);
			//HMODULE  - hInstance - Uchwyt do załadowanego modułu, którego chcemy odczytać ścieżkę. Jeśli wartość tego argumentu zostanie ustawiona na NULL to funkcja zwróci ścieżkę do pliku wykonywalnego aktualnego procesu.
			//LPTSTR  - szFileName - Wskaźnik na bufor do którego zostanie zapisana ścieżka.
			//DWORD  - Rozmiar bufora wyrażony w liczbie znaków (TCHAR).
			GetModuleFileName(hInstance, szFileName, MAX_PATH);
			MessageBox(hwnd, szFileName, "This program is:", MB_OK | MB_ICONEXCLAMATION);
		}
		break;*/
      case WM_CLOSE:
         DestroyWindow(hwnd);
			break;
      case WM_DESTROY:
			DestroyWindow(g_hToolbar);
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
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	 //Name of a menu resource to use for the windows with this class.
    wc.lpszMenuName  = NULL;
	 //Name to identify the class with.
    wc.lpszClassName = g_szClassName;
	 //small (usually 16x16) icon to show in the taskbar and in the top left corner of the window.
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

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
        "My small program",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 640, 520,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
	 // Initialise common controls.
	 INITCOMMONCONTROLSEX icc;
		icc.dwSize = sizeof(INITCOMMONCONTROLSEX);
		icc.dwICC = ICC_WIN95_CLASSES;
		InitCommonControlsEx(&icc);

    // Step 3: The Message Loop
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
		if(!IsDialogMessage(g_hToolbar, &Msg))
		{	 
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
        
    }
    return Msg.wParam;
}