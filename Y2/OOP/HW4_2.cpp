#include <iostream>

struct AStruct {
    int data;

    void setData(int value) {
        data = value;
    }

    void displayData() const {
        std::cout << "Struct data: " << data << std::endl;
    }
};

int main() {
    AStruct s;
    s.setData(42);
    s.displayData();
    return 0;
}