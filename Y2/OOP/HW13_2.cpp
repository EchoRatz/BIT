#include <iostream>

class Counted {
private:
    int id;
    static int count;

public:
    Counted() : id(count++) {
        std::cout << "Creating Counted object with id: " << id << std::endl;
    }

    ~Counted() {
        std::cout << "Destroying Counted object with id: " << id << std::endl;
    }
};

int Counted::count = 0;

int main() {
    std::cout << "Creating a single object using new..." << std::endl;
    Counted* singleObject = new Counted();
    std::cout << "Deleting the single object..." << std::endl;
    delete singleObject;

    std::cout << "\nCreating an array of objects using new..." << std::endl;
    Counted* objectArray = new Counted[3];
    std::cout << "Deleting the array of objects..." << std::endl;
    delete[] objectArray;

    std::cout << "\nExiting main..." << std::endl;
    return 0;
}