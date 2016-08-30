#ifndef CARTA_H
#define CARTA_H
#include<QString>
using namespace std;

class Carta
{
public:
    Carta(QString valor, QString simbolo, QString color, QString path);
    QString getValor();
    QString getSimbolo();
    QString getColor();
    QString getPath();


private:
    QString color;
    QString simbolo;
    QString valor;
    QString path;
};

#endif // CARTA_H
