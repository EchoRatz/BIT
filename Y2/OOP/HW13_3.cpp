#include <iostream>
#include <vector>

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

class PStash {
private:
    std::vector<Counted*> storage;

public:
    ~PStash() {
        std::cout << "PStash destructor called. Cleaning up objects..." << std::endl;
        for (Counted* obj : storage) {
            delete obj;
        }
        storage.clear();
    }

    void add(Counted* obj) {
        storage.push_back(obj);
    }
};

int main() {
    std::cout << "Creating a PStash object..." << std::endl;
    PStash stash;

    std::cout << "Adding Counted objects to PStash..." << std::endl;
    for (int i = 0; i < 3; ++i) {
        stash.add(new Counted());
    }

    std::cout << "Exiting main. PStash will go out of scope..." << std::endl;
    return 0;
}