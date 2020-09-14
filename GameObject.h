//
// Created by GOFORBROKE on 12.09.2020.
//

#ifndef HELLO_DIRECTX_GAMEOBJECT_H
#define HELLO_DIRECTX_GAMEOBJECT_H

#include <d3d11.h>

#include "Mesh.h"

class GameObject {
public:
    Mesh *getMesh() const;

    void setMesh(Mesh *mesh);

private:
    Mesh *m_mesh;
};


#endif //HELLO_DIRECTX_GAMEOBJECT_H
