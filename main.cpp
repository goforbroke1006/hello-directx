#include <windows.h>
#include <iostream>

#include "src/engine/GraphicsEngineFactory.h"
//#include "GraphicsEngine.h"
#include "Scene.h"

// define the screen resolution
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow) {
    HWND hWnd;
    WNDCLASSEX wc;

    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = "WindowClass";

    RegisterClassEx(&wc);

    RECT wr = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

    hWnd = CreateWindowEx(0,
                          "WindowClass",
                          "Our First Direct3D Program",
                          WS_OVERLAPPEDWINDOW,
                          300,
                          300,
                          wr.right - wr.left,
                          wr.bottom - wr.top,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hWnd, nCmdShow);

//    GraphicsEngine graphicsEngine{};

    DX11GraphicsEngine *pGraphicsEngine = GraphicsEngineFactory::buildDX11(hWnd, SCREEN_WIDTH, SCREEN_HEIGHT, true);

    Scene scene;
    scene.SetViewport(pGraphicsEngine);

    Mesh triangle2D{};
    GameObject triangle{};
    triangle.setMesh(&triangle2D);
    scene.Append(&triangle);

//    Shader petrolShader{};
//    graphicsEngine.LoadShader("../shaders.shader", &petrolShader);

    // enter the main loop:
    MSG msg;
    while (TRUE) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                break;
        }

        graphicsEngine.RenderFrame();
    }

    // clean up DirectX and COM
    graphicsEngine.Destroy();
    scene.RemoveAll();

    return msg.wParam;
}


// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_DESTROY: {
            PostQuitMessage(0);
            return 0;
        }
            break;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}
