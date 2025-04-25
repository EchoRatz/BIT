#include <iostream>
#include <string>

class AClass{
private:
    std::string data;

public:
    AClass(const std::string& str) : data(str){}

    void setData(const std::string& str){
        data = str;
    }

    std::string getData() const{
        return data;
    }

    void printData(){
        std::cout << "Non-const print: " << data << "\n";
    }

    void printData() const{
        std::cout << "Const print: " << data << "\n";
    }
};

int main(){

    AClass obj1("Hello");
    obj1.setData("World");
    obj1.printData(); 
    std::cout << "Data: " << obj1.getData() << "\n";

    const AClass obj2("Const Object");
    
    obj2.printData();
    std::cout << "Data: " << obj2.getData() << "\n";

    return 0;
}