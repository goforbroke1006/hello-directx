//
// Created by GOFORBROKE on 10.09.2020.
//

#include "GraphicsEngine.h"

#include "utils.h"

void GraphicsEngine::Initialize(
        HWND windowDescriptor,
        UINT screenWidth,
        UINT screenHeight
) {
    // create a struct to hold information about the swap chain
    DXGI_SWAP_CHAIN_DESC scd;

    // clear out the struct for use
    ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

    // fill the swap chain description struct
    scd.BufferCount = 1;                                   // one back buffer
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;    // use 32-bit color
    scd.BufferDesc.Width = screenWidth;                    // set the back buffer width
    scd.BufferDesc.Height = screenHeight;                  // set the back buffer height
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;     // how swap chain is to be used
    scd.OutputWindow = windowDescriptor;                   // the window to be used
    scd.SampleDesc.Count = 4;                              // how many multisamples
    scd.Windowed = TRUE;                                   // windowed/full-screen mode
    scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;    // allow full-screen switching

    // create a device, device context and swap chain using the information in the scd struct
    D3D11CreateDeviceAndSwapChain(
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
}

// this is the function used to render a single frame
void GraphicsEngine::RenderFrame() {
    float color[4] = {0.0f, 0.5f, 0.7f, 1.0f};
    // clear the back buffer to a light blue
    deviceContext->ClearRenderTargetView(backBuffer, color);

    for (auto mesh : this->meshes) {
        // select which vertex buffer to display
        UINT stride = sizeof(VERTEX);
        UINT offset = 0;
        deviceContext->IASetVertexBuffers(0, 1, &mesh->getVertexBuffer(), &stride, &offset);

        // select which primtive type we are using
        deviceContext->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

        // draw the vertex buffer to the back buffer
        int vertexCount = mesh->getVertices().size();
        deviceContext->Draw(vertexCount, 0);
    }

    // switch the back buffer and the front buffer
    swapChain->Present(0, 0);
}

void GraphicsEngine::Destroy() {
    swapChain->SetFullscreenState(FALSE, nullptr);    // switch to windowed mode

    // close and release all existing COM objects
    pLayout->Release();

    swapChain->Release();
    backBuffer->Release();
    device->Release();
    deviceContext->Release();
}


// this is the function that creates the shape to render
void GraphicsEngine::LoadGraphics(Mesh *mesh) {
    std::vector<VERTEX> vertices = mesh->getVertices();

    VERTEX *verticesArr = &vertices[0];

    // create the vertex buffer
    D3D11_BUFFER_DESC bd;
    ZeroMemory(&bd, sizeof(bd));

    size_t verticesBytesWidth = sizeof(VERTEX) * vertices.size();

    bd.Usage = D3D11_USAGE_DYNAMIC;
    bd.ByteWidth = verticesBytesWidth;
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

    device->CreateBuffer(&bd, nullptr, &mesh->getVertexBuffer());


    // copy the vertices into the buffer
    D3D11_MAPPED_SUBRESOURCE ms;
    deviceContext->Map(mesh->getVertexBuffer(), 0, D3D11_MAP_WRITE_DISCARD, 0, &ms);
    memcpy(ms.pData, verticesArr, verticesBytesWidth);

    deviceContext->Unmap(mesh->getVertexBuffer(), 0);

    meshes.push_back(mesh);
}

// this function loads and prepares the shaders
void GraphicsEngine::LoadShader(const std::string &filename, Shader *shader) {
    // load and compile the two shaders
    ID3D10Blob *VS, *PS;

    D3DCompileFromFile(filename.c_str(), 0, 0, "VShader", "vs_4_0", 0, 0, &VS, 0);
    D3DCompileFromFile(filename.c_str(), 0, 0, "PShader", "ps_4_0", 0, 0, &PS, 0);

    // encapsulate both shaders into shader objects
    device->CreateVertexShader(VS->GetBufferPointer(), VS->GetBufferSize(), nullptr, &shader->getVertexShader());
    device->CreatePixelShader(PS->GetBufferPointer(), PS->GetBufferSize(), nullptr, &shader->getPixelShader());

    // set the shader objects
    deviceContext->VSSetShader(shader->getVertexShader(), 0, 0);
    deviceContext->PSSetShader(shader->getPixelShader(), 0, 0);

    // create the input layout object
    D3D11_INPUT_ELEMENT_DESC ied[] =
            {
                    {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0},
                    {"COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0},
            };

    device->CreateInputLayout(ied, 2, VS->GetBufferPointer(), VS->GetBufferSize(), &pLayout);
    deviceContext->IASetInputLayout(pLayout);
}
