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
// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

std::atomic<bool> data_ready(true);
namespace smily
{

    class joining_thread
    {
        std::thread t;

    public:
        joining_thread() noexcept = default;
        template <typename Callable, typename... Args>
        explicit joining_thread(Callable &&func, Args &&...args) : t(std::forward<Callable>(func), std::forward<Args>(args)...)
        {
        }
        explicit joining_thread(std::thread t_) noexcept : t(std::move(t_))
        {
        }
        joining_thread(joining_thread &&other) noexcept : t(std::move(other.t))
        {
        }
        joining_thread &operator=(joining_thread &&other) noexcept
        {

            if (joinable())
            {
                join();
            }
            t = std::move(other.t);
            return *this;
        }

        ~joining_thread() noexcept
        {
            if (joinable())
                join();
        }
        void swap(joining_thread &other) noexcept
        {
            t.swap(other.t);
        }
        std::thread::id get_id() const noexcept
        {
            return t.get_id();
        }
        bool joinable() const noexcept
        {
            return t.joinable();
        }
        void join()
        {
            t.join();
        }
        void detach()
        {
            t.detach();
        }
        std::thread &as_thread() noexcept
        {
            return t;
        }
        const std::thread &as_thread() const noexcept
        {
            return t;
        }
    };

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

            return ImVec2((float)width, (float)height);
        }
        ImVec2 getSzie(float scaling)
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
    class Button
    {

    private:
        ImVec2 buttonSize;
        std::string label;

    public:
        Button() = default;
        Button(std::string label, ImVec2 size) : label(label), buttonSize(size)
        {
        }
        ImVec2 getButtonSize()
        {
            return buttonSize;
        }
        const char *getButtonLabel()
        {
            return label.c_str();
        }

        ~Button() = default;
    };
    class Div
    {
    private:
        std::string display = "flex";
        float windowWidth;
        float windowHeight;
        ImVec2 minSpace = {20.0, 20.0};
        ImVec2 WindowPadding = {0.0, 0.0};

    public:
        Div(std::string divName, bool *p_open, ImGuiWindowFlags window_flags = 0)
        {

            ImGui::Begin(divName.c_str(), p_open, window_flags); // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            windowWidth = ImGui::GetWindowWidth();
            windowHeight = ImGui::GetWindowHeight();
        }

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

                ImVec2 ItemSpacing;
                float windowswidth_ = windowWidth - WindowPadding.x * 2;
                float width = 0;
                bool flag = false;
                std::deque<smily::Image> deque_Images;
                for (size_t i = 0; i < Images.size(); i++)
                {
                    auto image = Images[i];

                    if (width + 2 + image.getImageSize().x + std::max(1, (int)deque_Images.size() - 1) * minSpace.x <= windowswidth_)
                    {

                        width += image.getImageSize().x + 2;
                        deque_Images.push_back(image);
                    }
                    else
                    {
                        // ImGui::Text("%d",deque_Images.size());
                        if (deque_Images.empty())
                        {
                            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0, minSpace.y));
                            ItemSpacing = ImVec2(0.0, minSpace.y);
                            ImGui::Image(image.getImTextureID(), image.getImageSize(), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
                            ImGui::PopStyleVar();
                        }
                        if (deque_Images.size() == 1)
                        {
                            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2((windowswidth_ - width) / 2, minSpace.y));
                            ItemSpacing = ImVec2((windowswidth_ - width) / 2, minSpace.y);
                            auto item = deque_Images.front();
                            deque_Images.pop_front();
                            ImGui::Image(item.getImTextureID(), item.getImageSize(), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
                            i--;
                            ImGui::PopStyleVar();
                        }

                        if (deque_Images.size() > 1)
                        {
                            bool flag_ = false;
                            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2((windowswidth_ - width) / (deque_Images.size() - 1), minSpace.y));
                            ItemSpacing = ImVec2((windowswidth_ - width) / (deque_Images.size() - 1), minSpace.y);

                            for (auto item : deque_Images)
                            {
                                if (!flag_)
                                {
                                    flag_ = true;
                                }
                                else
                                {

                                    ImGui::SameLine();
                                }
                                ImGui::Image(item.getImTextureID(), item.getImageSize(), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
                                ImGui::SetItemDefaultFocus();
                            }
                            deque_Images.clear();
                            i--;
                            ImGui::PopStyleVar();
                        }
                        width = 0;
                    }
                }
                if (deque_Images.size() <= 1)
                {
                    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0, 10.0));
                }
                else if (deque_Images.size() == Images.size())
                {
                    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2((windowswidth_ - width) / (deque_Images.size() - 1), minSpace.y));
                }
                else
                {

                    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ItemSpacing);
                    // ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2((windowswidth_ - width) / (deque_Images.size() - 1), 10.0));
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
                    ImGui::Image(item.getImTextureID(), item.getImageSize(), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
                }
                deque_Images.clear();
                ImGui::PopStyleVar();
            }
        }

        void drawButton(std::vector<Button> Buttons)
        {

            auto fItemSpacing = ImGui::GetStyle().ItemSpacing;
            auto WindowPadding = ImGui::GetStyle().WindowPadding;
            if (display == "flex")
            {
                ImVec2 ItemSpacing = {0.0, 0.0};
                float windowswidth_ = windowWidth - WindowPadding.x * 2;
                float width = 0;
                bool flag = false;
                std::deque<smily::Button> dequeButtons;

                for (size_t i = 0; i < Buttons.size(); i++)
                {
                    auto button = Buttons[i];

                    if (width + 2 + button.getButtonSize().x + std::max(1, (int)dequeButtons.size() - 1) * minSpace.x <= windowswidth_)
                    {

                        width += button.getButtonSize().x;
                        dequeButtons.push_back(button);
                    }
                    else
                    {

                        if (dequeButtons.empty())
                        {
                            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0, minSpace.y));
                            ItemSpacing = ImVec2(0.0, minSpace.y);
                            ImGui::Button(button.getButtonLabel(), button.getButtonSize());
                            ImGui::PopStyleVar();
                        }
                        if (dequeButtons.size() == 1)
                        {
                            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2((windowswidth_ - width) / 2, minSpace.y));
                            ItemSpacing = ImVec2((windowswidth_ - width) / 2, minSpace.y);

                            auto item = dequeButtons.front();
                            dequeButtons.pop_front();

                            ImGui::Button(item.getButtonLabel(), item.getButtonSize());
                            i--;
                            ImGui::PopStyleVar();
                        }

                        if (dequeButtons.size() > 1)
                        {
                            bool flag_ = false;
                            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2((windowswidth_ - width) / (dequeButtons.size() - 1), minSpace.y));
                            ItemSpacing = ImVec2((windowswidth_ - width) / (dequeButtons.size() - 1), minSpace.y);

                            for (auto item : dequeButtons)
                            {
                                if (!flag_)
                                {
                                    flag_ = true;
                                }
                                else
                                {

                                    ImGui::SameLine();
                                }
                                ImGui::Button(item.getButtonLabel(), item.getButtonSize());
                                ImGui::SetItemDefaultFocus();
                            }
                            dequeButtons.clear();
                            i--;
                            ImGui::PopStyleVar();
                        }
                        width = 0;
                    }
                }
                if (dequeButtons.size() <= 1)
                {
                    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0, 10.0));
                }
                else if (dequeButtons.size() == Buttons.size())
                {
                    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2((windowswidth_ - width) / (dequeButtons.size() - 1), minSpace.y));
                }
                else
                {

                    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ItemSpacing);
                    // ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2((windowswidth_ - width) / (dequeButtons.size() - 1), 10.0));
                }
                for (auto item : dequeButtons)
                {
                    if (!flag)
                    {
                        flag = true;
                    }
                    else
                    {
                        ImGui::SameLine();
                    }
                    ImGui::Button(item.getButtonLabel(), item.getButtonSize());
                }
                dequeButtons.clear();
                ImGui::PopStyleVar();
            }
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
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;
void fun(GLFWwindow *window)
{

    while (1)
    {
        ImGuiIO &io = ImGui::GetIO();
        int width, height;
        bool flag = false;
        glfwGetWindowSize(window, &width, &height);
        if (io.MousePos.x - 10 < 0 || io.MousePos.y - 10 < 0 || io.MousePos.x > width + 10 || io.MousePos.y > height + 10)
        {
            flag = true;
        }
        if (!ImGui::IsMousePosValid())
        {
            flag = true;
        }
        if (flag)
        {
            if (io.Framerate > 30.0)
            {
                data_ready = false;
            }
            // std::this_thread::sleep_for(std::chrono::duration<long long, std::ratio<1, 1000>>(20));
        }
        if (glfwWindowShouldClose(window))
        {
            break;
        }
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
    glfwSwapInterval(1);
    // build and compile our shader zprogram
    // 在上面配置初始化完成后再进行界面的引入
    // 创建imgui的上下文
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
      io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // !!! 启用 docking 功能的支持
      io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // !!! 启用 viewport 功能的支持
                                                          // ImFont *font = io.Fonts->AddFontFromFileTTF("C:\\Users\\yam_l\\wallpaper-imgui\\Fonts\\noto\\NotoSerifCJK-Bold.ttc", 18.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    // ImFont *font = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\simhei.ttf", 20.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
    smily::joining_thread tt{[](){ ImFont *font = ImGui::GetIO().Fonts->AddFontFromFileTTF("../../Fonts/noto/NotoSansCJKsc-Regular.otf", 25.0f, NULL, ImGui::GetIO().Fonts->GetGlyphRangesChineseFull());}};
    tt.join();
    //  设置样式
    //  ImGui::StyleColorsDark();
    io.FontGlobalScale = 2;
    ImGui::StyleColorsClassic();
    // 设置平台和渲染器
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    // cv::Mat img;
    // // 读取图像
    // img = cv::imread("C:\\Users\\yam_l\\wallpaper-imgui\\2.jpg", 1); // 1-RGB、0-gray
    // // 创建一个名为 "beautiful"窗口
    // cv::namedWindow("beautiful");
    // // 在窗口中显示“beautiful”窗口
    // cv::imshow("beautiful", img);
    // // 等待6000 ms后窗口自动关闭
    // cv::waitKey(6000);
    // // destroyAllWindows();
    // // destroyWindow("beautiful");

    // std::future<GLuint> the_answer = std::async([]()
    //                                             {
    //     smily::Mat2Texture mat2Texture("C:\\Users\\yam_l\\wallpaper-imgui\\2.jpg");
    //     return mat2Texture.getId(); }
    //                                             );
    // GLuint textureIDS = the_answer.get();
    smily::Mat2Texture mat2Texture("C:\\Users\\yam_l\\wallpaper-imgui\\wallpaper-imgui\\2.jpg");
    GLuint textureIDS = mat2Texture.getId();

    std::byte a[sizeof(ImTextureID) > sizeof(GLuint) ? sizeof(ImTextureID) : sizeof(GLuint)]{};
    memcpy(a, &textureIDS, sizeof(textureIDS));

    ImTextureID textureID;
    memcpy(&textureID, a, sizeof(textureID));
    std::vector<smily::Image> Images;
    for (int i = 0; i < 7; i++)
    {
        Images.push_back({textureID, ImVec2(200.0, 100.0)});
    }
    std::vector<smily::Button> buttons;
    for (int i = 0; i < 7; i++)
    {
        buttons.push_back({"按钮", ImVec2(200.0, 100.0)});
    }
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(1.0f, 1.0f, 1.0f, 1.00f);
    // render loop
    // -----------
    // Normalized coordinates of pixel (10,10) in a 256x256 texture.
    ImVec2 uv0 = ImVec2(10.0f / 256.0f, 10.0f / 256.0f);

    // Normalized coordinates of pixel (110,210) in a 256x256 texture.
    ImVec2 uv1 = ImVec2((10.0f + 100.0f) / 256.0f, (10.0f + 200.0f) / 256.0f);
    smily::joining_thread t{fun, window};
    while (!glfwWindowShouldClose(window))
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

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("你好世界"); // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");          // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window); // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);
            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);             // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float *)&clear_color); // Edit 3 floats representing a color
            if (ImGui::Button("Button"))                             // Buttons return true when clicked (most widgets return true when edited/activated)
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
            div.drawImage(Images);
            div.drawButton(buttons);
            ImGui::Text("Hello from another window!");
            ImGui::Text("width = %lf", ImGui::GetWindowWidth());

            // ImGui::Image(textureID, mat2Texture.getSzie(0.1), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
            // ImGui::SameLine();

            // ImGui::Image(textureID, mat2Texture.getSzie(0.1), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
            // ImGui::SameLine();
            // ImGui::Image(textureID, mat2Texture.getSzie(0.1), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
            if (ImGui::Button("Close Me"))
                show_another_window = false;
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

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (!data_ready)
        {
            std::this_thread::sleep_for(std::chrono::duration<long long, std::ratio<1, 1000>>(20));
            data_ready = true;
        }
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


