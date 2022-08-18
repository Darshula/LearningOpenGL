#ifndef LEARN_OPENGL_RENDERER_HPP
#define LEARN_OPENGL_RENDERER_HPP

#include "indexBuffer.hpp"
#include "shader.hpp"
#include "vertexArray.hpp"

class Renderer {
public:
  Renderer() = default;
  ~Renderer() = default;
  static void clear();
  static void draw(const VertexArray &var, const IndexBuffer &ibx,
                   const Shader &shader);

  Renderer(const Renderer &) = delete;
  Renderer &operator=(const Renderer &) = delete;
  Renderer(Renderer &&) = delete;
  Renderer &operator=(Renderer &&) = delete;
};

#endif // LEARN_OPENGL_RENDERER_HPP
