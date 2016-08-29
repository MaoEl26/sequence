#include <QApplication>
#include "Game.h"
#include "Carta.h"
#include "arraycarta.h"
#include <QString>
#include <iostream>
#include <mazo.h>
using namespace std;

Game* game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game= new Game();

    return a.exec();
}
