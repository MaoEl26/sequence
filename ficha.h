#ifndef FICHA_H
#define FICHA_H
#include<QString>
using namespace std;


class Ficha
{
public:
    Ficha(int ID, string color, string path);

    int getID();

    string getColor();

    string getPath();

protected:
    string color;
    string path;
    int ID;
};

#endif // FICHA_H
