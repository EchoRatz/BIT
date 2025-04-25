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
    std::cout << "Creating objects..." << std::endl;
    Counted c1;
    Counted c2;
    Counted c3;

    std::cout << "Exiting main..." << std::endl;
    return 0;
}