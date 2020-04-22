#include "Nr_Natural_Mare.h"

NrNaturalMare::NrNaturalMare()
{
	cout << "Constructor fara parametri NrNaturalMare." << endl;
	noDigits = 0;
}

NrNaturalMare::NrNaturalMare(int n)
{
	cout << "Constructor cu parametru int NrNaturalMare." << endl;
	noDigits = 0;
	Vector aux(n);
	v = aux;
}

NrNaturalMare::NrNaturalMare(char s[200])
{
	cout << "Constructor cu parametru string NrNaturalMare." << endl;
	noDigits = strlen(s);

	for (int i = noDigits - 1; i >= 0; i--)
		v.push(s[i] - '0');
}

NrNaturalMare::NrNaturalMare(const NrNaturalMare& ob)
{
	cout << "Constructor de copiere NrNaturalMare." << endl;
	noDigits = ob.noDigits;
	v = ob.v;
}

NrNaturalMare::~NrNaturalMare()
{
	cout << "Destructor NrNaturalMare." << endl;
}

NrNaturalMare& NrNaturalMare:: operator=(const NrNaturalMare& ob)
{
	noDigits = ob.noDigits;
	v = ob.v;
	return *this;
}

istream& operator>> (istream& in, NrNaturalMare& ob)
{
	cout << "Introduceti numarul: ";
	char* s;
	s = new char [500];
	in >> s;
	cout << endl;
	NrNaturalMare aux(s);
	ob = aux;
	delete []s;
	return in;
}

ostream& operator<< (ostream& out, NrNaturalMare& ob)
{
	int lim = ob.v.getDimUsed();

	while (ob.v[lim - 1] == 0)
		lim--;

	out << endl << endl;

	for (int i = lim - 1; i >= 0; i--)
		out << ob.v[i];

	out << endl << endl;
	return out;
}
