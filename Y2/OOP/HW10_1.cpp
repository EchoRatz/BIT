#include <iostream>

int main(){
   
    auto num = 42; 
    auto message = "Hello, World!"; 

    register int counter = 0;

    std::cout << message << "\n";

    for (counter = 0; counter < num; ++counter){
        std::cout << "Counter: " << counter << "\n";
    }

    return 0;
}