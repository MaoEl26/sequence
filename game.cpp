#include "game.h"
#include "jugador.h"
#include "mazo.h"
#include "carta.h"
#include "arraycarta.h"

#include <iostream>

using namespace std;

//Define la cantidad de jugadores que pueden ser utilizados
#define nulo 0
#define players2 2
#define players3 3
#define players4 4
#define players6 6
#define players8 8
#define players9 9
#define players10 10
#define players12 12
#define largoLista 7
#define cartas2Jugadores 7
#define cartas3Jugadores 6
#define cartas4Jugadores 6
#define cartas6Jugadores 5
#define cartas8Jugadores 4
#define cartas9Jugadores 4
#define cartas10Jugadores 3
#define cartas12Jugadores 3

//Define el largo de las listas a utilizar
#define largoListaFichas 100
#define largoMazoCartas 103

//Define los paths de las cartas de mas uso
#define jotaDiamante ":/imagenes/JD.png"
#define jotaCorazon ":/imagenes/JC.png"
#define jotaTrebol ":/imagenes/JT.png"
#define jotaPicas ":/imagenes/JP.png"
#define Comodin ":/imagenes/COMODIN.png"
#define cartaReverso ":/imagenes/REVERSO.png"
#define basePila ":/imagenes/basepila.png"

//Avance Coordenadas en el tablero
#define avanceCoorX 85
#define avanceCoorY 58

//Tope de coordenadas
#define topeSuperior 35
#define topeIzquierdo 230
#define topeInferior 557
#define topeDerecho 995

//Control de las secuencias
#define secuenciaFicha 5
#define largoSecuencia 4

Game::Game()
{

    ambiente();
    agregarBotonesJugar();
    show();
}

void Game::ambiente(){
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1300, 660);
    setScene(scene);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1350,680);
}

void Game::seteoBotones(){
    agregarBotonesJugar();
}

void Game::agregarBotonesJugar(){
    //Boton de inicio del Juego
    scene->clear();

    scene->setBackgroundBrush(QBrush(QImage(":/imagenes/FondoInicio2.png")));

    startButton= new Boton("Start Game",":/imagenes/startButton.png");
    startButton->setPos(388,440);
    connect(startButton, SIGNAL(clicked()), this, SLOT(startMenu()));

    //Botón de menu de ayuda
    wikiButton= new Boton("Help",":/imagenes/Helpbutton.png");
    wikiButton->setPos(550,440);
    connect(wikiButton,SIGNAL(clicked()),this,SLOT(wiki()));

    //Boton de Salida del juego
    exitButton = new Boton("Exit",":/imagenes/exitButton.png");
    exitButton->setPos(712,440);
    connect(exitButton,SIGNAL(clicked()),this,SLOT(exit()));

    //Agrega los botones en la escena
    scene->addItem(startButton);
    scene->addItem(wikiButton);
    scene->addItem(exitButton);
}

void Game::startMenu(){
    cartas = mazoJugadores();

    scene->clear();//Limpia la escena
    scene->setBackgroundBrush(QBrush(QImage(":/imagenes/fondoJugadores.png")));//Cambia el fondo

    plays2B = new Boton("2 jugadores",":/imagenes/2plays.png");//Crea el botón de 2 Jugadores
    plays2B->setPos(300,130);//Establece la posición en la que se va a ubicar
    connect(plays2B,SIGNAL(clicked()),this,SLOT(play2()));//Establece la acción que va a realizar

    plays3B = new Boton("3 jugadores",":/imagenes/3plays.png");//Crea el botón de 3 Jugadores
    plays3B->setPos(700,130);//Establece la posición en la que se va a ubicar
    connect(plays3B,SIGNAL(clicked()),this,SLOT(play3()));//Establece la acción que va a realizar

    plays4B = new Boton("4 jugadores",":/imagenes/4plays.png");//Crea el botón de 4 Jugadores
    plays4B->setPos(150,300);//Establece la posición en la que se va a ubicar
    connect(plays4B,SIGNAL(clicked()),this,SLOT(play4()));//Establece la acción que va a realizar

    plays6B = new Boton("6 jugadores",":/imagenes/6plays.png");//Crea el botón de 6 Jugadores
    plays6B->setPos(500,300);//Establece la posición en la que se va a ubicar
    connect(plays6B,SIGNAL(clicked()),this,SLOT(play6()));//Establece la acción que va a realizar

    plays8B = new Boton("8 jugadores",":/imagenes/8plays.png");//Crea el botón de 8 Jugadores
    plays8B->setPos(850,300);//Establece la posición en la que se va a ubicar
    connect(plays8B,SIGNAL(clicked()),this,SLOT(play8()));//Establece la acción que va a realizar

    plays9B = new Boton("9 jugadores",":/imagenes/9plays.png");//Crea el botón de 9 Jugadores
    plays9B->setPos(150,480);//Establece la posición en la que se va a ubicar
    connect(plays9B,SIGNAL(clicked()),this,SLOT(play9()));//Establece la acción que va a realizar

    plays10B = new Boton("10 jugadores",":/imagenes/10plays.png");//Crea el botón de 10 Jugadores
    plays10B->setPos(500,480);//Establece la posición en la que se va a ubicar
    connect(plays10B,SIGNAL(clicked()),this,SLOT(play10()));//Establece la acción que va a realizar

    plays12B = new Boton("12 jugadores",":/imagenes/12plays.png");//Crea el botón de 12 Jugadores
    plays12B->setPos(850,480);//Establece la posición en la que se va a ubicar
    connect(plays12B,SIGNAL(clicked()),this,SLOT(play12()));//Establece la acción que va a realizar

    backButton = new Boton("Atrás",":/imagenes/backButton.png");//Crea el botón de back
    backButton->setPos(0,0);//Establece la posición en la que se va a ubicar
    connect(backButton,SIGNAL(clicked()),this,SLOT(seteoBotones()));//Establece la acción que va a realizar


    //Añade los botones a la pantalla
    scene->addItem(plays2B);
    scene->addItem(plays3B);
    scene->addItem(plays4B);
    scene->addItem(plays6B);
    scene->addItem(plays8B);
    scene->addItem(plays9B);
    scene->addItem(plays10B);
    scene->addItem(plays12B);
    scene->addItem(backButton);

}

void Game::wiki(){
    //Crea el wiki
    scene->clear();//Limpia la Pantalla
    scene->setBackgroundBrush(QBrush(QImage(":/imagenes/fondoJugadores.png")));//Inserta el nuevo fondo
    backButton = new Boton("Atrás",":/imagenes/backButton.png");//Crea el botón de Back
    backButton->setPos(0,0);//Establece la posícion
    connect(backButton,SIGNAL(clicked()),this,SLOT(seteoBotones()));//Establece la acción que va a realizar
    scene->addItem(backButton);//Añade el botón a la pantalla

    //Prueba
      QImage holi11(":/imagenes/10P.png");
      QGraphicsPixmapItem *item11= new QGraphicsPixmapItem( QPixmap::fromImage(holi11));

      item11->setPos(0,100);
      item11->setScale(0.55);
      item11->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
      scene->addItem(item11);
}

void Game::exit(){
    //LLama a CoreApp para la salida del programa
    QCoreApplication::quit();
}

void Game::random(){

    //Elimina las cartas
    //Fila 0
    delete Pos000;
    delete Pos001;
    delete Pos002;
    delete Pos003;
    delete Pos004;
    delete Pos005;
    delete Pos006;
    delete Pos007;
    delete Pos008;
    delete Pos009;

    //Fila 1
    delete Pos010;
    delete Pos011;
    delete Pos012;
    delete Pos013;
    delete Pos014;
    delete Pos015;
    delete Pos016;
    delete Pos017;
    delete Pos018;
    delete Pos019;

    //Fila 2
    delete Pos020;
    delete Pos021;
    delete Pos022;
    delete Pos023;
    delete Pos024;
    delete Pos025;
    delete Pos026;
    delete Pos027;
    delete Pos028;
    delete Pos029;

    //Fila 3
    delete Pos030;
    delete Pos031;
    delete Pos032;
    delete Pos033;
    delete Pos034;
    delete Pos035;
    delete Pos036;
    delete Pos037;
    delete Pos038;
    delete Pos039;

    //Fila 4
    delete Pos040;
    delete Pos041;
    delete Pos042;
    delete Pos043;
    delete Pos044;
    delete Pos045;
    delete Pos046;
    delete Pos047;
    delete Pos048;
    delete Pos049;

    //Fila 5
    delete Pos050;
    delete Pos051;
    delete Pos052;
    delete Pos053;
    delete Pos054;
    delete Pos055;
    delete Pos056;
    delete Pos057;
    delete Pos058;
    delete Pos059;

    //Fila 6
    delete Pos060;
    delete Pos061;
    delete Pos062;
    delete Pos063;
    delete Pos064;
    delete Pos065;
    delete Pos066;
    delete Pos067;
    delete Pos068;
    delete Pos069;

    //Fila 7
    delete Pos070;
    delete Pos071;
    delete Pos072;
    delete Pos073;
    delete Pos074;
    delete Pos075;
    delete Pos076;
    delete Pos077;
    delete Pos078;
    delete Pos079;

    //Fila 8
    delete Pos080;
    delete Pos081;
    delete Pos082;
    delete Pos083;
    delete Pos084;
    delete Pos085;
    delete Pos086;
    delete Pos087;
    delete Pos088;
    delete Pos089;

    //Fila 9
    delete Pos090;
    delete Pos091;
    delete Pos092;
    delete Pos093;
    delete Pos094;
    delete Pos095;
    delete Pos096;
    delete Pos097;
    delete Pos098;
    delete Pos099;

    int largo= descartes->getSize();

    for (int i=0; i< largo; i++){
        cartas->push(descartes->pop());
    }
    delete nombreJugador;
    delete itemDescarte;

    arrayFichas->clear();
    arrayCoorX->clear();
    arrayCoorY->clear();

    muestraCartaDescarte(basePila);
    muestraFichaJugador(jugador1->getFicha()->getPath());
    muestraNombreJugador(jugador1->getPath());
    cartasJugador(jugador1->getCards());
    nextPlay= nulo;
    turno= true;
    botonesTablero(tableroRandom());
}

void Game::Table(){
    descartes = new ArrayStack<Carta*>(largoMazoCartas);
    arrayFichas= new ArrayCarta<Ficha*>(largoListaFichas);
    arrayCoorX= new ArrayCarta<int>(largoListaFichas);
    arrayCoorY= new ArrayCarta<int> (largoListaFichas);

    scene->clear();

    scene->setBackgroundBrush(QBrush(QImage(":/imagenes/fondo.png")));//Inserta el nuevo fondo

    backButton = new Boton("Atrás",":/imagenes/backButton.png");//Crea el botón de Back
    backButton->setPos(0,0);//Establece la posícion
    connect(backButton,SIGNAL(clicked()),this,SLOT(seteoBotones()));//Establece la acción que va a realizar
    scene->addItem(backButton);//Añade el botón a la pantalla

    randomButton = new Boton("random",":/imagenes/randomButton.png");
    randomButton->setPos(10,600);
    connect(randomButton,SIGNAL(clicked()),this,SLOT(random()));
    scene->addItem(randomButton);

    redoButton = new Boton("redo",":/imagenes/redoButton.png");
    redoButton->setPos(110,560);
    scene->addItem(redoButton);

    undoButton = new Boton("undo",":/imagenes/UndoButton.png");
    undoButton->setPos(0,560);
    connect(undoButton,SIGNAL(clicked()),this,SLOT(undo()));
    scene->addItem(undoButton);

    nextButton = new Boton("next",":/imagenes/NextButton.png");
    nextButton->setPos(1120,600);
    connect(nextButton,SIGNAL(clicked()),this,SLOT(next()));
    scene->addItem(nextButton);

    muestraCartaDescarte(basePila);
    muestraCartaMazo(cartaReverso);
    botonesTablero(mazoTablero());
    nextPlay =nulo;
}

void Game::undo(){


}

void Game::next(){
    //Aumenta jugador
    //llama lista carta

    if(turno==false){
    delete nombreJugador; //Elimina la imagen con el nombre del jugador actual

    //Elimina las fichas para no sobreescribir
    delete itemFicha;
    delete itemFicha2;
    delete itemFicha3;
    delete reverso;

    //Elimina las cartas para no sobreescribir

    delete Carta01;
    delete Carta02;
    delete Carta03;
    delete Carta04;
    delete Carta05;
    delete Carta06;
    delete Carta07;

    //Indica que el siguiente jugador ya puede poner su fica
    turno= true;
    //Set seleccion jugador
    seleccionJugador=new BotonCarta("NULL",nulo,nulo,nulo);
    //Muestra el nombre del siguiente jugador


    if (nextPlay+1 < jugadores->getSize()){
        nextPlay++;
        muestraFichaJugador(jugadores->returnPos(nextPlay)->getFicha()->getPath());
        muestraNombreJugador(jugadores->returnPos(nextPlay)->getPath());
        cartasJugador(jugadores->returnPos(nextPlay)->getCards());
    }
    else{
        nextPlay=nulo;
        muestraFichaJugador(jugadores->returnPos(nextPlay)->getFicha()->getPath());
        muestraNombreJugador(jugadores->returnPos(nextPlay)->getPath());
        cartasJugador(jugadores->returnPos(nextPlay)->getCards());
    }
    }

}

void Game::muestraFichaJugador(QString pathFicha){
    QImage representacionFicha(pathFicha);
    itemFicha= new QGraphicsPixmapItem( QPixmap::fromImage(representacionFicha));
    itemFicha2= new QGraphicsPixmapItem( QPixmap::fromImage(representacionFicha));
    itemFicha3 = new QGraphicsPixmapItem( QPixmap::fromImage(representacionFicha));

    itemFicha->setPos(55,100);
    itemFicha2->setPos(25,130);
    itemFicha3->setPos(85,130);

    //itemFicha->setScale(0.7);
    scene->addItem(itemFicha3);
    scene->addItem(itemFicha2);
    scene->addItem(itemFicha);
}

void Game::muestraNombreJugador(QString JugadorPath){
    QImage jugadorImagen(JugadorPath);

    nombreJugador= new QGraphicsPixmapItem( QPixmap::fromImage(jugadorImagen));
    nombreJugador->setPos(1115,40);
    nombreJugador->setScale(0.7);

    scene->addItem(nombreJugador);
}

void Game::muestraFichaTablero(int coorX, int coorY){

    if (turno){

    QImage jugadorImagen(jugadores->returnPos(nextPlay)->getFicha()->getPath());

    itemFichaTablero= new QGraphicsPixmapItem( QPixmap::fromImage(jugadorImagen));
    itemFichaTablero->setPos(coorX+20,coorY+5);
    itemFichaTablero->setScale(0.5);

    scene->addItem(itemFichaTablero);

    //Turno de jugador actual a finalizado
    turno= false;

    //Muestra el reverso de la carta cuando ya es utilizada
    QImage borrar(cartaReverso);
    reverso= new QGraphicsPixmapItem( QPixmap::fromImage(borrar));
    reverso->setPos(seleccionJugador->posX(),seleccionJugador->posY());
    reverso->setScale(0.65);
    scene->addItem(reverso);
    }
}

void Game::muestraCartaDescarte(QString pathDescarte){
    //Muestra en la pila de descartes la ultima carta utilizada
    //por lo jugadores
    QImage descarte(pathDescarte);
    itemDescarte= new QGraphicsPixmapItem( QPixmap::fromImage(descarte));

    itemDescarte->setPos(45,400);
    itemDescarte->setScale(0.7);

    if (pathDescarte!=basePila){
        QGraphicsDropShadowEffect* brush = new QGraphicsDropShadowEffect;
        brush->setColor(Qt::black);
        itemDescarte->setGraphicsEffect(brush);
    }

    scene->addItem(itemDescarte);

}

void Game::mazoCartasDescartes(BotonCarta *cartaDescarte){
    //se almacena la instancia de la carta en la pila
    //Se obtiene el path y lo presenta en la carta
    //elimina el path de la pila mazo

    delete itemDescarte;

    muestraCartaDescarte(cartaDescarte->getPath());

    descartes->push(jugadores->returnPos(nextPlay)->getCards().remove(cartaDescarte->getIDCarta()));

    if (cartas->isEmpty()){
           jugadores->returnPos(nextPlay)->getCards().goToPos(nulo);
           jugadores->returnPos(nextPlay)->getCards().insert(new Carta("NULL","NULL","NULL",cartaReverso));
           muestraCartaMazo(basePila);
    }
    else{
        jugadores->returnPos(nextPlay)->getCards().goToPos(nulo);
        jugadores->returnPos(nextPlay)->getCards().insert(cartas->topValue());

        cartas->pop();
    }

}

void Game::muestraCartaMazo(QString pathMazo){

    //Muestra la imagen de la pila de descartes
    QImage baraja(pathMazo);
    itemBaraja= new QGraphicsPixmapItem( QPixmap::fromImage(baraja));

    itemBaraja->setPos(45,270);
    itemBaraja->setScale(0.7);

    if (pathMazo!=basePila){
        QGraphicsDropShadowEffect* brush = new QGraphicsDropShadowEffect;
        brush->setColor(Qt::black);
        itemBaraja->setGraphicsEffect(brush);
    }

    scene->addItem(itemBaraja);
}

void Game::cantidadJugadores(int players){

    //inicializa en array de jugadores con el largo correspondiente
    jugadores= new ArrayCarta<Jugador*>(players);

    //Crea las fichas a utilizar
    Ficha *ficha1 = new Ficha(1,"Azul",":/imagenes/FICHA _AZUL.png");
    Ficha *ficha2 = new Ficha(2,"Morado",":/imagenes/FICHA _MORADA.png");
    Ficha *ficha3 = new Ficha(3,"Verde",":/imagenes/FICHA _VERDE.png");

    //Crea 2 jugadores
    if (players==players2){
        cantCartas=cartas2Jugadores;

        ArrayCarta<Carta*> *manoJugador=listaCartas(cantCartas);
        jugador1 = new Jugador("Jugador 1",ficha1,cantCartas,":/imagenes/etiquetaJug1.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador2 = new Jugador("Jugador 2",ficha3,cantCartas,":/imagenes/etiquetaJug2.png",manoJugador);

        jugadores->append(jugador1);
        jugadores->append(jugador2);

        muestraFichaJugador(jugador1->getFicha()->getPath());
        muestraNombreJugador(jugador1->getPath());
        cartasJugador(jugador1->getCards());
    }
    //crea 3 jugadores
    if (players==players3){
        cantCartas=cartas3Jugadores;

        ArrayCarta<Carta*> *manoJugador=listaCartas(cantCartas);
        jugador1 = new Jugador("Jugador 1",ficha1,cantCartas,":/imagenes/etiquetaJug1.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador2 = new Jugador("Jugador 2",ficha2,cantCartas,":/imagenes/etiquetaJug2.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador3 = new Jugador("Jugador 3",ficha3,cantCartas,":/imagenes/etiquetaJug3.png",manoJugador);

        jugadores->append(jugador1);
        jugadores->append(jugador2);
        jugadores->append(jugador3);

        muestraFichaJugador(jugador1->getFicha()->getPath());
        muestraNombreJugador(jugador1->getPath());
        cartasJugador(jugador1->getCards());
    }
    //crea 4 jugadores
    if (players==players4){
        cantCartas=cartas4Jugadores;

        ArrayCarta<Carta*> *manoJugador=listaCartas(cantCartas);
        jugador1 = new Jugador("Jugador 1",ficha1,cantCartas,":/imagenes/etiquetaJug1.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador2 = new Jugador("Jugador 2",ficha3,cantCartas,":/imagenes/etiquetaJug2.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador3 = new Jugador("Jugador 3",ficha1,cantCartas,":/imagenes/etiquetaJug3.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador4 = new Jugador("Jugador 4",ficha3,cantCartas,":/imagenes/etiquetaJug4.png",manoJugador);

        jugadores->append(jugador1);
        jugadores->append(jugador2);
        jugadores->append(jugador3);
        jugadores->append(jugador4);

        muestraFichaJugador(jugador1->getFicha()->getPath());
        muestraNombreJugador(jugador1->getPath());
        cartasJugador(jugador1->getCards());
    }
    //Crea 6 jugadores
    if (players==players6){
        cantCartas=cartas6Jugadores;

        ArrayCarta<Carta*> *manoJugador=listaCartas(cantCartas);
        jugador1 = new Jugador("Jugador 1",ficha1,cantCartas,":/imagenes/etiquetaJug1.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador2 = new Jugador("Jugador 2",ficha2,cantCartas,":/imagenes/etiquetaJug2.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador3 = new Jugador("Jugador 3",ficha3,cantCartas,":/imagenes/etiquetaJug3.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador4 = new Jugador("Jugador 4",ficha1,cantCartas,":/imagenes/etiquetaJug4.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador5 = new Jugador("Jugador 5",ficha2,cantCartas,":/imagenes/etiquetaJug5.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador6 = new Jugador("Jugador 6",ficha3,cantCartas,":/imagenes/etiquetaJug6.png",manoJugador);

        jugadores->append(jugador1);
        jugadores->append(jugador2);
        jugadores->append(jugador3);
        jugadores->append(jugador4);
        jugadores->append(jugador5);
        jugadores->append(jugador6);

        muestraFichaJugador(jugador1->getFicha()->getPath());
        muestraNombreJugador(jugador1->getPath());
        cartasJugador(jugador1->getCards());
    }
    //Crea 8 jugadores
    if (players==players8){
        cantCartas=cartas8Jugadores;

        ArrayCarta<Carta*> *manoJugador=listaCartas(cantCartas);
        jugador1 = new Jugador("Jugador 1",ficha1,cantCartas,":/imagenes/etiquetaJug1.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador2 = new Jugador("Jugador 2",ficha3,cantCartas,":/imagenes/etiquetaJug2.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador3 = new Jugador("Jugador 3",ficha1,cantCartas,":/imagenes/etiquetaJug3.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador4 = new Jugador("Jugador 4",ficha3,cantCartas,":/imagenes/etiquetaJug4.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador5 = new Jugador("Jugador 5",ficha1,cantCartas,":/imagenes/etiquetaJug5.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador6 = new Jugador("Jugador 6",ficha3,cantCartas,":/imagenes/etiquetaJug6.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador7 = new Jugador("Jugador 7",ficha1,cantCartas,":/imagenes/etiquetaJug7.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador8 = new Jugador("Jugador 8",ficha3,cantCartas,":/imagenes/etiquetaJug8.png",manoJugador);

        jugadores->append(jugador1);
        jugadores->append(jugador2);
        jugadores->append(jugador3);
        jugadores->append(jugador4);
        jugadores->append(jugador5);
        jugadores->append(jugador6);
        jugadores->append(jugador7);
        jugadores->append(jugador8);

        muestraFichaJugador(jugador1->getFicha()->getPath());
        muestraNombreJugador(jugador1->getPath());
        cartasJugador(jugador1->getCards());
    }
    //Crea 9 jugadores
    if (players==players9){
        cantCartas=cartas9Jugadores;

        ArrayCarta<Carta*> *manoJugador=listaCartas(cantCartas);
        jugador1 = new Jugador("Jugador 1",ficha1,cantCartas,":/imagenes/etiquetaJug1.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador2 = new Jugador("Jugador 2",ficha2,cantCartas,":/imagenes/etiquetaJug2.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador3 = new Jugador("Jugador 3",ficha3,cantCartas,":/imagenes/etiquetaJug3.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador4 = new Jugador("Jugador 4",ficha1,cantCartas,":/imagenes/etiquetaJug4.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador5 = new Jugador("Jugador 5",ficha2,cantCartas,":/imagenes/etiquetaJug5.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador6 = new Jugador("Jugador 6",ficha3,cantCartas,":/imagenes/etiquetaJug6.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador7 = new Jugador("Jugador 7",ficha1,cantCartas,":/imagenes/etiquetaJug7.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador8 = new Jugador("Jugador 8",ficha2,cantCartas,":/imagenes/etiquetaJug8.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador9 = new Jugador("Jugador 9",ficha3,cantCartas,":/imagenes/etiquetaJug9.png",manoJugador);

        jugadores->append(jugador1);
        jugadores->append(jugador2);
        jugadores->append(jugador3);
        jugadores->append(jugador4);
        jugadores->append(jugador5);
        jugadores->append(jugador6);
        jugadores->append(jugador7);
        jugadores->append(jugador8);
        jugadores->append(jugador9);

        muestraFichaJugador(jugador1->getFicha()->getPath());
        muestraNombreJugador(jugador1->getPath());
        cartasJugador(jugador1->getCards());
    }
    //Crea 10 jugadores
    if (players==players10){
        cantCartas=cartas10Jugadores;

        ArrayCarta<Carta*> *manoJugador=listaCartas(cantCartas);
        jugador1 = new Jugador("Jugador 1",ficha1,cantCartas,":/imagenes/etiquetaJug1.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador2 = new Jugador("Jugador 2",ficha3,cantCartas,":/imagenes/etiquetaJug2.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador3 = new Jugador("Jugador 3",ficha1,cantCartas,":/imagenes/etiquetaJug3.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador4 = new Jugador("Jugador 4",ficha3,cantCartas,":/imagenes/etiquetaJug4.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador5 = new Jugador("Jugador 5",ficha1,cantCartas,":/imagenes/etiquetaJug5.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador6 = new Jugador("Jugador 6",ficha3,cantCartas,":/imagenes/etiquetaJug6.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador7 = new Jugador("Jugador 7",ficha1,cantCartas,":/imagenes/etiquetaJug7.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador8 = new Jugador("Jugador 8",ficha3,cantCartas,":/imagenes/etiquetaJug8.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador9 = new Jugador("Jugador 9",ficha1,cantCartas,":/imagenes/etiquetaJug9.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador10 = new Jugador("Jugador 10",ficha3,cantCartas,":/imagenes/etiquetaJug10.png",manoJugador);

        jugadores->append(jugador1);
        jugadores->append(jugador2);
        jugadores->append(jugador3);
        jugadores->append(jugador4);
        jugadores->append(jugador5);
        jugadores->append(jugador6);
        jugadores->append(jugador7);
        jugadores->append(jugador8);
        jugadores->append(jugador9);
        jugadores->append(jugador10);

        muestraFichaJugador(jugador1->getFicha()->getPath());
        muestraNombreJugador(jugador1->getPath());
        cartasJugador(jugador1->getCards());
    }
    //Crea 12 jugadores
    if (players==players12){
        cantCartas=cartas12Jugadores;

        ArrayCarta<Carta*> *manoJugador=listaCartas(cantCartas);
        jugador1 = new Jugador("Jugador 1",ficha1,cantCartas,":/imagenes/etiquetaJug1.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador2 = new Jugador("Jugador 2",ficha2,cantCartas,":/imagenes/etiquetaJug2.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador3 = new Jugador("Jugador 3",ficha3,cantCartas,":/imagenes/etiquetaJug3.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador4 = new Jugador("Jugador 4",ficha1,cantCartas,":/imagenes/etiquetaJug4.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador5 = new Jugador("Jugador 5",ficha2,cantCartas,":/imagenes/etiquetaJug5.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador6 = new Jugador("Jugador 6",ficha3,cantCartas,":/imagenes/etiquetaJug6.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador7 = new Jugador("Jugador 7",ficha1,cantCartas,":/imagenes/etiquetaJug7.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador8 = new Jugador("Jugador 8",ficha2,cantCartas,":/imagenes/etiquetaJug8.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador9 = new Jugador("Jugador 9",ficha3,cantCartas,":/imagenes/etiquetaJug9.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador10 = new Jugador("Jugador 10",ficha1,cantCartas,":/imagenes/etiquetaJug10.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador11 = new Jugador("Jugador 11",ficha2,cantCartas,":/imagenes/etiquetaJug11.png",manoJugador);

        manoJugador=listaCartas(cantCartas);
        jugador12 = new Jugador("Jugador 12",ficha3,cantCartas,":/imagenes/etiquetaJug12.png",manoJugador);

        jugadores->append(jugador1);
        jugadores->append(jugador2);
        jugadores->append(jugador3);
        jugadores->append(jugador4);
        jugadores->append(jugador5);
        jugadores->append(jugador6);
        jugadores->append(jugador7);
        jugadores->append(jugador8);
        jugadores->append(jugador9);
        jugadores->append(jugador10);
        jugadores->append(jugador11);
        jugadores->append(jugador12);

        muestraFichaJugador(jugador1->getFicha()->getPath());
        muestraNombreJugador(jugador1->getPath());
        cartasJugador(jugador1->getCards());
    }
}

ArrayCarta<Carta*>* Game::listaCartas(int cantCartas){
    //Crea la lista de cartas correspondiente a cada jugador

    ArrayCarta<Carta*>* cartasjugador= new ArrayCarta<Carta*>(largoLista);
    for (int i=0;i<cantCartas;i++){
        cartasjugador->append(cartas->topValue());
        cartas->pop();
    }
    if (cantCartas < largoLista){
        for (int i=cantCartas-1;i<largoLista;i++){
            cartasjugador->append(new Carta("NULL","NULL","NULL",cartaReverso));
        }
    }
    return cartasjugador;
}

void Game::cartasJugador(ArrayCarta<Carta *> cartasJgd){

    //Recibe lista de cartas correspondiente por jugador y las despliega
    //Avance de coordenadas eje X = Estático
    //Avance de coordenadas eje Y = 70
    //Crea el botón por carta
    Carta01 = new BotonCarta( cartasJgd.returnPos(0)->getPath(),1145,95,0);
    Carta02 = new BotonCarta( cartasJgd.returnPos(1)->getPath(),1145,165,1);
    Carta03 = new BotonCarta( cartasJgd.returnPos(2)->getPath(),1145,235,2);
    Carta04 = new BotonCarta( cartasJgd.returnPos(3)->getPath(),1145,305,3);
    Carta05 = new BotonCarta( cartasJgd.returnPos(4)->getPath(),1145,375,4);
    Carta06 = new BotonCarta( cartasJgd.returnPos(5)->getPath(),1145,445,5);
    Carta07 = new BotonCarta( cartasJgd.returnPos(6)->getPath(),1145,515,6);

    //Establece la posicion de cada botón
    Carta01->setPos(Carta01->posX(),Carta01->posY());
    Carta02->setPos(Carta02->posX(),Carta02->posY());
    Carta03->setPos(Carta03->posX(),Carta03->posY());
    Carta04->setPos(Carta04->posX(),Carta04->posY());
    Carta05->setPos(Carta05->posX(),Carta05->posY());
    Carta06->setPos(Carta06->posX(),Carta06->posY());
    Carta07->setPos(Carta07->posX(),Carta07->posY());

    //Establece la escala o tamaño de la carta
    Carta01->setScale(0.65);
    Carta02->setScale(0.65);
    Carta03->setScale(0.65);
    Carta04->setScale(0.65);
    Carta05->setScale(0.65);
    Carta06->setScale(0.65);
    Carta07->setScale(0.65);

    //Le asigna la funcion a cada botón
    connect(Carta01,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(obtienePathCarta(BotonCarta*)));
    connect(Carta02,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(obtienePathCarta(BotonCarta*)));
    connect(Carta03,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(obtienePathCarta(BotonCarta*)));
    connect(Carta04,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(obtienePathCarta(BotonCarta*)));
    connect(Carta05,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(obtienePathCarta(BotonCarta*)));
    connect(Carta06,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(obtienePathCarta(BotonCarta*)));
    connect(Carta07,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(obtienePathCarta(BotonCarta*)));

    //Añade el item a la pantalla
    scene->addItem(Carta01);
    scene->addItem(Carta02);
    scene->addItem(Carta03);
    scene->addItem(Carta04);
    scene->addItem(Carta05);
    scene->addItem(Carta06);
    scene->addItem(Carta07);

}

void Game::obtienePathCarta(BotonCarta* boton){ 
    if(turno){
           seleccionJugador= boton;
    }
}

void Game::almacenaFicha(Ficha* ficha, int coorX, int coorY){
    arrayFichas->append(ficha);
    arrayCoorX->append(coorX);
    arrayCoorY->append(coorY);
}

Ficha* Game::analizarFicha(int coorX, int coorY){
    Ficha *ficha = new Ficha(nulo,"NULL","NULL");
    int largoArrayFichas = arrayFichas->getSize();
    for(int i=0;i < largoArrayFichas;i++){
        if ((arrayCoorX->returnPos(i)== coorX) && (arrayCoorY->returnPos(i)==coorY)){
            return arrayFichas->returnPos(i);
        }
    }
    return ficha;
}

void Game::borrarFicha(int coorX, int coorY){

    int largoArrayFichas = arrayFichas->getSize();
    for(int i=0;i < largoArrayFichas;i++){
        if ((arrayCoorX->returnPos(i)== coorX) && (arrayCoorY->returnPos(i)==coorY)){
            arrayCoorX->remove(i);
            arrayCoorY->remove(i);
            arrayFichas->remove(i);
        }
    }
}

void Game::evaluaFicha(BotonCarta *botonTablero){
    pathCartaTablero= botonTablero->getPath();
    if (seleccionJugador->getPath()== pathCartaTablero){
        if(analizarFicha(botonTablero->posX(),botonTablero->posY())->getID()==0){

            almacenaFicha(jugadores->returnPos(nextPlay)->getFicha()
                          ,botonTablero->posX(),botonTablero->posY());

            muestraFichaTablero(botonTablero->posX(), botonTablero->posY());

            mazoCartasDescartes(seleccionJugador);

            evaluaGameVertical(botonTablero->posX(),botonTablero->posY());
            evaluaGameHorizontal(botonTablero->posX(),botonTablero->posY());
            evaluaGameDiagonalDerecho(botonTablero->posX(),botonTablero->posY());
            evaluaGameDiagonalIzquierdo(botonTablero->posX(),botonTablero->posY());
        }

    }else{
        if (((seleccionJugador->getPath() == jotaDiamante)||
                (seleccionJugador->getPath() == jotaTrebol))&&
                (pathCartaTablero != Comodin )){

            if(analizarFicha(botonTablero->posX(),botonTablero->posY())->getID()==0){

                almacenaFicha(jugadores->returnPos(nextPlay)->getFicha()
                              ,botonTablero->posX(),botonTablero->posY());

                muestraFichaTablero(botonTablero->posX(), botonTablero->posY());

                mazoCartasDescartes(seleccionJugador);

                evaluaGameVertical(botonTablero->posX(),botonTablero->posY());
                evaluaGameHorizontal(botonTablero->posX(),botonTablero->posY());
                evaluaGameDiagonalDerecho(botonTablero->posX(),botonTablero->posY());
                evaluaGameDiagonalIzquierdo(botonTablero->posX(),botonTablero->posY());
            }

        }else{
            if ((seleccionJugador->getPath() == jotaPicas)||
                    (seleccionJugador->getPath() == jotaCorazon)){

                if((analizarFicha(botonTablero->posX(),botonTablero->posY())->getID()!=0)
                         &&(analizarFicha(botonTablero->posX(),botonTablero->posY())->getID()
                            != jugadores->returnPos(nextPlay)->getFicha()->getID())){

                   mazoCartasDescartes(seleccionJugador);

                   borrarFicha(botonTablero->posX(),botonTablero->posY());

                   QImage carta(pathCartaTablero);
                   cartaItem= new QGraphicsPixmapItem( QPixmap::fromImage(carta));
                   cartaItem->setPos(botonTablero->posX(),botonTablero->posY());
                   cartaItem->setScale(0.55);
                   scene->addItem(cartaItem);

                   QImage borrar(cartaReverso);
                   reverso= new QGraphicsPixmapItem( QPixmap::fromImage(borrar));
                   reverso->setPos(seleccionJugador->posX(),seleccionJugador->posY());
                   reverso->setScale(0.65);
                   scene->addItem(reverso);

                   turno = false;
                }
            }
        }
    }

}

void Game::evaluaGameHorizontal(int pCoorX, int pCoorY){
    cout<<"Horizontal"<<endl;
    int coorX = pCoorX-avanceCoorX;
    int IDfichaJugadorActual=jugadores->returnPos(nextPlay)->getFicha()->getID();
    bool flag = true;
    int contadorCiclo = 0;
    int cantidadFichas = 1;

    while ((contadorCiclo < largoSecuencia)&&(flag)){
        if (coorX >= topeIzquierdo){
            if (analizarFicha(coorX,pCoorY)->getID()==IDfichaJugadorActual){
                cantidadFichas++;

            }
            else if (evaluaComodin(coorX,pCoorY)){
                cantidadFichas++;
            } else {
                flag = false;
            }

        }
        coorX-=avanceCoorX;
        contadorCiclo++;
    }
    cout<<cantidadFichas<<endl;

    if (cantidadFichas != secuenciaFicha){
        coorX = pCoorX+avanceCoorX;
        flag = true;
        contadorCiclo = 0;

        while ((contadorCiclo < largoSecuencia)&&(flag)){
            if (coorX <= topeDerecho){
                if (analizarFicha(coorX,pCoorY)->getID()==IDfichaJugadorActual){
                    cantidadFichas++;

                }
                else if (evaluaComodin(coorX,pCoorY)){
                    cantidadFichas++;
                } else {
                    flag = false;
                }

            }
            coorX+=avanceCoorX;
            contadorCiclo++;
        }
    }
    cout<<cantidadFichas<<" segundo ciclo horizontal"<<endl;
}

void Game::evaluaGameVertical(int pCoorX, int pCoorY){
    cout<<"vertical"<<endl;
    int coorY = pCoorY-avanceCoorY;
    int IDfichaJugadorActual=jugadores->returnPos(nextPlay)->getFicha()->getID();
    bool flag = true;
    int contadorCiclo = 0;
    int cantidadFichas = 1;

    while ((contadorCiclo < largoSecuencia)&&(flag)){
        if (coorY >= topeSuperior){
            if (analizarFicha(pCoorX,coorY)->getID()==IDfichaJugadorActual){
                cantidadFichas++;
            }
            else if (evaluaComodin(pCoorX,coorY)){
                cantidadFichas++;
            } else {
                flag = false;
            }

        }
        coorY-=avanceCoorY;
        contadorCiclo++;
    }
    cout<<cantidadFichas<<endl;

    if (cantidadFichas != secuenciaFicha){
        coorY = pCoorY+avanceCoorY;
        flag = true;
        contadorCiclo = 0;

        while ((contadorCiclo < largoSecuencia)&&(flag)){
            if (coorY <= topeInferior){
                if (analizarFicha(pCoorX,coorY)->getID()==IDfichaJugadorActual){
                    cantidadFichas++;
                }
                else if (evaluaComodin(pCoorX,coorY)){
                    cantidadFichas++;
                } else {
                    flag = false;
                }

            }
            coorY+=avanceCoorY;
            contadorCiclo++;
        }
    }
    cout<<cantidadFichas<<" segundo ciclo vertical"<<endl;
}

void Game::evaluaGameDiagonalDerecho(int pCoorX, int pCoorY){
    cout<<"Diagonal Derecho"<<endl;
    int coorY = pCoorY-avanceCoorY;
    int coorX = pCoorX-avanceCoorX;
    int IDfichaJugadorActual=jugadores->returnPos(nextPlay)->getFicha()->getID();
    bool flag = true;
    int contadorCiclo = 0;
    int cantidadFichas = 1;

    while ((contadorCiclo < largoSecuencia)&&(flag)){
        if ((coorY >= topeSuperior)||(coorX >= topeIzquierdo)){
            if (analizarFicha(coorX,coorY)->getID()==IDfichaJugadorActual){
                cantidadFichas++;
            }
            else if (evaluaComodin(coorX,coorY)){
                cantidadFichas++;
            } else {
                flag = false;
            }

        }
        coorY-=avanceCoorY;
        coorX-=avanceCoorX;
        contadorCiclo++;
    }
    cout<<cantidadFichas<<endl;

    if (cantidadFichas != secuenciaFicha){
        coorY = pCoorY+avanceCoorY;
        coorX = pCoorX+avanceCoorX;
        flag = true;
        contadorCiclo = 0;

        while ((contadorCiclo < largoSecuencia)&&(flag)){
            if ((coorY <= topeInferior)||(coorX <=topeDerecho)){
                if (analizarFicha(coorX,coorY)->getID()==IDfichaJugadorActual){
                    cantidadFichas++;
                }
                else if (evaluaComodin(coorX,coorY)){
                    cantidadFichas++;
                } else {
                    flag = false;
                }

            }
            coorY+=avanceCoorY;
            coorX+=avanceCoorX;
            contadorCiclo++;
        }
    }
    cout<<cantidadFichas<<" segundo ciclo diagonal derecho"<<endl;
}

void Game::evaluaGameDiagonalIzquierdo(int pCoorX,int pCoorY){
    cout<<"Diagonal Izquierdo"<<endl;
    int coorY = pCoorY-avanceCoorY;
    int coorX = pCoorX+avanceCoorX;
    int IDfichaJugadorActual=jugadores->returnPos(nextPlay)->getFicha()->getID();
    bool flag = true;
    int contadorCiclo = 0;
    int cantidadFichas = 1;

    while ((contadorCiclo < largoSecuencia)&&(flag)){
        if ((coorY >= topeSuperior)||(coorX <= topeDerecho)){
            if (analizarFicha(coorX,coorY)->getID()==IDfichaJugadorActual){
                cantidadFichas++;
            }
            else if (evaluaComodin(coorX,coorY)){
                cantidadFichas++;
            } else {
                flag = false;
            }

        }
        coorY-=avanceCoorY;
        coorX+=avanceCoorX;
        contadorCiclo++;
    }
    cout<<cantidadFichas<<endl;

    if (cantidadFichas != secuenciaFicha){
        coorY = pCoorY+avanceCoorY;
        coorX = pCoorX-avanceCoorX;
        flag = true;
        contadorCiclo = 0;

        while ((contadorCiclo < largoSecuencia)&&(flag)){
            if ((coorY <= topeInferior)||(coorX >=topeIzquierdo)){
                if (analizarFicha(coorX,coorY)->getID()==IDfichaJugadorActual){
                    cantidadFichas++;
                }
                else if (evaluaComodin(coorX,coorY)){
                    cantidadFichas++;
                } else {
                    flag = false;
                }

            }
            coorY+=avanceCoorY;
            coorX-=avanceCoorX;
            contadorCiclo++;
        }
    }
    cout<<cantidadFichas<<" segundo ciclo diagonal izquierdo"<<endl;
}

bool Game::evaluaComodin(int coorX, int coorY){
    return (((coorX == topeDerecho)&& (coorY == topeSuperior))||
            ((coorX == topeIzquierdo)&&(coorY == topeSuperior))||
            ((coorX == topeDerecho)&& (coorY == topeInferior))||
            ((coorX == topeIzquierdo)&&(coorY == topeInferior)));
}

void Game::botonesTablero(ArrayCarta<Carta*> matrizCartas){
    //Creacion y establecimiento de los botones de la matriz tablero
    //Avance de coordenadas eje X = 85
    //Avance de coordenadas eje Y = 58
    //Fila 0
    Pos000 = new BotonCarta(Comodin,230,35,0);//Comodin
    Pos001 = new BotonCarta(matrizCartas.returnPos(0)->getPath(),315,35,1);
    Pos002 = new BotonCarta(matrizCartas.returnPos(1)->getPath(),400,35,2);
    Pos003 = new BotonCarta(matrizCartas.returnPos(2)->getPath(),485,35,3);
    Pos004 = new BotonCarta(matrizCartas.returnPos(3)->getPath(),570,35,4);
    Pos005 = new BotonCarta(matrizCartas.returnPos(4)->getPath(),655,35,5);
    Pos006 = new BotonCarta(matrizCartas.returnPos(5)->getPath(),740,35,6);
    Pos007 = new BotonCarta(matrizCartas.returnPos(6)->getPath(),825,35,7);
    Pos008 = new BotonCarta(matrizCartas.returnPos(7)->getPath(),910,35,8);
    Pos009 = new BotonCarta(Comodin,995,35,9);//Comodin

    //Fila 1
    Pos010 = new BotonCarta(matrizCartas.returnPos(8)->getPath(),230,93,10);
    Pos011 = new BotonCarta(matrizCartas.returnPos(9)->getPath(),315,93,11);
    Pos012 = new BotonCarta(matrizCartas.returnPos(10)->getPath(),400,93,12);
    Pos013 = new BotonCarta(matrizCartas.returnPos(11)->getPath(),485,93,13);
    Pos014 = new BotonCarta(matrizCartas.returnPos(12)->getPath(),570,93,14);
    Pos015 = new BotonCarta(matrizCartas.returnPos(13)->getPath(),655,93,15);
    Pos016 = new BotonCarta(matrizCartas.returnPos(14)->getPath(),740,93,16);
    Pos017 = new BotonCarta(matrizCartas.returnPos(15)->getPath(),825,93,17);
    Pos018 = new BotonCarta(matrizCartas.returnPos(16)->getPath(),910,93,18);
    Pos019 = new BotonCarta(matrizCartas.returnPos(17)->getPath(),995,93,19);

    //Fila 2
    Pos020 = new BotonCarta(matrizCartas.returnPos(18)->getPath(),230,151,20);
    Pos021 = new BotonCarta(matrizCartas.returnPos(19)->getPath(),315,151,21);
    Pos022 = new BotonCarta(matrizCartas.returnPos(20)->getPath(),400,151,22);
    Pos023 = new BotonCarta(matrizCartas.returnPos(21)->getPath(),485,151,23);
    Pos024 = new BotonCarta(matrizCartas.returnPos(22)->getPath(),570,151,24);
    Pos025 = new BotonCarta(matrizCartas.returnPos(23)->getPath(),655,151,25);
    Pos026 = new BotonCarta(matrizCartas.returnPos(24)->getPath(),740,151,26);
    Pos027 = new BotonCarta(matrizCartas.returnPos(25)->getPath(),825,151,27);
    Pos028 = new BotonCarta(matrizCartas.returnPos(26)->getPath(),910,151,28);
    Pos029 = new BotonCarta(matrizCartas.returnPos(27)->getPath(),995,151,29);

    //Fila 3
    Pos030 = new BotonCarta(matrizCartas.returnPos(28)->getPath(),230,209,30);
    Pos031 = new BotonCarta(matrizCartas.returnPos(29)->getPath(),315,209,31);
    Pos032 = new BotonCarta(matrizCartas.returnPos(30)->getPath(),400,209,32);
    Pos033 = new BotonCarta(matrizCartas.returnPos(31)->getPath(),485,209,33);
    Pos034 = new BotonCarta(matrizCartas.returnPos(32)->getPath(),570,209,34);
    Pos035 = new BotonCarta(matrizCartas.returnPos(33)->getPath(),655,209,35);
    Pos036 = new BotonCarta(matrizCartas.returnPos(34)->getPath(),740,209,36);
    Pos037 = new BotonCarta(matrizCartas.returnPos(35)->getPath(),825,209,37);
    Pos038 = new BotonCarta(matrizCartas.returnPos(36)->getPath(),910,209,38);
    Pos039 = new BotonCarta(matrizCartas.returnPos(37)->getPath(),995,209,39);

    //Fila 4
    Pos040 = new BotonCarta(matrizCartas.returnPos(38)->getPath(),230,267,40);
    Pos041 = new BotonCarta(matrizCartas.returnPos(39)->getPath(),315,267,41);
    Pos042 = new BotonCarta(matrizCartas.returnPos(40)->getPath(),400,267,42);
    Pos043 = new BotonCarta(matrizCartas.returnPos(41)->getPath(),485,267,43);
    Pos044 = new BotonCarta(matrizCartas.returnPos(42)->getPath(),570,267,44);
    Pos045 = new BotonCarta(matrizCartas.returnPos(43)->getPath(),655,267,45);
    Pos046 = new BotonCarta(matrizCartas.returnPos(44)->getPath(),740,267,46);
    Pos047 = new BotonCarta(matrizCartas.returnPos(45)->getPath(),825,267,47);
    Pos048 = new BotonCarta(matrizCartas.returnPos(46)->getPath(),910,267,48);
    Pos049 = new BotonCarta(matrizCartas.returnPos(47)->getPath(),995,267,49);

    //Fila 5
    Pos050 = new BotonCarta(matrizCartas.returnPos(48)->getPath(),230,325,50);
    Pos051 = new BotonCarta(matrizCartas.returnPos(49)->getPath(),315,325,51);
    Pos052 = new BotonCarta(matrizCartas.returnPos(50)->getPath(),400,325,52);
    Pos053 = new BotonCarta(matrizCartas.returnPos(51)->getPath(),485,325,53);
    Pos054 = new BotonCarta(matrizCartas.returnPos(52)->getPath(),570,325,54);
    Pos055 = new BotonCarta(matrizCartas.returnPos(53)->getPath(),655,325,55);
    Pos056 = new BotonCarta(matrizCartas.returnPos(54)->getPath(),740,325,56);
    Pos057 = new BotonCarta(matrizCartas.returnPos(55)->getPath(),825,325,57);
    Pos058 = new BotonCarta(matrizCartas.returnPos(56)->getPath(),910,325,58);
    Pos059 = new BotonCarta(matrizCartas.returnPos(57)->getPath(),995,325,59);

    //Fila 6
    Pos060 = new BotonCarta(matrizCartas.returnPos(58)->getPath(),230,383,60);
    Pos061 = new BotonCarta(matrizCartas.returnPos(59)->getPath(),315,383,61);
    Pos062 = new BotonCarta(matrizCartas.returnPos(60)->getPath(),400,383,62);
    Pos063 = new BotonCarta(matrizCartas.returnPos(61)->getPath(),485,383,63);
    Pos064 = new BotonCarta(matrizCartas.returnPos(62)->getPath(),570,383,64);
    Pos065 = new BotonCarta(matrizCartas.returnPos(63)->getPath(),655,383,65);
    Pos066 = new BotonCarta(matrizCartas.returnPos(64)->getPath(),740,383,66);
    Pos067 = new BotonCarta(matrizCartas.returnPos(65)->getPath(),825,383,67);
    Pos068 = new BotonCarta(matrizCartas.returnPos(66)->getPath(),910,383,68);
    Pos069 = new BotonCarta(matrizCartas.returnPos(67)->getPath(),995,383,69);

    //Fila 7
    Pos070 = new BotonCarta(matrizCartas.returnPos(68)->getPath(),230,441,70);
    Pos071 = new BotonCarta(matrizCartas.returnPos(69)->getPath(),315,441,71);
    Pos072 = new BotonCarta(matrizCartas.returnPos(70)->getPath(),400,441,72);
    Pos073 = new BotonCarta(matrizCartas.returnPos(71)->getPath(),485,441,73);
    Pos074 = new BotonCarta(matrizCartas.returnPos(72)->getPath(),570,441,74);
    Pos075 = new BotonCarta(matrizCartas.returnPos(73)->getPath(),655,441,75);
    Pos076 = new BotonCarta(matrizCartas.returnPos(74)->getPath(),740,441,76);
    Pos077 = new BotonCarta(matrizCartas.returnPos(75)->getPath(),825,441,77);
    Pos078 = new BotonCarta(matrizCartas.returnPos(76)->getPath(),910,441,78);
    Pos079 = new BotonCarta(matrizCartas.returnPos(77)->getPath(),995,441,79);

    //Fila 8
    Pos080 = new BotonCarta(matrizCartas.returnPos(78)->getPath(),230,499,80);
    Pos081 = new BotonCarta(matrizCartas.returnPos(79)->getPath(),315,499,81);
    Pos082 = new BotonCarta(matrizCartas.returnPos(80)->getPath(),400,499,82);
    Pos083 = new BotonCarta(matrizCartas.returnPos(81)->getPath(),485,499,83);
    Pos084 = new BotonCarta(matrizCartas.returnPos(82)->getPath(),570,499,84);
    Pos085 = new BotonCarta(matrizCartas.returnPos(83)->getPath(),655,499,85);
    Pos086 = new BotonCarta(matrizCartas.returnPos(84)->getPath(),740,499,86);
    Pos087 = new BotonCarta(matrizCartas.returnPos(85)->getPath(),825,499,87);
    Pos088 = new BotonCarta(matrizCartas.returnPos(86)->getPath(),910,499,88);
    Pos089 = new BotonCarta(matrizCartas.returnPos(87)->getPath(),995,499,89);

    //Fila 9
    Pos090 = new BotonCarta(Comodin,230,557,90);//Comodin
    Pos091 = new BotonCarta(matrizCartas.returnPos(88)->getPath(),315,557,91);
    Pos092 = new BotonCarta(matrizCartas.returnPos(89)->getPath(),400,557,92);
    Pos093 = new BotonCarta(matrizCartas.returnPos(90)->getPath(),485,557,93);
    Pos094 = new BotonCarta(matrizCartas.returnPos(91)->getPath(),570,557,94);
    Pos095 = new BotonCarta(matrizCartas.returnPos(92)->getPath(),655,557,95);
    Pos096 = new BotonCarta(matrizCartas.returnPos(93)->getPath(),740,557,96);
    Pos097 = new BotonCarta(matrizCartas.returnPos(94)->getPath(),825,557,97);
    Pos098 = new BotonCarta(matrizCartas.returnPos(95)->getPath(),910,557,98);
    Pos099 = new BotonCarta(Comodin,995,557,99);//Comodin

    //Funciones de los botones
    //Fila 0
    connect(Pos000,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos001,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos002,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos003,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos004,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos005,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos006,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos007,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos008,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos009,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));

    //Fila 1
    connect(Pos010,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos011,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos012,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos013,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos014,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos015,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos016,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos017,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos018,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos019,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));

    //Fila 2
    connect(Pos020,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos021,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos022,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos023,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos024,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos025,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos026,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos027,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos028,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos029,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));

    //Fila 3
    connect(Pos030,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos031,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos032,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos033,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos034,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos035,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos036,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos037,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos038,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos039,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));

    //Fila 4
    connect(Pos040,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos041,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos042,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos043,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos044,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos045,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos046,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos047,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos048,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos049,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));

    //Fila 5
    connect(Pos050,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos051,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos052,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos053,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos054,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos055,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos056,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos057,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos058,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos059,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));

    //Fila 6
    connect(Pos060,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos061,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos062,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos063,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos064,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos065,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos066,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos067,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos068,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos069,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));

    //Fila 7
    connect(Pos070,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos071,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos072,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos073,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos074,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos075,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos076,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos077,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos078,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos079,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));

    //Fila 8
    connect(Pos080,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos081,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos082,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos083,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos084,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos085,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos086,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos087,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos088,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos089,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));

    //Fila 9
    connect(Pos090,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos091,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos092,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos093,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos094,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos095,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos096,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos097,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos098,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));
    connect(Pos099,SIGNAL(getSignalPath(BotonCarta*)),this,SLOT(evaluaFicha(BotonCarta*)));

    //Coordenadas
    //Fila 0

    Pos000->setPos(Pos000->posX(),Pos000->posY());//Mantener posición
    Pos001->setPos(Pos001->posX(),Pos001->posY());
    Pos002->setPos(Pos002->posX(),Pos002->posY());
    Pos003->setPos(Pos003->posX(),Pos003->posY());
    Pos004->setPos(Pos004->posX(),Pos004->posY());
    Pos005->setPos(Pos005->posX(),Pos005->posY());
    Pos006->setPos(Pos006->posX(),Pos006->posY());
    Pos007->setPos(Pos007->posX(),Pos007->posY());
    Pos008->setPos(Pos008->posX(),Pos008->posY());
    Pos009->setPos(Pos009->posX(),Pos009->posY());

    //Fila 1
    Pos010->setPos(Pos010->posX(),Pos010->posY());
    Pos011->setPos(Pos011->posX(),Pos011->posY());
    Pos012->setPos(Pos012->posX(),Pos012->posY());
    Pos013->setPos(Pos013->posX(),Pos013->posY());
    Pos014->setPos(Pos014->posX(),Pos014->posY());
    Pos015->setPos(Pos015->posX(),Pos015->posY());
    Pos016->setPos(Pos016->posX(),Pos016->posY());
    Pos017->setPos(Pos017->posX(),Pos017->posY());
    Pos018->setPos(Pos018->posX(),Pos018->posY());
    Pos019->setPos(Pos019->posX(),Pos019->posY());

    //Fila 2
    Pos020->setPos(Pos020->posX(),Pos020->posY());
    Pos021->setPos(Pos021->posX(),Pos021->posY());
    Pos022->setPos(Pos022->posX(),Pos022->posY());
    Pos023->setPos(Pos023->posX(),Pos023->posY());
    Pos024->setPos(Pos024->posX(),Pos024->posY());
    Pos025->setPos(Pos025->posX(),Pos025->posY());
    Pos026->setPos(Pos026->posX(),Pos026->posY());
    Pos027->setPos(Pos027->posX(),Pos027->posY());
    Pos028->setPos(Pos028->posX(),Pos028->posY());
    Pos029->setPos(Pos029->posX(),Pos029->posY());

    //Fila 3
    Pos030->setPos(Pos030->posX(),Pos030->posY());
    Pos031->setPos(Pos031->posX(),Pos031->posY());
    Pos032->setPos(Pos032->posX(),Pos032->posY());
    Pos033->setPos(Pos033->posX(),Pos033->posY());
    Pos034->setPos(Pos034->posX(),Pos034->posY());
    Pos035->setPos(Pos035->posX(),Pos035->posY());
    Pos036->setPos(Pos036->posX(),Pos036->posY());
    Pos037->setPos(Pos037->posX(),Pos037->posY());
    Pos038->setPos(Pos038->posX(),Pos038->posY());
    Pos039->setPos(Pos039->posX(),Pos039->posY());

    //Fila 4
    Pos040->setPos(Pos040->posX(),Pos040->posY());
    Pos041->setPos(Pos041->posX(),Pos041->posY());
    Pos042->setPos(Pos042->posX(),Pos042->posY());
    Pos043->setPos(Pos043->posX(),Pos043->posY());
    Pos044->setPos(Pos044->posX(),Pos044->posY());
    Pos045->setPos(Pos045->posX(),Pos045->posY());
    Pos046->setPos(Pos046->posX(),Pos046->posY());
    Pos047->setPos(Pos047->posX(),Pos047->posY());
    Pos048->setPos(Pos048->posX(),Pos048->posY());
    Pos049->setPos(Pos049->posX(),Pos049->posY());

    //Fila 5
    Pos050->setPos(Pos050->posX(),Pos050->posY());
    Pos051->setPos(Pos051->posX(),Pos051->posY());
    Pos052->setPos(Pos052->posX(),Pos052->posY());
    Pos053->setPos(Pos053->posX(),Pos053->posY());
    Pos054->setPos(Pos054->posX(),Pos054->posY());
    Pos055->setPos(Pos055->posX(),Pos055->posY());
    Pos056->setPos(Pos056->posX(),Pos056->posY());
    Pos057->setPos(Pos057->posX(),Pos057->posY());
    Pos058->setPos(Pos058->posX(),Pos058->posY());
    Pos059->setPos(Pos059->posX(),Pos059->posY());

    //Fila 6
    Pos060->setPos(Pos060->posX(),Pos060->posY());
    Pos061->setPos(Pos061->posX(),Pos061->posY());
    Pos062->setPos(Pos062->posX(),Pos062->posY());
    Pos063->setPos(Pos063->posX(),Pos063->posY());
    Pos064->setPos(Pos064->posX(),Pos064->posY());
    Pos065->setPos(Pos065->posX(),Pos065->posY());
    Pos066->setPos(Pos066->posX(),Pos066->posY());
    Pos067->setPos(Pos067->posX(),Pos067->posY());
    Pos068->setPos(Pos068->posX(),Pos068->posY());
    Pos069->setPos(Pos069->posX(),Pos069->posY());

    //Fila 7
    Pos070->setPos(Pos070->posX(),Pos070->posY());
    Pos071->setPos(Pos071->posX(),Pos071->posY());
    Pos072->setPos(Pos072->posX(),Pos072->posY());
    Pos073->setPos(Pos073->posX(),Pos073->posY());
    Pos074->setPos(Pos074->posX(),Pos074->posY());
    Pos075->setPos(Pos075->posX(),Pos075->posY());
    Pos076->setPos(Pos076->posX(),Pos076->posY());
    Pos077->setPos(Pos077->posX(),Pos077->posY());
    Pos078->setPos(Pos078->posX(),Pos078->posY());
    Pos079->setPos(Pos079->posX(),Pos079->posY());

    //Fila 8
    Pos080->setPos(Pos080->posX(),Pos080->posY());
    Pos081->setPos(Pos081->posX(),Pos081->posY());
    Pos082->setPos(Pos082->posX(),Pos082->posY());
    Pos083->setPos(Pos083->posX(),Pos083->posY());
    Pos084->setPos(Pos084->posX(),Pos084->posY());
    Pos085->setPos(Pos085->posX(),Pos085->posY());
    Pos086->setPos(Pos086->posX(),Pos086->posY());
    Pos087->setPos(Pos087->posX(),Pos087->posY());
    Pos088->setPos(Pos088->posX(),Pos088->posY());
    Pos089->setPos(Pos089->posX(),Pos089->posY());

    //Fila 9
    Pos090->setPos(Pos090->posX(),Pos090->posY());
    Pos091->setPos(Pos091->posX(),Pos091->posY());
    Pos092->setPos(Pos092->posX(),Pos092->posY());
    Pos093->setPos(Pos093->posX(),Pos093->posY());
    Pos094->setPos(Pos094->posX(),Pos094->posY());
    Pos095->setPos(Pos095->posX(),Pos095->posY());
    Pos096->setPos(Pos096->posX(),Pos096->posY());
    Pos097->setPos(Pos097->posX(),Pos097->posY());
    Pos098->setPos(Pos098->posX(),Pos098->posY());
    Pos099->setPos(Pos099->posX(),Pos099->posY());

    //Agrega a Pantalla
    //Fila 0
    scene->addItem(Pos000);
    scene->addItem(Pos001);
    scene->addItem(Pos002);
    scene->addItem(Pos003);
    scene->addItem(Pos004);
    scene->addItem(Pos005);
    scene->addItem(Pos006);
    scene->addItem(Pos007);
    scene->addItem(Pos008);
    scene->addItem(Pos009);

    //Fila 1
    scene->addItem(Pos010);
    scene->addItem(Pos011);
    scene->addItem(Pos012);
    scene->addItem(Pos013);
    scene->addItem(Pos014);
    scene->addItem(Pos015);
    scene->addItem(Pos016);
    scene->addItem(Pos017);
    scene->addItem(Pos018);
    scene->addItem(Pos019);

    //Fila 2
    scene->addItem(Pos020);
    scene->addItem(Pos021);
    scene->addItem(Pos022);
    scene->addItem(Pos023);
    scene->addItem(Pos024);
    scene->addItem(Pos025);
    scene->addItem(Pos026);
    scene->addItem(Pos027);
    scene->addItem(Pos028);
    scene->addItem(Pos029);

    //Fila 3
    scene->addItem(Pos030);
    scene->addItem(Pos031);
    scene->addItem(Pos032);
    scene->addItem(Pos033);
    scene->addItem(Pos034);
    scene->addItem(Pos035);
    scene->addItem(Pos036);
    scene->addItem(Pos037);
    scene->addItem(Pos038);
    scene->addItem(Pos039);

    //Fila 4
    scene->addItem(Pos040);
    scene->addItem(Pos041);
    scene->addItem(Pos042);
    scene->addItem(Pos043);
    scene->addItem(Pos044);
    scene->addItem(Pos045);
    scene->addItem(Pos046);
    scene->addItem(Pos047);
    scene->addItem(Pos048);
    scene->addItem(Pos049);

    //Fila 5
    scene->addItem(Pos050);
    scene->addItem(Pos051);
    scene->addItem(Pos052);
    scene->addItem(Pos053);
    scene->addItem(Pos054);
    scene->addItem(Pos055);
    scene->addItem(Pos056);
    scene->addItem(Pos057);
    scene->addItem(Pos058);
    scene->addItem(Pos059);

    //Fila 6
    scene->addItem(Pos060);
    scene->addItem(Pos061);
    scene->addItem(Pos062);
    scene->addItem(Pos063);
    scene->addItem(Pos064);
    scene->addItem(Pos065);
    scene->addItem(Pos066);
    scene->addItem(Pos067);
    scene->addItem(Pos068);
    scene->addItem(Pos069);

    //Fila 7
    scene->addItem(Pos070);
    scene->addItem(Pos071);
    scene->addItem(Pos072);
    scene->addItem(Pos073);
    scene->addItem(Pos074);
    scene->addItem(Pos075);
    scene->addItem(Pos076);
    scene->addItem(Pos077);
    scene->addItem(Pos078);
    scene->addItem(Pos079);

    //Fila 8
    scene->addItem(Pos080);
    scene->addItem(Pos081);
    scene->addItem(Pos082);
    scene->addItem(Pos083);
    scene->addItem(Pos084);
    scene->addItem(Pos085);
    scene->addItem(Pos086);
    scene->addItem(Pos087);
    scene->addItem(Pos088);
    scene->addItem(Pos089);

    //Fila 9
    scene->addItem(Pos090);
    scene->addItem(Pos091);
    scene->addItem(Pos092);
    scene->addItem(Pos093);
    scene->addItem(Pos094);
    scene->addItem(Pos095);
    scene->addItem(Pos096);
    scene->addItem(Pos097);
    scene->addItem(Pos098);
    scene->addItem(Pos099);
}

void Game::play2(){
    Table();
    cantidadJugadores(players2);
}

void Game::play3(){
    Table();
    cantidadJugadores(players3);
}

void Game::play4(){
    Table();
    cantidadJugadores(players4);
}

void Game::play6(){
   Table();
   cantidadJugadores(players6);
}

void Game::play8(){
    Table();
    cantidadJugadores(players8);
}

void Game::play9(){
    Table();
    cantidadJugadores(players9);
}

void Game::play10(){
    Table();
    cantidadJugadores(players10);
}

void Game::play12(){
    Table();
    cantidadJugadores(players12);
}
