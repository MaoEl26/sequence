#include "ficha.h"

Ficha::Ficha(int ID, string color, string path)
{
    this->ID=ID;
    this->color=color;
    this->path=path;
}

int Ficha::getID(){
    return ID;
}

string Ficha::getColor(){
    return color;
}

string Ficha::getPath(){
    return path;
}
