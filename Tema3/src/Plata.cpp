#include "Plata.h"

Plata::Plata()
{
    suma=0;
}

Plata::Plata(float f,string s)
{
    suma=f;
    data=s;
}

Plata::Plata(Plata& p)
{
    data=p.data;
    suma=p.suma;
}

Plata::~Plata()
{
    data.erase();
    suma=0;
    cout<<"\n Des plata";
}

void Plata::setData(string s)
{
    data=s;
}

string Plata::getData()
{
    return data;
}

void Plata::setSuma(float f)
{
    suma=f;
}

float Plata::getSuma()
{
    return suma;
}
Plata& Plata::operator=(Plata& p)
{
    if(this == &p)
        return *this;

    data=p.data;
    suma=p.suma;
    return *this;
}

istream& operator >>(istream& in, Plata& p)
{
    cout << "Data platii?( zi , luna , an separate de punct )\nExemplu :\n 20.05.2020 " << endl;
    in >> p.data;
    cout<< "Suma platita( x lei si y (de) bani separate de punct)?\n Exemplu : \n 321.09" << endl;
    in >> p.suma;
    return in;
}
