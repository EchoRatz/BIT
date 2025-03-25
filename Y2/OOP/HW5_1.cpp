#include <iostream>

class AClass {
public:
    int publicVar;
    void publicFunction() {
        std::cout << "Public function called." << std::endl;
    }

protected:
    int protectedVar;
    void protectedFunction() {
        std::cout << "Protected function called." << std::endl;
    }

private:
    int privateVar;
    void privateFunction() {
        std::cout << "Private function called." << std::endl;
    }
};

int main() {
    AClass obj;

    obj.publicVar = 10;
    obj.publicFunction();

    /* obj.protectedVar = 20;
    obj.protectedFunction();*/

    /* obj.privateVar = 30;
    obj.privateFunction();*/

    return 0;
}
