//
// Created by GOFORBROKE on 26.09.2020.
//

#ifndef HELLO_DIRECTX_GRAPHICSENGINEFACTORY_H
#define HELLO_DIRECTX_GRAPHICSENGINEFACTORY_H

#include "DX9GraphicsEngine.h"
#include "DX10GraphicsEngine.h"
#include "DX11GraphicsEngine.h"

class GraphicsEngineFactory {
public:
    static DX9GraphicsEngine buildDX9() {
        // TODO: implement me
    }

    static DX10GraphicsEngine buildDX10(HWND windowDescriptor, UINT screenWidth, UINT screenHeight, BOOL windowed) {
        // TODO: implement me
        IDXGISwapChain *swapChain;          // the pointer to the swap chain interface
        ID3D10Device *device;               // the pointer to our Direct3D device interface
        IDXGIDevice *deviceContext;         // the pointer to our Direct3D device context
        ID3D10RenderTargetView *backBuffer; // the pointer to our back buffer

        DXGI_SWAP_CHAIN_DESC scd;
        ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));
        scd.BufferCount = 1;                                   // one back buffer
        scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;    // use 32-bit color
        scd.BufferDesc.Width = screenWidth;                    // set the back buffer width
        scd.BufferDesc.Height = screenHeight;                  // set the back buffer height
        scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;     // how swap chain is to be used
        scd.OutputWindow = windowDescriptor;                   // the window to be used
        scd.SampleDesc.Count = 4;                              // how many multisamples
        scd.Windowed = windowed;                               // windowed/full-screen mode
        scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;    // allow full-screen switching

        D3D10CreateDeviceAndSwapChain(
                nullptr,
                D3D10_DRIVER_TYPE_HARDWARE,
                nullptr,
                0,
                D3D10_SDK_VERSION,
                &scd,
                &swapChain,
                &device);

        device->QueryInterface(__uuidof(IDXGIDevice), (void **) &deviceContext);
    }

    static DX11GraphicsEngine *buildDX11(HWND windowDescriptor, UINT screenWidth, UINT screenHeight, BOOL windowed) {

#include <d3d11.h>

        IDXGISwapChain *swapChain;          // the pointer to the swap chain interface
        ID3D11Device *device;               // the pointer to our Direct3D device interface
        ID3D11DeviceContext *deviceContext; // the pointer to our Direct3D device context
        ID3D11RenderTargetView *backBuffer; // the pointer to our back buffer

        DXGI_SWAP_CHAIN_DESC scd;
        ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));
        scd.BufferCount = 1;                                   // one back buffer
        scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;    // use 32-bit color
        scd.BufferDesc.Width = screenWidth;                    // set the back buffer width
        scd.BufferDesc.Height = screenHeight;                  // set the back buffer height
        scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;     // how swap chain is to be used
        scd.OutputWindow = windowDescriptor;                   // the window to be used
        scd.SampleDesc.Count = 4;                              // how many multisamples
        scd.Windowed = windowed;                               // windowed/full-screen mode
        scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;    // allow full-screen switching

        // create a device, device context and swap chain using the information in the scd struct
        /*HRESULT initResult =*/ D3D11CreateDeviceAndSwapChain(
                nullptr,
                D3D_DRIVER_TYPE_HARDWARE,
                nullptr,
                0,
                nullptr,
                0,
                D3D11_SDK_VERSION,
                &scd,
                &swapChain,
                &device,
                nullptr,
                &deviceContext);
        // TODO: check initResult is not error (and try - D3D_DRIVER_TYPE_HARDWARE | D3D_DRIVER_TYPE_REFERENCE | D3D_DRIVER_TYPE_SOFTWARE)


        // get the address of the back buffer
        ID3D11Texture2D *pBackBuffer;
        swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID *) &pBackBuffer);

        // use the back buffer address to create the render target
        device->CreateRenderTargetView(pBackBuffer, nullptr, &backBuffer);
        pBackBuffer->Release();

        // set the render target as the back buffer
        deviceContext->OMSetRenderTargets(1, &backBuffer, nullptr);


        // Set the viewport
        D3D11_VIEWPORT viewport;
        ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

        viewport.TopLeftX = 0;
        viewport.TopLeftY = 0;
        viewport.Width = screenWidth;
        viewport.Height = screenHeight;

        deviceContext->RSSetViewports(1, &viewport);


        return new DX11GraphicsEngine(swapChain, device, deviceContext, backBuffer);
    }

    static void destroy(DX11GraphicsEngine *engine) {
        engine->getSwapChain()->SetFullscreenState(FALSE, nullptr);    // switch to windowed mode

        // close and release all existing COM objects
//            pLayout->Release();
        // TODO: fix it

        engine->getSwapChain()->Release();
        engine->getBackBuffer()->Release();
        engine->getDevice()->Release();
        engine->getDeviceContext()->Release();

    }
};


#endif //HELLO_DIRECTX_GRAPHICSENGINEFACTORY_H
