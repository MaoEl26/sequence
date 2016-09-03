#include "ArrayStack.h"

ArrayStack::ArrayStack(int pMax)
{
    max = pMax;
    size = 0;
    pos = 0;
    elements = new int [pMax];
    top = 0;
}

int ArrayStack::getSize(){
    return size;
}
void ArrayStack::push(int value){
    elements [size] = value;
    size++;
    top = size-1;
}

int ArrayStack::pop(){
    goToPos(top);
    int deletedElement = elements [top];
    for (int i = top; i < size; i++){
        elements[i]= elements [i+1];
    }
    if (top == size-1 && top != 0){
        top--;
    }
    size --;

    return deletedElement;
}

void ArrayStack::goToPos (int pos){
    this->pos = pos;
}

int ArrayStack::topValue(){
    return elements[top];
}


void ArrayStack::clear(){
    size= 0;
    pos = 0;
    delete[]elements;
}

void ArrayStack::print(){
    cout<< "\n[ ";
    for (int i =0; i<size; i++){
        cout <<elements[i]<<" ";
    }
    cout<< "]";
}
ArrayStack::~ArrayStack()
{
    clear();

}
