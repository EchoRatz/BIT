#include <iostream>

class AClass{
private:
    const float constValue;
    float nonConstValue;

public:
    AClass(float constVal, float nonConstVal)
        : constValue(constVal), nonConstValue(nonConstVal){}

    void display() const{
        std::cout << "Const Value: " << constValue << ", Non-Const Value: " << nonConstValue << "\n";
    }

    // Method to modify non-const value
    void setNonConstValue(float newValue){
        nonConstValue = newValue;
    }
};

int main(){
    AClass obj(3.14f, 2.71f);
    obj.display();

    obj.setNonConstValue(1.61f);
    obj.display();

    return 0;
}