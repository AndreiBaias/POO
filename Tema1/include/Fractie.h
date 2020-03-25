#ifndef FRACTIE_H
#define FRACTIE_H
#include <iostream>
using namespace std;

class Fractie
{
int a,b;
public:
    Fractie();
    Fractie(int a);
    Fractie(int a, int b);
    ~Fractie();
    Fractie(const Fractie& ob);
    int getA();
    int getB();
    void setA(int x);
    void setB(int x);
    void nElem(int n);
    void simplificare();
    friend istream& operator>>(istream &in, Fractie& f);
    friend ostream& operator<<(ostream &cout, Fractie& f);
    friend Fractie operator+(Fractie& x, Fractie& y );
    friend Fractie operator-(Fractie& x, Fractie& y );
    friend Fractie operator*(Fractie& x, Fractie& y );
    friend Fractie operator/(Fractie& x, Fractie& y );
    friend Fractie operator*(Fractie& x, int y);
};

#endif // FRACTIE_H
