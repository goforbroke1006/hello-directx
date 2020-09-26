//
// Created by GOFORBROKE on 26.09.2020.
//

#ifndef HELLO_DIRECTX_DX9GRAPHICSENGINE_H
#define HELLO_DIRECTX_DX9GRAPHICSENGINE_H

#include <d3d9.h>

#include "AbstractGraphicsEngine.h"

class DX9GraphicsEngine : public AbstractGraphicsEngine {
public:
    IDirect3DSwapChain9 *getSwapChain() override {
        return swapChain;
    }

    IDirect3DDevice9 *getDevice() override {
        return device;
    }

    IUnknown *getDeviceContext() override {
//        return surface->GetDC(); // FIXME: find tutorial how get device context in DX9
        return nullptr;
    }

    IDirect3DIndexBuffer9 *getBackBuffer() override {
        return backBuffer;
    }

private:
    IDirect3DSwapChain9 *swapChain;     // the pointer to the swap chain interface
    IDirect3DDevice9 *device;           // the pointer to our Direct3D device interface
    IDirect3DSurface9 *surface;         // the pointer to our Direct3D device context
    IDirect3DIndexBuffer9 *backBuffer;  // the pointer to our back buffer
};


#endif //HELLO_DIRECTX_DX9GRAPHICSENGINE_H
