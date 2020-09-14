//
// Created by GOFORBROKE on 12.09.2020.
//

#ifndef HELLO_DIRECTX_MESH_H
#define HELLO_DIRECTX_MESH_H

#include <d3d11.h>
#include <vector>
#include "types.h"

class Mesh {
public:
    Mesh();

    std::vector<VERTEX> getVertices();

    ID3D11Buffer *&getVertexBuffer();

private:
    std::vector<VERTEX> vertices;
    ID3D11Buffer *pVBuffer;
};


#endif //HELLO_DIRECTX_MESH_H
