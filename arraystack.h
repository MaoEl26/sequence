#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include "carta.h"
#include <iostream>

using namespace std;
template<class E>
class ArrayStack
{
    public:
        ArrayStack(int pMax);
        void push(E value);
        E pop();
        E topValue();
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
        E* elements;
};

#endif // ARRAYSTACK_H
