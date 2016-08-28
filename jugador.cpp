#include "jugador.h"

Jugador::Jugador(int players)
{
    this->players=players;
    if (players==3){
    QCoreApplication::quit();
    }

}
