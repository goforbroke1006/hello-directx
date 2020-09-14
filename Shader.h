//
// Created by GOFORBROKE on 13.09.2020.
//

#ifndef HELLO_DIRECTX_SHADER_H
#define HELLO_DIRECTX_SHADER_H

#include <d3d11.h>

class Shader {
public:
    ID3D11VertexShader *&getVertexShader();

    ID3D11PixelShader *&getPixelShader();

private:
    ID3D11VertexShader *pVS;               // the pointer to the vertex shader
    ID3D11PixelShader *pPS;                // the pointer to the pixel shader
};


#endif //HELLO_DIRECTX_SHADER_H
