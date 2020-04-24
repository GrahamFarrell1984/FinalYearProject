#include "BaseScene.h"

#include "SceneManager.h"

BaseScene::BaseScene(SceneManager& sceneManager, const Scene::Name name)
        : m_name{ name }
        , m_sceneManager{ sceneManager }
{
}

Scene::Name BaseScene::getName() const
{
    return m_name;
}

void BaseScene::requestSceneChange(const Scene::Action action, const Scene::Name name) const
{
    m_sceneManager.requestSceneChange(action, name);
}