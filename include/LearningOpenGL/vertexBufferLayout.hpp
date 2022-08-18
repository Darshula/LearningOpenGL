#ifndef LEARN_OPENGL_VERTEX_BUFFER_LAYOUT_HPP
#define LEARN_OPENGL_VERTEX_BUFFER_LAYOUT_HPP

#include <vector>

#define GL_TRUE 1
#define GL_FALSE 0
#define GL_UNSIGNED_BYTE 0x1401
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406

struct VertexBufferElement {
  unsigned int type;
  unsigned int count;
  unsigned char normalized;

  static unsigned int getTypeSize(unsigned int type)
  {
    switch (type) {
    case GL_FLOAT:
      return sizeof(float);
    case GL_UNSIGNED_INT:
      return sizeof(unsigned int);
    case GL_UNSIGNED_BYTE:
      return sizeof(unsigned char);
    }
    return 0;
  }
};

class VertexBufferLayout {
public:
  VertexBufferLayout() = default;
  ~VertexBufferLayout() = default;
  template <typename T> void push(unsigned int count);
  unsigned int getStride() const { return m_Stride; }
  const std::vector<VertexBufferElement> &getElements() const
  {
    return m_Elements;
  }

private:
  std::vector<VertexBufferElement> m_Elements;
  unsigned int m_Stride{};

public:
  VertexBufferLayout(const VertexBufferLayout &) = delete;
  VertexBufferLayout &operator=(const VertexBufferLayout &) = delete;
  VertexBufferLayout(VertexBufferLayout &&) = delete;
  VertexBufferLayout &operator=(VertexBufferLayout &&) = delete;
};

template <> inline void VertexBufferLayout::push<float>(unsigned int count)
{
  m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
  m_Stride += count * VertexBufferElement::getTypeSize(GL_FLOAT);
}

template <>
inline void VertexBufferLayout::push<unsigned int>(unsigned int count)
{
  m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
  m_Stride += count * VertexBufferElement::getTypeSize(GL_UNSIGNED_INT);
}

template <>
inline void VertexBufferLayout::push<unsigned char>(int unsigned count)
{
  m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
  m_Stride += count * VertexBufferElement::getTypeSize(GL_UNSIGNED_BYTE);
}

#endif // LEARN_OPENGL_VERTEX_BUFFER_LAYOUT_HPP
