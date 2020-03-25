#include <iostream>
#include "Fractie.h"
using namespace std;

int main()
{   int n;
    cout<<"Introdu dimensiunea vectorului ";
    cin>>n;
    Fractie a;
    a.nElem(n);
    /*Fractie f(20,1);
    f.simplificare();
    Fractie f1;
    f1=Fractie(20,2);
    f1.simplificare();
    Fractie f2(20,20);
    f2.simplificare();
    Fractie f(2,4);
    cout<<f;
    Fractie f1(10,40);
    Fractie g;
    g=(f+f1);
    cout<<g;
    g=(f-f1);
    cout<<g;
    g=(f*f1);
    cout<<g;
    g=(f/f1);
    cout<<g;
    g=(f*12);
    cout<<g;*/
    Fractie f1,f2,f3,f4,f5,f6,x,y,f53,f26,f51,f24,f5326,f5124,f1x,f31x;
    cout<<"Ecuatiile sunt de forma coef1*x+coef2*y=coef3*z cu z=1";
    cout<<"\nIntrodu primul coeficient pentru x sub forma numarator spatiu numitor\n";
    cin>>f1;
    cout<<"\nIntrodu primul coeficient pentru y sub forma numarator spatiu numitor\n";
    cin>>f2;
    cout<<"\nIntrodu primul coeficient pentru z=1 sub forma numarator spatiu numitor\n";
    cin>>f3;
    cout<<"\nIntrodu al doilea coeficient pentru x sub forma numarator spatiu numitor\n";
    cin>>f4;
    cout<<"\nIntrodu al doilea coeficient pentru y sub forma numarator spatiu numitor\n";
    cin>>f5;
    cout<<"\nIntrodu al doilea coeficient pentru z=1 sub forma numarator spatiu numitor\n";
    cin>>f6;
    cout<<"Sistemul este:\n"<<f1<<"*x+"<<f2<<"*y="<<f3<<'\n';
    cout<<f4<<"*x+"<<f5<<"*y="<<f6<<'\n';
    f53=f5*f3;
    f26=f2*f6;
    f51=f5*f1;
    f24=f2*f4;
    f5326=f53-f26;
    f5124=f51-f24;
    x=f5326/f5124;
    f1x=f1*x;
    f31x=f3-f1x;
    y=f31x/f2;
    cout<<"Solutia este: x="<<x<<" , y="<<y;
    return 0;
}
