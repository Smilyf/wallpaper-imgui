
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <iostream>

#include <opencv2/opencv.hpp>
// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

namespace smily
{

    class Mat2Texture
    {
    public:
        GLuint texture;
        int width;
        int height;
        uchar *data;
        Mat2Texture() = default;
        Mat2Texture(std::string imgdir)
        {
            cv::Mat image;
            image = cv::imread(imgdir);
            // cv::cvtColor(image, image, cv::COLOR_RGB2BGRA);
            width = image.cols;
            height = image.rows;
            data = image.data;
            glGenTextures(1, &texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            // 为当前绑定的纹理对象设置环绕、过滤方式
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            // 加载并生成纹理
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        GLuint getId()
        {
            return texture;
        }
        ImVec2 getSzie()
        {
            return ImVec2(width, height);
        }
        ImVec2 getSzie(double scaling)
        {
            return ImVec2(width * scaling, height * scaling);
        }
        ~Mat2Texture()
        {
            glDeleteTextures(1, &texture);
        }
    };
    class Image
    {

    private:
        ImTextureID imTextureId;
        ImVec2 imageSize;

    public:
        Image(ImTextureID imTextureid, ImVec2 imagesize) : imTextureId(imTextureid), imageSize(imagesize)
        {
        }
        ImVec2 getImageSize()
        {
            return imageSize;
        }

        ImTextureID getImTextureID()
        {
            return imTextureId;
        }
    };
    class Div
    {
    private:
        std::string display = "flex";
        float windowWidth;
        float windowHeight;
        ImVec2 minSpace = {20.0, 20.0};
        ImVec2 ItemSpacing;
        ImVec2 WindowPadding = {0.0, 0.0};

    public:
        Div(std::string divName, bool *p_open, ImGuiWindowFlags window_flags = 0)
        {

            ImGui::Begin(divName.c_str(), p_open, window_flags); // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            windowWidth = ImGui::GetWindowWidth();
            windowHeight = ImGui::GetWindowHeight();
        }
        // void display(std::string x)
        // {
        //     display = x;
        // }
        void setDisplay(std::string x)
        {
            display = x;
        }
        void drawImage(std::vector<Image> Images)
        {

            auto fItemSpacing = ImGui::GetStyle().ItemSpacing;
            auto WindowPadding = ImGui::GetStyle().WindowPadding;
            if (display == "flex")
            {
                ImGui::GetStyle().WindowPadding = WindowPadding;

                ImVec2 imageSize;
                float windowswidth_ = windowWidth - WindowPadding.x * 2;
                float width = 0;
                bool flag = false;
                std::deque<smily::Image> deque_Images;
                for (auto i = 0; i < Images.size(); i++)
                {
                    auto image = Images[i];
                    
                    if (width +2+ image.getImageSize().x + std::max(1, (int)deque_Images.size() - 1) * minSpace.x <= windowswidth_)
                    {
                        
                        width += image.getImageSize().x + 2;
                        deque_Images.push_back(image);
                    }
                    else
                    {
                        // ImGui::Text("%d",deque_Images.size());
                        if (deque_Images.empty())
                        {
                            ImGui::GetStyle().ItemSpacing = ImVec2(0.0, minSpace.y);
                            ImGui::Image(image.getImTextureID(), image.getImageSize(), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
                        }
                        if (deque_Images.size() == 1)
                        {
                            ImGui::GetStyle().ItemSpacing = ImVec2(0.0, minSpace.y);
                            auto item = deque_Images.front();
                            deque_Images.pop_front();
                            ImGui::Image(item.getImTextureID(), item.getImageSize(), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
                            i--;
                        }
                        
                        if (deque_Images.size() > 1)
                        {
                            bool flag_ = false;
                            ImGui::GetStyle().ItemSpacing = ImVec2((windowswidth_ - width) / (deque_Images.size() - 1), minSpace.y);
                            int xxx=0;
                            
                            for (auto item : deque_Images)
                            {
                                if (!flag_)
                                {
                                    flag_ = true;
                                }
                                else
                                {
                                    xxx++;
                                    ImGui::SameLine();
                                }
                                ImGui::Image(item.getImTextureID(), item.getImageSize(), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
                            }
                            deque_Images.clear();
                            i--;
                        }
                        width = 0;
                    }
                }
                if (deque_Images.size() <= 1)
                {
                    ImGui::GetStyle().ItemSpacing = ImVec2(0.0, 10.0);
                }
                else
                {
                    ImGui::GetStyle().ItemSpacing = ImVec2((windowswidth_ - width) / (deque_Images.size() - 1), 10.0);
                }
                for (auto item : deque_Images)
                {
                    if (!flag)
                    {
                        flag = true;
                    }
                    else
                    {
                        ImGui::SameLine();
                    }
                    ImGui::Image(item.getImTextureID(), item.getImageSize(), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 255, 0, 1));
                }
                deque_Images.clear();
            }
            ImGui::Text("%f", windowWidth);
            ImGui::GetStyle().ItemSpacing = fItemSpacing;
            ImGui::GetStyle().WindowPadding = WindowPadding;
        }
        ~Div()
        {
            ImGui::End();
        }
    };

};

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

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
    // glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); // 设置 offscreen context 的标志位
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
    // build and compile our shader zprogram
    // 在上面配置初始化完成后再进行界面的引入
    // 创建imgui的上下文
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
    // io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // !!! 启用 docking 功能的支持
    // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // !!! 启用 viewport 功能的支持

    ImFont *font = io.Fonts->AddFontFromFileTTF("/home/kali-smily/openglim/Fonts/simhei.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
    // 设置样式
    ImGui::StyleColorsDark();
    // 设置平台和渲染器
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    smily::Mat2Texture mat2Texture("/home/kali-smily/openglim/2.jpg");
    GLuint textureIDS = mat2Texture.getId();

    ImTextureID textureID = reinterpret_cast<ImTextureID>(textureIDS);
    std::vector<smily::Image> Images;
    for (int i = 0; i < 8; i++)
    {
        Images.push_back({textureID, ImVec2(200.0, 100.0)});
    }
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    // render loop
    // -----------
    // Normalized coordinates of pixel (10,10) in a 256x256 texture.
    ImVec2 uv0 = ImVec2(10.0f / 256.0f, 10.0f / 256.0f);

    // Normalized coordinates of pixel (110,210) in a 256x256 texture.
    ImVec2 uv1 = ImVec2((10.0f + 100.0f) / 256.0f, (10.0f + 200.0f) / 256.0f);
    while (!glfwWindowShouldClose(window))
    {

        // input
        // -----
        processInput(window);
        glBindTexture(GL_TEXTURE_2D, textureIDS);
        // 使用imgui创建窗口
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        ImGui::NewFrame();

        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!"); // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");          // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window); // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);             // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float *)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("Button")) // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::End();
        }

        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGuiWindowFlags window_flags = 0;
            window_flags |= ImGuiWindowFlags_NoTitleBar;
            window_flags |= ImGuiWindowFlags_NoScrollbar;
            bool flag = true;
            smily::Div div("Another Window", &flag, window_flags);

            //div.drawImage(Images);
            // ImGui::Text("Hello from another window!");
            // ImGui::Text("width = %lf", ImGui::GetWindowWidth());

            // ImGui::Image(textureID, mat2Texture.getSzie(0.1), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
            // ImGui::SameLine();

            // ImGui::Image(textureID, mat2Texture.getSzie(0.1), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
            // ImGui::SameLine();
            // ImGui::Image(textureID, mat2Texture.getSzie(0.1), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
            // if (ImGui::Button("Close Me"))
            //     show_another_window = false;
        }

        // render
        // 通过imgui的颜色控制背景颜色
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

        // 渲染
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
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
