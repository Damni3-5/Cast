project(main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

add_executable (main "main.cpp" ${SOURCES} ${HEADERS})

find_package(raylib CONFIG REQUIRED)
target_link_libraries(main PRIVATE raylib)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(main PRIVATE raylib imgui::imgui)

find_package(Stb REQUIRED)
target_include_directories(main PRIVATE ${Stb_INCLUDE_DIR})

file(COPY shaders/ DESTINATION ${CMAKE_BINARY_DIR}/shaders)
file(COPY textures/ DESTINATION ${CMAKE_BINARY_DIR}/textures)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/textures DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET main PROPERTY CXX_STANDARD 20)
endif()