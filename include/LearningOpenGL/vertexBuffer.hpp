#ifndef LEARN_OPENGL_VERTEX_BUFFER_HPP
#define LEARN_OPENGL_VERTEX_BUFFER_HPP

class VertexBuffer {
public:
  VertexBuffer(const void *data, unsigned int size);
  ~VertexBuffer();
  void bind() const;
  static void unbind();

private:
  unsigned int m_RendererID;

public:
  VertexBuffer(const VertexBuffer &) = delete;
  VertexBuffer &operator=(const VertexBuffer &) = delete;
  VertexBuffer(VertexBuffer &&) = delete;
  VertexBuffer &operator=(VertexBuffer &&) = delete;
};

#endif // LEARN_OPENGL_VERTEX_BUFFER_HPP
