#include "ArrayStack.h"

template <class E>
ArrayStack<E>::ArrayStack(int pMax)
{
    max = pMax;
    size = 0;
    pos = 0;
    elements = new E [pMax];
    top = 0;
}

template <class E>
int ArrayStack<E>::getSize(){
    return size;
}

template <class E>
void ArrayStack<E>::push(E value){
    elements [size] = value;
    size++;
    top = size-1;
}

template <class E>
E ArrayStack<E>::pop(){
    goToPos(top);
    E deletedElement = elements [top];
    for (int i = top; i < size; i++){
        elements[i]= elements [i+1];
    }
    if (top == size-1 && top != 0){
        top--;
    }
    size --;

    return deletedElement;
}


template <class E>
void ArrayStack<E>::goToPos (int pos){
    this->pos = pos;
}

template <class E>
bool ArrayStack<E>::isEmpty(){
    return size==0;
}

template <class E>
E ArrayStack<E>::topValue(){
    return elements[top];
}

template <class E>
void ArrayStack<E>::clear(){
    size= 0;
    pos = 0;
    delete[]elements;
}

template <class E>
ArrayStack<E>::~ArrayStack()
{
    clear();

}


template class ArrayStack<Carta*>;
template class ArrayStack<string>;
template class ArrayStack<int>;
