#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "Engine/Core/Renderer/Shader.h"

struct RenderContext {
    //std::unique_ptr<WindowManager> windowManagerPtr;
    //std::unique_ptr<Renderer> rendererPtr;
    int fps = 0;
    int max_fps = 60;
    float deltaTime = 0.0f;
};

class Scene
{
protected:
    RenderContext& m_renderContext;
    //std::vector<std::unique_ptr<Model>> m_modelPtrs;
    //LightsManager m_lightsManager;
    //std::vector<std::unique_ptr<Camera>> m_cameraPtrs;
    //std::vector<std::unique_ptr<Shader>> m_shaderPtrs;

private:
    int m_activeCameraIndex = 0;

    int m_selectedModelIndex = 0;
    int m_activeMeshIndex = 0;
    int m_activeLightIndex = 0;

    float m_xSensitivity = 8.0f;
    float m_ySensitivity = 8.0f;
    float m_moveSpeed = 8.0f;
    bool isInverted = true;

    std::string m_sceneTitle;

    //std::unique_ptr<ObjectPropertiesEditor> m_objectPropertiesEditorPtr;
    //std::unique_ptr<CameraPropertiesEditor> m_cameraPropertiesEditorPtr;
    //std::unique_ptr<InputPropertiesEditor> m_inputPropertiesEditorPtr;
    //std::unique_ptr<LightPropertiesEditor> m_lightPropertiesEditorPtr;

public:
    Scene(RenderContext& renderContext, std::string sceneTitle);

    //virtual void OnUpdate();
    //virtual void OnRender() {};
    //virtual void OnGUIRender();

protected:
    //void AddCamera(std::unique_ptr<Camera>&& cameraPtr) 
    //{
    //    m_cameraPtrs.push_back(std::move(cameraPtr));
    //}

    //Camera& GetActiveCamera() 
    //{
    //    if (m_cameraPtrs.size() == 0) 
    //    {
    //        throw std::runtime_error("No camera has been added to the scene");
    //    }
    //
    //    return *m_cameraPtrs[m_activeCameraIndex];
    //}

    //void SetActiveCameraIndex(int index) 
    //{
    //    if (index < m_cameraPtrs.size()) 
    //    {
    //        m_activeCameraIndex = index;
    //    }
    //}

    //void AddModel(std::unique_ptr<Model>&& modelPtr) 
    //{
    //    m_modelPtrs.push_back(std::move(modelPtr));
    //}

    //void AddLight(std::unique_ptr<BaseLight>&& lightPtr) 
    //{
    //    m_lightsManager.IncreaseLightCount(lightPtr->type);
    //    m_lightsManager.lightPtrs.push_back(std::move(lightPtr));
    //}

    //void AddShader(std::unique_ptr<Shader>&& shaderPtr) 
    //{
    //    m_shaderPtrs.push_back(std::move(shaderPtr));
    //}

    //Model& GetSelectedModel() 
    //{
    //    if (m_modelPtrs.size() == 0) 
    //    {
    //        throw std::runtime_error("No model has been added to the scene");
    //    }
    //
    //    return *m_modelPtrs[m_selectedModelIndex];
    //}

    //std::unique_ptr<BaseLight>& GetSelectedLightPtr() 
    //{
    //    if (m_lightsManager.lightPtrs.size() == 0) 
    //    {
    //        throw std::runtime_error("No light has been added to the scene");
    //    }
    //
    //    return m_lightsManager.lightPtrs[m_activeLightIndex];
    //}
};