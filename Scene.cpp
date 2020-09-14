//
// Created by GOFORBROKE on 12.09.2020.
//

#include "Scene.h"

void Scene::SetViewport(GraphicsEngine *graphicsEngine) {
    m_graphicsEngine = graphicsEngine;
}

void Scene::Append(GameObject *gameObject) {
    if (gameObject->getMesh()) {
        m_graphicsEngine->LoadGraphics(gameObject->getMesh());
    }
    m_gameObjects.push_back(gameObject);
}

void Scene::RemoveAll() {
    for (auto go : this->m_gameObjects) {
        if (go->getMesh()) {
            go->getMesh()->getVertexBuffer()->Release(); // TODO: move to GraphicsEngine
        }
    }
}
