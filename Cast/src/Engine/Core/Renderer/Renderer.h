#pragma once

#include "Buffer.h"
#include "Shader.h"

class Renderer {
public:
    Renderer();

    void SetViewport(int x, int y, int width, int height);

    void Clear(GLbitfield mask = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    void Clear(float r, float g, float b, float a);
    void Draw(VArray& vertexArray, IBuffer& indexBuffer);

    static glm::mat4 ComputeMVPMatrix(glm::mat4& modelMatrix, glm::mat4& viewMatrix,
        glm::mat4& projectionMatrix);

    static glm::mat4 ComputeMVPMatrix(glm::mat4& vpMatrix, glm::mat4& modelMatrix);
};