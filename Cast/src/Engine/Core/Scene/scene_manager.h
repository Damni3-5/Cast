#pragma once

#include "scene.h"

#include <functional>
#include <vector>

//#include "function.h"

class SceneManager {
private:
    RenderContext& m_renderContext;
    std::vector<std::pair<std::string, std::function<Scene* ()>>> m_scenes;
    Scene* m_ScenePtr;

public:
    SceneManager(RenderContext& renderContext);

    template <typename T>
    void RegisterScene(const std::string& sceneName) {
        std::cout << "Registering scene: {}\n" << sceneName << std::endl;
        m_scenes.push_back(std::make_pair(
            sceneName, [&]() { return new T(m_renderContext); }));
    }

    void RenderSceneList();

    Scene* GetActiveScenePtr() const {
        return m_ScenePtr;
    }

    void DeleteActiveScenePtr() {
        delete m_ScenePtr;
        m_ScenePtr = nullptr;
    }
};