#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor called" << std::endl;
    }
    virtual ~Base() {
        std::cout << "Base destructor called" << std::endl;
    }
};

class Intermediate : public Base {
public:
    Intermediate() {
        std::cout << "Intermediate constructor called" << std::endl;
    }
    ~Intermediate() override {
        std::cout << "Intermediate destructor called" << std::endl;
    }
};

class Derived : public Intermediate {
public:
    Derived() {
        std::cout << "Derived constructor called" << std::endl;
    }
    ~Derived() override {
        std::cout << "Derived destructor called" << std::endl;
    }
};

int main() {
    std::cout << "Creating Derived object:" << std::endl;
    Derived obj;
    std::cout << "Destroying Derived object:" << std::endl;
    return 0;
}