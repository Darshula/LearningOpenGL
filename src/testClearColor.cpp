#include "LearningOpenGL/renderer.hpp"

#include "LearningOpenGL/testClearColor.hpp"

#include "GL/glew.h"
#include "imgui.h"

namespace test {
TestClearColor::TestClearColor()
    : m_ClearColor{0.0F / RGB, 100.0F / RGB, 186.0F / RGB, 1.0F} // NOLINT
{
}

TestClearColor::~TestClearColor() = default;

void TestClearColor::onUpdate(float deltaTime) {}

void TestClearColor::onRender()
{
  glClearColor(m_ClearColor.at(0), m_ClearColor.at(1), m_ClearColor.at(2),
               m_ClearColor.at(3));
  glClear(GL_COLOR_BUFFER_BIT);
}

void TestClearColor::onImGuiRender()
{
  ImGui::ColorEdit4("Clear Color", &m_ClearColor.at(0));
}

} // namespace test
