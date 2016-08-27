#include "carta.h"

Carta::Carta(string valor, string simbolo, string color, string path)
{
    this->valor = valor;
    this->simbolo = simbolo;
    this->color = color;
    this->path= path;

}

string Carta::getValor()
{
    return valor;
}

string Carta::getSimbolo()
{
    return simbolo;
}

string Carta::getColor()
{
    return color;
}

string Carta::getPath()
{
    return path;
}
