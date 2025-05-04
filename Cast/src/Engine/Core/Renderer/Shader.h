#pragma once

#include <string>
#include "Buffer.h"


//GLuint compileShader(GLenum type, const char* source) {
//	GLuint shader = glCreateShader(type);
//	glShaderSource(shader, 1, &source, nullptr);
//	glCompileShader(shader);
//
//	int success;
//	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		char infoLog[512];
//		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
//		std::cerr << "Shader compilation failed: " << infoLog << std::endl;
//	}
//	return shader;
//}
//
//GLuint createShaderProgram() {
//	GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
//	GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
//
//	GLuint shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//
//	int success;
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		char infoLog[512];
//		glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
//		std::cerr << "Shader linking failed: " << infoLog << std::endl;
//	}
//
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//	return shaderProgram;
//}

class Shader
{
public:
	unsigned int ID;

	Shader(const char* VertexPath, const char* FragmentPath);
	Shader() = default;
	~Shader();

	Shader& Bind();

	void Compile(const char* vertexPath, const char* fragmentPath);

	void setBool(const char* name, bool value, bool useShader = false) const;
	void setInt(const char* name, int value, bool useShader = false) const;
	void setFloat(const char* name, float value, bool useShader = false) const;

	void setVector2f(const char* name, float value, float value2, bool useShader = false) const;
	void setVector2f(const char* name, const glm::vec2& value, bool useShader = false) const;

	void setVector3f(const char* name, float value, float value2, float value3, bool useShader = false) const;
	void setVector3f(const char* name, const glm::vec3& value, bool useShader = false) const;

	void setVector4f(const char* name, float value, float value2, float value3, float value4, bool useShader = false) const;
	void setVector4f(const char* name, const glm::vec4& value, bool useShader = false) const;

	void SetMatrix4(const char* name, const glm::mat4& matrix, bool useShader = false) const;
private:
	void compileErrors(unsigned int shader, const char* type);
};