#include <iostream>

int Function(double x) {

    std::cout << "Function(" << x << ") calle\n";
    return static_cast<int>(x);
}

int main() {
    int (*funcPtr)(double) = Function;

    int result = funcPtr(7.89);

    std::cout << "Result: " << result << "\n";

    return 0;
}
