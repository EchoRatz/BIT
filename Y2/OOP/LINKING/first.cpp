#include "header.h"
#include <iostream>
using namespace std;

void functionVoid() {
    cout << "Void function" << endl;
}

int functionint(int a) {
    cout << "Int function(" << a << ")\n";
    return 1;
}

float functionFloat(float a) {
    cout << "Float function(" << a << ")\n";
    return 1.1; 
}

char functionChar(char a) {
    cout << "Char function(" << a << ")\n";
    return 'x';
}