#ifndef VECTOR_H
#define VECTOR_H


#include <iostream>
using namespace std;

class Vector
{
private:
	int* a;
	int dimTotal;
	int dimUsed;

public:
	Vector();
	Vector(int n);
	Vector(const Vector&);
	~Vector();
	void push(int);
	int getDimTotal();
	int getDimUsed();
	Vector& operator=(const Vector&);
	int operator [](int i);
	friend istream& operator>> (istream& in, Vector& ob);
	friend ostream& operator<< (ostream& out, Vector& ob);

};


#endif // VECTOR_H
