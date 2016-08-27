#include "game.h"

Game::Game()
{
    ambiente();
    agregarBotonJugar();
   // show();
}

void Game::ambiente(){
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1300, 660);
    setScene(scene);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1350,680);
}

void Game::agregarBotonJugar(){
    //Boton de inicio del Juego
    scene->clear();
    scene->setBackgroundBrush(QBrush(QImage(":/imagenes/FondoInicio2.png")));

    startButton= new Boton("Start Game",":/imagenes/startButton.png");
    startButton->setPos(388,440);
    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));

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

void Game::seteoBotones(){
    agregarBotonJugar();
}

void Game::start(){

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


    //Prueba
//      QImage holi(":/imagenes/exitButton.png");
//      QGraphicsPixmapItem *item= new QGraphicsPixmapItem( QPixmap::fromImage(holi));
//      item->setPos(0,100);
//      item->setScale(1.0);
//     item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
//      scene->addItem(item);

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

void Game::play2(){
    int players=2;
    table(players);
}

void Game::play3(){
    int players=3;
    table(players);
}

void Game::play4(){
    int players=4;
    table(players);
}

void Game::play6(){
    int players=6;
    table(players);
}

void Game::play8(){
    int players=8;
    table(players);
}

void Game::play9(){
    int players=9;
    table(players);
}

void Game::play10(){
    int players=10;
    table(players);
}

void Game::play12(){
    int players=12;
    table(players);
}

void Game::table(int players){

}

void Game::wiki(){
    //Crea el wiki
    scene->clear();//Limpia la Pantalla
    scene->setBackgroundBrush(QBrush(QImage(":/imagenes/fondoJugadores.png")));//Inserta el nuevo fondo
    backButton = new Boton("Atrás",":/imagenes/backButton.png");//Crea el botón de Back
    backButton->setPos(0,0);//Establece la posícion
    connect(backButton,SIGNAL(clicked()),this,SLOT(seteoBotones()));//Establece la acción que va a realizar
    scene->addItem(backButton);//Añade el botón a la pantalla
}

void Game::exit(){

    //LLama a CoreApp para la salida del programa
    QCoreApplication::quit();
}
