#ifndef NUMAR_INTREG_MARE_H
#define NUMAR_INTREG_MARE_H

#include <Nr_Natural_Mare.h>

#include <iostream>
#include <cstring>

using namespace std;

class NrIntregMare: protected NrNaturalMare
{
private:
	char s;
public:
	NrIntregMare();
	NrIntregMare(int n);
	NrIntregMare(char*);
	NrIntregMare(const NrIntregMare&);
	~NrIntregMare();
	NrIntregMare& operator=(const NrIntregMare&);
	friend istream& operator>> (istream& in, NrIntregMare& ob);
	ostream& operator<< (ostream& out);
	bool compara(NrIntregMare&);
	bool sgn();
	NrIntregMare operator+(NrIntregMare&);
	NrIntregMare operator-(NrIntregMare&);
	NrIntregMare operator*(NrIntregMare&);
    NrIntregMare operator/(NrIntregMare&);

	void af();

};
#endif // NUMAR_INTREG_MARE_H
