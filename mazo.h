#ifndef MAZO_H
#define MAZO_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ArrayCarta.h"
#include "carta.h"
using namespace std;

class Mazo
{
public:
    Mazo();
    Carta* mazoTablero(int position); 
    ArrayCarta<Carta*> tableroRandom();
    ArrayCarta<Carta*> mazoJugadores();
};

#endif // MAZO_H
