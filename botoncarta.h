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
        BotonCarta(QString Url, int x , int y);
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
        int posX();
        int posY();

        QString getPath();

    signals:

        void getSignalPath(BotonCarta *object);
        void clicked();

    private:
        BotonCarta *object = this;
        QString Url;
        int x;
        int y;

    };

#endif // BOTONCARTA_H
