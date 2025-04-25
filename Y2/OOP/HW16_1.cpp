#include <iostream>

template <typename T>
T fibonacci(int n) {
    if (n <= 1) {
        return static_cast<T>(n);
    }
    T a = 0;
    T b = 1;
    T result = 0;
    for (int i = 2; i <= n; ++i) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int main() {
    int n = 10;

    std::cout << "Fibonacci of " << n << " as int: " << fibonacci<int>(n) << std::endl;
    std::cout << "Fibonacci of " << n << " as long: " << fibonacci<long>(n) << std::endl;
    std::cout << "Fibonacci of " << n << " as float: " << fibonacci<float>(n) << std::endl;
    std::cout << "Fibonacci of " << n << " as double: " << fibonacci<double>(n) << std::endl;

    return 0;
}