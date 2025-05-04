#pragma once

#include "Engine/Core/functions.h"

class VBuffer
{
public:
	~VBuffer();

	VBuffer(const void* data, GLuint size);

	void Bind() const;
	void Unbind() const;

	GLuint m_buffer;
};

class IBuffer
{
public:
	~IBuffer();

	IBuffer(const GLuint* data, GLuint count);

	void Bind() const;
	void Unbind() const;

	inline GLuint GetCount() const { return m_Count; }

	GLuint m_buffer = 0, m_Count = 0;
};

class VArray {
public:
	GLuint m_array;

	VArray();
	~VArray();

	void AddBuffer(const VBuffer& vb, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);

	void Bind() const;
	void Unbind() const;
};