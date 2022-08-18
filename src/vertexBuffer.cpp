#include "LearningOpenGL/vertexBuffer.hpp"
#include "LearningOpenGL/renderer.hpp"

#include "GL/glew.h"

VertexBuffer::VertexBuffer(const void *data, unsigned int size)
    : m_RendererID(0)
{
  glGenBuffers(1, &m_RendererID);
  glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() { glDeleteBuffers(1, &m_RendererID); }

void VertexBuffer::bind() const
{
  glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void VertexBuffer::unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }
