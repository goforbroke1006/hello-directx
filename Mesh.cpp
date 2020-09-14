//
// Created by GOFORBROKE on 12.09.2020.
//

#include "Mesh.h"

Mesh::Mesh() {
    vertices = {
            {0.0f,   0.5f,  0.0f, {1.0f, 0.0f, 0.0f, 1.0f}},
            {0.45f,  -0.5,  0.0f, {0.0f, 1.0f, 0.0f, 1.0f}},
            {-0.45f, -0.5f, 0.0f, {0.0f, 0.0f, 1.0f, 1.0f}}
    };
}

std::vector<VERTEX> Mesh::getVertices() const {
    return this->vertices;
}

ID3D11Buffer *&Mesh::getVertexBuffer() {
    return this->pVBuffer;
}
