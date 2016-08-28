#include "arraycarta.h"

#define default_max_size 1024
#include <stdexcept>
#include <iostream>
using namespace std;

template <class E>
ArrayCarta<E>::ArrayCarta(int pMax)
{
    max = pMax;
    size = 0;
    pos = 0;
    elements = new E [pMax];
}

template <class E>
E ArrayCarta<E>::getValue(){

        return elements [pos];
}

template <class E>
int ArrayCarta<E>::getPos (){
    return pos;
}

template <class E>
int ArrayCarta<E>::getSize(){
    return size;
}

template <class E>
void ArrayCarta<E>::goToStart(){
    pos = 0;
}

template <class E>
void ArrayCarta<E>::goToEnd(){
    pos = size;
}

template <class E>
void ArrayCarta<E>::goToPos (int pos){

    //validar pos existe
    this->pos = pos;
}

template <class E>
void ArrayCarta<E>::previous(){
    // Validaciones
    pos--;
}

template <class E>
void ArrayCarta<E>::next(){
    if (pos < size){
        pos++;
    }
}

template <class E>
void ArrayCarta<E>::append(E pElement){
    if (size == max){
        throw runtime_error ("List Full");
    }
    elements [size] = pElement;
    size++;
}

template <class E>
void ArrayCarta<E>::insert(E pElement){
    if (size == max){
        throw runtime_error ("List Full");
    }
    for (int i= size; i> pos; i--){
        elements [i] = elements[i-1];
    }
    elements[pos]= pElement;
    size++;
}

template <class E>
E ArrayCarta<E>::remove(int pos){
    if (size == 0){
        throw runtime_error ("Empty List");
    }else{
        goToPos(pos);
        E deletedElement = elements [pos];
        for (int i = pos; i < size; i++){
            elements[i]= elements [i+1];
        }
        size --;
        return deletedElement;
    }
}


template <class E>
ArrayCarta<E>::~ArrayCarta (){
    size= 0;
    pos = 0;
    delete[]elements;
}
template class ArrayCarta<Carta*>;
