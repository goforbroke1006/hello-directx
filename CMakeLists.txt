cmake_minimum_required(VERSION 2.8)
project(hello-directx)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} WIN32 main.cpp
        GraphicsEngine.cpp GraphicsEngine.h
        Scene.cpp Scene.h
        utils.h
        GameObject.cpp GameObject.h types.h Mesh.cpp Mesh.h Shader.cpp Shader.h)

target_link_libraries(${PROJECT_NAME} d3d9 d3d11 d3dcompiler)




configure_file(tests/CMakeLists.gtest.txt googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

set(CMAKE_LEGACY_CYGWIN_WIN32 0)
add_subdirectory(tests)