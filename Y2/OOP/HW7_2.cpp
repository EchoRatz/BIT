#include <iostream>
using namespace std;

class XClass {
public:
    void func(){
        cout << "0 arguments called." << "\n";
    }

    void func(int a){
        cout << "1 argument called: " << a << "\n";
    }

    void func(int a, int b){
        cout << "2 arguments called: " << a << ", " << b << "\n";
    }

    void func(int a, int b, int c){
        cout << "3 arguments called: " << a << ", " << b << ", " << c << "\n";
    }
};

int main() {
    XClass obj;

    obj.func();
    obj.func(10);
    obj.func(10, 20);
    obj.func(10, 20, 30);

    return 0;
}