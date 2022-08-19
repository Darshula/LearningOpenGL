#include "LearningOpenGL/renderer.hpp"
#include "LearningOpenGL/texture.hpp"

#include "LearningOpenGL/test.hpp"
#include "LearningOpenGL/testClearColor.hpp"
#include "LearningOpenGL/testTexture2D.hpp"

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <iostream>

int main(int /*argc*/, char ** /*argv*/)
{
  constexpr int width{1280};
  constexpr int height{720};

  GLFWwindow *window{nullptr};
  if (glfwInit() != GLFW_TRUE) {
    return -1;
  }
  window = glfwCreateWindow(width, height, "Hello World", nullptr, nullptr);
  if (window == nullptr) {
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  if (glewInit() != GLEW_OK) {
    return -1;
  }

  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  glfwSwapInterval(1);

  std::cout << "OpenGL renderer " << glGetString(GL_RENDERER) << '\n'
            << "OpenGL version " << glGetString(GL_VERSION) << '\n'
            << "GLSL version " << glGetString(GL_SHADING_LANGUAGE_VERSION)
            << '\n';

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init(reinterpret_cast<const char *>(
      glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS)));
  ImGui::StyleColorsDark();

  test::Test *currentTest{nullptr};
  auto *testMenu = new test::TestMenu(currentTest);
  currentTest = testMenu;

  testMenu->registerTest<test::TestClearColor>("Clear Color");
  testMenu->registerTest<test::TestTexture2D>("2D Texture");

  while (glfwWindowShouldClose(window) == GLFW_FALSE) {
    glClearColor(0.0F, 0.0F, 0.0F, 1.0F);
    Renderer::clear();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if (currentTest != nullptr) {
      currentTest->onUpdate(0.0F);
      currentTest->onRender();
      ImGui::Begin("Tests Window");
      ImGui::Text("%.1f FPS", ImGui::GetIO().Framerate);
      if (currentTest != testMenu && ImGui::Button("<- Back")) {
        delete currentTest;
        currentTest = testMenu;
      }
      currentTest->onImGuiRender();
      ImGui::End();
    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  if (currentTest != testMenu) {
    delete testMenu;
  }
  delete currentTest;

  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
