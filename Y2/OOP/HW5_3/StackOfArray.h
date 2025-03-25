#ifndef STACKOFARRAY_H
#define STACKOFARRAY_H

#include <iostream>
#include "StackOfInt.h"

using namespace std;

struct StackOfInt::StackArrImp{
    int arr[10];
    int topIndex;
};

#endif