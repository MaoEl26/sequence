#ifndef JUGADOR_H
#define JUGADOR_H

#include "mazo.h"
#include "arraycarta.h"
#include "carta.h"
#include "ficha.h"


class Jugador:public Mazo
{

    public:
        Jugador(string name, Ficha *ficha, int cantCartas,ArrayStack<Carta*>cartas);
        Ficha* getFicha();
        int getCantCartas();
        string getName();
        ArrayCarta<Carta*> getCards();
        ArrayCarta<Carta *> *repartoCartas(ArrayStack<Carta*> cartas);


    protected:
        string name;
        Ficha* ficha;
        int cantCartas;

        ArrayCarta<Carta*>* cards;
};

#endif // JUGADOR_H
