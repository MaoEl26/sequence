#include "mazo.h"

Mazo::Mazo()
{
    simbolos(0);
}

string  Mazo::simbolos()
{
    ArrayList arraySimbolos(130);
    arraySimbolos.append("diamante");
    arraySimbolos.goToPos(0);
    cout<< arraySimbolos.getValue();
    return arraySimbolos.getValue();
}


