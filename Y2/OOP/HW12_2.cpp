#include <iostream>
#include <string>

class Bird {
private:
    std::string identifier;
    static int birdCount;

public:
    Bird() {
        birdCount++;
        identifier = "Bird #" + std::to_string(birdCount);
    }

    Bird(const Bird& other) {
        birdCount++;
        identifier = other.identifier + " (copy)";
    }

    Bird& operator=(const Bird& other) {
        if (this != &other) {
            identifier = other.identifier + " (assigned)";
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Bird& bird) {
        os << bird.identifier;
        return os;
    }
};

int Bird::birdCount = 0;

int main() {
    Bird b1;
    Bird b2;
    Bird b3 = b1;
    Bird b4;
    b4 = b2;

    std::cout << b1 << "\n";
    std::cout << b2 << "\n";
    std::cout << b3 << "\n";
    std::cout << b4 << "\n";

    return 0;
}
