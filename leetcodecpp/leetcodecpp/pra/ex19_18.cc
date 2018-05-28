#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<vector>

int main(int argc, char **argv)
{
    std::vector<std::string> v;
    std::string a;
    while(std::getline(std::cin, a)){
        v.push_back(a);
    }

    auto m = std::count_if(v.begin(), v.end(), std::mem_fn(&std::string::empty));
    std::cout<<"using mem_fn, the num of empty lines:"<<m<<std::endl;

    auto n = std::count_if(v.begin(), v.end(), std::bind(&std::string::empty, std::placeholders::_1));
    std::cout<<"using bind, the num of empty lines:"<<n<<std::endl;

    auto q = std::count_if(v.begin(), v.end(), [](std::string &tem){
            return tem.empty(); 
            });

    std::cout<<"using lamba, the num of empty lines:"<<q<<std::endl;

    return 0;
}
