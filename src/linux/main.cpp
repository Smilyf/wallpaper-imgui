#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <opencv2/opencv.hpp>
#include <future>
#include <iostream>
#include <thread>
#include <chrono>

#include <smily/smily.h>
// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;
struct Funcs
{
    static int MyResizeCallback(ImGuiInputTextCallbackData *data)
    {
        if (data->EventFlag == ImGuiInputTextFlags_CallbackResize)
        {

            ImVector<char> *my_str = (ImVector<char> *)data->UserData;
            IM_ASSERT(my_str->begin() == data->Buf);
            my_str->resize(data->BufSize); // NB: On resizing calls, generally data->BufSize == data->BufTextLen + 1
            data->Buf = my_str->begin();
        }
        return 0;
    }

    // Note: Because ImGui:: is a namespace you would typically add your own function into the namespace.
    // For example, you code may declare a function 'ImGui::InputText(const char* label, MyString* my_str)'
    static bool MyInputTextMultiline(const char *label, ImVector<char> *my_str, const ImVec2 &size = ImVec2(0, 0), ImGuiInputTextFlags flags = 0)
    {
        IM_ASSERT((flags & ImGuiInputTextFlags_CallbackResize) == 0);
        return ImGui::InputTextMultiline(label, my_str->begin(), (size_t)my_str->size(), size, flags | ImGuiInputTextFlags_CallbackResize, Funcs::MyResizeCallback, (void *)my_str);
    }
};

void drawTriangle(ImDrawList *draw_list, ImVec2 p1, ImVec2 p2, ImVec2 p3, ImU32 color)
{
    draw_list->AddTriangle(p1, p2, p3, color);
}
void CenteredText(const char *text)
{
    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize(text).x) / 2.0f);
    ImGui::SetCursorPosY((ImGui::GetWindowHeight() - ImGui::GetFontSize()) / 2.0f);
    ImGui::Text(text);
}

void drawImGuiCanvas(ImTextureID textureID)
{
    // 创建新的 ImDrawList 对象以在画布上进行绘制
    ImDrawList *draw_list = ImGui::GetWindowDrawList();
    // ImGui::Image((void *)(intptr_t)(textureID), t);
    //  为画布绘制白色背景
    draw_list->AddRectFilled(ImGui::GetWindowPos(), ImVec2(ImGui::GetWindowPos().x + ImGui::GetWindowWidth(), ImGui::GetWindowPos().y + ImGui::GetWindowHeight()), IM_COL32_WHITE);
    // draw_list->AddRectFilled(ImGui::GetWindowPos(), ImVec2(ImGui::GetWindowPos().x+ImGui::GetWindowWidth(), ImGui::GetWindowPos().y+ImGui::GetWindowHeight()), IM_COL32_WHITE);

    draw_list->AddImage(
        textureID,
        ImGui::GetWindowPos(),
        ImVec2(ImGui::GetWindowPos().x + ImGui::GetWindowWidth(), ImGui::GetWindowPos().y + ImGui::GetWindowHeight()),
        ImVec2(0, 0),
        ImVec2(1, 1),
        ImColor(255, 255, 255, 255));
    // 使用 ImDrawList 绘制红色三角形
    // drawTriangle(draw_list, ImGui::GetWindowPos(), ImVec2(ImGui::GetWindowPos().x+100, ImGui::GetWindowPos().y+150), ImVec2(ImGui::GetWindowPos().x+250, ImGui::GetWindowPos().y+50), IM_COL32_BLACK);
}
bool drawing_line = true;
ImVec2 start_point;
ImVec2 end_point;
std::vector<std::pair<ImVec2, ImVec2>> lines;
void drawLines(ImDrawList *draw_list)
{
    for (const auto &line : lines)
    {
        draw_list->AddLine(line.first, line.second, IM_COL32_BLACK);
    }

    if (drawing_line)
    {
        draw_list->AddLine(start_point, end_point, IM_COL32_BLACK);
    }
}

void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        // 开始绘制新的线段
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        start_point = {static_cast<float>(x), static_cast<float>(y)};
        end_point = {static_cast<float>(x), static_cast<float>(y)};
        drawing_line = true;
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        // 添加完成的线段到线段列表中
        lines.push_back({start_point, end_point});
        drawing_line = false;
    }
}

void cursorPosCallback(GLFWwindow *window, double xpos, double ypos)
{
    if (drawing_line)
    {
        end_point = {static_cast<float>(xpos), static_cast<float>(ypos)};
    }
}

int main()
{
    // 设置330版本给imgui使用
    const char *glsl_version = "#version 330";
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); // 设置 offscreen context 的标志位
    //  glfw window creation
    //  --------------------
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
    glfwSwapInterval(1);
    // build and compile our shader zprogram
    // 在上面配置初始化完成后再进行界面的引入
    // 创建imgui的上下文
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // !!! 启用 docking 功能的支持
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;   // !!! 启用 viewport 功能的支持
    //                                                       // ImFont *font = io.Fonts->AddFontFromFileTTF("C:\\Users\\yam_l\\wallpaper-imgui\\Fonts\\noto\\NotoSerifCJK-Bold.ttc", 18.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
    // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    // ImFont *font = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\simhei.ttf", 20.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
    ImFont *font = ImGui::GetIO().Fonts->AddFontFromFileTTF("../../Fonts/noto/NotoSansCJKsc-Regular.otf", 60.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
    //  设置样式
    //  ImGui::StyleColorsDark();
    // io.FontGlobalScale = 1;

    ImGui::StyleColorsLight();
    // 设置平台和渲染器
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(1.0f, 1.0f, 1.0f, 1.00f);
    bool close = true;
    ImVector<char> my_str;
    if (my_str.empty())
        my_str.push_back(0);

    std::vector<smily::Image> Images;
    smily::Mat2Texture img("C:\\Users\\yam_l\\Pictures\\Saved Pictures\\wallhaven-jx17ym.png");
    auto textureID = img.getId();

    smily::Image xxx((void *)(intptr_t)(textureID), img.getSzie());
    Images.push_back(xxx);
    float ff = 0.5;

    while (!glfwWindowShouldClose(window) && close)
    {

        // input
        // -----
        processInput(window);
        // glBindTexture(GL_TEXTURE_2D, textureIDS);
        // 使用imgui创建窗口
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 5.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_TabRounding, 5.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_GrabRounding, 5.0f);
        ImGui::NewFrame();

        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);
        // 在ImGui窗口中显示居中的文本
        ImGui::Begin("Centered Text Window");
        CenteredText("Hello, world!");
        ImGui::End();
        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
        {
            ImGuiWindowFlags window_flags = 0;
            // window_flags |= ImGuiWindowFlags_NoTitleBar;
            // window_flags |= ImGuiWindowFlags_NoScrollbar;
            // window_flags |= ImGuiTableFlags_SizingFixedSame;

            window_flags |= ImGuiWindowFlags_HorizontalScrollbar;
            static float fppp = 0.0f;
            static int counter = 0;

            ImGui::Begin("你好世界", &close, window_flags); // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");          // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window); // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);
            ImGui::SliderFloat("float", &fppp, 0.0f, 1.0f);          // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float *)&clear_color); // Edit 3 floats representing a color
            if (ImGui::Button("Button"))                             // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();

            ImGui::Text("counter = %d", counter);
            ImGui::SliderFloat("float", &ff, 0.0f, 1.0f);
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImVec2 t{img.getSzie().x * ff, img.getSzie().y * ff};

            ImGui::Image((void *)(intptr_t)(textureID), t);

            ImGui::End();
        }
        if (show_another_window)
        {
            ImGuiWindowFlags window_flags = 0;
            // window_flags |= ImGuiWindowFlags_NoTitleBar;
            // window_flags |= ImGuiWindowFlags_NoScrollbar;
            // window_flags |= ImGuiTableFlags_SizingFixedSame;

            window_flags |= ImGuiWindowFlags_HorizontalScrollbar;
            ImGui::Begin("Another Window", &show_another_window, window_flags); // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            // static char str1[128] = "";
            // ImDrawList *draw_list = ImGui::GetWindowDrawList();
            // drawLines(draw_list);
            // ImGui::InputTextWithHint("input text (w/ hint)", "enter text here", str1, IM_ARRAYSIZE(str1));
            // Funcs::MyInputTextMultiline("##MyStr", &my_str);
            // ImGui::Text("宽度%f", ImGui::GetWindowWidth());
            if (ImGui::Button("Close Me"))
                show_another_window = false;

            drawImGuiCanvas(window);
            // bool flag = true;
            // smily::Div div("Another Window", &flag, window_flags);
            // div.drawImage(Images);

            // ImDrawList* drawList = ImGui::GetWindowDrawList();
            //    drawList->AddImage((void*)(intptr_t)texture, ImVec2(ImGui::GetCursorScreenPos()), ImVec2(ImGui::GetCursorScreenPos().x + imageSize.x, ImGui::GetCursorScreenPos().y + imageSize.y), ImVec2(0, 1), ImVec2(1, 0));
            // div.drawButton(buttons);
            ImGui::End();
        }

        // render
        // 通过imgui的颜色控制背景颜色
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!
        ImGui::PopStyleVar(4);
        // 渲染
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// huafen midu cengce
