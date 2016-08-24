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


class Game : public QGraphicsView
{
    Q_OBJECT

public:
    Game();

    void ambiente();
    void agregarBotonJugar();
    void table(int players);

    QGraphicsScene *scene;

    Boton *startButton;
    Boton *wikiButton;
    Boton *exitButton; 
    Boton *noButton;
    Boton *yesButton;
    Boton *testButton;
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
