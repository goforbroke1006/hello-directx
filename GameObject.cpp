//
// Created by GOFORBROKE on 12.09.2020.
//

#include "GameObject.h"


Mesh *GameObject::getMesh() const {
    return m_mesh;
}

void GameObject::setMesh(Mesh *mesh) {
    m_mesh = mesh;
}


