#include "ArrayList.h"
#define default_max_size 1024
#include <stdexcept>
#include <iostream>
using namespace std;

ArrayList::ArrayList(int pMax = default_max_size)
{
    max = pMax;
    size = 0;
    pos = 0;
    elements = new string [pMax];
}

//Precondicion: Pos debe apuntar al elemento que se quiere procesar
string ArrayList::getValue(){
    if (pos < 0 || pos > size){
        throw runtime_error ("Index out of bound");
    }else{
        return elements [pos];
    }
}

int ArrayList::getPos (){
    return pos;
}

int ArrayList::getSize(){
    return size;
}

void ArrayList::goToStart(){
    pos = 0;
}

void ArrayList::goToEnd(){
    pos = size;
}

void ArrayList::goToPos (int pos){

    //validar pos existe
    this->pos = pos;
}

void ArrayList::previous(){
    // Validaciones
    pos--;
}

void ArrayList::next(){
    if (pos < size){
        pos++;
    }
}

void ArrayList::append(string pElement){
    if (size == max){
        throw runtime_error ("List Full");
    }
    elements [size] = pElement;
    size++;
}

void ArrayList::insert(string pElement){
    if (size == max){
        throw runtime_error ("List Full");
    }
    for (int i= size; i> pos; i--){
        elements [i] = elements[i-1];
    }
    elements[pos]= pElement;
    size++;
}

string ArrayList::remove(int pos){
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

void ArrayList::print(){
    for (int i =0; i< size; i++){
        cout <<"Elemento sub "<<i<<" : "<<elements[i]<<"\n";
    }
}

ArrayList::~ArrayList (){
    size= 0;
    pos = 0;
    delete[]elements;
}
