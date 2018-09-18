#include<iostream>
#include<memory>

int main() {
    std::pair<int, int> p{1,2};
    auto pp = std::make_shared<std::pair<int,int>>(p);
    std::cout<<(void*)pp.get()<<std::endl;
    std::cout<<&p<<std::endl;
    std::cout<<&pp<<std::endl;
    std::cout<<std::get<0>(p)<<std::endl;
    std::cout<<std::get<1>(p)<<std::endl;
    std::cout<<p.first<<std::endl;
    std::cout<<p.second<<std::endl;
    std::cout<<pp->first<<std::endl;
    std::cout<<pp->second<<std::endl;
    std::cout<<std::get<0>(*pp)<<std::endl;
    std::cout<<std::get<1>(*pp)<<std::endl;
}
