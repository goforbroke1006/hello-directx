//
// Created by GOFORBROKE on 12.09.2020.
//

#ifndef HELLO_DIRECTX_SCENE_H
#define HELLO_DIRECTX_SCENE_H

#include "GraphicsEngine.h"
#include "GameObject.h"

class Scene {
public:
    void SetViewport(GraphicsEngine *graphicsEngine);

    void Append(GameObject *gameObject);

    void RemoveAll();

private:
    GraphicsEngine *m_graphicsEngine;
    std::vector<GameObject *> m_gameObjects;
};


#endif //HELLO_DIRECTX_SCENE_H
