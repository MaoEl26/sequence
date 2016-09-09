#ifndef FICHA_H
#define FICHA_H
#include<QString>
using namespace std;


class Ficha
{
public:
    Ficha(int ID, QString color, QString path);

    int getID();

    QString getColor();

    QString getPath();

protected:
    QString color;
    QString path;
    int ID;
};

#endif // FICHA_H
