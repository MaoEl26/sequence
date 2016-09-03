#ifndef ARRAYCARTA_H
#define ARRAYCARTA_H
#include "carta.h"
template<class E>
class ArrayCarta
{
    public:
        ArrayCarta(int pMax);

        E getValue();
        int getPos();
        int getSize();
        E remove(int pos);
        void goToStart();
        void goToEnd();
        void goToPos(int pos);
        void previous();
        void next();
        void append (E pElement);
        void insert(E pElement);
        void print();
        ~ArrayCarta();
        E returnPos(int pos);
protected:
        int size;
        int max;
        int pos;
        E *elements;
};

#endif // ARRAYCARTA_H
