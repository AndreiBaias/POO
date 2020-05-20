#ifndef CEC_H
#define CEC_H

#include <Plata.h>


class Cec : public Plata
{
    string nume;
    string prenume;
    string sex;

public:

    Cec();
    Cec(float,string,string,string,string);
    Cec(Cec&);
    virtual ~Cec();
    friend istream& operator >>(istream&, Cec&);
    Cec& operator =(Cec&);
    void afisare();

};

#endif // CEC_H
