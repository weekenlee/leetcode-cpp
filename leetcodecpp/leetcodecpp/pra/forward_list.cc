#include<iostream>
#include<forward_list>

using namespace std;

int main(int argc, char* argv[]) {
    forward_list<string> arguments(argv, argv+argc);

    cout <<"file name:" <<arguments.front() <<endl;

    arguments.pop_front();

    arguments.unique();

    arguments.sort([](const string& a,  const string &b){
                return a.length() < b.length();
            });

    for (const auto arg :arguments) {
        cout << arg << endl;
    }
}
