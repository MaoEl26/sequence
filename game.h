#ifndef GAME_H
#define GAME_H
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
#include "boton.h"
#include "botoncarta.h"
#include "mazo.h"

#include <iostream>
using namespace std;


class Game : public QGraphicsView
{
    Q_OBJECT

public:
    Game();

    void ambiente();
    void agregarBotonJugar();
    void Table();

    QGraphicsScene *scene;

    //Botones de Menú
    Boton *startButton;
    Boton *wikiButton;
    Boton *exitButton; 
    Boton *backButton;

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
    Boton *Carta01;
    Boton *Carta02;
    Boton *Carta03;
    Boton *Carta04;
    Boton *Carta05;
    Boton *Carta06;
    Boton *Carta07;

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

    QImage holi;

public slots:
        /// aqui va la respuesta de los boton
        void start();
        void wiki();
        void exit();
        void seteoBotones();

        void play2();
        void play3();
        void play4();
        void play6();
        void play8();
        void play9();
        void play10();
        void play12();




};

#endif // GAME_H
