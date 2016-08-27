#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include<QString>
#include "Carta.h"
using namespace std;

template <typename E>
class ArrayCarta
{
public:

    ArrayCarta (int pMaX);
    E getValue();
    int getPos();
    int getSize();
    E remove(int pos);
    void goToStart();
    void goToEnd();
    void goToPos(int pos);
    void previous();
    void next();
    void append (E Element);
    void insert(E pElement);
    void print ();
    virtual ~ArrayCarta();

private:
    int size;
    int max;
    int pos;
    E* elements;
};

#endif // ARRAYLIST_H
