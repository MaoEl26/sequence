#ifndef MAZO_H
#define MAZO_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ArrayCarta.h"
#include "carta.h"
#include <QString>
using namespace std;

class Mazo
{
public:
    Mazo();
    ArrayCarta<Carta *> mazoTablero();
    ArrayCarta<Carta*> tableroRandom();
    ArrayCarta<Carta*> mazoJugadores();
};

#endif // MAZO_H
