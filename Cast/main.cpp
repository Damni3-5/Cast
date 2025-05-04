#include "src/Engine/Core/Application.h"

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main(int argc, char** argv)
{
    const int screenWidth = 1200, screenHeight = 600;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    std::cout << "ImGui Version: " << IMGUI_VERSION << std::endl;

    try // Все что в Scene. Сделать кастомные сценки.
    {
        glfwSetErrorCallback(glfw_error_callback);

        Application game(screenWidth, screenHeight);

        while (!glfwWindowShouldClose(Application::Get().GetWindow()))
        {
            game.Update();
            game.Render();
            game.HandleInput();

            //App app = App();
            //app.sceneManager.RegisterScene<HelloTriangleScene>("Hello Triangle");
            //app.sceneManager.RegisterScene<HelloTextureScene>("Hello Texture");
            //app.sceneManager.RegisterScene<Hello3DWorldScene>("Hello 3D World");
            //app.sceneManager.RegisterScene<HelloLightsScene>("Hello Lights");
            //app.StartRenderLoop();
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        exit(-1);
    }

    return 0;
}

