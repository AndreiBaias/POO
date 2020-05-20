#include "Cec.h"

Cec::Cec() : Plata() {}

Cec::Cec(float f, string s1, string s3,string s4,string s5 ) : Plata(f, s1)
{
    nume=s3;
    prenume=s4;
    sex=s5;
}

Cec::Cec(Cec& c) : Plata(c.suma,c.data)
{
    nume=c.nume;
    prenume=c.prenume;
    sex=c.sex;
}

Cec::~Cec()
{
    nume.erase();
    prenume.erase();
    sex.erase();
    cout<<"\n des cec";
}

istream& operator >>(istream& in, Cec& c)
{
    in >> (Plata&)c;
    cout<<"Numele de familie?\n";
    in >> c.nume;
    cout<<"Prenumele?(in cazul in care aveti mai multe prenume treceti unul singur)\n";
    in >> c.prenume;
    cout << "Pentru verificare va rugam introduceti sexul. Introduceti F sau M\n";
    try
    {
        in >> c.sex;
        if(c.sex.compare("F") != 0 && c.sex.compare("M") != 0)
            throw 0;
    }
    catch(int x)
    {
        cout << "Eroare : Nu ati introdus F sau M!\n";
        return in;
    }
    return in;
}

Cec& Cec::operator=(Cec& c)
{
    if(this == &c)
        return *this;

    sex=c.sex;
    nume=c.nume;
    prenume=c.prenume;
    return *this;
}

void Cec::afisare()
{
    cout << "Plata a fost efectuata cu un cec.\n";
    cout << "Suma platita : " << suma << endl;
    cout << "Data la care a fost efectuata plata : " << data << endl;
    cout << "Numele clientului : " << nume << endl;
    cout << "Prenumele clientului : " << prenume << endl;
    cout << "Sexul clientului : " << sex << endl;
}
