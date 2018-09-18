#include<functional>
#include<iostream>
using namespace std;

template<int repeattimes, typename F, typename ...Args>
void doSomeThing(F &&f,  Args &&...args)
{
    auto func_ = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
    for (int i = 0 ; i < repeattimes; i++ ) {
       func_();
    }
}

static double my_divide(double x, double y) {
    cout << "compute"<<endl;
    return x / y;
}

int main() 
{
    doSomeThing<5> (
            [](){
                cout<<"hello"<<endl;
            }
    );

    auto fn_five = std::bind(my_divide, 10.0, 2.0);   
    doSomeThing<5> (fn_five);
}
