#include "LearningOpenGL/texture.hpp"
#include "LearningOpenGL/renderer.hpp"

#include "GL/glew.h"
#include "stb/stb_image.h"

#include <iostream>

Texture::Texture(std::string path)
    : m_RendererID(0), m_Filepath(std::move(path)), m_LocalBuffer(nullptr),
      m_Width(0), m_Height(0), m_BytesPerPixel(0)
{
  stbi_set_flip_vertically_on_load(1);
  m_LocalBuffer =
      stbi_load(m_Filepath.c_str(), &m_Width, &m_Height, &m_BytesPerPixel, 4);

  glGenTextures(1, &m_RendererID);
  glBindTexture(GL_TEXTURE_2D, m_RendererID);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA,
               GL_UNSIGNED_BYTE, m_LocalBuffer);
  glBindTexture(GL_TEXTURE_2D, 0);

  if (m_LocalBuffer != nullptr) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, m_LocalBuffer);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(m_LocalBuffer);
  }
  else {
    std::cout << "[ERROR]: Failed to load texture- ";
    std::cout << stbi_failure_reason() << '\n';
    __debugbreak();
  }
}

Texture::~Texture() { glDeleteTextures(1, &m_RendererID); }

void Texture::bind(unsigned int slot /*= 0*/) const
{
  glActiveTexture(GL_TEXTURE0 + slot);
  glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

void Texture::unbind() { glBindTexture(GL_TEXTURE_2D, 0); }
