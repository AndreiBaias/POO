#include "Vector.h"

Vector::Vector()
{
	cout << "Constructor fara parametri Vector." << '\n';
	a = NULL;
	dimTotal = dimUsed = 0;
}

Vector:: Vector(int n)
{
	cout << "Constructor cu parametri Vector." << '\n';
	a = new int [n];

	for (int i = 0; i < n; i++)
		a[i] = 0;

	dimTotal = n;
	dimUsed = 0;
}

Vector::Vector(const Vector& ob)
{
	cout << "Constructor de copiere Vector." << '\n';
	dimTotal = ob.dimTotal;
	dimUsed = ob.dimUsed;
	delete [] a;
	a = new int[dimTotal];

	for (int i = 0; i < dimUsed; i++)
		a[i] = ob.a[i];
}

Vector:: ~Vector()
{
	cout << "Destructor Vector." << '\n';
	delete [] a;
}

void Vector::push(int key)
{
	dimUsed++;

	if (dimUsed > dimTotal)
	{
		int* aux;
		aux = new int[dimUsed - 1];

		for (int i = 0; i < dimUsed - 1; i++)
		{
			aux[i] = a[i];
		}

		delete [] a;
		a = new int[dimUsed];

		for (int i = 0; i < dimUsed - 1; i++)
		{
			a[i] = aux[i];
		}

		delete [] aux;
		dimTotal++;
	}

	a[dimUsed - 1] = key;
}

int Vector::getDimTotal()
{
	return dimTotal;
}

int Vector::getDimUsed()
{
	return dimUsed;
}

Vector& Vector:: operator=(const Vector& ob)
{
	dimTotal = ob.dimTotal;
	dimUsed = ob.dimUsed;
	delete [] a;
	a = new int[dimTotal];

	for (int i = 0; i < dimUsed; i++)
		a[i] = ob.a[i];

	return *this;
}

int Vector:: operator [](int i)
{  if(i>=0&&i<=dimUsed)
	return a[i];
	else return -1;
}


istream& operator>> (istream& in, Vector& ob)
{
	cout << "Introduceti numarul de elemente: ";
	in >> ob.dimTotal;
	cout << '\n' << "Introduceti " << ob.dimTotal << " elemente: ";
	ob.dimUsed = 0;
	delete [] ob.a;
	ob.a = new int [ob.dimTotal];

	for (int i = 0; i < ob.dimTotal; i++)
	{
		int x;
		in >> x;
		ob.push(x);
	}

	cout << '\n';
	return in;
}

ostream& operator<< (ostream& out, Vector& ob)
{
	for (int i = 0; i < ob.dimUsed; i++)
		out << ob.a[i] << " ";

	out << '\n';
	return out;
}
