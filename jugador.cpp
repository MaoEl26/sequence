#include "jugador.h"
#define largoLista 7

Jugador:: Jugador(string name, Ficha* ficha, int cantCartas, ArrayCarta<Carta*> *cartasJugador)
{
    this->name=name;
    this->ficha=ficha;
    this->cantCartas=cantCartas;
    this->cartasJugador=cartasJugador;
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

ArrayCarta<Carta *> Jugador::getCards(){
    return *cartasJugador;
}

