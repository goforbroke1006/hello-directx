cmake_minimum_required(VERSION 3.17)
project(hello-directx)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp
        GraphicsEngine.cpp GraphicsEngine.h
        Scene.cpp Scene.h
        utils.h
        GameObject.cpp GameObject.h types.h Mesh.cpp Mesh.h Shader.cpp Shader.h)

target_link_libraries(${PROJECT_NAME} d3d9 d3d11 d3dcompiler_43)
