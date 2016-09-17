#include "boton.h"

Boton::Boton(QString name, QString Url)
{
    //Almacena la ubicación de la imagen para luego se utilizada
    this->Url=Url;
    this->name=name;

    //Setea la imagen al boton a partir del Path
    //y la posición
    this->setPixmap(Url);
    this->setPos(121,122);

    setAcceptHoverEvents(true);
}

void Boton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Boton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //Cambia la opacidad del boton cuando el mouse entra
    QGraphicsOpacityEffect* brush = new QGraphicsOpacityEffect;
    brush->setOpacity(0.7);
    this->setGraphicsEffect(brush);

}

void Boton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    //Cambia la opacidad del boton cuando el mouse sale
    QGraphicsOpacityEffect* brush = new QGraphicsOpacityEffect;
    brush->setOpacity(1.0);
    this->setGraphicsEffect(brush);

}

QString Boton::getName(){
    return name;
}
