#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <sstream>

#include <glad/glad.h> 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GLFW/glfw3.h>

#include <iostream>

#ifdef _DEBUG
#define GL_CALL(statement) \
    ClearAllGLErrors();    \
    statement;             \
    CheckOpenGLError(#statement, __FILE__, __LINE__);
#else
#define GL_CALL(statement) statement
#endif

void ClearAllGLErrors();
bool CheckOpenGLError(const char* statement, const char* file, int line);

