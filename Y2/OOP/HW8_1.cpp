#include <iostream>

void ModValue(const int num){

    // num = num + 1;
    std::cout << "The value of num is: " << num << "\n";
}

int main() {
    int num = 5;
    ModValue(num);
    return 0;
}