#ifndef STACKOFVECTOR_H
#define STACKOFVECTOR_H

#include <iostream>
#include <vector>
#include "StackOfInt.h"

using namespace std;

struct StackOfInt::StackVecImp{
    vector<int> vec;
};

#endif
