#include "functions.h"

void ClearAllGLErrors()
{
    while (glGetError() != GL_NO_ERROR) {}
}

bool CheckOpenGLError(const char* statement, const char* file, int line)
{
    while (GLenum error = glGetError()) {
        std::cerr << "OpenGL error " << error << " at " << file << ":" << line << " - " << statement << std::endl;
        throw std::runtime_error("OpenGL Error");
        return false;
    }
    return true;
}