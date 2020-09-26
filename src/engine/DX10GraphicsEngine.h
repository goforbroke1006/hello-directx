//
// Created by GOFORBROKE on 26.09.2020.
//

#ifndef HELLO_DIRECTX_DX10GRAPHICSENGINE_H
#define HELLO_DIRECTX_DX10GRAPHICSENGINE_H

#include "AbstractGraphicsEngine.h"

#include <d3d10.h>

class DX10GraphicsEngine : public AbstractGraphicsEngine {
public:
    DX10GraphicsEngine(
            IDXGISwapChain *swapChain,
            ID3D10Device *device,
            IDXGIDevice *deviceContext,
            ID3D10RenderTargetView *backBuffer
    )
            : swapChain(swapChain),
              device(device),
              deviceContext(deviceContext),
              backBuffer(backBuffer) {}

    IDXGISwapChain *getSwapChain() override {
        return swapChain;
    }

    ID3D10Device *getDevice() override {
        return device;
    }

    IDXGIDevice *getDeviceContext() override {
        return deviceContext;
    }

    ID3D10RenderTargetView *getBackBuffer() override {
        return backBuffer;
    }

private:
    IDXGISwapChain *swapChain;          // the pointer to the swap chain interface
    ID3D10Device *device;               // the pointer to our Direct3D device interface
    IDXGIDevice *deviceContext; // the pointer to our Direct3D device context
    ID3D10RenderTargetView *backBuffer; // the pointer to our back buffer
};


#endif //HELLO_DIRECTX_DX10GRAPHICSENGINE_H
