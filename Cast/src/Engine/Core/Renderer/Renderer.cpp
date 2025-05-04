#include "Renderer.h"

Renderer::Renderer()
{
    //GL_CALL(glEnable(GL_DEPTH_TEST));
    
    //GL_CALL(glEnable(GL_BLEND));
    //GL_CALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
    //GL_CALL(glBlendEquation(GL_FUNC_ADD));
    //
    //GL_CALL(glEnable(GL_CULL_FACE));
    //GL_CALL(glCullFace(GL_BACK));
    //GL_CALL(glFrontFace(GL_CCW));
}

void Renderer::Clear(GLbitfield mask) 
{
    GL_CALL(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
    GL_CALL(glClear(mask));
}

void Renderer::Clear(float r, float g, float b, float a) 
{
    GL_CALL(glClearColor(r, g, b, a));
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Renderer::Draw(VArray& vertexArray, IBuffer& indexBuffer) 
{
    vertexArray.Bind();
    indexBuffer.Bind();
    GL_CALL(glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr));
    vertexArray.Unbind();
    indexBuffer.Unbind();
}