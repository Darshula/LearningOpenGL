#ifndef LEARN_OPENGL_VERTEX_ARRAY_HPP
#define LEARN_OPENGL_VERTEX_ARRAY_HPP

#include "vertexBuffer.hpp"
#include "vertexBufferLayout.hpp"

class VertexArray {
public:
  VertexArray();
  ~VertexArray();
  void addBuffer(const VertexBuffer &vertexbuffer,
                 const VertexBufferLayout &layout) const;
  void bind() const;
  static void unbind();

private:
  unsigned int m_RendererID;

public:
  VertexArray(const VertexArray &) = delete;
  VertexArray &operator=(const VertexArray &) = delete;
  VertexArray(VertexArray &&) = delete;
  VertexArray &operator=(VertexArray &&) = delete;
};

#endif // LEARN_OPENGL_VERTEX_ARRAY_HPP
