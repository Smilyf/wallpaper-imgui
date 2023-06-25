
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
<<<<<<< HEAD

#include <iostream>

#include <opencv2/opencv.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
using namespace cv;

=======
 
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


#include <opencv2/highgui/highgui_c.h>
using namespace cv;
>>>>>>> origin/main
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
<<<<<<< HEAD
GLuint Mat2Texture(std::string imgdir)
{

    cv::Mat image;
    image = imread(imgdir);
    // cv::cvtColor(image, image, cv::COLOR_RGB2BGRA);
    auto width = image.cols;
    auto height = image.rows;
    auto data = image.data;
    if (image.empty())
    {
        std::cout << "image is empty! " << std::endl;
        return -1;
    }
    else
    {

        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        // 为当前绑定的纹理对象设置环绕、过滤方式
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // 加载并生成纹理
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        return texture;
    }

    // unsigned int texture;
    // glGenTextures(1, &texture);
    // glBindTexture(GL_TEXTURE_2D, texture);
    // // 为当前绑定的纹理对象设置环绕、过滤方式
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // // 加载并生成纹理
    // int width, height, nrChannels;
    // unsigned char *data = stbi_load(imgdir.c_str(), &width, &height, &nrChannels, 0);
    // if (data)
    // {
    //      //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    //     // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    //     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    //     glGenerateMipmap(GL_TEXTURE_2D);
    // }
    // else
    // {
    //     std::cout << "Failed to load texture" << std::endl;
    // }
    // stbi_image_free(data);
    // return texture;
}
int main()
{
    // 设置330版本给imgui使用
    const char *glsl_version = "#version 330";
=======

int main()
{

>>>>>>> origin/main
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
<<<<<<< HEAD
    glfwWindowHint(GLFW_SAMPLES, 4);
=======

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

>>>>>>> origin/main
    // glfw window creation
    // --------------------
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

<<<<<<< HEAD
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
    ImFont *font = io.Fonts->AddFontFromFileTTF("/home/kali-smily/openglim/Fonts/simhei.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
    // 设置样式
    ImGui::StyleColorsDark();
    // 设置平台和渲染器
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    Shader ourShader("/home/kali-smily/openglim/src/linux/shaders/fragment.txt", "/home/kali-smily/openglim/src/linux/shaders/vertex.txt");
=======
    // build and compile our shader zprogram
    // ------------------------------------
    Shader ourShader("/home/kali-smily/openglim/src/linux/shaders/text.vs", "/home/kali-smily/openglim/src/linux/shaders/text.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
>>>>>>> origin/main
    float vertices[] = {
        // positions          // colors           // texture coords
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
    };
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
<<<<<<< HEAD

    GLuint textureIDS = Mat2Texture("/home/kali-smily/openglim/2.jpg");
    ImTextureID textureID = reinterpret_cast<ImTextureID>(textureIDS);

      bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
=======
    Mat mat1 = imread("/home/kali-smily/openglim/1.jpg");

    // load and create a texture
    // -------------------------
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    // unsigned char *data = stbi_load("/home/kali-smily/openglim/1.jpg", &width, &height, &nrChannels, 0);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mat1.cols, mat1.rows, 0, 0x80E0, GL_UNSIGNED_BYTE, mat1.data); // GL_BGR_EXT

    glGenerateMipmap(GL_TEXTURE_2D);



>>>>>>> origin/main
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
<<<<<<< HEAD

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
            ImGui::Begin("Another Window", &show_another_window); // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
             ImGui::Image(textureID, ImGui::GetContentRegionAvail(), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

        // render
        // 通过imgui的颜色控制背景颜色
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!
=======
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // bind Texture
        glBindTexture(GL_TEXTURE_2D, texture);
>>>>>>> origin/main

        // render container
        ourShader.use();
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
<<<<<<< HEAD
        // 渲染
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
=======

>>>>>>> origin/main
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
<<<<<<< HEAD

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glfwTerminate();
=======
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();

>>>>>>> origin/main
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
<<<<<<< HEAD
}





















#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
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
        float width;
        float height;
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
            glGenTextures(1, 0);
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
                for (auto i = 0; i < Images.size(); i++)
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
                ImVec2 ItemSpacing;
                float windowswidth_ = windowWidth - WindowPadding.x * 2;
                float width = 0;
                bool flag = false;
                std::deque<smily::Button> dequeButtons;
               
                
                for (auto i = 0; i < Buttons.size(); i++)
                {
                    auto button = Buttons[i];

                    if (width + 2 + button.getButtonSize().x + std::max(1, (int)dequeButtons.size() - 1) * minSpace.x <= windowswidth_)
                    {

                        width += button.getButtonSize().x + 2;
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
    // io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // !!! 启用 docking 功能的支持
    // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // !!! 启用 viewport 功能的支持
    //ImFont *font = io.Fonts->AddFontFromFileTTF("Fonts\\noto\\NotoSansCJK-Regular.ttc", 60.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
    ImFont *font = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\simhei.ttf", 20.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
    // 设置样式
    // ImGui::StyleColorsDark();
    io.FontGlobalScale=2;
    ImGui::StyleColorsClassic();
    // 设置平台和渲染器
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // smily::Mat2Texture mat2Texture("C:\\Users\\yam_l\\wallpaper-imgui\\2.jpg");
    // GLuint textureIDS = mat2Texture.getId();

    // std::byte a[sizeof(ImTextureID) > sizeof(GLuint) ? sizeof(ImTextureID) : sizeof(GLuint)]{};
    // memcpy(a, &textureIDS, sizeof(textureIDS));

    // ImTextureID textureID;
    // memcpy(&textureID, a, sizeof(textureID));
    // std::vector<smily::Image> Images;
    // for (int i = 0; i < 7; i++)
    // {
    //     Images.push_back({textureID, ImVec2(200.0, 100.0)});
    // }
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
            //div.drawImage(Images);
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

        // 渲染
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
        ImGui::PopStyleVar(4);
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





#include <imgui.h>
#include "imgui_impl_win32.h"
#include "imgui_impl_dx12.h"
#include <d3d12.h>
#include <dxgi1_4.h>
#include <tchar.h>

#include <future>
#include <iostream>
#include <thread>
#include <chrono>
#include <deque>
#ifdef _DEBUG
#define DX12_ENABLE_DEBUG_LAYER
#endif

#ifdef DX12_ENABLE_DEBUG_LAYER
#include <dxgidebug.h>
#pragma comment(lib, "dxguid.lib")
#endif

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

    // class Mat2Texture
    // {
    // public:
    //     GLuint texture;
    //     int width;
    //     int height;
    //     uchar *data;
    //     Mat2Texture() = default;
    //     Mat2Texture(std::string imgdir)
    //     {
    //         cv::Mat image;
    //         image = cv::imread(imgdir);
    //         // cv::cvtColor(image, image, cv::COLOR_RGB2BGRA);
    //         width = image.cols;
    //         height = image.rows;
    //         data = image.data;
    //         glGenTextures(1, &texture);
    //         glBindTexture(GL_TEXTURE_2D, texture);
    //         // 为当前绑定的纹理对象设置环绕、过滤方式
    //         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    //         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    //         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //         // 加载并生成纹理
    //         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    //         glGenerateMipmap(GL_TEXTURE_2D);
    //     }
    //     GLuint getId()
    //     {
    //         return texture;
    //     }
    //     ImVec2 getSzie()
    //     {

    //         return ImVec2((float)width, (float)height);
    //     }
    //     ImVec2 getSzie(float scaling)
    //     {
    //         return ImVec2(width * scaling, height * scaling);
    //     }
    //     ~Mat2Texture()
    //     {
    //         glDeleteTextures(1, &texture);
    //     }
    // };
    // class Image
    // {

    // private:
    //     ImTextureID imTextureId;
    //     ImVec2 imageSize;

    // public:
    //     Image(ImTextureID imTextureid, ImVec2 imagesize) : imTextureId(imTextureid), imageSize(imagesize)
    //     {
    //     }
    //     ImVec2 getImageSize()
    //     {
    //         return imageSize;
    //     }

    //     ImTextureID getImTextureID()
    //     {
    //         return imTextureId;
    //     }
    // };
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
        // void drawImage(std::vector<Image> Images)
        // {

        //     auto fItemSpacing = ImGui::GetStyle().ItemSpacing;
        //     auto WindowPadding = ImGui::GetStyle().WindowPadding;
        //     if (display == "flex")
        //     {

        //         ImVec2 ItemSpacing;
        //         float windowswidth_ = windowWidth - WindowPadding.x * 2;
        //         float width = 0;
        //         bool flag = false;
        //         std::deque<smily::Image> deque_Images;
        //         for (size_t i = 0; i < Images.size(); i++)
        //         {
        //             auto image = Images[i];

        //             if (width + 2 + image.getImageSize().x + std::max(1, (int)deque_Images.size() - 1) * minSpace.x <= windowswidth_)
        //             {

        //                 width += image.getImageSize().x + 2;
        //                 deque_Images.push_back(image);
        //             }
        //             else
        //             {
        //                 // ImGui::Text("%d",deque_Images.size());
        //                 if (deque_Images.empty())
        //                 {
        //                     ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0, minSpace.y));
        //                     ItemSpacing = ImVec2(0.0, minSpace.y);
        //                     ImGui::Image(image.getImTextureID(), image.getImageSize(), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
        //                     ImGui::PopStyleVar();
        //                 }
        //                 if (deque_Images.size() == 1)
        //                 {
        //                     ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2((windowswidth_ - width) / 2, minSpace.y));
        //                     ItemSpacing = ImVec2((windowswidth_ - width) / 2, minSpace.y);
        //                     auto item = deque_Images.front();
        //                     deque_Images.pop_front();
        //                     ImGui::Image(item.getImTextureID(), item.getImageSize(), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
        //                     i--;
        //                     ImGui::PopStyleVar();
        //                 }

        //                 if (deque_Images.size() > 1)
        //                 {
        //                     bool flag_ = false;
        //                     ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2((windowswidth_ - width) / (deque_Images.size() - 1), minSpace.y));
        //                     ItemSpacing = ImVec2((windowswidth_ - width) / (deque_Images.size() - 1), minSpace.y);

        //                     for (auto item : deque_Images)
        //                     {
        //                         if (!flag_)
        //                         {
        //                             flag_ = true;
        //                         }
        //                         else
        //                         {

        //                             ImGui::SameLine();
        //                         }
        //                         ImGui::Image(item.getImTextureID(), item.getImageSize(), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
        //                         ImGui::SetItemDefaultFocus();
        //                     }
        //                     deque_Images.clear();
        //                     i--;
        //                     ImGui::PopStyleVar();
        //                 }
        //                 width = 0;
        //             }
        //         }
        //         if (deque_Images.size() <= 1)
        //         {
        //             ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0, 10.0));
        //         }
        //         else if (deque_Images.size() == Images.size())
        //         {
        //             ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2((windowswidth_ - width) / (deque_Images.size() - 1), minSpace.y));
        //         }
        //         else
        //         {

        //             ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ItemSpacing);
        //             // ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2((windowswidth_ - width) / (deque_Images.size() - 1), 10.0));
        //         }
        //         for (auto item : deque_Images)
        //         {
        //             if (!flag)
        //             {
        //                 flag = true;
        //             }
        //             else
        //             {
        //                 ImGui::SameLine();
        //             }
        //             ImGui::Image(item.getImTextureID(), item.getImageSize(), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
        //         }
        //         deque_Images.clear();
        //         ImGui::PopStyleVar();
        //     }
        // }

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

                    if (width + 2 + button.getButtonSize().x + (std::max)(1, (int)dequeButtons.size() - 1) * minSpace.x <= windowswidth_)
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

struct FrameContext
{
    ID3D12CommandAllocator *CommandAllocator;
    UINT64 FenceValue;
};

// Data
static int const NUM_FRAMES_IN_FLIGHT = 3;
static FrameContext g_frameContext[NUM_FRAMES_IN_FLIGHT] = {};
static UINT g_frameIndex = 0;

static int const NUM_BACK_BUFFERS = 3;
static ID3D12Device *g_pd3dDevice = NULL;
static ID3D12DescriptorHeap *g_pd3dRtvDescHeap = NULL;
static ID3D12DescriptorHeap *g_pd3dSrvDescHeap = NULL;
static ID3D12CommandQueue *g_pd3dCommandQueue = NULL;
static ID3D12GraphicsCommandList *g_pd3dCommandList = NULL;
static ID3D12Fence *g_fence = NULL;
static HANDLE g_fenceEvent = NULL;
static UINT64 g_fenceLastSignaledValue = 0;
static IDXGISwapChain3 *g_pSwapChain = NULL;
static HANDLE g_hSwapChainWaitableObject = NULL;
static ID3D12Resource *g_mainRenderTargetResource[NUM_BACK_BUFFERS] = {};
static D3D12_CPU_DESCRIPTOR_HANDLE g_mainRenderTargetDescriptor[NUM_BACK_BUFFERS] = {};

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
void WaitForLastSubmittedFrame();
FrameContext *WaitForNextFrameResources();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Main code
int main(int, char **)
{

    // Create application window
    // ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEXW wc = {sizeof(wc), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, L"ImGui Example", NULL};
    ::RegisterClassExW(&wc);
    HWND hwnd = ::CreateWindowW(wc.lpszClassName, L"Dear ImGui DirectX12 Example", WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);

    // Initialize Direct3D
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    // ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX12_Init(g_pd3dDevice, NUM_FRAMES_IN_FLIGHT,
                        DXGI_FORMAT_R8G8B8A8_UNORM, g_pd3dSrvDescHeap,
                        g_pd3dSrvDescHeap->GetCPUDescriptorHandleForHeapStart(),
                        g_pd3dSrvDescHeap->GetGPUDescriptorHandleForHeapStart());

    ImFont *font = ImGui::GetIO().Fonts->AddFontFromFileTTF("../../Fonts/noto/NotoSansCJKsc-Regular.otf", 25.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
    // Our state

    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    bool done = false;
    std::vector<smily::Button> buttons;
    for (int i = 0; i < 7; i++)
    {
        buttons.push_back({"按钮", ImVec2(200.0, 100.0)});
    }

    while (!done)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // See the WndProc() function below for our to dispatch events to the Win32 backend.
        MSG msg;
        while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;

        // Start the Dear ImGui frame
        ImGui_ImplDX12_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("我, world!"); // Create a window called "Hello, world!" and append into it.

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
            // div.drawImage(Images);
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

        // Rendering
        ImGui::Render();

        FrameContext *frameCtx = WaitForNextFrameResources();
        UINT backBufferIdx = g_pSwapChain->GetCurrentBackBufferIndex();
        frameCtx->CommandAllocator->Reset();

        D3D12_RESOURCE_BARRIER barrier = {};
        barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
        barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
        barrier.Transition.pResource = g_mainRenderTargetResource[backBufferIdx];
        barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
        barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
        barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
        g_pd3dCommandList->Reset(frameCtx->CommandAllocator, NULL);
        g_pd3dCommandList->ResourceBarrier(1, &barrier);

        // Render Dear ImGui graphics
        const float clear_color_with_alpha[4] = {clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w};
        g_pd3dCommandList->ClearRenderTargetView(g_mainRenderTargetDescriptor[backBufferIdx], clear_color_with_alpha, 0, NULL);
        g_pd3dCommandList->OMSetRenderTargets(1, &g_mainRenderTargetDescriptor[backBufferIdx], FALSE, NULL);
        g_pd3dCommandList->SetDescriptorHeaps(1, &g_pd3dSrvDescHeap);
        ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), g_pd3dCommandList);
        barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
        barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
        g_pd3dCommandList->ResourceBarrier(1, &barrier);
        g_pd3dCommandList->Close();

        g_pd3dCommandQueue->ExecuteCommandLists(1, (ID3D12CommandList *const *)&g_pd3dCommandList);

        g_pSwapChain->Present(1, 0); // Present with vsync
        // g_pSwapChain->Present(0, 0); // Present without vsync

        UINT64 fenceValue = g_fenceLastSignaledValue + 1;
        g_pd3dCommandQueue->Signal(g_fence, fenceValue);
        g_fenceLastSignaledValue = fenceValue;
        frameCtx->FenceValue = fenceValue;
    }

    WaitForLastSubmittedFrame();

    // Cleanup
    ImGui_ImplDX12_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);

    return 0;
}

// Helper functions

bool CreateDeviceD3D(HWND hWnd)
{
    // Setup swap chain
    DXGI_SWAP_CHAIN_DESC1 sd;
    {
        ZeroMemory(&sd, sizeof(sd));
        sd.BufferCount = NUM_BACK_BUFFERS;
        sd.Width = 0;
        sd.Height = 0;
        sd.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.Flags = DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT;
        sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        sd.SampleDesc.Count = 1;
        sd.SampleDesc.Quality = 0;
        sd.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
        sd.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
        sd.Scaling = DXGI_SCALING_STRETCH;
        sd.Stereo = FALSE;
    }

    // [DEBUG] Enable debug interface
#ifdef DX12_ENABLE_DEBUG_LAYER
    ID3D12Debug *pdx12Debug = NULL;
    if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&pdx12Debug))))
        pdx12Debug->EnableDebugLayer();
#endif

    // Create device
    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;
    if (D3D12CreateDevice(NULL, featureLevel, IID_PPV_ARGS(&g_pd3dDevice)) != S_OK)
        return false;

        // [DEBUG] Setup debug interface to break on any warnings/errors
#ifdef DX12_ENABLE_DEBUG_LAYER
    if (pdx12Debug != NULL)
    {
        ID3D12InfoQueue *pInfoQueue = NULL;
        g_pd3dDevice->QueryInterface(IID_PPV_ARGS(&pInfoQueue));
        pInfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_ERROR, true);
        pInfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_CORRUPTION, true);
        pInfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_WARNING, true);
        pInfoQueue->Release();
        pdx12Debug->Release();
    }
#endif

    {
        D3D12_DESCRIPTOR_HEAP_DESC desc = {};
        desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        desc.NumDescriptors = NUM_BACK_BUFFERS;
        desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
        desc.NodeMask = 1;
        if (g_pd3dDevice->CreateDescriptorHeap(&desc, IID_PPV_ARGS(&g_pd3dRtvDescHeap)) != S_OK)
            return false;

        SIZE_T rtvDescriptorSize = g_pd3dDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
        D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = g_pd3dRtvDescHeap->GetCPUDescriptorHandleForHeapStart();
        for (UINT i = 0; i < NUM_BACK_BUFFERS; i++)
        {
            g_mainRenderTargetDescriptor[i] = rtvHandle;
            rtvHandle.ptr += rtvDescriptorSize;
        }
    }

    {
        D3D12_DESCRIPTOR_HEAP_DESC desc = {};
        desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
        desc.NumDescriptors = 1;
        desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
        if (g_pd3dDevice->CreateDescriptorHeap(&desc, IID_PPV_ARGS(&g_pd3dSrvDescHeap)) != S_OK)
            return false;
    }

    {
        D3D12_COMMAND_QUEUE_DESC desc = {};
        desc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
        desc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
        desc.NodeMask = 1;
        if (g_pd3dDevice->CreateCommandQueue(&desc, IID_PPV_ARGS(&g_pd3dCommandQueue)) != S_OK)
            return false;
    }

    for (UINT i = 0; i < NUM_FRAMES_IN_FLIGHT; i++)
        if (g_pd3dDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&g_frameContext[i].CommandAllocator)) != S_OK)
            return false;

    if (g_pd3dDevice->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, g_frameContext[0].CommandAllocator, NULL, IID_PPV_ARGS(&g_pd3dCommandList)) != S_OK ||
        g_pd3dCommandList->Close() != S_OK)
        return false;

    if (g_pd3dDevice->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&g_fence)) != S_OK)
        return false;

    g_fenceEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
    if (g_fenceEvent == NULL)
        return false;

    {
        IDXGIFactory4 *dxgiFactory = NULL;
        IDXGISwapChain1 *swapChain1 = NULL;
        if (CreateDXGIFactory1(IID_PPV_ARGS(&dxgiFactory)) != S_OK)
            return false;
        if (dxgiFactory->CreateSwapChainForHwnd(g_pd3dCommandQueue, hWnd, &sd, NULL, NULL, &swapChain1) != S_OK)
            return false;
        if (swapChain1->QueryInterface(IID_PPV_ARGS(&g_pSwapChain)) != S_OK)
            return false;
        swapChain1->Release();
        dxgiFactory->Release();
        g_pSwapChain->SetMaximumFrameLatency(NUM_BACK_BUFFERS);
        g_hSwapChainWaitableObject = g_pSwapChain->GetFrameLatencyWaitableObject();
    }

    CreateRenderTarget();
    return true;
}

void CleanupDeviceD3D()
{
    CleanupRenderTarget();
    if (g_pSwapChain)
    {
        g_pSwapChain->SetFullscreenState(false, NULL);
        g_pSwapChain->Release();
        g_pSwapChain = NULL;
    }
    if (g_hSwapChainWaitableObject != NULL)
    {
        CloseHandle(g_hSwapChainWaitableObject);
    }
    for (UINT i = 0; i < NUM_FRAMES_IN_FLIGHT; i++)
        if (g_frameContext[i].CommandAllocator)
        {
            g_frameContext[i].CommandAllocator->Release();
            g_frameContext[i].CommandAllocator = NULL;
        }
    if (g_pd3dCommandQueue)
    {
        g_pd3dCommandQueue->Release();
        g_pd3dCommandQueue = NULL;
    }
    if (g_pd3dCommandList)
    {
        g_pd3dCommandList->Release();
        g_pd3dCommandList = NULL;
    }
    if (g_pd3dRtvDescHeap)
    {
        g_pd3dRtvDescHeap->Release();
        g_pd3dRtvDescHeap = NULL;
    }
    if (g_pd3dSrvDescHeap)
    {
        g_pd3dSrvDescHeap->Release();
        g_pd3dSrvDescHeap = NULL;
    }
    if (g_fence)
    {
        g_fence->Release();
        g_fence = NULL;
    }
    if (g_fenceEvent)
    {
        CloseHandle(g_fenceEvent);
        g_fenceEvent = NULL;
    }
    if (g_pd3dDevice)
    {
        g_pd3dDevice->Release();
        g_pd3dDevice = NULL;
    }

#ifdef DX12_ENABLE_DEBUG_LAYER
    IDXGIDebug1 *pDebug = NULL;
    if (SUCCEEDED(DXGIGetDebugInterface1(0, IID_PPV_ARGS(&pDebug))))
    {
        pDebug->ReportLiveObjects(DXGI_DEBUG_ALL, DXGI_DEBUG_RLO_SUMMARY);
        pDebug->Release();
    }
#endif
}

void CreateRenderTarget()
{
    for (UINT i = 0; i < NUM_BACK_BUFFERS; i++)
    {
        ID3D12Resource *pBackBuffer = NULL;
        g_pSwapChain->GetBuffer(i, IID_PPV_ARGS(&pBackBuffer));
        g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, g_mainRenderTargetDescriptor[i]);
        g_mainRenderTargetResource[i] = pBackBuffer;
    }
}

void CleanupRenderTarget()
{
    WaitForLastSubmittedFrame();

    for (UINT i = 0; i < NUM_BACK_BUFFERS; i++)
        if (g_mainRenderTargetResource[i])
        {
            g_mainRenderTargetResource[i]->Release();
            g_mainRenderTargetResource[i] = NULL;
        }
}

void WaitForLastSubmittedFrame()
{
    FrameContext *frameCtx = &g_frameContext[g_frameIndex % NUM_FRAMES_IN_FLIGHT];

    UINT64 fenceValue = frameCtx->FenceValue;
    if (fenceValue == 0)
        return; // No fence was signaled

    frameCtx->FenceValue = 0;
    if (g_fence->GetCompletedValue() >= fenceValue)
        return;

    g_fence->SetEventOnCompletion(fenceValue, g_fenceEvent);
    WaitForSingleObject(g_fenceEvent, INFINITE);
}

FrameContext *WaitForNextFrameResources()
{
    UINT nextFrameIndex = g_frameIndex + 1;
    g_frameIndex = nextFrameIndex;

    HANDLE waitableObjects[] = {g_hSwapChainWaitableObject, NULL};
    DWORD numWaitableObjects = 1;

    FrameContext *frameCtx = &g_frameContext[nextFrameIndex % NUM_FRAMES_IN_FLIGHT];
    UINT64 fenceValue = frameCtx->FenceValue;
    if (fenceValue != 0) // means no fence was signaled
    {
        frameCtx->FenceValue = 0;
        g_fence->SetEventOnCompletion(fenceValue, g_fenceEvent);
        waitableObjects[1] = g_fenceEvent;
        numWaitableObjects = 2;
    }

    WaitForMultipleObjects(numWaitableObjects, waitableObjects, TRUE, INFINITE);

    return frameCtx;
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            WaitForLastSubmittedFrame();
            CleanupRenderTarget();
            HRESULT result = g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT);
            assert(SUCCEEDED(result) && "Failed to resize swapchain.");
            CreateRenderTarget();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}





























=======
}
>>>>>>> origin/main





#include <imgui.h>
#include "imgui_impl_win32.h"
#include "imgui_impl_dx12.h"
#include <d3d12.h>
#include <dxgi1_4.h>
#include <tchar.h>
#include <windows.h>
#include <future>
#include <iostream>
#include <thread>
#include <chrono>
#include <deque>
#include <smily/smily.h>
#include <clocale>
#ifdef _DEBUG
#define DX12_ENABLE_DEBUG_LAYER
#endif

#ifdef DX12_ENABLE_DEBUG_LAYER
#include <dxgidebug.h>
#pragma comment(lib, "dxguid.lib")
#endif

std::atomic<bool> data_ready(true);
std::atomic<int> data_(true);
struct FrameContext
{
    ID3D12CommandAllocator *CommandAllocator;
    UINT64 FenceValue;
};

// Data
static int const NUM_FRAMES_IN_FLIGHT = 3;
static FrameContext g_frameContext[NUM_FRAMES_IN_FLIGHT] = {};
static UINT g_frameIndex = 0;

static int const NUM_BACK_BUFFERS = 3;
static ID3D12Device *g_pd3dDevice = NULL;
static ID3D12DescriptorHeap *g_pd3dRtvDescHeap = NULL;
static ID3D12DescriptorHeap *g_pd3dSrvDescHeap = NULL;
static ID3D12CommandQueue *g_pd3dCommandQueue = NULL;
static ID3D12GraphicsCommandList *g_pd3dCommandList = NULL;
static ID3D12Fence *g_fence = NULL;
static HANDLE g_fenceEvent = NULL;
static UINT64 g_fenceLastSignaledValue = 0;
static IDXGISwapChain3 *g_pSwapChain = NULL;
static HANDLE g_hSwapChainWaitableObject = NULL;
static ID3D12Resource *g_mainRenderTargetResource[NUM_BACK_BUFFERS] = {};
static D3D12_CPU_DESCRIPTOR_HANDLE g_mainRenderTargetDescriptor[NUM_BACK_BUFFERS] = {};

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
void WaitForLastSubmittedFrame();
FrameContext *WaitForNextFrameResources();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
// class ffplay
// {
// private:
//     STARTUPINFO si;
//     PROCESS_INFORMATION pi;

// public:
//     ffplay()
//     {
//         data_ = 0;
//     }
//     void play()
//     {

//         // ZeroMemory(&si, sizeof(si));
//         // si.cb = sizeof(si);
//         // ZeroMemory(&pi, sizeof(pi));
//         // auto szCommandLine =(wchar_t *)L"D:\\sf\\ffmpeg\\bin\\ffplay.exe D:\\video\\1.mp4";
//         // if (!CreateProcess(NULL,
//         //                    szCommandLine,
//         //                    NULL,
//         //                    NULL,
//         //                    FALSE,
//         //                    0,
//         //                    NULL,
//         //                    NULL,
//         //                    &si,
//         //                    &pi))
//         // {
//         //     printf("CreateProcess failed (%d).\n", GetLastError());
//         // }
//     }
//     void function()
//     {
//         int data = 0;
//         while (true)
//         {
//             if (data != data_)
//             {
//                 if (data_ == 1)
//                 {
//                     play();
//                 }
//                 if (data_ == 8)
//                 {
//                     // CloseHandle(pi.hProcess);
//                     // CloseHandle(pi.hThread);
//                     break;
//                 }
//                 data = data_;
//             }
//         }
//     }
//     ~ffplay()
//     {

//         CloseHandle(pi.hProcess);
//         CloseHandle(pi.hThread);
//     }
// };

// Main code
int main()
{
    setlocale(LC_ALL, "chs");
    // Create application window
    ImGui_ImplWin32_EnableDpiAwareness();

    WNDCLASSEXW wc = {sizeof(wc), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, L"ImGui Example", NULL};
    ::RegisterClassExW(&wc);
    HWND hwnd = ::CreateWindowW(wc.lpszClassName, L"Dear ImGui DirectX12 Example", WS_OVERLAPPEDWINDOW, 0, 0, 0, 0, NULL, NULL, wc.hInstance, NULL);

    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    //::ShowWindow(hwnd, SW_SHOWDEFAULT);
    //::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;   // Enable Multi-Viewport / Platform Windows
                                                          // io.ConfigViewportsNoAutoMerge = true;
                                                          // io.ConfigViewportsNoTaskBarIcon = true;

    ImGui::StyleColorsClassic();

    ImGuiStyle &style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;

        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX12_Init(g_pd3dDevice, NUM_FRAMES_IN_FLIGHT,
                        DXGI_FORMAT_R8G8B8A8_UNORM, g_pd3dSrvDescHeap,
                        g_pd3dSrvDescHeap->GetCPUDescriptorHandleForHeapStart(),
                        g_pd3dSrvDescHeap->GetGPUDescriptorHandleForHeapStart());

    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    ImFont *font = ImGui::GetIO().Fonts->AddFontFromFileTTF("../../Fonts/noto/NotoSansCJKsc-Regular.otf", 60.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
    // ImFont *font = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\simhei.ttf", 20.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());

    //   Main loop
    bool done = false;
    bool mainwindow = true;
    std::vector<smily::Button> buttons;
    for (int i = 0; i < 7; i++)
    {
        buttons.push_back({"按钮", ImVec2(200.0, 100.0)});
    }

    // smily::joining_thread t{[]()
    //                         { ffplay fff;
    //                         fff.function(); }};
    // ffplay fff;
    char str0[12] = "我";

    while (!done)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // See the WndProc() function below for our to dispatch events to the Win32 backend.
        MSG msg;
        while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT || !mainwindow)
            {
                done = true;
            }
        }
        if (done)
        {
            break;
        }

        // Start the Dear ImGui frame
        ImGui_ImplDX12_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 5.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_TabRounding, 5.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_GrabRounding, 5.0f);
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);
        // // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
        // {
        //     static float f = 0.0f;
        //     static int counter = 0;

        //     ImGui::Begin("你好世界!", &mainwindow);                   // Create a window called "Hello, world!" and append into it.
        //     ImGui::Text("This is some useful text.");          // Display some text (you can use a format strings too)
        //     ImGui::Checkbox("Demo Window", &show_demo_window); // Edit bools storing our window open/close state
        //     ImGui::Checkbox("Another Window", &show_another_window);

        //     ImGui::SliderFloat("float", &f, 0.0f, 1.0f);             // Edit 1 float using a slider from 0.0f to 1.0f
        //     ImGui::ColorEdit3("clear color", (float *)&clear_color); // Edit 3 floats representing a color

        //     if (ImGui::Button("Button")) // Buttons return true when clicked (most widgets return true when edited/activated)
        //     {
        //         data_ = 1;
        //         counter++;
        //     }
        //     if (ImGui::Button("display")) // Buttons return true when clicked (most widgets return true when edited/activated)
        //     {
        //         data_ = 8;
        //         counter++;
        //     }
        //     ImGui::SameLine();
        //     ImGui::Text("counter = %d", counter);
        //     ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
        //     ImGui::End();
        // }

        // 3. Show another simple window.
        // if (show_another_window)
        // {
        //     ImGuiWindowFlags window_flags = 0;
        //     window_flags |= ImGuiWindowFlags_NoTitleBar;
        //     window_flags |= ImGuiWindowFlags_NoScrollbar;
        //     bool flag = true;
        //     smily::Div div("Another Window", &flag, window_flags);
        //     // div.drawImage(Images);
        //     div.drawButton(buttons);
        //     ImGui::Text("Hello from another window!");
        //     ImGui::Text("width = %lf", ImGui::GetWindowWidth());

        //     ImGui::InputText("input text", str0, IM_ARRAYSIZE(str0));

        //     // ImGui::Image(textureID, mat2Texture.getSzie(0.1), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
        //     // ImGui::SameLine();

        //     // ImGui::Image(textureID, mat2Texture.getSzie(0.1), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
        //     // ImGui::SameLine();
        //     // ImGui::Image(textureID, mat2Texture.getSzie(0.1), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 0, 0, 1));
        //     if (ImGui::Button("Close Me"))
        //         show_another_window = false;
        // }
        ImGui::PopStyleVar(4);
        // Rendering
        ImGui::Render();

        FrameContext *frameCtx = WaitForNextFrameResources();
        UINT backBufferIdx = g_pSwapChain->GetCurrentBackBufferIndex();
        frameCtx->CommandAllocator->Reset();

        D3D12_RESOURCE_BARRIER barrier = {};
        barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
        barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
        barrier.Transition.pResource = g_mainRenderTargetResource[backBufferIdx];
        barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
        barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
        barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
        g_pd3dCommandList->Reset(frameCtx->CommandAllocator, NULL);
        g_pd3dCommandList->ResourceBarrier(1, &barrier);

        // Render Dear ImGui graphics
        const float clear_color_with_alpha[4] = {clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w};
        g_pd3dCommandList->ClearRenderTargetView(g_mainRenderTargetDescriptor[backBufferIdx], clear_color_with_alpha, 0, NULL);
        g_pd3dCommandList->OMSetRenderTargets(1, &g_mainRenderTargetDescriptor[backBufferIdx], FALSE, NULL);
        g_pd3dCommandList->SetDescriptorHeaps(1, &g_pd3dSrvDescHeap);
        ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), g_pd3dCommandList);
        barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
        barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
        g_pd3dCommandList->ResourceBarrier(1, &barrier);
        g_pd3dCommandList->Close();

        g_pd3dCommandQueue->ExecuteCommandLists(1, (ID3D12CommandList *const *)&g_pd3dCommandList);

        // Update and Render additional Platform Windows
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault(NULL, (void *)g_pd3dCommandList);
        }

        g_pSwapChain->Present(1, 0); // Present with vsync
        // g_pSwapChain->Present(0, 0); // Present without vsync
        barrier.Transition.StateAfter  = D3D12_RESOURCE_STATE_PRESENT;
        g_pd3dCommandList->ResourceBarrier(1, &barrier);
        g_pd3dCommandList->Close();

        g_pd3dCommandQueue->ExecuteCommandLists(1, (ID3D12CommandList* const*)&g_pd3dCommandList);

        g_pSwapChain->Present(1, 0); // Present with vsync
        //g_pSwapChain->Present(0, 0); // Present without vsync

        UINT64 fenceValue = g_fenceLastSignaledValue + 1;
        g_pd3dCommandQueue->Signal(g_fence, fenceValue);
        g_fenceLastSignaledValue = fenceValue;
        frameCtx->FenceValue = fenceValue;
    }

    WaitForLastSubmittedFrame();

    // Cleanup
    ImGui_ImplDX12_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
    data_ = 8;
    return 0;
}

// Helper functions
bool CreateDeviceD3D(HWND hWnd)
{
    // Setup swap chain
    DXGI_SWAP_CHAIN_DESC1 sd;
    {
        ZeroMemory(&sd, sizeof(sd));
        sd.BufferCount = NUM_BACK_BUFFERS;
        sd.Width = 0;
        sd.Height = 0;
        sd.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.Flags = DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT;
        sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        sd.SampleDesc.Count = 1;
        sd.SampleDesc.Quality = 0;
        sd.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
        sd.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
        sd.Scaling = DXGI_SCALING_STRETCH;
        sd.Stereo = FALSE;
    }

    // [DEBUG] Enable debug interface
#ifdef DX12_ENABLE_DEBUG_LAYER
    ID3D12Debug *pdx12Debug = NULL;
    if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&pdx12Debug))))
        pdx12Debug->EnableDebugLayer();
#endif

    // Create device
    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;
    if (D3D12CreateDevice(NULL, featureLevel, IID_PPV_ARGS(&g_pd3dDevice)) != S_OK)
        return false;

        // [DEBUG] Setup debug interface to break on any warnings/errors
#ifdef DX12_ENABLE_DEBUG_LAYER
    if (pdx12Debug != NULL)
    {
        ID3D12InfoQueue *pInfoQueue = NULL;
        g_pd3dDevice->QueryInterface(IID_PPV_ARGS(&pInfoQueue));
        pInfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_ERROR, true);
        pInfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_CORRUPTION, true);
        pInfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_WARNING, true);
        pInfoQueue->Release();
        pdx12Debug->Release();
    }
#endif

    {
        D3D12_DESCRIPTOR_HEAP_DESC desc = {};
        desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        desc.NumDescriptors = NUM_BACK_BUFFERS;
        desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
        desc.NodeMask = 1;
        if (g_pd3dDevice->CreateDescriptorHeap(&desc, IID_PPV_ARGS(&g_pd3dRtvDescHeap)) != S_OK)
            return false;

        SIZE_T rtvDescriptorSize = g_pd3dDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
        D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = g_pd3dRtvDescHeap->GetCPUDescriptorHandleForHeapStart();
        for (UINT i = 0; i < NUM_BACK_BUFFERS; i++)
        {
            g_mainRenderTargetDescriptor[i] = rtvHandle;
            rtvHandle.ptr += rtvDescriptorSize;
        }
    }

    {
        D3D12_DESCRIPTOR_HEAP_DESC desc = {};
        desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
        desc.NumDescriptors = 1;
        desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
        if (g_pd3dDevice->CreateDescriptorHeap(&desc, IID_PPV_ARGS(&g_pd3dSrvDescHeap)) != S_OK)
            return false;
    }

    {
        D3D12_COMMAND_QUEUE_DESC desc = {};
        desc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
        desc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
        desc.NodeMask = 1;
        if (g_pd3dDevice->CreateCommandQueue(&desc, IID_PPV_ARGS(&g_pd3dCommandQueue)) != S_OK)
            return false;
    }

    for (UINT i = 0; i < NUM_FRAMES_IN_FLIGHT; i++)
        if (g_pd3dDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&g_frameContext[i].CommandAllocator)) != S_OK)
            return false;

    if (g_pd3dDevice->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, g_frameContext[0].CommandAllocator, NULL, IID_PPV_ARGS(&g_pd3dCommandList)) != S_OK ||
        g_pd3dCommandList->Close() != S_OK)
        return false;

    if (g_pd3dDevice->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&g_fence)) != S_OK)
        return false;

    g_fenceEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
    if (g_fenceEvent == NULL)
        return false;

    {
        IDXGIFactory4 *dxgiFactory = NULL;
        IDXGISwapChain1 *swapChain1 = NULL;
        if (CreateDXGIFactory1(IID_PPV_ARGS(&dxgiFactory)) != S_OK)
            return false;
        if (dxgiFactory->CreateSwapChainForHwnd(g_pd3dCommandQueue, hWnd, &sd, NULL, NULL, &swapChain1) != S_OK)
            return false;
        if (swapChain1->QueryInterface(IID_PPV_ARGS(&g_pSwapChain)) != S_OK)
            return false;
        swapChain1->Release();
        dxgiFactory->Release();
        g_pSwapChain->SetMaximumFrameLatency(NUM_BACK_BUFFERS);
        g_hSwapChainWaitableObject = g_pSwapChain->GetFrameLatencyWaitableObject();
    }

    CreateRenderTarget();
    return true;
}

void CleanupDeviceD3D()
{
    CleanupRenderTarget();
    if (g_pSwapChain)
    {
        g_pSwapChain->SetFullscreenState(false, NULL);
        g_pSwapChain->Release();
        g_pSwapChain = NULL;
    }
    if (g_hSwapChainWaitableObject != NULL)
    {
        CloseHandle(g_hSwapChainWaitableObject);
    }
    for (UINT i = 0; i < NUM_FRAMES_IN_FLIGHT; i++)
        if (g_frameContext[i].CommandAllocator)
        {
            g_frameContext[i].CommandAllocator->Release();
            g_frameContext[i].CommandAllocator = NULL;
        }
    if (g_pd3dCommandQueue)
    {
        g_pd3dCommandQueue->Release();
        g_pd3dCommandQueue = NULL;
    }
    if (g_pd3dCommandList)
    {
        g_pd3dCommandList->Release();
        g_pd3dCommandList = NULL;
    }
    if (g_pd3dRtvDescHeap)
    {
        g_pd3dRtvDescHeap->Release();
        g_pd3dRtvDescHeap = NULL;
    }
    if (g_pd3dSrvDescHeap)
    {
        g_pd3dSrvDescHeap->Release();
        g_pd3dSrvDescHeap = NULL;
    }
    if (g_fence)
    {
        g_fence->Release();
        g_fence = NULL;
    }
    if (g_fenceEvent)
    {
        CloseHandle(g_fenceEvent);
        g_fenceEvent = NULL;
    }
    if (g_pd3dDevice)
    {
        g_pd3dDevice->Release();
        g_pd3dDevice = NULL;
    }

#ifdef DX12_ENABLE_DEBUG_LAYER
    IDXGIDebug1 *pDebug = NULL;
    if (SUCCEEDED(DXGIGetDebugInterface1(0, IID_PPV_ARGS(&pDebug))))
    {
        pDebug->ReportLiveObjects(DXGI_DEBUG_ALL, DXGI_DEBUG_RLO_SUMMARY);
        pDebug->Release();
    }
#endif
}

void CreateRenderTarget()
{
    for (UINT i = 0; i < NUM_BACK_BUFFERS; i++)
    {
        ID3D12Resource *pBackBuffer = NULL;
        g_pSwapChain->GetBuffer(i, IID_PPV_ARGS(&pBackBuffer));
        g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, g_mainRenderTargetDescriptor[i]);
        g_mainRenderTargetResource[i] = pBackBuffer;
    }
}

void CleanupRenderTarget()
{
    WaitForLastSubmittedFrame();

    for (UINT i = 0; i < NUM_BACK_BUFFERS; i++)
        if (g_mainRenderTargetResource[i])
        {
            g_mainRenderTargetResource[i]->Release();
            g_mainRenderTargetResource[i] = NULL;
        }
}

void WaitForLastSubmittedFrame()
{
    FrameContext *frameCtx = &g_frameContext[g_frameIndex % NUM_FRAMES_IN_FLIGHT];

    UINT64 fenceValue = frameCtx->FenceValue;
    if (fenceValue == 0)
        return; // No fence was signaled

    frameCtx->FenceValue = 0;
    if (g_fence->GetCompletedValue() >= fenceValue)
        return;

    g_fence->SetEventOnCompletion(fenceValue, g_fenceEvent);
    WaitForSingleObject(g_fenceEvent, INFINITE);
}

FrameContext *WaitForNextFrameResources()
{
    UINT nextFrameIndex = g_frameIndex + 1;
    g_frameIndex = nextFrameIndex;

    HANDLE waitableObjects[] = {g_hSwapChainWaitableObject, NULL};
    DWORD numWaitableObjects = 1;

    FrameContext *frameCtx = &g_frameContext[nextFrameIndex % NUM_FRAMES_IN_FLIGHT];
    UINT64 fenceValue = frameCtx->FenceValue;
    if (fenceValue != 0) // means no fence was signaled
    {
        frameCtx->FenceValue = 0;
        g_fence->SetEventOnCompletion(fenceValue, g_fenceEvent);
        waitableObjects[1] = g_fenceEvent;
        numWaitableObjects = 2;
    }

    WaitForMultipleObjects(numWaitableObjects, waitableObjects, TRUE, INFINITE);

    return frameCtx;
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
    {
        return true;
    }
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            WaitForLastSubmittedFrame();
            CleanupRenderTarget();
            HRESULT result = g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT);
            assert(SUCCEEDED(result) && "Failed to resize swapchain.");
            CreateRenderTarget();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }

    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}



