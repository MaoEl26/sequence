#ifndef CARTA_H
#define CARTA_H
#include<QString>
using namespace std;

class Carta
{
public:
    Carta(string valor, string simbolo, string color, string path);
    string getValor();
    string getSimbolo();
    string getColor();
    string getPath();


private:
    string color;
    string simbolo;
    string valor;
    string path;
};

#endif // CARTA_H
