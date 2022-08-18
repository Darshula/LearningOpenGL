#include "LearningOpenGL/renderer.hpp"
#include "LearningOpenGL/indexBuffer.hpp"

#include "GL/glew.h"

#include <iostream>

void Renderer::clear() { glClear(GL_COLOR_BUFFER_BIT); }

void Renderer::draw(const VertexArray &var, const IndexBuffer &ibx,
                    const Shader &shader)
{

  shader.bind();
  var.bind();
  glDrawElements(GL_TRIANGLES, (signed)ibx.getCount(), GL_UNSIGNED_INT, nullptr);
}
