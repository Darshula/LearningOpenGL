#ifndef LEARN_OPENGL_TEST
#define LEARN_OPENGL_TEST

#include <functional>
#include <iostream>
#include <vector>

namespace test {

class Test {
public:
  Test() = default;
  virtual ~Test()= default;

  virtual void onUpdate(float deltaTime) {}
  virtual void onRender() {}
  virtual void onImGuiRender() {}

private:
public:
  Test(const Test &) = delete;
  Test &operator=(const Test &) = delete;
  Test(Test &&) = delete;
  Test &operator=(Test &&) = delete;
};

class TestMenu : public Test {
public:
  TestMenu(Test *&currentTestPointer);
  ~TestMenu() override = default;

  void onImGuiRender() override;

  template <typename T> void registerTest(const std::string &name)
  {
    m_Tests.push_back(std::make_pair(name, []() { return new T(); }));
    std::cout << "Registered test " << name << '\n';
  }

private:
  Test *&m_CurrentTest;
  std::vector<std::pair<std::string, std::function<Test *()>>> m_Tests;

public:
  TestMenu(const TestMenu &) = delete;
  TestMenu &operator=(const TestMenu &) = delete;
  TestMenu(TestMenu &&) = delete;
  TestMenu &operator=(TestMenu &&) = delete;
};

} // namespace test

#endif // LEARN_OPENGL_TEST
