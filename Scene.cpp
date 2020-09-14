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

}
