#include "game.h"
#include "jugador.h"
#include "mazo.h"
#include "carta.h"
#include "arraycarta.h"

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
    Table();
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

void Game::Table(){
    scene->clear();
    scene->setBackgroundBrush(QBrush(QImage(":/imagenes/fondo.png")));//Inserta el nuevo fondo
    QString Comodin = ":/imagenes/COMODIN.png";


    ArrayCarta<Carta*> matrizCartas = tableroRandom();


    //Fila 0
    Pos000 = new BotonCarta(Comodin);//Comodin
    Pos001 = new BotonCarta(matrizCartas.returnPos(0)->getPath());
    Pos002 = new BotonCarta(matrizCartas.returnPos(1)->getPath());
    Pos003 = new BotonCarta(matrizCartas.returnPos(2)->getPath());
    Pos004 = new BotonCarta(matrizCartas.returnPos(3)->getPath());
    Pos005 = new BotonCarta(matrizCartas.returnPos(4)->getPath());
    Pos006 = new BotonCarta(matrizCartas.returnPos(5)->getPath());
    Pos007 = new BotonCarta(matrizCartas.returnPos(6)->getPath());
    Pos008 = new BotonCarta(matrizCartas.returnPos(7)->getPath());
    Pos009 = new BotonCarta(Comodin);//Comodin

    //Fila 1
    Pos010 = new BotonCarta(matrizCartas.returnPos(8)->getPath());
    Pos011 = new BotonCarta(matrizCartas.returnPos(9)->getPath());
    Pos012 = new BotonCarta(matrizCartas.returnPos(10)->getPath());
    Pos013 = new BotonCarta(matrizCartas.returnPos(11)->getPath());
    Pos014 = new BotonCarta(matrizCartas.returnPos(12)->getPath());
    Pos015 = new BotonCarta(matrizCartas.returnPos(13)->getPath());
    Pos016 = new BotonCarta(matrizCartas.returnPos(14)->getPath());
    Pos017 = new BotonCarta(matrizCartas.returnPos(15)->getPath());
    Pos018 = new BotonCarta(matrizCartas.returnPos(16)->getPath());
    Pos019 = new BotonCarta(matrizCartas.returnPos(17)->getPath());

    //Fila 2
    Pos020 = new BotonCarta(matrizCartas.returnPos(18)->getPath());
    Pos021 = new BotonCarta(matrizCartas.returnPos(19)->getPath());
    Pos022 = new BotonCarta(matrizCartas.returnPos(20)->getPath());
    Pos023 = new BotonCarta(matrizCartas.returnPos(21)->getPath());
    Pos024 = new BotonCarta(matrizCartas.returnPos(22)->getPath());
    Pos025 = new BotonCarta(matrizCartas.returnPos(23)->getPath());
    Pos026 = new BotonCarta(matrizCartas.returnPos(24)->getPath());
    Pos027 = new BotonCarta(matrizCartas.returnPos(25)->getPath());
    Pos028 = new BotonCarta(matrizCartas.returnPos(26)->getPath());
    Pos029 = new BotonCarta(matrizCartas.returnPos(27)->getPath());

    //Fila 3
    Pos030 = new BotonCarta(matrizCartas.returnPos(28)->getPath());
    Pos031 = new BotonCarta(matrizCartas.returnPos(29)->getPath());
    Pos032 = new BotonCarta(matrizCartas.returnPos(30)->getPath());
    Pos033 = new BotonCarta(matrizCartas.returnPos(31)->getPath());
    Pos034 = new BotonCarta(matrizCartas.returnPos(32)->getPath());
    Pos035 = new BotonCarta(matrizCartas.returnPos(33)->getPath());
    Pos036 = new BotonCarta(matrizCartas.returnPos(34)->getPath());
    Pos037 = new BotonCarta(matrizCartas.returnPos(35)->getPath());
    Pos038 = new BotonCarta(matrizCartas.returnPos(36)->getPath());
    Pos039 = new BotonCarta(matrizCartas.returnPos(37)->getPath());

    //Fila 4
    Pos040 = new BotonCarta(matrizCartas.returnPos(38)->getPath());
    Pos041 = new BotonCarta(matrizCartas.returnPos(39)->getPath());
    Pos042 = new BotonCarta(matrizCartas.returnPos(40)->getPath());
    Pos043 = new BotonCarta(matrizCartas.returnPos(41)->getPath());
    Pos044 = new BotonCarta(matrizCartas.returnPos(42)->getPath());
    Pos045 = new BotonCarta(matrizCartas.returnPos(43)->getPath());
    Pos046 = new BotonCarta(matrizCartas.returnPos(44)->getPath());
    Pos047 = new BotonCarta(matrizCartas.returnPos(45)->getPath());
    Pos048 = new BotonCarta(matrizCartas.returnPos(46)->getPath());
    Pos049 = new BotonCarta(matrizCartas.returnPos(47)->getPath());

    //Fila 5
    Pos050 = new BotonCarta(matrizCartas.returnPos(48)->getPath());
    Pos051 = new BotonCarta(matrizCartas.returnPos(49)->getPath());
    Pos052 = new BotonCarta(matrizCartas.returnPos(50)->getPath());
    Pos053 = new BotonCarta(matrizCartas.returnPos(51)->getPath());
    Pos054 = new BotonCarta(matrizCartas.returnPos(52)->getPath());
    Pos055 = new BotonCarta(matrizCartas.returnPos(53)->getPath());
    Pos056 = new BotonCarta(matrizCartas.returnPos(54)->getPath());
    Pos057 = new BotonCarta(matrizCartas.returnPos(55)->getPath());
    Pos058 = new BotonCarta(matrizCartas.returnPos(56)->getPath());
    Pos059 = new BotonCarta(matrizCartas.returnPos(57)->getPath());

    //Fila 6
    Pos060 = new BotonCarta(matrizCartas.returnPos(58)->getPath());
    Pos061 = new BotonCarta(matrizCartas.returnPos(59)->getPath());
    Pos062 = new BotonCarta(matrizCartas.returnPos(60)->getPath());
    Pos063 = new BotonCarta(matrizCartas.returnPos(61)->getPath());
    Pos064 = new BotonCarta(matrizCartas.returnPos(62)->getPath());
    Pos065 = new BotonCarta(matrizCartas.returnPos(63)->getPath());
    Pos066 = new BotonCarta(matrizCartas.returnPos(64)->getPath());
    Pos067 = new BotonCarta(matrizCartas.returnPos(65)->getPath());
    Pos068 = new BotonCarta(matrizCartas.returnPos(66)->getPath());
    Pos069 = new BotonCarta(matrizCartas.returnPos(67)->getPath());

    //Fila 7
    Pos070 = new BotonCarta(matrizCartas.returnPos(68)->getPath());
    Pos071 = new BotonCarta(matrizCartas.returnPos(69)->getPath());
    Pos072 = new BotonCarta(matrizCartas.returnPos(70)->getPath());
    Pos073 = new BotonCarta(matrizCartas.returnPos(71)->getPath());
    Pos074 = new BotonCarta(matrizCartas.returnPos(72)->getPath());
    Pos075 = new BotonCarta(matrizCartas.returnPos(73)->getPath());
    Pos076 = new BotonCarta(matrizCartas.returnPos(74)->getPath());
    Pos077 = new BotonCarta(matrizCartas.returnPos(75)->getPath());
    Pos078 = new BotonCarta(matrizCartas.returnPos(76)->getPath());
    Pos079 = new BotonCarta(matrizCartas.returnPos(77)->getPath());

    //Fila 8
    Pos080 = new BotonCarta(matrizCartas.returnPos(78)->getPath());
    Pos081 = new BotonCarta(matrizCartas.returnPos(79)->getPath());
    Pos082 = new BotonCarta(matrizCartas.returnPos(80)->getPath());
    Pos083 = new BotonCarta(matrizCartas.returnPos(81)->getPath());
    Pos084 = new BotonCarta(matrizCartas.returnPos(82)->getPath());
    Pos085 = new BotonCarta(matrizCartas.returnPos(83)->getPath());
    Pos086 = new BotonCarta(matrizCartas.returnPos(84)->getPath());
    Pos087 = new BotonCarta(matrizCartas.returnPos(85)->getPath());
    Pos088 = new BotonCarta(matrizCartas.returnPos(86)->getPath());
    Pos089 = new BotonCarta(matrizCartas.returnPos(87)->getPath());

    //Fila 9
    Pos090 = new BotonCarta(Comodin);//Comodin
    Pos091 = new BotonCarta(matrizCartas.returnPos(88)->getPath());
    Pos092 = new BotonCarta(matrizCartas.returnPos(89)->getPath());
    Pos093 = new BotonCarta(matrizCartas.returnPos(90)->getPath());
    Pos094 = new BotonCarta(matrizCartas.returnPos(91)->getPath());
    Pos095 = new BotonCarta(matrizCartas.returnPos(92)->getPath());
    Pos096 = new BotonCarta(matrizCartas.returnPos(93)->getPath());
    Pos097 = new BotonCarta(matrizCartas.returnPos(94)->getPath());
    Pos098 = new BotonCarta(matrizCartas.returnPos(95)->getPath());
    Pos099 = new BotonCarta(Comodin);//Comodin

    connect(Pos000,SIGNAL(clicked()),this,SLOT(seteoBotones()));

    //Coordenadas
    //Fila 0
    Pos000->setPos(290,35);//Mantener posición
    Pos001->setPos(375,35);
    Pos002->setPos(460,35);
    Pos003->setPos(545,35);
    Pos004->setPos(630,35);
    Pos005->setPos(715,35);
    Pos006->setPos(800,35);
    Pos007->setPos(885,35);
    Pos008->setPos(970,35);
    Pos009->setPos(1055,35);

    //Fila 1
    Pos010->setPos(290,93);
    Pos011->setPos(375,93);
    Pos012->setPos(460,93);
    Pos013->setPos(545,93);
    Pos014->setPos(630,93);
    Pos015->setPos(715,93);
    Pos016->setPos(800,93);
    Pos017->setPos(885,93);
    Pos018->setPos(970,93);
    Pos019->setPos(1055,93);

    //Fila 2
    Pos020->setPos(290,151);
    Pos021->setPos(375,151);
    Pos022->setPos(460,151);
    Pos023->setPos(545,151);
    Pos024->setPos(630,151);
    Pos025->setPos(715,151);
    Pos026->setPos(800,151);
    Pos027->setPos(885,151);
    Pos028->setPos(970,151);
    Pos029->setPos(1055,151);

    //Fila 3
    Pos030->setPos(290,209);
    Pos031->setPos(375,209);
    Pos032->setPos(460,209);
    Pos033->setPos(545,209);
    Pos034->setPos(630,209);
    Pos035->setPos(715,209);
    Pos036->setPos(800,209);
    Pos037->setPos(885,209);
    Pos038->setPos(970,209);
    Pos039->setPos(1055,209);

    //Fila 4
    Pos040->setPos(290,267);
    Pos041->setPos(375,267);
    Pos042->setPos(460,267);
    Pos043->setPos(545,267);
    Pos044->setPos(630,267);
    Pos045->setPos(715,267);
    Pos046->setPos(800,267);
    Pos047->setPos(885,267);
    Pos048->setPos(970,267);
    Pos049->setPos(1055,267);

    //Fila 5
    Pos050->setPos(290,325);
    Pos051->setPos(375,325);
    Pos052->setPos(460,325);
    Pos053->setPos(545,325);
    Pos054->setPos(630,325);
    Pos055->setPos(715,325);
    Pos056->setPos(800,325);
    Pos057->setPos(885,325);
    Pos058->setPos(970,325);
    Pos059->setPos(1055,325);

    //Fila 6
    Pos060->setPos(290,383);
    Pos061->setPos(375,383);
    Pos062->setPos(460,383);
    Pos063->setPos(545,383);
    Pos064->setPos(630,383);
    Pos065->setPos(715,383);
    Pos066->setPos(800,383);
    Pos067->setPos(885,383);
    Pos068->setPos(970,383);
    Pos069->setPos(1055,383);

    //Fila 7
    Pos070->setPos(290,441);
    Pos071->setPos(375,441);
    Pos072->setPos(460,441);
    Pos073->setPos(545,441);
    Pos074->setPos(630,441);
    Pos075->setPos(715,441);
    Pos076->setPos(800,441);
    Pos077->setPos(885,441);
    Pos078->setPos(970,441);
    Pos079->setPos(1055,441);

    //Fila 8
    Pos080->setPos(290,499);
    Pos081->setPos(375,499);
    Pos082->setPos(460,499);
    Pos083->setPos(545,499);
    Pos084->setPos(630,499);
    Pos085->setPos(715,499);
    Pos086->setPos(800,499);
    Pos087->setPos(885,499);
    Pos088->setPos(970,499);
    Pos089->setPos(1055,499);

    //Fila 9
    Pos090->setPos(290,557);
    Pos091->setPos(375,557);
    Pos092->setPos(460,557);
    Pos093->setPos(545,557);
    Pos094->setPos(630,557);
    Pos095->setPos(715,557);
    Pos096->setPos(800,557);
    Pos097->setPos(885,557);
    Pos098->setPos(970,557);
    Pos099->setPos(1055,557);

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
