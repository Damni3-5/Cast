project(main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

add_executable (main "main.cpp" ${SOURCES} ${HEADERS})

find_package(raylib CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
target_link_libraries(main PRIVATE raylib imgui::imgui)

find_package(Stb REQUIRED)
target_include_directories(main PRIVATE ${Stb_INCLUDE_DIR})

file(COPY assets/shaders/ DESTINATION ${CMAKE_BINARY_DIR}/shaders)
file(COPY assets/textures/ DESTINATION ${CMAKE_BINARY_DIR}/textures)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/textures DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

