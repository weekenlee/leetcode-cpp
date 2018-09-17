#include<functional>
#include<iostream>
using namespace std;
class Defer {
    public:
        Defer() {}
        Defer(Defer &&d) {
            func_ = std::move(d.func_);
        }

        Defer(const Defer &d) = delete;
        void operator=(const Defer &d) = delete;

        template<typename F, typename ...Args>
        Defer(F&& f, Args&& ...args) {
            func_ = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
        }

        ~Defer() noexcept {
            if(func_ ) {
                func_();
            }
        }
    private:
        std::function<void()> func_;
};

#define _CONCAT(a, b) a##b
#define _MAKE_DEFER_HELPER_(line) Defer _CONCAT(defer, line) = [&]()
#define DEFER _MAKE_DEFER_HELPER_(__LINE__)

int main() 
{
    Defer([&](){
        cout << "defer 1"<<endl; 
    });
    Defer([&](){
        cout << "defer 2"<<endl; 
    });
    DEFER {
        cout << "defer 3"<<endl;
    };
    return 1;
}
