#include <iostream>
using namespace std;

class Base {
public:
    static void staticFunction1() {
        cout << "Base staticFunction1" << endl;
    }

    static void staticFunction2() {
        cout << "Base staticFunction2" << endl;
    }
};

class Derived : public Base {
public:
    static void staticFunction1() {
        cout << "Derived staticFunction1" << endl;
    }
};

int main() {
    Base::staticFunction1();
    Base::staticFunction2();
    Derived::staticFunction1();
    Derived::staticFunction2();

    return 0;
}
