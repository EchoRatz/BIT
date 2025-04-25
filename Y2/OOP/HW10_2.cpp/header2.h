#ifndef NAMESPACE2_H
#define NAMESPACE2_H
#include <iostream>

#include "header.h"

namespace MyNamespace {
    void function4();
    void function5(){
        std::cout << "Function5" << "\n";
    }
    void function6();
}

#endif