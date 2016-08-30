#include "carta.h"

Carta::Carta(QString valor, QString simbolo, QString color, QString path)
{
    this->valor = valor;
    this->simbolo = simbolo;
    this->color = color;
    this->path= path;

}

QString Carta::getValor()
{
    return valor;
}

QString Carta::getSimbolo()
{
    return simbolo;
}

QString Carta::getColor()
{
    return color;
}

QString Carta::getPath()
{
    return path;
}
