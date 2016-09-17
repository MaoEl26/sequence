#ifndef MAZO_H
#define MAZO_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ArrayCarta.h"
#include "carta.h"
#include <QString>
#include "arraystack.h"
using namespace std;

class Mazo
{
public:
    Mazo();
    ArrayCarta<Carta *> mazoTablero();
    ArrayCarta<Carta*> tableroRandom();
    ArrayStack<Carta *> *mazoJugadores();
    ArrayStack<Carta *> *randomCartasDescartes(ArrayStack<Carta *> *mazoCartasDescartes);
};

#endif // MAZO_H
