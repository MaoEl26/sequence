#include "jugador.h"
#define largoLista 7

Jugador:: Jugador(string name, Ficha* ficha, int cantCartas, ArrayStack<Carta*> cartas)
{
    this->name=name;
    this->ficha=ficha;
    this->cantCartas=cantCartas;
    this->cards=repartoCartas(cartas);
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

ArrayCarta<Carta*> Jugador::getCards(){
    return *cards;
}

ArrayCarta<Carta*>* Jugador::repartoCartas(ArrayStack<Carta *> cartas){
    ArrayCarta<Carta*>* cartasjgd= new ArrayCarta<Carta*>(largoLista);
    for (int i=0;i<cantCartas;i++){
        cartasjgd->append(cartas.topValue());
        cartas.pop();
    }
    if (cantCartas < largoLista){
        for (int i=cantCartas-1;i<largoLista;i++){
            cartasjgd->append(new Carta("NULL","NULL","NULL",":/imagenes/COMODIN.png"));
        }
    }
    return cartasjgd;
}
