#include <iostream>
using namespace std;

// Base 
class Base {
public:
    virtual void func(int x) {
        cout << "Base::func(int) called with " << x << endl;
    }

    virtual void func(double x) {
        cout << "Base::func(double) called with " << x << endl;
    }

    virtual void func(const string& str) {
        cout << "Base::func(string) called with " << str << endl;
    }

    virtual ~Base() = default; // Virtual destructor
};

// Derived class
class Derived : public Base {
public:
    void func(int x) override {
        cout << "Derived::func(int) called with " << x << endl;
    }
};

int main() {
  
    Derived derivedObj;

    // Call all base class functions through the derived-class object
    derivedObj.func(42);          // Calls Derived::func(int)
    derivedObj.func(3.14);        // Calls Base::func(double)
    derivedObj.func("Hello");     // Calls Base::func(string)

    // Upcast the address of the object to the base
    Base* basePtr = &derivedObj;

    // Call all functions through the base pointer
    basePtr->func(42);            // Calls Derived::func(int) (polymorphism)
    basePtr->func(3.14);          // Calls Base::func(double)
    basePtr->func("World");       // Calls Base::func(string)
    
    // derivedObj.func(42);       
    // derivedObj.func(3.14);    
    // derivedObj.func("Hello"); 

    return 0;
}