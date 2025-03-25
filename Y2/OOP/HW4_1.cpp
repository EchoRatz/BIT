#include <iostream>

struct AStruct {
    int data;
};

void setStructData(AStruct* s, int value) {
    s->data = value;
}

void displayStructData(const AStruct* s) {
    std::cout << "Struct data: " << s->data << std::endl;
}

int main() {
    AStruct s;
    setStructData(&s, 42);
    displayStructData(&s);
    return 0;
}