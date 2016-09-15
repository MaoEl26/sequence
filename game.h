#ifndef GAME_H
#define GAME_H
//Opciones para diseño
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QWidget>
#include <QBrush>
#include <QDebug>
#include <QImage>
#include <QMouseEvent>
#include <QPointF>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QFrame>
#include <QCoreApplication>
//Inclusion de funciones del programa
#include "boton.h"
#include "botoncarta.h"
#include "mazo.h"
#include "carta.h"
#include "arraycarta.h"
#include "arraystack.h"
#include "jugador.h"

//#define TamannoMazo 103 //Cantidad de cartas en el mazo 0 a 103


#include <iostream>
using namespace std;


class Game : public QGraphicsView, public Mazo
{
    Q_OBJECT

protected:

    int nextPlay;
    int cantCartas;

    bool turno=true;
    bool key=false;

    //QString Comodin = ":/imagenes/COMODIN.png";
    QString pathCartaTablero;

    BotonCarta *seleccionJugador=new BotonCarta( "NULL",0,0,0);

    ArrayStack<Carta*> *descartes;
    ArrayStack<Carta*> *cartas;

    ArrayCarta<Jugador*> *jugadores;
    ArrayCarta<Ficha*> *arrayFichas;
    ArrayCarta<int> *arrayCoorX;
    ArrayCarta<int> *arrayCoorY;

    QGraphicsPixmapItem *cartaItem;
    QGraphicsPixmapItem *nombreJugador;
    QGraphicsPixmapItem *reverso;
    QGraphicsPixmapItem *itemBaraja;
    QGraphicsPixmapItem *itemFicha;
    QGraphicsPixmapItem *itemFicha2;
    QGraphicsPixmapItem *itemFicha3;
    QGraphicsPixmapItem *itemDescarte;
    QGraphicsPixmapItem *itemFichaTablero;


public:
    Game();

    //Metodos de funcionamiento principales
    void ambiente();
    void agregarBotonesJugar();

    void Table();
    void botonesTablero(ArrayCarta<Carta*> matrizCartas);
    void cartasJugador(ArrayCarta<Carta *> cartasJgd);

    void mazoCartasDescartes(BotonCarta *cartaDescarte);

    void cantidadJugadores(int players);

    void muestraCartaDescarte(QString pathDescarte);
    void muestraCartaMazo(QString pathMazo);
    void muestraFichaJugador(QString pathFicha);
    void muestraNombreJugador(QString JugadorPath);
    void muestraFichaTablero(int coorX,int coorY);

    void almacenaFicha(Ficha* ficha, int coorX, int coorY);
    void borrarFicha(int coorX,int coorY);

    void evaluaGameHorizontal(int pCoorX, int pCoorY);
    void evaluaGameVertical(int pCoorX, int pCoorY);
    void evaluaGameDiagonalDerecho(int pCoorX, int pCoorY);
    void evaluaGameDiagonalIzquierdo(int pCoorX,int pCoorY);
    bool evaluaComodin(int coorX, int coorY);

    ArrayCarta<Carta *> *listaCartas(int cantCartas);

    Ficha* analizarFicha(int coorX, int coorY);

    //Escena del juego
    QGraphicsScene *scene;

    Jugador *jugador1;
    Jugador *jugador2;
    Jugador *jugador3;
    Jugador *jugador4;
    Jugador *jugador5;
    Jugador *jugador6;
    Jugador *jugador7;
    Jugador *jugador8;
    Jugador *jugador9;
    Jugador *jugador10;
    Jugador *jugador11;
    Jugador *jugador12;


    //Botones de Menú
    Boton *startButton;
    Boton *wikiButton;
    Boton *exitButton; 
    Boton *backButton;
    Boton *randomButton;
    Boton *nextButton;
    Boton *undoButton;
    Boton *redoButton;


    //Botones jugadores
    Boton *plays2B;
    Boton *plays3B;
    Boton *plays4B;
    Boton *plays6B;
    Boton *plays8B;
    Boton *plays9B;
    Boton *plays10B;
    Boton *plays12B;

    //Botones Cartas Jugadores
    BotonCarta *Carta01;
    BotonCarta *Carta02;
    BotonCarta *Carta03;
    BotonCarta *Carta04;
    BotonCarta *Carta05;
    BotonCarta *Carta06;
    BotonCarta *Carta07;

    //Botones Matriz
    BotonCarta *Pos000;
    BotonCarta *Pos001;
    BotonCarta *Pos002;
    BotonCarta *Pos003;
    BotonCarta *Pos004;
    BotonCarta *Pos005;
    BotonCarta *Pos006;
    BotonCarta *Pos007;
    BotonCarta *Pos008;
    BotonCarta *Pos009;
    BotonCarta *Pos010;
    BotonCarta *Pos011;
    BotonCarta *Pos012;
    BotonCarta *Pos013;
    BotonCarta *Pos014;
    BotonCarta *Pos015;
    BotonCarta *Pos016;
    BotonCarta *Pos017;
    BotonCarta *Pos018;
    BotonCarta *Pos019;
    BotonCarta *Pos020;
    BotonCarta *Pos021;
    BotonCarta *Pos022;
    BotonCarta *Pos023;
    BotonCarta *Pos024;
    BotonCarta *Pos025;
    BotonCarta *Pos026;
    BotonCarta *Pos027;
    BotonCarta *Pos028;
    BotonCarta *Pos029;
    BotonCarta *Pos030;
    BotonCarta *Pos031;
    BotonCarta *Pos032;
    BotonCarta *Pos033;
    BotonCarta *Pos034;
    BotonCarta *Pos035;
    BotonCarta *Pos036;
    BotonCarta *Pos037;
    BotonCarta *Pos038;
    BotonCarta *Pos039;
    BotonCarta *Pos040;
    BotonCarta *Pos041;
    BotonCarta *Pos042;
    BotonCarta *Pos043;
    BotonCarta *Pos044;
    BotonCarta *Pos045;
    BotonCarta *Pos046;
    BotonCarta *Pos047;
    BotonCarta *Pos048;
    BotonCarta *Pos049;
    BotonCarta *Pos050;
    BotonCarta *Pos051;
    BotonCarta *Pos052;
    BotonCarta *Pos053;
    BotonCarta *Pos054;
    BotonCarta *Pos055;
    BotonCarta *Pos056;
    BotonCarta *Pos057;
    BotonCarta *Pos058;
    BotonCarta *Pos059;
    BotonCarta *Pos060;
    BotonCarta *Pos061;
    BotonCarta *Pos062;
    BotonCarta *Pos063;
    BotonCarta *Pos064;
    BotonCarta *Pos065;
    BotonCarta *Pos066;
    BotonCarta *Pos067;
    BotonCarta *Pos068;
    BotonCarta *Pos069;
    BotonCarta *Pos070;
    BotonCarta *Pos071;
    BotonCarta *Pos072;
    BotonCarta *Pos073;
    BotonCarta *Pos074;
    BotonCarta *Pos075;
    BotonCarta *Pos076;
    BotonCarta *Pos077;
    BotonCarta *Pos078;
    BotonCarta *Pos079;
    BotonCarta *Pos080;
    BotonCarta *Pos081;
    BotonCarta *Pos082;
    BotonCarta *Pos083;
    BotonCarta *Pos084;
    BotonCarta *Pos085;
    BotonCarta *Pos086;
    BotonCarta *Pos087;
    BotonCarta *Pos088;
    BotonCarta *Pos089;
    BotonCarta *Pos090;
    BotonCarta *Pos091;
    BotonCarta *Pos092;
    BotonCarta *Pos093;
    BotonCarta *Pos094;
    BotonCarta *Pos095;
    BotonCarta *Pos096;
    BotonCarta *Pos097;
    BotonCarta *Pos098;
    BotonCarta *Pos099;

public slots:
        /// aqui va la respuesta de los boton
        void startMenu();
        void wiki();
        void exit();
        void seteoBotones();
        void random();
        void next();
        void undo();
        //void redo();

        ///Funciones de los botones de jugador
        void play2();
        void play3();
        void play4();
        void play6();
        void play8();
        void play9();
        void play10();
        void play12();

        ///Almacena Path's y compara
        void evaluaFicha(BotonCarta *botonTablero);
        void obtienePathCarta(BotonCarta *boton);
};

#endif // GAME_H
