#include "Fractie.h"
#include <iostream>
#include <vector>
using namespace std;
Fractie::Fractie()
{
    //ctor default
    a=1;
    b=1;
    cout<<"\nConstructor default\n";
}

Fractie::Fractie(int x)
{
    a=x;
    b=1;
    cout<<"\nFractie cu numitor 1\n";
}

Fractie::Fractie(int x, int y)
{
    a=x;
    b=y;
    cout<<"\nConstructor overload\n";
}

Fractie::Fractie(const Fractie& ob)
{
    a=ob.a;
    b=ob.b;
    cout<<"\nCopy constructor\n";
}

Fractie::~Fractie()
{
    //dtor
    cout<<"\nDestructor\n";
}

int Fractie::getA()
{
    return a;
}

int Fractie::getB()
{
    return b;
}

void Fractie::setA(int x)
{
    a=x;
}

void Fractie::setB(int x)
{
    b=x;
}
void Fractie::nElem(int n)
{
    vector <Fractie> vect;
    vect.resize(n);
    int a,b;
    for(int i=0; i<n;i++)
        {
            cout<<"\nObiectul "<<i+1<<" :"<<'\n'<<"a=";
            cin>>a;
            cout<<"b=";
            cin>>b;
            vect[i]=Fractie(a,b);
            cout<<"Fractia "<<i+1<<": "<<a<<"/"<<b<<"\n";
        }
    vect.resize(0);
}

void Fractie::simplificare()
{
    if(b==1||b==-1)
        cout<<"Fractie ireductibila egala cu "<<*this<<'\n';
    else
        if(a%b)
            {
            int n;
                if(a<b)
                    n=a;
                else
                    n=b;
            for(int i=n;i>1;i--)
                if(a%i==0 && b%i==0)
                    {
                        a/=i;
                        b/=i;
                    }
            cout<<"Fractia devine "<<*this<<'\n';}
        else
            cout<<"Numitorul divide numaratorul si fractia e egala cu "<<a/b<<'\n';
}

istream& operator>>(istream &cin, Fractie& f)
{
    cin>>f.a>>f.b;
    return cin;
}

ostream& operator<<(ostream &cout, Fractie& f)
{
    if(f.b==1||f.b==-1)
        cout<<f.a*f.b;
    else
        if(f.b<0 )
            cout<<-f.a<<"/"<<-f.b;
        else

            cout<<f.a<<"/"<<f.b;
    return cout;
}

Fractie operator+(Fractie& x,Fractie& y)
{   Fractie f(x.a*y.b+y.a*x.b, y.b*x.b);
    f.simplificare();
    return f;
}

Fractie operator-(Fractie& x,Fractie& y)
{
    Fractie f(x.a*y.b-y.a*x.b, y.b*x.b);
    f.simplificare();
    return f;
}

Fractie operator*(Fractie& x,Fractie& y)
{
    Fractie f(x.a*y.a, y.b*x.b);
    f.simplificare();
    return f;
}

Fractie operator/(Fractie& x,Fractie& y)
{
    Fractie f(x.a*y.b, y.a*x.b);
    f.simplificare();
    return f;
}

Fractie operator*(Fractie& x, int y)
{
    Fractie f(x.a*y, x.b);
    f.simplificare();
    return f;
}
