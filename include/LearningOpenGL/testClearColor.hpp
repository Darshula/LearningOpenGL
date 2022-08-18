#ifndef LEARN_OPENGL_TEST_CLEAR_COLOR
#define LEARN_OPENGL_TEST_CLEAR_COLOR

#include "test.hpp"

#include <array>

namespace test {
class TestClearColor : public Test {
public:
  TestClearColor();
  ~TestClearColor() override;

  void onUpdate(float deltaTime) override;
  void onRender() override;
  void onImGuiRender() override;

private:
  const float RGB{255.0F};
  std::array<float, 4> m_ClearColor;

public:
  TestClearColor(const TestClearColor &) = delete;
  TestClearColor &operator=(const TestClearColor &) = delete;
  TestClearColor(TestClearColor &&) = delete;
  TestClearColor &operator=(TestClearColor &&) = delete;
};
} // namespace test

#endif // LEARN_OPENGL_TEST_CLEAR_COLOR
