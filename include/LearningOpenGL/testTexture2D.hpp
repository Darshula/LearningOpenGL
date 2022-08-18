#ifndef LEARN_OPENGL_TEST_TEXTURE_2D
#define LEARN_OPENGL_TEST_TEXTURE_2D

#include "indexBuffer.hpp"
#include "texture.hpp"
#include "vertexArray.hpp"
#include "vertexBuffer.hpp"
#include "vertexBufferLayout.hpp"

#include "test.hpp"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <array>
#include <memory>

namespace test {
class TestTexture2D : public Test {
public:
  TestTexture2D();
  ~TestTexture2D() override;

  void onUpdate(float deltaTime) override;
  void onRender() override;
  void onImGuiRender() override;

private:
  std::unique_ptr<VertexArray> m_VertexArray;
  std::unique_ptr<VertexBuffer> m_VertexBuffer;
  std::unique_ptr<IndexBuffer> m_IndexBuffer;
  std::unique_ptr<Shader> m_Shader;
  std::unique_ptr<Texture> m_Texture;

  glm::mat4 m_Proj, m_View;

  glm::vec3 m_TranslationA, m_TranslationB;

public:
  TestTexture2D(const TestTexture2D &) = delete;
  TestTexture2D &operator=(const TestTexture2D &) = delete;
  TestTexture2D(TestTexture2D &&) = delete;
  TestTexture2D &operator=(TestTexture2D &&) = delete;
};
} // namespace test

#endif // LEARN_OPENGL_TEST_TEXTURE_2D
