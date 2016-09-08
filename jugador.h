#ifndef JUGADOR_H
#define JUGADOR_H

#include "mazo.h"
#include "arraycarta.h"
#include "carta.h"
#include "ficha.h"


class Jugador:public Mazo
{

    public:
        Jugador(string name, Ficha *ficha, int cantCartas,QString path,ArrayCarta<Carta*>*cartasJugador);
        Ficha* getFicha();
        int getCantCartas();
        string getName();
        QString getPath();
        ArrayCarta<Carta*> getCards();


    protected:
        QString path;
        string name;
        Ficha* ficha;
        int cantCartas;
        ArrayCarta<Carta*>* cartasJugador;
};

#endif // JUGADOR_H
