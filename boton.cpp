#include "boton.h"

Boton::Boton(QString Name, QString Url)
{
    //Almacena la ubicación de la imagen para luego se utilizada
    this->Url=Url;
    //Creacion del botón y seteo del estilo
    //setRect(0,0,121,122);
    //QBrush brush;
    //brush.setStyle(Qt::TexturePattern);
    //brush.setTextureImage(QImage(Url));
    //setBrush(brush);

    //Setea la imagen al boton a partir del Path
    //y la posición
    this->setPixmap(Url);
    this->setPos(121,122);
//    textBoton = new QGraphicsTextItem(Name,this);
//    textBoton->setPos(23,14);
    setAcceptHoverEvents(true);
}

void Boton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Boton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    // cambia fondo cuando entra el mouse
       //QBrush bi;
       //bi.setTextureImage(QImage(Url));
       //bi.setStyle(Qt::TexturePattern),setOpacity(0.5);
       //setBrush(bi);

    //Cambia la opacidad del boton cuando el mouse entra
    QGraphicsOpacityEffect* brush = new QGraphicsOpacityEffect;
    brush->setOpacity(0.7);
    this->setGraphicsEffect(brush);

}

void Boton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    //QBrush bi;
   //bi.setTextureImage(QImage(Url));
   //bi.setStyle(Qt::TexturePattern),setOpacity(1.0);
   //setBrush(bi);

    //Cambia la opacidad del boton cuando el mouse sale
    QGraphicsOpacityEffect* brush = new QGraphicsOpacityEffect;
    brush->setOpacity(1.0);
    this->setGraphicsEffect(brush);

}




