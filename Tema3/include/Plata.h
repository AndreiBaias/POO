#ifndef PLATA_H
#define PLATA_H
#include <iostream>
using namespace std;

class Plata
{
protected:
    float suma;
    string data;
public:
    Plata();
    Plata(float , string);
    Plata(Plata&);
    virtual ~Plata();
    void setSuma(float);
    void setData(string);
    string getData();
    float getSuma();
    friend istream& operator >>(istream&, Plata&);
    Plata& operator =(Plata&);

    virtual void afisare()=0;

};
#endif // PLATA_H
