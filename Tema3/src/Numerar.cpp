#include "Numerar.h"

Numerar::Numerar() : Plata() {}

Numerar::Numerar(float f, string s) : Plata(f, s) {}

Numerar::Numerar(Numerar& n) : Plata(n.suma,n.data) {}

Numerar::~Numerar() {cout<<"\n des numerar";}

istream& operator >>(istream& in, Numerar& n)
{
    in >> (Plata&)n;

    return in;
}

Numerar& Numerar::operator=(Numerar& n)
{
    if(this == &n)
        return *this;

    static_cast<Plata&>(*this) = (Plata&)n;
    return *this;
}

void Numerar::afisare()
{
    cout << "Plata a fost efectuata in numerar.\n";
    cout << "Suma platita : " << suma << endl;
    cout << "Data la care a fost efectuata plata : " << data << endl;
}
