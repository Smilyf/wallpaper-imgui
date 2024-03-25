#include <thread>
#include <string>
#include <vector>
namespace smily
{
    class kongzhi
    {
    private:
        bool flag{false};

    public:
        kongzhi() = default;
        ~kongzhi() = default;
        void set()
        {
            flag = true;
        }
        bool get()
        {
            return flag;
        }
        void init()
        {
            flag = false;
        }
    };

    template <class T>
    class State
    {
    public:
        T value;
        kongzhi *t;
        State(kongzhi *t_,T value_)
        {
            value=value_;
            t=t_;
        }
        void set(T value_)
        {
            value = value_;
            (*t).set();
        }
        T get()
        {
            return value;
        }
    };


};