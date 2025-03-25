#include <iostream>

class Simple {
public:
    Simple() {
        std::cout << "Simple constructor" << "\n";
    }
    ~Simple() {
        std::cout << "Simple destructor" << "\n";
    }
};

using namespace std;

int main() {
    Simple obj;
    cout << "Simple constructor" << "\n";
    return 0;
}
