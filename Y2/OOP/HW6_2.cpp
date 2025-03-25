#include <iostream>

class Simple {
public:
    Simple() {
        std::cout << "Simple constructor" << "\n";
    }
};

using namespace std;

int main() {
    Simple obj;
    cout << "Simple constructor" << "\n";
    return 0;
}

