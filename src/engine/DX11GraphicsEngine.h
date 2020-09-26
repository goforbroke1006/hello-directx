//
// Created by GOFORBROKE on 26.09.2020.
//

#ifndef HELLO_DIRECTX_DX11GRAPHICSENGINE_H
#define HELLO_DIRECTX_DX11GRAPHICSENGINE_H

#include "AbstractGraphicsEngine.h"

#include <d3d11.h>

class DX11GraphicsEngine : public AbstractGraphicsEngine {
public:
    DX11GraphicsEngine(
            IDXGISwapChain *swapChain,
            ID3D11Device *device,
            ID3D11DeviceContext *deviceContext,
            ID3D11RenderTargetView *backBuffer
    ) : swapChain(swapChain),
        device(device),
        deviceContext(deviceContext),
        backBuffer(backBuffer) {}

    IDXGISwapChain *getSwapChain() override {
        return swapChain;
    }

    ID3D11Device *getDevice() override {
        return device;
    }

    ID3D11DeviceContext *getDeviceContext() override {
        return deviceContext;
    }

    ID3D11RenderTargetView *getBackBuffer() override {
        return backBuffer;
    }

private:
    IDXGISwapChain *swapChain;          // the pointer to the swap chain interface
    ID3D11Device *device;               // the pointer to our Direct3D device interface
    ID3D11DeviceContext *deviceContext; // the pointer to our Direct3D device context
    ID3D11RenderTargetView *backBuffer; // the pointer to our back buffer
};


#endif //HELLO_DIRECTX_DX11GRAPHICSENGINE_H
