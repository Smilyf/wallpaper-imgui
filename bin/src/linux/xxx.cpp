// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>
// // #include "Shader.h"
// #include "imgui.h"
// #include "imgui_impl_glfw.h"
// #include "imgui_impl_opengl3.h"

// #include <iostream>

// #include <opencv2/opencv.hpp>
// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"
// using namespace cv;

// void framebuffer_size_callback(GLFWwindow *window, int width, int height);
// void processInput(GLFWwindow *window);

// // settings
// const unsigned int SCR_WIDTH = 800;
// const unsigned int SCR_HEIGHT = 600;
// GLuint Mat2Texture(std::string imgdir)
// {

//     cv::Mat image;
//     image = imread(imgdir);
//     cv::cvtColor(image, image, cv::COLOR_RGB2BGRA);

//     // auto width=image.cols;
//     // auto height=image.rows;
//     // auto data=image.data;
//     int width = 10, height = 10, nrChannels;
//     unsigned char *data = stbi_load(imgdir.c_str(), &width, &height, &nrChannels, 0);

//     if (image.empty())
//     {
//         std::cout << "image is empty! " << std::endl;
//         return -1;
//     }
//     else
//     {
        
//         GLuint texture;
//         glGenTextures(1, &texture);
//         glBindTexture(GL_TEXTURE_2D, texture);
//         // 为当前绑定的纹理对象设置环绕、过滤方式
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//         // 加载并生成纹理
//         int width, height, nrChannels;
//         unsigned char *data = stbi_load(imgdir.c_str(), &width, &height, &nrChannels, 0);
//         if (data)
//         {
//             glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//             glGenerateMipmap(GL_TEXTURE_2D);
//         }
//         else
//         {
//             std::cout << "Failed to load texture" << std::endl;
//         }
//         stbi_image_free(data);
//         return texture;
//     }
// }
// int main()
// {
//     // 设置330版本给imgui使用
//     const char *glsl_version = "#version 330";
//     // glfw: initialize and configure
//     // ------------------------------
//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


//     // glfw window creation
//     // --------------------
//     GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//     if (window == NULL)
//     {
//         std::cout << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }
//     glfwMakeContextCurrent(window);
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

//     // glad: load all OpenGL function pointers
//     // ---------------------------------------
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         std::cout << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }

//     // configure global opengl state
//     // -----------------------------
//     glEnable(GL_DEPTH_TEST);

//     // build and compile our shader zprogram
//     // 在上面配置初始化完成后再进行界面的引入
//     // 创建imgui的上下文
//     ImGui::CreateContext();
//     ImGuiIO &io = ImGui::GetIO();
//     (void)io;
//     ImFont *font = io.Fonts->AddFontFromFileTTF("/home/kali-smily/openglim/Fonts/simhei.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
//     // 设置样式
//     ImGui::StyleColorsDark();
//     // 设置平台和渲染器
//     ImGui_ImplGlfw_InitForOpenGL(window, true);
//     ImGui_ImplOpenGL3_Init(glsl_version);

//     GLuint textureID = Mat2Texture("/home/kali-smily/openglim/2.jpg");
//     float f = 0.0f;
//     ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
//     // render loop
//     // -----------
//     while (!glfwWindowShouldClose(window))
//     {
//         // input
//         // -----
//         processInput(window);

//         // 使用imgui创建窗口
//         ImGui_ImplOpenGL3_NewFrame();
//         ImGui_ImplGlfw_NewFrame();
//         ImGui::NewFrame();
//         ImGui::Begin("你好");
//         ImGui::Image(&textureID, ImGui::GetContentRegionAvail(), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 255, 0, 1));
//         ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
//         ImGui::SliderFloat("float", &f, 0.0f, 1.0f);             // Edit 1 float using a slider from 0.0f to 1.0f
//         ImGui::ColorEdit3("clear color", (float *)&clear_color); // Edit 3 floats representing a color
//         ImGui::End();
//         // render
//         // 通过imgui的颜色控制背景颜色
//         glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

//         // 渲染
//         ImGui::Render();
//         ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//         // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//         // -------------------------------------------------------------------------------
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     // optional: de-allocate all resources once they've outlived their purpose:
//     // ------------------------------------------------------------------------

//     // glfw: terminate, clearing all previously allocated GLFW resources.
//     // ------------------------------------------------------------------
//     glfwTerminate();
//     return 0;
// }

// // process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// // ---------------------------------------------------------------------------------------------------------
// void processInput(GLFWwindow *window)
// {
//     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, true);
// }

// // glfw: whenever the window size changed (by OS or user resize) this callback function executes
// // ---------------------------------------------------------------------------------------------
// void framebuffer_size_callback(GLFWwindow *window, int width, int height)
// {
//     // make sure the viewport matches the new window dimensions; note that width and
//     // height will be significantly larger than specified on retina displays.
//     glViewport(0, 0, width, height);
// }
































// #include "imgui.h"
// #include "imgui_impl_glfw.h"
// #include "imgui_impl_opengl3.h"

// #include <stdio.h>
// #define GL_SILENCE_DEPRECATION
// #if defined(IMGUI_IMPL_OPENGL_ES2)
// #include <GLES2/gl2.h>
// #endif

// #include <glad/glad.h>
// #include <GLFW/glfw3.h> // Will drag system OpenGL headers
// #include <iostream>
// #include <string>
// #include <opencv2/opencv.hpp>
// using namespace cv;
// void framebuffer_size_callback(GLFWwindow *window, int width, int height);
// void processInput(GLFWwindow *window);

// GLuint Mat2Texture(std::string imgdir)
// {

//     cv::Mat image;
//     image = imread(imgdir);
//     cv::cvtColor(image, image, cv::COLOR_RGB2BGRA);

//     auto width = image.cols;
//     auto height = image.rows;
//     auto data = image.data;

//     if (image.empty())
//     {
//         std::cout << "image is empty! " << std::endl;
//         return -1;
//     }
//     else
//     {

//         GLuint texture;
//         glGenTextures(1, &texture);
//         glBindTexture(GL_TEXTURE_2D, texture);
//         // 为当前绑定的纹理对象设置环绕、过滤方式
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//         // 加载并生成纹理

//         if (data)
//         {
//             glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//             glGenerateMipmap(GL_TEXTURE_2D);
//         }
//         else
//         {
//             std::cout << "Failed to load texture" << std::endl;
//         }

//         return texture;
//     }
// }

// // settings
// const unsigned int SCR_WIDTH = 800;
// const unsigned int SCR_HEIGHT = 600;

// const char *vertexShaderSource = "#version 330 core\n"
//                                  "layout (location = 0) in vec3 aPos;\n"
//                                  "void main()\n"
//                                  "{\n"
//                                  "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//                                  "}\0";
// const char *fragmentShaderSource = "#version 330 core\n"
//                                    "out vec4 FragColor;\n"
//                                    "void main()\n"
//                                    "{\n"
//                                    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//                                    "}\n\0";

// int main()
// {
//     const char *glsl_version = "#version 130";
//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// #ifdef __APPLE__
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
// #endif

//     // glfw window creation
//     // --------------------
//     GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//     if (window == NULL)
//     {
//         std::cout << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }
//     glfwMakeContextCurrent(window);
//     glfwSwapInterval(1);
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

//     // Setup Dear ImGui context
//     IMGUI_CHECKVERSION();
//     ImGui::CreateContext();
//     ImGuiIO &io = ImGui::GetIO();
//     (void)io;
//     io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
//     io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

//     // Setup Dear ImGui style
//     ImGui::StyleColorsDark();
//     // ImGui::StyleColorsLight();

//     // Setup Platform/Renderer backends
//     ImGui_ImplGlfw_InitForOpenGL(window, true);
//     ImGui_ImplOpenGL3_Init(glsl_version);
//     ImFont *font = io.Fonts->AddFontFromFileTTF("/home/kali-smily/openglim/Fonts/simhei.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());

//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         std::cout << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }
//     GLuint ID = Mat2Texture("/home/kali-smily/openglim/1.jpg");

//     float vertices[] = {
//         // positions          // colors           // texture coords
//          0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
//          0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
//         -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
//         -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
//     };
//     unsigned int indices[] = {  
//         0, 1, 3, // first triangle
//         1, 2, 3  // second triangle
//     };
//     unsigned int VBO, VAO, EBO;
//     glGenVertexArrays(1, &VAO);
//     glGenBuffers(1, &VBO);
//     glGenBuffers(1, &EBO);

//     glBindVertexArray(VAO);

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//     glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

//     // position attribute
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);
//     // color attribute
//     glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//     glEnableVertexAttribArray(1);
//     // texture coord attribute
//     glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//     glEnableVertexAttribArray(2);


//     while (!glfwWindowShouldClose(window))
//     {

//         // Start the Dear ImGui frame
//         ImGui_ImplOpenGL3_NewFrame();
//         ImGui_ImplGlfw_NewFrame();
//         ImGui::NewFrame();

//         ImGui::Begin("Another Window"); // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
//         ImGui::Text("Hello from another window!");
//         ImGui::Image(&ID, ImGui::GetContentRegionAvail(), ImVec2(0.0, 0.0), ImVec2(1.0, 1.0), ImVec4(255, 255, 255, 1), ImVec4(0, 255, 0, 1));
//         ImGui::End();
//         // input
//         // -----
//         processInput(window);

//         glUseProgram(shaderProgram);
//         glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//         // glDrawArrays(GL_TRIANGLES, 0, 6);
//         glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//         // glBindVertexArray(0); // no need to unbind it every time

//         // render
//         // ------
//         glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);

//         ImGui::Render();
//         ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }
//     ImGui_ImplOpenGL3_Shutdown();
//     ImGui_ImplGlfw_Shutdown();
//     ImGui::DestroyContext();

//     glfwTerminate();
//     return 0;
// }

// void processInput(GLFWwindow *window)
// {
//     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, true);
// }

// void framebuffer_size_callback(GLFWwindow *window, int width, int height)
// {

//     glViewport(0, 0, width, height);
// }