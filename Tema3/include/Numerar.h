#ifndef NUMERAR_H
#define NUMERAR_H

#include <Plata.h>


class Numerar : public Plata
{

public:
    Numerar();
    Numerar(float,string);
    Numerar(Numerar&);
    virtual ~Numerar();
    friend istream& operator >>(istream&, Numerar&);
    Numerar& operator =(Numerar&);
    void afisare();
};


#endif // NUMERAR_H
