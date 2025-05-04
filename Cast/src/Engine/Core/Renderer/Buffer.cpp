#include "Buffer.h"

VBuffer::VBuffer(const void* data, GLuint size) : m_buffer(0) 
{
    GL_CALL(glGenBuffers(1, &m_buffer));
    Bind();
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VBuffer::~VBuffer() 
{
    GL_CALL(glDeleteBuffers(1, &m_buffer));
    Unbind();
}

void VBuffer::Bind() const 
{
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_buffer));
}

void VBuffer::Unbind() const 
{
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

IBuffer::IBuffer(const GLuint* data, GLuint count) : m_buffer(0), m_Count(count) 
{
    GL_CALL(glGenBuffers(1, &m_buffer));

    Bind();
    GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data,
        GL_STATIC_DRAW));
    Unbind();
}

IBuffer::~IBuffer() 
{
    GL_CALL(glDeleteBuffers(1, &m_buffer));
}

void IBuffer::Bind() const 
{
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer));
}

void IBuffer::Unbind() const 
{
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

VArray::VArray()
{
    GL_CALL(glGenVertexArrays(1, &m_array));
}

VArray::~VArray() 
{
    GL_CALL(glDeleteVertexArrays(1, &m_array));
}

void VArray::AddBuffer(const VBuffer& vb, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer)
{
    Bind();   
    vb.Bind(); 

    //const auto& elements = layout.GetElements();
    //unsigned int offset = 0;
    //for (unsigned int i = 0; i < elements.size(); i++) {
    //    const auto& element = elements[i];
    //    GL_CALL(glEnableVertexAttribArray(i));
    //    GL_CALL(glVertexAttribPointer(i, element.count, element.type,
    //        element.normalized, layout.GetStride(),
    //        (const void*)offset));
    //    offset += element.count * VertexBufferElement::GetSize(element.type);
    //}

    vb.Unbind(); 
    Unbind();    
}

void VArray::Bind() const
{
    GL_CALL(glBindVertexArray(m_array));
}
void VArray::Unbind() const
{
    GL_CALL(glBindVertexArray(0));
}