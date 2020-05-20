#ifndef CARD_DE_CREDIT_H
#define CARD_DE_CREDIT_H

#include <Plata.h>


class Card_de_credit : public Plata
{
    string nume;
    string prenume;
    string sex;
    string nr_card;


public:

    Card_de_credit();
    Card_de_credit(float,string,string,string,string,string);
    Card_de_credit(Card_de_credit&);
    virtual ~Card_de_credit();
    friend istream& operator >> (istream&, Card_de_credit&);
    Card_de_credit& operator = (Card_de_credit&);
    void afisare();

};

#endif // CARD_DE_CREDIT_H
