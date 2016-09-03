#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include <iostream>
using namespace std;

class ArrayStack
{
    public:
        ArrayStack(int pMax);
        void push(int value);
        int pop();
        int topValue();
        bool isFull();
        bool isEmpty();
        void goToPos(int pos);
        void clear();
        int getSize();
        void print ();
        virtual ~ArrayStack();

    private:
        int top;
        int size;
        int max;
        int pos;
        int* elements;
};

#endif // ARRAYSTACK_H
