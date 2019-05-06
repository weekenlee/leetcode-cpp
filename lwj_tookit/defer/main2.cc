#include <iostream>
#include <functional>
using namespace std;

// 用于定义一个匿名变量名，把行号放到变量名中
#define  __ANONYMOUS1(type, var, line)  type  var##line
#define  _ANONYMOUS0(type, line)  __ANONYMOUS1(type, _anonymous, line)
#define  ANONYMOUS(type)  _ANONYMOUS0(type, __LINE__)

// defer所执行的函数的类型
void __defercleanup(std::function<void()> *func)
{
	(*func)();
}

#define defer \
   std::function<void()> defercleanup_##__LINE__ __attribute__((cleanup(__defercleanup), unused)) = 

void test()
{
	cout << "call the test func!" << endl;
}

int main() {
	if (true)
	{
		// 可以用匿名函数做defer
		defer [](){
			cout<<"will out if block!" << endl;
		};

		// 也可以用普通函数做defer
		defer test;
		cout << "in if block!" << endl;
	}
}
