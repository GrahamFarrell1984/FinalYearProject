#include "BaseScene.h"

#include "SceneManager.h"

BaseScene::BaseScene(SceneManager& sceneManager, const Scene::Name name, const bool isTransparent)
        : m_isTransparent{ isTransparent }
        , m_name         { name }
        , m_sceneManager { sceneManager }
{
}

bool BaseScene::isTransparent()
{
    return m_isTransparent;
}

Scene::Name BaseScene::getName() const
{
    return m_name;
}

const SharedContext& BaseScene::getSharedContext() const
{
    return m_sceneManager.getSharedContext();
}

void BaseScene::requestSceneChange(const Scene::Action action, const Scene::Name name) const
{
    m_sceneManager.requestSceneChange(action, name);
}
