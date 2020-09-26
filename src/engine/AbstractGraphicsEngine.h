//
// Created by GOFORBROKE on 26.09.2020.
//

#ifndef HELLO_DIRECTX_ABSTRACTGRAPHICSENGINE_H
#define HELLO_DIRECTX_ABSTRACTGRAPHICSENGINE_H

#include <dxgi.h>

class AbstractGraphicsEngine {
public:
    virtual IUnknown *getSwapChain() = 0;       // the pointer to the swap chain interface
    virtual IUnknown *getDevice() = 0;          // the pointer to our Direct3D device interface
    virtual IUnknown *getDeviceContext() = 0;   // the pointer to our Direct3D device context
    virtual IUnknown *getBackBuffer() = 0;      // the pointer to our back buffer
};

#endif //HELLO_DIRECTX_ABSTRACTGRAPHICSENGINE_H
