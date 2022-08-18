set(sources
    src/indexBuffer.cpp
    src/renderer.cpp
    src/shader.cpp
    src/test.cpp
    src/testClearColor.cpp
    src/testTexture2D.cpp
    src/texture.cpp
    src/vertexArray.cpp
    src/vertexBuffer.cpp)

set(exe_sources src/application.cpp ${sources})

set(headers include/LearningOpenGL/indexBuffer.hpp
include/LearningOpenGL/renderer.hpp
include/LearningOpenGL/shader.hpp
include/LearningOpenGL/test.hpp
include/LearningOpenGL/testClearColor.hpp
include/LearningOpenGL/testTexture2D.hpp
include/LearningOpenGL/texture.hpp
include/LearningOpenGL/vertexArray.hpp
include/LearningOpenGL/vertexBuffer.hpp
include/LearningOpenGL/vertexBufferLayout.hpp)

set(test_sources)
