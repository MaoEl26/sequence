#ifndef BOTON_H
#define BOTON_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsEffect>

using namespace std;

class Boton: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Boton(QString Name,QString Url);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();

private:
    QGraphicsTextItem *textBoton;
    QString Url;

};

#endif // BOTON_H
