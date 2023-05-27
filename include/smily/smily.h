#include<thread>
#include<string>
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
                    if (width + 2 + image.getImageSize().x + (std::max)(1, (int)deque_Images.size() - 1) * minSpace.x <= windowswidth_)
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
        void push_back(std::vector<Button> &Buttons)
        {
            

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