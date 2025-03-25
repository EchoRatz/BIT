#ifndef HANDLE_H
#define HANDLE_H

class StackOfInt{

    struct StackArrImp;
    struct StackVecImp;

    StackArrImp* arrptr;
    StackVecImp* vecptr;

    public:

        void initialize(bool usevector);
        void cleanup();

        void pushStack(int num);
        void popStack();
        int topStack();
        bool isEmpty();
        bool isFull();

};

#endif
