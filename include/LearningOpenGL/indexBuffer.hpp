#ifndef LEARN_OPENGL_INDEX_BUFFER_HPP
#define LEARN_OPENGL_INDEX_BUFFER_HPP

class IndexBuffer {
public:
  IndexBuffer(const unsigned int *data, unsigned int count);
  ~IndexBuffer();
  void bind() const;
  static void unbind();
  inline unsigned int getCount() const { return m_Count; }

private:
  unsigned int m_RendererID;
  unsigned int m_Count;

public:
  IndexBuffer(const IndexBuffer &) = delete;
  IndexBuffer &operator=(const IndexBuffer &) = delete;
  IndexBuffer(IndexBuffer &&) = delete;
  IndexBuffer &operator=(IndexBuffer &&) = delete;
};

#endif // LEARN_OPENGL_INDEX_BUFFER_HPP
