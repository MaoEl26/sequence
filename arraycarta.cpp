#include "ArrayCarta.h"
#define default_max_size 1024
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename E>
ArrayCarta<E>::ArrayCarta(int pMax= default_max_size)
{
    max = pMax;
    size = 0;
    pos = 0;
    elements = new E [pMax];
}

template <typename E>
E ArrayCarta<E>::getValue(){
    if (pos < 0 || pos > size){
        throw runtime_error ("Index out of bound");
    }else{
        return elements [pos];
    }
}

template <typename E>
int ArrayCarta<E>::getPos (){
    return pos;
}

template <typename E>
int ArrayCarta<E>::getSize(){
    return size;
}

template <typename E>
void ArrayCarta<E>::goToStart(){
    pos = 0;
}

template <typename E>
void ArrayCarta<E>::goToEnd(){
    pos = size;
}

template <typename E>
void ArrayCarta<E>::goToPos (int pos){

    //validar pos existe
    this->pos = pos;
}

template <typename E>
void ArrayCarta<E>::previous(){
    // Validaciones
    pos--;
}

template <typename E>
void ArrayCarta<E>::next(){
    if (pos < size){
        pos++;
    }
}

template <typename E>
void ArrayCarta<E>::append(E pElement){
    if (size == max){
        throw runtime_error ("List Full");
    }
    elements [size] = pElement;
    size++;
}

template <typename E>
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

template <typename E>
E ArrayCarta<E>::remove(int pos){
    if (size == 0){
        throw runtime_error ("Empty List");
    }else{
        goToPos(pos);
        string deletedElement = elements [pos];
        for (int i = pos; i < size; i++){
            elements[i]= elements [i+1];
        }
        size --;
        return deletedElement;
    }
}

template <typename E>
void ArrayCarta<E>::print(){
    for (int i =0; i< size; i++){
        cout <<"Elemento sub "<<i<<" : "<<elements[i]<<"\n";
    }
}

template <typename E>
ArrayCarta<E>::~ArrayCarta (){
    size= 0;
    pos = 0;
    delete[]elements;
}
