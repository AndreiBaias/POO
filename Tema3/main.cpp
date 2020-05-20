#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "Plata.h"
#include "Numerar.h"
#include "Card_de_credit.h"
#include "Cec.h"
template <class T>
class Gestiune
{
protected:
    static int nr_plati;
    vector<T*> plati;
public:
    Gestiune() {}
    ~Gestiune()
    {
        int i;
        for(i = 0; i < plati.size(); i++)
            delete plati[i];
        nr_plati= 0;
    }
    Gestiune(Gestiune<T> &p)
    {
        plati=p.plati;
    }
    Gestiune<T>& operator +=(T &p)
    {
        plati.push_back(&p);
        nr_plati++;
        return *this;
    }
    static int getNr_plati ()
    {
        return nr_plati;
    }
    void afisare_plati()
    {
        int i;
        for(i = 0; i < plati.size(); i++)
        {
            {

                if ( Numerar *P=dynamic_cast<Numerar*>(plati[i]))
                    P->afisare();
                else if ( Card_de_credit *P=dynamic_cast<Card_de_credit*>(plati[i]))
                    P->afisare();
                else if ( Cec *P=dynamic_cast<Cec*>(plati[i]))
                    P->afisare();


            }
        }

    }
};

template <class T>
int Gestiune<T>::nr_plati=0;

template <>
class Gestiune<char*>
{
    int clienti;
    vector<string>nume_clienti;

public:
    Gestiune()
    {
        clienti = 0;
    }
    ~Gestiune() {}
    Gestiune(Gestiune<char*> &p)
    {
        nume_clienti=p.nume_clienti;
        clienti=p.clienti;
    }
    Gestiune <char*>& operator +=(string s)
    {
        nume_clienti.push_back(s);
        clienti++;
        return *this;
    }
    void afisare_clienti()
    {
        int i;
        try
        {
            if(nume_clienti.size() == 0)
                throw 0;
            cout << "Numarul curent de clienti este : " << clienti << endl;
            for(i = 0; i < nume_clienti.size(); i++)
                cout << nume_clienti[i] << endl;

        }
        catch(int x)
        {
            cout << "Nu a fost inregistrat niciun client in baza de date.\n";
        }
    }

};

int main()
{
    int n,out=1;
    Gestiune<Plata> P;
    Gestiune<char*> C;

    Numerar N;
    Card_de_credit Cd;
    Cec K;

    while(out==1)
    {
        cout << "\n Meniu : \n";
        cout << "Pentru plata numerar apasati tasta 1.\n";
        cout << "Pentru plata cu cardul de credit apasati tasta 2. \n";
        cout << "Pentru plata in cec apasati tasta 3. \n";
        cout << "Pentru a introduce doar numele dumneavoastra in baza de date apasati tasta 4. \n";
        cout << "Pentru a iesi apasati tasta 5.\n";

        cin >> n;
        switch(n)
        {
        case 1 :
        {
            cin >> N;
            P += N;
            break;
        }
        case 2 :
        {
            cin >> Cd;
            P += Cd;
            break;
        }
        case 3 :
        {
            cin >> K;
            P += K;
            break;
        }
        case 4 :
        {
            string s;
            cin >> s;
            C += s;
            break;
        }
        case 5 :
        {
            out=0;
            break;
        }

        }
    }

    cout << "\nNumarul total de plati efectuate : ";
    cout << P.getNr_plati() << endl;

    P.afisare_plati();
    C.afisare_clienti();
    return 0;
}
