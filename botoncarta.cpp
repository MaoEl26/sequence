#include "botoncarta.h"



BotonCarta::BotonCarta(QString Url, int coorX, int coorY, int IDCarta)
{
    //Almacena la ubicación de la imagen para luego se utilizada
    this->Url=Url;

    //Setea la imagen al boton a partir del Path
    //y la posición
    this->setPixmap(Url);
    this->setScale(0.55);
    this->setPos(121,122);
    this->coorX = coorX;
    this->coorY = coorY;
    this->IDCarta = IDCarta;

    setAcceptHoverEvents(true);
}

void BotonCarta::mousePressEvent(QGraphicsSceneMouseEvent *event){


    emit getSignalPath(object);
}

void BotonCarta::hoverEnterEvent(QGraphicsSceneHoverEvent *event){

    //Cambia la opacidad del boton cuando el mouse entra
    QGraphicsDropShadowEffect* brush = new QGraphicsDropShadowEffect;
    brush->setColor(Qt::black);
    this->setGraphicsEffect(brush);

}

void BotonCarta::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    //Cambia la opacidad del boton cuando el mouse sale
    QGraphicsOpacityEffect* brush = new QGraphicsOpacityEffect;
    brush->setOpacity(1.0);
    this->setGraphicsEffect(brush);
}

int BotonCarta::posX()
{
    return coorX;
}

int BotonCarta::posY()
{
    return coorY;
}

QString BotonCarta::getPath(){
    return Url;
}

int BotonCarta::getIDCarta(){
    return IDCarta;
}



