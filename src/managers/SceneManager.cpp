#include "ControlsScene.h"
#include "GameoverScene.h"
#include "GameScene.h"
#include "PauseScene.h"
#include "SceneManager.h"
#include "TestScene.h"
#include "TitleScene.h"

SceneManager::SceneManager(SharedContext&& sharedContext)
        : m_sharedContext{ std::move(sharedContext) }
        , m_sceneRequest { Scene::Action::PUSH, Scene::Name::TITLE }
{
    m_sceneStack.reserve(Scene::SCENECOUNT);
}

void SceneManager::processInput(const Keyboard& keyboard) const
{
    m_sceneStack.back()->processInput(keyboard);
}

void SceneManager::update() const
{
    m_sceneStack.back()->update();
}

void SceneManager::render(sf::RenderWindow& window) const
{
    auto itr = m_sceneStack.end();
    while (--itr != m_sceneStack.begin() && (*itr)->isTransparent())
        ;
    while (itr != m_sceneStack.end()) {
        (*itr)->render(window);
        ++itr;
    }
}

void SceneManager::checkForUpdates()
{
    if (m_sceneRequest.action != Scene::Action::NONE) {
        switch (m_sceneRequest.action) {
            case Scene::Action::PUSH:
                pushScene();
                break;
            case Scene::Action::POPUNTIL:
                popUntilScene();
                break;
            case Scene::Action::POP:
                popScene();
                break;
            case Scene::Action::POPANDADD:
                popAndPushScene();
                break;
            case Scene::Action::POPALL:
                popAllScenes();
                break;
            default:
                break;
        }
        m_sceneRequest.action = Scene::Action::NONE;
        m_sceneRequest.name   = Scene::Name::NONE;
    }
}

void SceneManager::requestSceneChange(Scene::Action action, Scene::Name name)
{
    if (action != Scene::Action::NONE) {
        m_sceneRequest = Scene::Request{ action, name };
    }
}

bool SceneManager::isSceneStackEmpty() const
{
    return m_sceneStack.empty();
}

const SharedContext& SceneManager::getSharedContext() const
{
    return m_sharedContext;
}

void SceneManager::pushScene()
{
    auto scene = createScene(m_sceneRequest.name);
    if (scene != nullptr) {
        m_sceneStack.emplace_back(std::move(scene));
        m_sceneStack.back()->onEnter();
    }
}

void SceneManager::popAndPushScene()
{
    if (!m_sceneStack.empty()) {
        m_sceneStack.back()->onExit();
        m_sceneStack.pop_back();
        pushScene();
    }
}

void SceneManager::popUntilScene()
{
    while (!m_sceneStack.empty() && m_sceneRequest.name != m_sceneStack.back()->getName()) {
        m_sceneStack.back()->onExit();
        m_sceneStack.pop_back();
    }
}

void SceneManager::popScene()
{
    if (!m_sceneStack.empty()) {
        m_sceneStack.back()->onExit();
        m_sceneStack.pop_back();
    }
}

void SceneManager::popAllScenes()
{
    while (!m_sceneStack.empty()) {
        m_sceneStack.back()->onExit();
        m_sceneStack.pop_back();
    }
}

std::unique_ptr<BaseScene> SceneManager::createScene(const Scene::Name name)
{
    switch (name) {
        case Scene::Name::TITLE:
            return std::unique_ptr<BaseScene>(std::make_unique<TitleScene>(*this, name));
        case Scene::Name::OPTIONS:
            return std::unique_ptr<BaseScene>(std::make_unique<ControlsScene>(*this, name));
        case Scene::Name::GAME:
            return std::unique_ptr<BaseScene>(std::make_unique<GameScene>(*this, name));
        case Scene::Name::PAUSE:
            return std::unique_ptr<BaseScene>(std::make_unique<PauseScene>(*this, name));
        case Scene::Name::GAMEOVER:
            return std::unique_ptr<BaseScene>(std::make_unique<GameoverScene>(*this, name));
        case Scene::Name::TEST:
            return std::unique_ptr<BaseScene>(std::make_unique<TestScene>(*this, name));
        default:
            return std::unique_ptr<BaseScene>(nullptr);
    }
}
