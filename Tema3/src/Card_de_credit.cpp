#include "Card_de_credit.h"

Card_de_credit::Card_de_credit() : Plata() {}

Card_de_credit::Card_de_credit(float f, string s1, string s2, string s3,string s4,string s5 ) : Plata(f,s1)
{
    nume=s2;
    prenume=s3;
    sex=s4;
    nr_card=s5;

}

Card_de_credit::Card_de_credit(Card_de_credit& c) : Plata(c.suma, c.data)
{
    nume=c.nume;
    prenume=c.prenume;
    sex=c.sex;
    nr_card=c.nr_card;

}

Card_de_credit::~Card_de_credit()
{
    nume.erase();
    prenume.erase();
    sex.erase();
    nr_card.erase();
    cout<<"\n des card";
}

istream& operator >>(istream& in, Card_de_credit& c)
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
    cout << "Nr card?\n";
    try
    {
        string input;
        in >> input;
        if((input.size()<13)||(input.size()>16))
            throw 0;
        c.nr_card=input;
    }
    catch (int x)
    {
        cout << "Numar de card invalid. Va rugam introduceti un card valid.";
        return in;
    }

    return in;
}

Card_de_credit& Card_de_credit::operator=(Card_de_credit& c)
{
    if(this == &c)
        return *this;
    nume=c.nume;
    prenume=c.prenume;
    sex=c.sex;
    nr_card=c.nr_card;
    return *this;
}

void Card_de_credit::afisare()
{
    cout << "Plata a fost efectuata cu cardul de credit.\n";
    cout << "Suma platita : " << suma << endl;
    cout << "Data la care a fost efectuata plata : " << data << endl;
    cout << "Numele clientului : " << nume << endl;
    cout << "Prenumele clientului : " << prenume << endl;
    cout << "Sexul clientului : " << sex << endl;
    cout << "Numarul cardului de pe care s-a efectuat plata : " << nr_card << endl;
}
