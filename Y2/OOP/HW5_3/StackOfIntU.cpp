#include <iostream>
#include "StackOfInt.h"
#include "StackOfArray.h"
#include "StackOfVector.h"


using namespace std;

int main(){

    StackOfInt arrStack;
    arrStack.initialize(false);  // false => array
    arrStack.pushStack(10);
    arrStack.pushStack(20);

    cout << "Top (array) is: " << arrStack.topStack() << endl;

    arrStack.popStack();
    cout << "Top after pop (array) is: " << arrStack.topStack() << endl;

    arrStack.cleanup();

    // Example: Use the vector-based version
    StackOfInt vecStack;
    vecStack.initialize(true);   // true => vector
    vecStack.pushStack(100);
    vecStack.pushStack(200);

    cout << "Top (vector) is: " << vecStack.topStack() << endl;

    vecStack.popStack();
    cout << "Top after pop (vector) is: " << vecStack.topStack() << endl;

    vecStack.cleanup();

    return 0;
    
}