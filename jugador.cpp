#include "jugador.h"
#define largoLista 7

Jugador:: Jugador(string name, Ficha* ficha, int cantCartas,QString path, ArrayCarta<Carta*> *cartasJugador)
{
    this->name=name;
    this->ficha=ficha;
    this->cantCartas=cantCartas;
    this->cartasJugador=cartasJugador;
    this->path=path;
}

string Jugador::getName(){
    return name;
}

int Jugador::getCantCartas(){
    return cantCartas;
}

Ficha* Jugador::getFicha(){
    return ficha;
}

QString Jugador::getPath(){
    return path;
}

ArrayCarta<Carta *> Jugador::getCards(){
    return *cartasJugador;
}

