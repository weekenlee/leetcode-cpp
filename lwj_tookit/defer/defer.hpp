#pragma once

#include <functional>
#include <deque>

namespace lwj {

    class defer {
    public:
        enum execution {always, no_exception, exception};

        defer(defer &&) = default;
        explicit defer(execution policy = always):policy(policy) {}

        template<class Callable> 
        defer(Callable &&func, execution policy = always):policy(policy) {
            this->operator += <Callable>(std::forward<Callable>(func));
        }

        template<class Callable> 
        defer& operator += (Callable &&func) try {
            handlers.emplace_front(std::forward<Callable>(func));
            return *this;
        }catch(...) {
            if(policy != no_exception) func();
            throw;
        }

        ~defer() {
            if( policy == always || (std::uncaught_exception() == (policy == exception))) {
                for(auto &f : handlers) try {
                    f();
                }catch(...){
                }
            }
        }

        void dismiss() noexcept {
            handlers.clear();
        }

    private:
        defer(const defer&) = delete;
        void operator = (const defer&) = delete;

        std::deque<std::function<void()>> handlers;
        execution policy = always;
    };
}
