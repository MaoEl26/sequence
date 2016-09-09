#include "ficha.h"

Ficha::Ficha(int ID, QString color, QString path)
{
    this->ID=ID;
    this->color=color;
    this->path=path;
}

int Ficha::getID(){
    return ID;
}

QString Ficha::getColor(){
    return color;
}

QString Ficha::getPath(){
    return path;
}
