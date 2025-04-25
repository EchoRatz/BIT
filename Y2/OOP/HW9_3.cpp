#include <iostream>

class FClass{
public:
    void firstFunction(){
        std::cout << "FirstFunction: ";
        secondFunction();
    }

    void secondFunction(){
        std::cout << "SecondFunction" << "\n";
    }
};

int main(){
    FClass obj;
    obj.firstFunction();
    return 0;
}