//
// Created by GOFORBROKE on 13.09.2020.
//

#include "Shader.h"

ID3D11VertexShader *&Shader::getVertexShader() {
    return pVS;
}

ID3D11PixelShader *&Shader::getPixelShader() {
    return pPS;
}
