#include "LearningOpenGL/indexBuffer.hpp"
#include "LearningOpenGL/renderer.hpp"

#include "GL/glew.h"

IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count)
    : m_RendererID(0), m_Count(count)
{
  glGenBuffers(1, &m_RendererID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, (signed)(count * sizeof(GLuint)), data,
               GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer() { glDeleteBuffers(1, &m_RendererID); }

void IndexBuffer::bind() const
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void IndexBuffer::unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
