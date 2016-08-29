#include "game.h"
#include "jugador.h"

Game::Game()
{
    ambiente();
    agregarBotonJugar();
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

    //Se Deshabilitan los botones de jugadores que se agregan después
    plays6B->setEnabled(false);
    plays8B->setEnabled(false);
    plays9B->setEnabled(false);
    plays10B->setEnabled(false);
    plays12B->setEnabled(false);

}

void Game::play2(){
    Jugador(2);
}

void Game::play3(){
    Jugador(3);
}

void Game::play4(){
    Jugador(4);
}

void Game::play6(){
   Jugador(6);
}

void Game::play8(){
    Jugador(8);
}

void Game::play9(){
    Jugador(9);
}

void Game::play10(){
    Jugador(10);
}

void Game::play12(){
    Jugador(12);
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
      QImage holi(":/imagenes/2C.png");
      QGraphicsPixmapItem *item= new QGraphicsPixmapItem( QPixmap::fromImage(holi));
      item->setPos(0,100);
      item->setScale(0.55);
      item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
      scene->addItem(item);

      //p2
      QImage holi2(":/imagenes/2C.png");
      QGraphicsPixmapItem *item2= new QGraphicsPixmapItem( QPixmap::fromImage(holi2));
      item2->setPos(0,100);
      item2->setScale(0.55);
      item2->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
      scene->addItem(item2);

      //p3
      QImage holi3(":/imagenes/2C.png");
      QGraphicsPixmapItem *item3= new QGraphicsPixmapItem( QPixmap::fromImage(holi3));
      item3->setPos(0,100);
      item3->setScale(0.55);
      item3->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
      scene->addItem(item3);
      //p4
      QImage holi4(":/imagenes/2C.png");
      QGraphicsPixmapItem *item4= new QGraphicsPixmapItem( QPixmap::fromImage(holi4));
      item4->setPos(0,100);
      item4->setScale(0.55);
      item4->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
      scene->addItem(item4);
      //p5
      QImage holi5(":/imagenes/2C.png");
      QGraphicsPixmapItem *item5= new QGraphicsPixmapItem( QPixmap::fromImage(holi5));
      item5->setPos(0,100);
      item5->setScale(0.55);
      item5->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
      scene->addItem(item5);
      //p4
      QImage holi6(":/imagenes/2C.png");
      QGraphicsPixmapItem *item6= new QGraphicsPixmapItem( QPixmap::fromImage(holi6));
      item6->setPos(0,100);
      item6->setScale(0.55);
      item6->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
      scene->addItem(item6);
      //p4
      QImage holi10(":/imagenes/2C.png");
      QGraphicsPixmapItem *item10= new QGraphicsPixmapItem( QPixmap::fromImage(holi10));
      item10->setPos(0,100);
      item10->setScale(0.55);
      item10->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
      scene->addItem(item10);
      //p4
      QImage holi7(":/imagenes/2C.png");
      QGraphicsPixmapItem *item7= new QGraphicsPixmapItem( QPixmap::fromImage(holi7));
      item7->setPos(0,100);
      item7->setScale(0.55);
      item7->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
      scene->addItem(item7);
      //p4
      QImage holi8(":/imagenes/2C.png");
      QGraphicsPixmapItem *item8= new QGraphicsPixmapItem( QPixmap::fromImage(holi8));
      item8->setPos(0,100);
      item8->setScale(0.55);
      item8->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
      scene->addItem(item8);
      //p4
      QImage holi9(":/imagenes/2C.png");
      QGraphicsPixmapItem *item9= new QGraphicsPixmapItem( QPixmap::fromImage(holi9));
      item9->setPos(0,100);
      item9->setScale(0.55);
      item9->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
      scene->addItem(item6);

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
