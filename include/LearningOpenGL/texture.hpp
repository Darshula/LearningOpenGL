#ifndef LEARN_OPENGL_TEXTURE_HPP
#define LEARN_OPENGL_TEXTURE_HPP

#include "renderer.hpp"

#include <string>

class Texture {
public:
  Texture(std::string path);
  ~Texture();
  void bind(unsigned int slot = 0) const;
  static void unbind();
  int getWidth() const { return m_Width; }
  int getHeight() const { return m_Height; }

private:
  unsigned int m_RendererID;
  std::string m_Filepath;
  unsigned char *m_LocalBuffer;
  int m_Width;
  int m_Height;
  int m_BytesPerPixel;

public:
  Texture(const Texture &) = delete;
  Texture &operator=(const Texture &) = delete;
  Texture(Texture &&) = delete;
  Texture &operator=(Texture &&) = delete;
};

#endif // LEARN_OPENGL_TEXTURE_HPP
