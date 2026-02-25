#include <windows.h>
#include <stdio.h>

#define EDIT1 10
#define EDIT2 11

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    if (msg == WM_CREATE) {

        CreateWindowA("STATIC","Number 1",WS_VISIBLE|WS_CHILD,20,20,80,20,hwnd,NULL,NULL,NULL);
        CreateWindowA("EDIT","",WS_VISIBLE|WS_CHILD|WS_BORDER,100,20,120,20,hwnd,(HMENU)EDIT1,NULL,NULL);

        CreateWindowA("STATIC","Number 2",WS_VISIBLE|WS_CHILD,20,50,80,20,hwnd,NULL,NULL,NULL);
        CreateWindowA("EDIT","",WS_VISIBLE|WS_CHILD|WS_BORDER,100,50,120,20,hwnd,(HMENU)EDIT2,NULL,NULL);

        CreateWindowA("BUTTON","+",WS_VISIBLE|WS_CHILD,20,90,40,30,hwnd,(HMENU)1,NULL,NULL);
        CreateWindowA("BUTTON","-",WS_VISIBLE|WS_CHILD,70,90,40,30,hwnd,(HMENU)2,NULL,NULL);
        CreateWindowA("BUTTON","*",WS_VISIBLE|WS_CHILD,120,90,40,30,hwnd,(HMENU)3,NULL,NULL);
        CreateWindowA("BUTTON","/",WS_VISIBLE|WS_CHILD,170,90,40,30,hwnd,(HMENU)4,NULL,NULL);
    }

    if (msg == WM_COMMAND && HIWORD(wParam) == BN_CLICKED) {

        char a[100], b[100], out[100];
        double x, y, r = 0;

        GetDlgItemTextA(hwnd, EDIT1, a, 100);
        GetDlgItemTextA(hwnd, EDIT2, b, 100);

        x = atof(a);
        y = atof(b);

        if (LOWORD(wParam) == 1) r = x + y;
        if (LOWORD(wParam) == 2) r = x - y;
        if (LOWORD(wParam) == 3) r = x * y;
        if (LOWORD(wParam) == 4) r = x / y;

        sprintf(out, "%f", r);
        MessageBoxA(hwnd, out, "Result", MB_OK);
    }

    if (msg == WM_DESTROY) {
        PostQuitMessage(0);
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow) {

    WNDCLASSEX wc;
    HWND hwnd;
    MSG msg;

    memset(&wc,0,sizeof(wc));
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = CreateSolidBrush(RGB(500,200,255));
    wc.lpszClassName = "WindowClass";
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    RegisterClassEx(&wc);

    hwnd = CreateWindowExA(
        0,
        "WindowClass",
        "My Calculator",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
        100,100,250,200,
        NULL,NULL,hInst,NULL
    );

    ShowWindow(hwnd, nCmdShow);

    while (GetMessage(&msg,NULL,0,0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
