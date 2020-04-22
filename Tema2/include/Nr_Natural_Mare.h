#ifndef NR_NATURAL_MARE_H
#define NR_NATURAL_MARE_H

#include <iostream>
#include <cstring>
#include "Vector.h"
using namespace std;

class NrNaturalMare
{
protected:
	Vector v;
	int noDigits;
public:
	NrNaturalMare();
	NrNaturalMare(int);
	NrNaturalMare(char*);
	NrNaturalMare(const NrNaturalMare&);
	~NrNaturalMare();
	NrNaturalMare& operator=(const NrNaturalMare&);
	friend istream& operator>> (istream& in, NrNaturalMare& ob);
	friend ostream& operator<< (ostream& out, NrNaturalMare& ob);
    virtual void af()
    {
        cout<<'\n'<<"Af natural "<<this->v<<'\n';
    }
};

#endif // NR_NATURAL_MARE_H
