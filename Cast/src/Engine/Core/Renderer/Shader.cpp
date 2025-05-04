#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    Compile(vertexPath, fragmentPath);
}

Shader::~Shader()
{
    glDeleteShader(this->ID);
}

Shader& Shader::Bind()
{
    glUseProgram(this->ID);
    return *this;
}

void Shader::Compile(const char* vertexPath, const char* fragmentPath)
{
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    unsigned int vertex, fragment;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    compileErrors(vertex, "VERTEX");

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    compileErrors(vertex, "FRAGMENT");

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    compileErrors(vertex, "PROGRAM");

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::setBool(const char* name, bool value, bool useShader) const
{
    if (useShader) glUseProgram(ID);
    glUniform1i(glGetUniformLocation(ID, name), (int)value);
}

void Shader::setInt(const char* name, int value, bool useShader) const
{
    if (useShader) glUseProgram(ID);
    glUniform1i(glGetUniformLocation(ID, name), value);
}

void Shader::setFloat(const char* name, float value, bool useShader) const
{
    if (useShader) glUseProgram(ID);
    glUniform1f(glGetUniformLocation(ID, name), value);
}

void Shader::setVector2f(const char* name, float value, float value2, bool useShader) const
{
    if (useShader) glUseProgram(ID);
    glUniform2f(glGetUniformLocation(ID, name), value, value2);
}

void Shader::setVector2f(const char* name, const glm::vec2& value, bool useShader) const
{
    if (useShader) glUseProgram(ID);
    glUniform2f(glGetUniformLocation(ID, name), value.x, value.y);
}

void Shader::setVector3f(const char* name, float value, float value2, float value3, bool useShader) const
{
    if (useShader) glUseProgram(ID);
    glUniform3f(glGetUniformLocation(ID, name), value, value2, value3);
}

void Shader::setVector3f(const char* name, const glm::vec3& value, bool useShader) const
{
    if (useShader) glUseProgram(ID);
    glUniform3f(glGetUniformLocation(ID, name), value.x, value.y, value.z);
}

void Shader::setVector4f(const char* name, float value, float value2, float value3, float value4, bool useShader) const
{
    if (useShader) glUseProgram(ID);
    glUniform4f(glGetUniformLocation(ID, name), value, value2, value3, value4);
}

void Shader::setVector4f(const char* name, const glm::vec4& value, bool useShader) const
{
    if (useShader) glUseProgram(ID);
    glUniform4f(glGetUniformLocation(ID, name), value.x, value.y, value.z, value.w);
}

void Shader::SetMatrix4(const char* name, const glm::mat4& matrix, bool useShader) const
{
    if (useShader) glUseProgram(ID);
    glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, false, glm::value_ptr(matrix));
}

void Shader::compileErrors(unsigned int shader, const char* type)
{
    GLint hasCompiled;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
        if (hasCompiled == GL_FALSE)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
        if (hasCompiled == GL_FALSE)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << infoLog << std::endl;
        }
    }
}