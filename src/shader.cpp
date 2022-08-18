#include "LearningOpenGL/shader.hpp"
#include "LearningOpenGL/renderer.hpp"

#include "GL/glew.h"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>

Shader::Shader(std::string fileDirectory)
    : m_RendererID(0), m_FileDirectory(std::move(fileDirectory))
{
  ShaderProgramSource source = parseShader(m_FileDirectory);
  m_RendererID = createShader(source.vertexSource, source.fragmentSource);
}

Shader::~Shader() { glDeleteProgram(m_RendererID); }

ShaderProgramSource Shader::parseShader(const std::string &fileDirectory)
{
  std::string line;
  std::string vertexShader;
  std::string fragmentShader;

  for (const auto &dir : std::filesystem::directory_iterator(fileDirectory)) {
    if (dir.path().extension() == ".vert") {
      std::ifstream vertexStream{dir.path()};
      if (vertexStream.fail()) {
        std::cerr << "Failed to load vertex shader" << '\n';
      }
      while (std::getline(vertexStream, line)) {
        vertexShader.append(line + '\n');
      }
    }
    if (dir.path().extension() == ".frag") {
      std::ifstream fragmentStream{dir.path()};
      if (fragmentStream.fail()) {
        std::cerr << "Failed to load fragment shader" << '\n';
      }
      while (std::getline(fragmentStream, line)) {
        fragmentShader.append(line + '\n');
      }
    }
  }
  return {vertexShader, fragmentShader};
}

unsigned int Shader::compileShader(unsigned int type, const std::string &source)
{
  unsigned int shaderId{glCreateShader(type)};
  const char *src{source.c_str()};
  glShaderSource(shaderId, 1, &src, nullptr);
  glCompileShader(shaderId);
  int compilationResult{};
  glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compilationResult);
  if (compilationResult == GL_FALSE) {
    int length{};
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);
    char *message{static_cast<char *>(alloca(length * sizeof(char)))};
    glGetShaderInfoLog(shaderId, length, &length, message);

    std::cout << "Failed compiling ";
    if (type == GL_VERTEX_SHADER) {
      std::cout << "vertex";
    }
    else if (type == GL_FRAGMENT_SHADER) {
      std::cout << "fragment";
    }
    std::cout << " shader" << '\n' << "message: " << message << '\n';

    glDeleteShader(shaderId);
    return 0;
  }
  return shaderId;
}

unsigned int Shader::createShader(const std::string &vertexShader,
                                  const std::string &fragmentShader)
{
  unsigned int program{glCreateProgram()};
  unsigned int vShader{compileShader(GL_VERTEX_SHADER, vertexShader)};
  unsigned int fShader{compileShader(GL_FRAGMENT_SHADER, fragmentShader)};
  glAttachShader(program, vShader);
  glAttachShader(program, fShader);
  glLinkProgram(program);
  glValidateProgram(program);
  glDetachShader(program, vShader);
  glDetachShader(program, fShader);
  glDeleteShader(vShader);
  glDeleteShader(fShader);
  return program;
}

int Shader::getUniformLocation(const std::string &name)
{
  if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end()) {
    return m_UniformLocationCache.at(name);
  }
  int location{glGetUniformLocation(m_RendererID, name.c_str())};
  if (location == -1) {
    std::cout << "[WARNING]: uniform " << name << " doesn't exist" << '\n';
  }
  else {
    m_UniformLocationCache.insert({name, location});
  }
  return location;
}

void Shader::bind() const { glUseProgram(m_RendererID); }

void Shader::unbind() { glUseProgram(0); }

void Shader::setUniform1i(const std::string &name, int value)
{
  glUniform1i(getUniformLocation(name), value);
}

void Shader::setUniform1f(const std::string &name, float value)
{
  glUniform1f(getUniformLocation(name), value);
}

void Shader::setUniform4f(const std::string &name, float value0, float value1,
                          float value2, float value3)
{
  glUniform4f(getUniformLocation(name), value0, value1, value2, value3);
}

void Shader::setUniformMat4f(const std::string &name, const glm::mat4 &matrix)
{
  glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}
