//
// Created by GOFORBROKE on 10.09.2020.
//

#ifndef INIT_DX_VIEWPORT_H
#define INIT_DX_VIEWPORT_H

// include the Direct3D Library files
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3d10.lib")
#pragma comment (lib, "d3d11.lib")

#include <windows.h>
#include <d3d11.h>
#include <vector>
#include <string>

#include "types.h"
#include "Mesh.h"
#include "Shader.h"

class GraphicsEngine {
public:
    void Initialize(
            HWND windowDescriptor,
            UINT screenWidth,
            UINT screenHeight
    );

    void RenderFrame();

    void Destroy();

    void LoadGraphics(Mesh *mesh);

    void LoadShader(const std::string &filename, Shader *shader);

private:
    IDXGISwapChain *swapChain;             // the pointer to the swap chain interface
    ID3D11Device *device;                  // the pointer to our Direct3D device interface
    ID3D11DeviceContext *deviceContext;    // the pointer to our Direct3D device context
    ID3D11RenderTargetView *backBuffer;    // the pointer to our back buffer

    ID3D11InputLayout *pLayout;            // the pointer to the input layout

    std::vector<Mesh *> meshes;
};


#endif //INIT_DX_VIEWPORT_H
