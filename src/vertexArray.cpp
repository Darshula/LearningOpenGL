#include "LearningOpenGL/vertexArray.hpp"
#include "LearningOpenGL/renderer.hpp"
#include "LearningOpenGL/vertexBufferLayout.hpp"

#include "GL/glew.h"

VertexArray::VertexArray() : m_RendererID(0)
{
  glGenVertexArrays(1, &m_RendererID);
}

VertexArray::~VertexArray() { glDeleteVertexArrays(1, &m_RendererID); }

void VertexArray::addBuffer(const VertexBuffer &vertexbuffer,
                            const VertexBufferLayout &layout) const
{
  bind();
  vertexbuffer.bind();
  const auto &elements{layout.getElements()};
  unsigned long long offset{};
  for (unsigned int i{0}; i < elements.size(); ++i) {
    const auto element{elements.at(i)};
    glEnableVertexAttribArray(i);
    glVertexAttribPointer(i, (signed)element.count, element.type,
                          element.normalized, (signed)layout.getStride(),
                          reinterpret_cast<void *>(offset));
    offset += static_cast<unsigned long long>(element.count) *
              VertexBufferElement::getTypeSize(element.type);
  }
}

void VertexArray::bind() const { glBindVertexArray(m_RendererID); }

void VertexArray::unbind() { glBindVertexArray(0); }
