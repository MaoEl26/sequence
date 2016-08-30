#ifndef BOTONCARTA_H
#define BOTONCARTA_H

#include <QString>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsEffect>
using namespace std;

class BotonCarta:public QObject, public QGraphicsPixmapItem
    {
        Q_OBJECT
    public:
        BotonCarta(QString Url);
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    signals:
        void clicked();

    private:
        QString Url;

    };

#endif // BOTONCARTA_H
