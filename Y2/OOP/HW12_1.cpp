#include <iostream>

class Number {
private:
    double value;

public:
    Number(double val = 0.0) : value(val) {}

    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }

    Number operator-(const Number& other) const {
        return Number(value - other.value);
    }

    Number operator*(const Number& other) const {
        return Number(value * other.value);
    }

    Number operator/(const Number& other) const {
        if (other.value == 0) {
            throw std::runtime_error("Division by zero");
        }
        return Number(value / other.value);
    }

    Number& operator=(const Number& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    operator int() const {
        return static_cast<int>(value);
    }

    double getValue() const {
        return value;
    }
};

int main() {
    Number a(5.5), b(2.2);
    Number c = a + b;
    Number d = a - b;
    Number e = a * b;
    Number f = a / b;

    std::cout << "a + b = " << c.getValue() << std::endl;
    std::cout << "a - b = " << d.getValue() << std::endl;
    std::cout << "a * b = " << e.getValue() << std::endl;
    std::cout << "a / b = " << f.getValue() << std::endl;

    int intValue = c;
    std::cout << "c as int = " << intValue << std::endl;

    return 0;
}