#ifndef BOTON_H
#define BOTON_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QGraphicsEffect>

using namespace std;

class Boton: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Boton(QString name, QString Url);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    QString getName();

signals:
    void clicked();

private:
    QString Url;
    QString name;

};

#endif // BOTON_H
