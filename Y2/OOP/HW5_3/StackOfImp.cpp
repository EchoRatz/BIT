#include <iostream>
#include <vector>
#include "StackOfInt.h"
#include "StackOfArray.h"
#include "StackOfVector.h"

using namespace std;

void StackOfInt::initialize(bool useVector){

    arrptr = nullptr;
    vecptr = nullptr;

    //vector
    if (useVector) {
        vecptr = new StackVecImp();
    }
    //array 
    else {
        arrptr = new StackArrImp();
        arrptr->topIndex = 0; // Initialize top to 0
    }

};

void StackOfInt::cleanup(){

    delete arrptr;  
    arrptr = nullptr;

    delete vecptr;  
    vecptr = nullptr;

};

void StackOfInt::pushStack(int num){

    if (arrptr) {
        if (!isFull()) {
            arrptr->arr[arrptr->topIndex++] = num;
        } else {
            cerr << "[Error] Stack is full (array version)\n";
        }
    }
    
    else if (vecptr) {
        vecptr->vec.push_back(num);
    }
    
};

void StackOfInt::popStack(){

    if (arrptr) {
        if (!isEmpty()) {
            arrptr->topIndex--;
        } else {
            cerr << "[Error] Stack is empty (array version)\n";
        }
    } 
    else if (vecptr) {
        if (!vecptr->vec.empty()) {
            vecptr->vec.pop_back();
        } else {
            cerr << "[Error] Stack is empty (vector version)\n";
        }
    }

};

int StackOfInt::topStack(){

    if (arrptr) {
        if (!isEmpty()) {
            return arrptr->arr[arrptr->topIndex - 1];
        } else {
            cerr << "[Error] topStack() called on empty array stack.\n";
            return -1; 
        }
    }
    else if (vecptr) {
        if (!vecptr->vec.empty()) {
            return vecptr->vec.back();
        } else {
            cerr << "[Error] topStack() called on empty vector stack.\n";
            return -1; 
        }
    }
    
    cerr << "[Error] No valid stack pointer.\n";
    return -1;

};

bool StackOfInt::isEmpty(){

    if (arrptr) {
        return (arrptr->topIndex == 0);
    }
    else if (vecptr) {
        return vecptr->vec.empty();
    }
    
    return true;

};

bool StackOfInt::isFull(){

    if (arrptr) {
        return (arrptr->topIndex == 10);
    }
    else if (vecptr) {
        
        return false;
    }
    
    return false;

};
