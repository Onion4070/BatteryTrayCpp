#include <windows.h>
#include <shellapi.h>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
#include <iostream>

NOTIFYICONDATA nid;
HICON hIcon;
HWND hWnd;
UINT_PTR timerID;

byte points[16][16][8] = {
        {
        {0,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0}
        },{
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,0,0}
        },{
        {0,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,0,0,0,0},
        {0,0,1,1,0,0,0,0},
        {0,0,1,1,0,0,0,0},
        {0,0,1,1,0,0,0,0},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0}
        },{
        {0,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0}
        },{
        {0,0,0,0,0,0,0,0},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,0,0}
        },{
        {0,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,0,0,0,0},
        {0,0,1,1,0,0,0,0},
        {0,0,1,1,0,0,0,0},
        {0,0,1,1,0,0,0,0},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0}
        },{
        {0,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,0,0,0,0},
        {0,0,1,1,0,0,0,0},
        {0,0,1,1,0,0,0,0},
        {0,0,1,1,0,0,0,0},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0}
        },{
        {0,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,0,0}
        },{
        {0,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0}
        },{
        {0,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,0,0,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0}
        },{
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
        }
};

byte FullBattery[16][16] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1},
        {1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1},
        {1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1},
        {1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1},
        {1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1},
        {1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1},
        {1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1},
        {1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1},
        {1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1},
        {1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1},
        {1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1},
        {1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1},
        {1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1},
        {1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

byte ErrorBattery[16][16] = {
        {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
        {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0}
};

// 電源状態を確認
int checkPowerStatus() {
    SYSTEM_POWER_STATUS powerStatus;
    if (GetSystemPowerStatus(&powerStatus)) {
        //   0:オフライン
        //   1:オンライン
        // 255:不明
        return powerStatus.ACLineStatus;
    }
}

// 電源接続状態を取得する関数
bool isPowerConnected() {
    return checkPowerStatus() == 1;
}

// バッテリー残量を取得する関数
int getBatteryLevel() {
    SYSTEM_POWER_STATUS status;
    if (GetSystemPowerStatus(&status)) {
        return static_cast<int>(status.BatteryLifePercent);
    }
    else {
        std::cerr << "バッテリー残量の取得に失敗しました" << std::endl;
        return -1;
    }
}

static int currentBatteryLevel = 0;
static bool currentConnected = false;

// バッテリー残量，電源接続状態に応じたアイコンを作成する関数
HICON createBatteryIcon(int batteryLevel, bool isConnected) {
    byte image[16][16] = { 0 };
    if (batteryLevel == 100) {
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                image[i][j] = FullBattery[i][j];
            }
        }
    } else {
        int leftIndex = (batteryLevel < 10) ? 10 : batteryLevel / 10;
        int rightIndex = batteryLevel % 10;
        byte(*left)[8] = points[leftIndex];
        byte(*right)[8] = points[rightIndex];

        // 水平に配列を結合
        for (int j = 0; j < 16; ++j) {
            for (int k = 0; k < 8; ++k) {
                image[j][k] = left[j][k]; // leftを結合
                image[j][k + 8] = right[j][k]; // rightを結合
            }
        }
    }

    HDC hdcScreen = GetDC(NULL);
    HDC hdcMem = CreateCompatibleDC(hdcScreen);
    HBITMAP hBitmap = CreateCompatibleBitmap(hdcScreen, 16, 16);
    HBITMAP hOldBitmap = (HBITMAP)SelectObject(hdcMem, hBitmap);
    HDC hdcMemMask = CreateCompatibleDC(hdcScreen);
    HBITMAP hBitmapMask = CreateCompatibleBitmap(hdcScreen, 16, 16);
    HBITMAP hOldBitmapMask = (HBITMAP)SelectObject(hdcMemMask, hBitmapMask);

    // 2次元配列を参照して描画
    COLORREF color;
    if (isConnected) color = RGB(0, 255, 255);
    else {
        if (batteryLevel > 80) color = RGB(0, 255, 0);
        else if (batteryLevel > 50) color = RGB(255, 255, 255);
        else if (batteryLevel > 20) color = RGB(255, 143, 63);
        else color = RGB(255, 0, 0);
    }


    for (int y = 0; y < 16; ++y) {
        for (int x = 0; x < 16; ++x) {
            if (image[y][x] == 1) {
                SetPixel(hdcMem, x, y, color);
                SetPixel(hdcMemMask, x, y, RGB(0, 0, 0));
            } else {
                SetPixel(hdcMem, x, y, RGB(255, 255, 255));
                SetPixel(hdcMemMask, x, y, RGB(255, 255, 255));
            }
        }
    }

    SelectObject(hdcMem, hOldBitmap);
    SelectObject(hdcMemMask, hOldBitmapMask);
    ReleaseDC(NULL, hdcScreen);

    ICONINFO iconInfo = { TRUE, 0, 0, hBitmapMask, hBitmap };
    // iconInfo.hbmMask = hBitmapMask; // マスクビットマップを設定
    // iconInfo.hbmColor = hBitmap; // カラービットマップを設定
    // 両方がRGB(255, 255, 255)の場合、透過する
    HICON hIcon = CreateIconIndirect(&iconInfo);

    DeleteDC(hdcMem);
    DeleteObject(hBitmap);
    DeleteDC(hdcMemMask);
    DeleteObject(hBitmapMask);

    return hIcon;
}


// タスクトレイアイコンを更新する関数
void updateBatteryIcon() {
    int batteryLevel = getBatteryLevel();
    bool isConnected = isPowerConnected();
    if (batteryLevel > 100 || batteryLevel < 0) {
        std::cerr << "バッテリ残量取得に失敗しました" << std::endl;
        exit(1);
    }
    if (batteryLevel != currentBatteryLevel || isConnected != currentConnected) {
        currentBatteryLevel = batteryLevel;
        currentConnected = isConnected;
        if (batteryLevel != -1) {
            HICON hNewIcon = createBatteryIcon(batteryLevel, isConnected);
            if (hIcon) {
                DestroyIcon(hIcon);
            }
            hIcon = hNewIcon;
            nid.hIcon = hIcon;
            Shell_NotifyIcon(NIM_MODIFY, &nid);
        }
    }
}

// ウィンドウプロシージャ
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) { 
    switch (uMsg) {
    case WM_CREATE:
        timerID = SetTimer(hwnd, 1, 60000, NULL);
        break;
    case WM_TIMER:
        updateBatteryIcon();
        break;
    case WM_DESTROY:
        Shell_NotifyIcon(NIM_DELETE, &nid);
        if (hIcon) {
            DestroyIcon(hIcon);
        }
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

// メイン関数
int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    // アプリの多重起動防止(RAM上にlockを作成)
    HANDLE hMutex = CreateMutex(NULL, TRUE, L"Global\\BatteryIconAppMutex");
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        MessageBox(NULL, L"すでにアプリケーションが起動しています。", L"警告", MB_OK | MB_ICONWARNING);
        return 1;
    }

    const wchar_t CLASS_NAME[] = L"BatteryIconClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    hWnd = CreateWindowEx(0, CLASS_NAME, L"Battery Icon", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

    nid.cbSize = sizeof(nid);
    nid.hWnd = hWnd;
    nid.uID = 1;
    nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    nid.uCallbackMessage = WM_USER + 1;
    Shell_NotifyIcon(NIM_ADD, &nid);

    updateBatteryIcon();

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // lockを解放
    if (hMutex) {
    ReleaseMutex(hMutex);
    CloseHandle(hMutex);
    }
    
    return 0;
}