#include<functional>
#include<memory>
#include<iostream>
using namespace std;

using AnyPointer = std::shared_ptr<void>;

template<int repeattimes, typename F, typename ...Args>
void doSomeThing(F &&f,  Args &&...args)
{
    using ResultType = typename std::result_of<F (Args...)>::type;

    auto func_ = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
    for (int i = 0 ; i < repeattimes; i++ ) {
      ResultType result =  func_();
      if(result) {
        cout <<result<<endl;
      }
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
                return 0;
            }
    );

    auto fn_five = std::bind(my_divide, 90.0, 2.0);   
    doSomeThing<5> (fn_five);
}
