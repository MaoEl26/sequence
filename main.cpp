
#include <QApplication>
#include "Game.h"
#include "Carta.h"
#include "arraycarta.h"
#include "arraylist.h"
#include <iostream>
using namespace std;

Game* game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game= new Game();

    Carta* carta1 = new Carta ("4","corazon","rojo","jfjf");
  //  ArrayCarta <Carta> *cartas = new ArrayCarta <Carta>(5);

    ArrayCarta <Carta*> cartas ();
    cartas.append(carta1);
    //cartas.print();


    return 0;
  //  return a.exec();
}
