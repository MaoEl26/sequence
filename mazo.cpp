#include "mazo.h"

#define TamannoTablero 95 //Cantidad de cartas que van a estar en la matriz del tablero 0 a 95
#define TamannoMazo 103 //Cantidad de cartas en el mazo 0 a 103

#include <iostream>
using namespace std;
Mazo::Mazo()
{

}


ArrayCarta<Carta*> Mazo::mazoTablero(){
    ArrayCarta<Carta*> *cartasTablero = new ArrayCarta<Carta*>(TamannoTablero);
    //Fila 0
    cartasTablero->append(new Carta ("6" ,"diamante","rojo",":/imagenes/6D.png"));
    cartasTablero->append(new Carta ("7" ,"diamante","rojo",":/imagenes/7D.png"));
    cartasTablero->append(new Carta ("8" ,"diamante","rojo",":/imagenes/8D.png"));
    cartasTablero->append(new Carta ("9" ,"diamante","rojo",":/imagenes/9D.png"));
    cartasTablero->append(new Carta ("10","diamante","rojo",":/imagenes/10D.png"));
    cartasTablero->append(new Carta ("Q" ,"diamante","rojo",":/imagenes/QD.png"));
    cartasTablero->append(new Carta ("K" ,"diamante","rojo",":/imagenes/KD.png"));
    cartasTablero->append(new Carta ("A" ,"diamante","rojo",":/imagenes/AD.png"));
    //Fila 1
    cartasTablero->append(new Carta ("5" ,"diamante","rojo",":/imagenes/5D.png"));
    cartasTablero->append(new Carta ("3" ,"corazon","rojo",":/imagenes/3C.png"));
    cartasTablero->append(new Carta ("2" ,"corazon","rojo",":/imagenes/2C.png"));
    cartasTablero->append(new Carta ("2" ,"pica","negro",":/imagenes/2P.png"));
    cartasTablero->append(new Carta ("3" ,"pica","negro",":/imagenes/3P.png"));
    cartasTablero->append(new Carta ("4" ,"pica","negro",":/imagenes/4P.png"));
    cartasTablero->append(new Carta ("5" ,"pica","negro",":/imagenes/5P.png"));
    cartasTablero->append(new Carta ("6" ,"pica","negro",":/imagenes/6P.png"));
    cartasTablero->append(new Carta ("7" ,"pica","negro",":/imagenes/7P.png"));
    cartasTablero->append(new Carta ("A" ,"trebol","negro",":/imagenes/AT.png"));

    //Fila 2
    cartasTablero->append(new Carta ("4" ,"diamante","rojo",":/imagenes/4D.png"));
    cartasTablero->append(new Carta ("4" ,"corazon","rojo",":/imagenes/4C.png"));
    cartasTablero->append(new Carta ("K" ,"diamante","rojo",":/imagenes/KD.png"));
    cartasTablero->append(new Carta ("A" ,"diamante","rojo",":/imagenes/AD.png"));
    cartasTablero->append(new Carta ("A" ,"trebol","negro",":/imagenes/AT.png"));
    cartasTablero->append(new Carta ("K" ,"trebol","negro",":/imagenes/KT.png"));
    cartasTablero->append(new Carta ("Q" ,"trebol","negro",":/imagenes/QT.png"));
    cartasTablero->append(new Carta ("10" ,"trebol","negro",":/imagenes/10T.png"));
    cartasTablero->append(new Carta ("8" ,"pica","negro",":/imagenes/8P.png"));
    cartasTablero->append(new Carta ("K" ,"trebol","negro",":/imagenes/KT.png"));

    //Fila 3
    cartasTablero->append(new Carta ("3" ,"diamante","rojo",":/imagenes/3D.png"));
    cartasTablero->append(new Carta ("5" ,"corazon","rojo",":/imagenes/5C.png"));
    cartasTablero->append(new Carta ("Q" ,"diamante","rojo",":/imagenes/QD.png"));
    cartasTablero->append(new Carta ("Q" ,"corazon","rojo",":/imagenes/QC.png"));
    cartasTablero->append(new Carta ("10" ,"corazon","rojo",":/imagenes/10C.png"));
    cartasTablero->append(new Carta ("9" ,"corazon","rojo",":/imagenes/9C.png"));
    cartasTablero->append(new Carta ("8" ,"corazon","rojo",":/imagenes/8C.png"));
    cartasTablero->append(new Carta ("9" ,"trebol","negro",":/imagenes/9T.png"));
    cartasTablero->append(new Carta ("9" ,"pica","negro",":/imagenes/9P.png"));
    cartasTablero->append(new Carta ("Q" ,"trebol","negro",":/imagenes/QT.png"));

    //Fila 4
    cartasTablero->append(new Carta ("2" ,"diamante","rojo",":/imagenes/2D.png"));
    cartasTablero->append(new Carta ("6" ,"corazon","rojo",":/imagenes/6C.png"));
    cartasTablero->append(new Carta ("10" ,"diamante","rojo",":/imagenes/10D.png"));
    cartasTablero->append(new Carta ("K" ,"corazon","rojo",":/imagenes/KC.png"));
    cartasTablero->append(new Carta ("3" ,"corazon","rojo",":/imagenes/3C.png"));
    cartasTablero->append(new Carta ("2" ,"corazon","rojo",":/imagenes/2C.png"));
    cartasTablero->append(new Carta ("7" ,"corazon","rojo",":/imagenes/7C.png"));
    cartasTablero->append(new Carta ("8" ,"trebol","negro",":/imagenes/8T.png"));
    cartasTablero->append(new Carta ("10" ,"pica","negro",":/imagenes/10P.png"));
    cartasTablero->append(new Carta ("10" ,"trebol","negro",":/imagenes/10T.png"));

    //Fila 5
    cartasTablero->append(new Carta ("A" ,"pica","negro",":/imagenes/AP.png"));
    cartasTablero->append(new Carta ("7" ,"corazon","rojo",":/imagenes/7C.png"));
    cartasTablero->append(new Carta ("9" ,"diamante","rojo",":/imagenes/9D.png"));
    cartasTablero->append(new Carta ("A" ,"corazon","rojo",":/imagenes/AC.png"));
    cartasTablero->append(new Carta ("4" ,"corazon","rojo",":/imagenes/4C.png"));
    cartasTablero->append(new Carta ("5" ,"corazon","rojo",":/imagenes/5C.png"));
    cartasTablero->append(new Carta ("6" ,"corazon","rojo",":/imagenes/6C.png"));
    cartasTablero->append(new Carta ("7" ,"trebol","negro",":/imagenes/7T.png"));
    cartasTablero->append(new Carta ("Q" ,"pica","negro",":/imagenes/QP.png"));
    cartasTablero->append(new Carta ("9" ,"trebol","negro",":/imagenes/9T.png"));

    //Fila 6
    cartasTablero->append(new Carta ("K" ,"pica","negro",":/imagenes/KP.png"));
    cartasTablero->append(new Carta ("8" ,"corazon","rojo",":/imagenes/8C.png"));
    cartasTablero->append(new Carta ("8" ,"diamante","rojo",":/imagenes/8D.png"));
    cartasTablero->append(new Carta ("2" ,"trebol","negro",":/imagenes/2T.png"));
    cartasTablero->append(new Carta ("3" ,"trebol","negro",":/imagenes/3T.png"));
    cartasTablero->append(new Carta ("4" ,"trebol","negro",":/imagenes/4T.png"));
    cartasTablero->append(new Carta ("5" ,"trebol","negro",":/imagenes/5T.png"));
    cartasTablero->append(new Carta ("6" ,"trebol","negro",":/imagenes/6T.png"));
    cartasTablero->append(new Carta ("K" ,"pica","negro",":/imagenes/KP.png"));
    cartasTablero->append(new Carta ("8" ,"trebol","negro",":/imagenes/8T.png"));

    //Fila 7
    cartasTablero->append(new Carta ("Q" ,"pica","negro",":/imagenes/QP.png"));
    cartasTablero->append(new Carta ("9" ,"corazon","rojo",":/imagenes/9C.png"));
    cartasTablero->append(new Carta ("7" ,"diamante","rojo",":/imagenes/7D.png"));
    cartasTablero->append(new Carta ("6" ,"diamante","rojo",":/imagenes/6D.png"));
    cartasTablero->append(new Carta ("5" ,"diamante","rojo",":/imagenes/5D.png"));
    cartasTablero->append(new Carta ("4" ,"diamante","rojo",":/imagenes/4D.png"));
    cartasTablero->append(new Carta ("3" ,"diamante","rojo",":/imagenes/3D.png"));
    cartasTablero->append(new Carta ("2" ,"diamante","rojo",":/imagenes/2D.png"));
    cartasTablero->append(new Carta ("A" ,"pica","negro",":/imagenes/AP.png"));
    cartasTablero->append(new Carta ("7" ,"trebol","negro",":/imagenes/7T.png"));

    //Fila 8
    cartasTablero->append(new Carta ("10" ,"pica","negro",":/imagenes/10P.png"));
    cartasTablero->append(new Carta ("10" ,"corazon","rojo",":/imagenes/10C.png"));
    cartasTablero->append(new Carta ("Q" ,"corazon","rojo",":/imagenes/QC.png"));
    cartasTablero->append(new Carta ("K" ,"corazon","rojo",":/imagenes/KC.png"));
    cartasTablero->append(new Carta ("A" ,"corazon","rojo",":/imagenes/AC.png"));
    cartasTablero->append(new Carta ("2" ,"trebol","negro",":/imagenes/2T.png"));
    cartasTablero->append(new Carta ("3" ,"trebol","negro",":/imagenes/3T.png"));
    cartasTablero->append(new Carta ("4" ,"trebol","negro",":/imagenes/4T.png"));
    cartasTablero->append(new Carta ("5" ,"trebol","negro",":/imagenes/5T.png"));
    cartasTablero->append(new Carta ("6" ,"trebol","negro",":/imagenes/6T.png"));

    //Fila 9
    cartasTablero->append(new Carta ("9" ,"pica","negro",":/imagenes/9P.png"));
    cartasTablero->append(new Carta ("8" ,"pica","negro",":/imagenes/8P.png"));
    cartasTablero->append(new Carta ("7" ,"pica","negro",":/imagenes/7P.png"));
    cartasTablero->append(new Carta ("6" ,"pica","negro",":/imagenes/6P.png"));
    cartasTablero->append(new Carta ("5" ,"pica","negro",":/imagenes/5P.png"));
    cartasTablero->append(new Carta ("4" ,"pica","negro",":/imagenes/4P.png"));
    cartasTablero->append(new Carta ("3" ,"pica","negro",":/imagenes/3P.png"));
    cartasTablero->append(new Carta ("2" ,"pica","negro",":/imagenes/2P.png"));

    return *cartasTablero;
}

ArrayCarta<Carta*> Mazo::tableroRandom(){

    ArrayCarta<Carta*> *cartas = new ArrayCarta<Carta*>(TamannoMazo);
    ArrayCarta<Carta*> original =  mazoTablero();
    ArrayCarta<int> *arrayInt=new ArrayCarta<int>(TamannoTablero);

    for (int i =0; i<=TamannoTablero; i++){arrayInt->append(i);}

    srand(time(NULL)); //llamada al random
    int num; //Variable en la que se almacena el numero random
    int cont = 0;//Inicializa el contador en 0
    int maxCards = (arrayInt->getSize());//almacena el tamaño del array que va a crear

    while (cont < maxCards){

        num = rand() % (arrayInt->getSize());

        cartas->append(new Carta (original.returnPos(arrayInt->returnPos(num))->getValor(),
                                  original.returnPos(arrayInt->returnPos(num))->getSimbolo(),
                                  original.returnPos(arrayInt->returnPos(num))->getColor(),
                                  original.returnPos(arrayInt->returnPos(num))->getPath()) );

        arrayInt->remove(num);
        cont++;
    }
    return *cartas;
}

ArrayCarta<Carta *> Mazo::mazoJugadores()
{
    ArrayCarta<Carta*> mazoCartas = tableroRandom();

    int num;
    srand(time(NULL));

    for(int i=0;i<2;i++){
        num = 1 + rand() % (mazoCartas.getSize()- 0);
        mazoCartas.goToPos(num);
        mazoCartas.insert(new Carta ("J" ,"corazon","rojo",":/imagenes/JC.png"));

        num = 1 + rand() % (mazoCartas.getSize()- 0);
        mazoCartas.goToPos(num);
        mazoCartas.insert(new Carta ("J" ,"diamante","rojo",":/imagenes/JD.png"));

        num = 1 + rand() % (mazoCartas.getSize()- 0);
        mazoCartas.goToPos(num);
        mazoCartas.insert(new Carta ("J" ,"trebol","negro",":/imagenes/JT.png"));

        num = 1 + rand() % (mazoCartas.getSize()- 0);
        mazoCartas.goToPos(num);
        mazoCartas.insert(new Carta ("J" ,"pica","negro",":/imagenes/JP.png"));
    }

    return mazoCartas;
}












