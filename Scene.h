//
// Created by GOFORBROKE on 12.09.2020.
//

#ifndef HELLO_DIRECTX_SCENE_H
#define HELLO_DIRECTX_SCENE_H

#include "src/engine/AbstractGraphicsEngine.h"
#include "GraphicsEngine.h"
#include "GameObject.h"

class Scene {
public:
    void SetViewport(AbstractGraphicsEngine *graphicsEngine);

    void Append(GameObject *gameObject);

    void RemoveAll();

private:
    AbstractGraphicsEngine *m_graphicsEngine;
    std::vector<GameObject *> m_gameObjects;
};


#endif //HELLO_DIRECTX_SCENE_H
