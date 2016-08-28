
#include <QApplication>
#include "Game.h"
#include "Carta.h"
#include "arraycarta.h"
#include <QString>
#include <iostream>
using namespace std;

Game* game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game= new Game();

//    Carta* carta1 = new Carta ("4","corazon","rojo","jfjf");

//    ArrayCarta<Carta*>*cartas = new ArrayCarta<Carta*>(7);

//   // ArrayCarta <Carta*> *cartas(4);
//    cartas->append(carta1);
//    cout<<cartas->getSize()<<endl;
//   cout<<cartas->getSize();
//    cout<<carta1->getColor();


  return a.exec();
}
