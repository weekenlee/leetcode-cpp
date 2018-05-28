#include <cassert>
#include <tuple>
#include <string>

int main() {
    using namespace std::literals::string_literals;
    auto t = std::make_tuple(2, "Hello"s);

    assert(std::get<int>(t) == 2);
    assert(std::get<std::string>(t) == "Hello"s);


    assert(std::get<0>(t) == std::get<int>(t));
    assert(std::get<1>(t) == std::get<std::string>(t));

    return 0;
}
