#ifndef MAZO_H
#define MAZO_H
#include "ArrayCarta.h"
#include <iostream>
#include "carta.h"
using namespace std;

class Mazo
{
public:
    Mazo();
    string simbolos (int position);

    Carta* mazoTablero(int position);
};

#endif // MAZO_H
