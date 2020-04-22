#include "Numar_Intreg_mare.h"

void Shl(int H[], int Count)
{
	memmove(&H[Count + 1], &H[1], sizeof(int)*H[0]);
	memset(&H[1], 0, sizeof(int)*Count);
	H[0] += Count;
}

int Sgn(int H1[], int H2[])
{
	while (H1[0] && !H1[H1[0]]) H1[0]--;

	while (H2[0] && !H2[H2[0]]) H2[0]--;

	if (H1[0] < H2[0])
	{
		return -1;
	}
	else
		if (H1[0] > H2[0])
		{
			return +1;
		}

	for (int i = H1[0]; i > 0; --i)
	{
		if (H1[i] < H2[i])
		{
			return -1;
		}
		else
			if (H1[i] > H2[i])
			{
				return +1;
			}
	}

	return 0;
}

NrIntregMare::NrIntregMare(): NrNaturalMare()
{
	cout << "Constructor fara parametru NrIntregMare." << endl;
	s = '+';
}


NrIntregMare::NrIntregMare(int n): NrNaturalMare(n)
{
	cout << "Constructor cu parametru int NrIntregMare." << endl;
	s = '+';
}

NrIntregMare::NrIntregMare(char c[200]): NrNaturalMare(c + 1)
{
	cout << "Constructor cu parametru string NrIntregMare." << endl;
	s = c[0];
}

NrIntregMare::NrIntregMare(const NrIntregMare& ob): NrNaturalMare(ob)
{
	cout << "Constructor de copiere NrIntregMare." << endl;
	s = ob.s;
}

NrIntregMare::~NrIntregMare()
{
	cout << "Destructor NrIntregMare." << endl;
}

NrIntregMare& NrIntregMare::operator=(const NrIntregMare& ob)
{
	this->NrNaturalMare::operator=(ob);
	s = ob.s;
	return *this;
}

istream& operator>> (istream& in, NrIntregMare& ob)
{
	cout << "Introduceti numarul intreg (scrieti semnul inainte de numar si nu lasati spatiu): ";
	char* c;
	c = new char [500];
	in >> c;
	cout << endl;
	NrIntregMare aux(c);
	ob = aux;
	delete []c;
	return in;
}

ostream& NrIntregMare::operator<< (ostream& out)
{
	int lim = v.getDimUsed();

	while (v[lim - 1] == 0)
		lim--;

	out << endl << endl;

	if (lim <= 0)
		out << '0';
	else
	{
		out << s;

		for (int i = lim - 1; i >= 0; i--)
			out << v[i];
	}

	out << endl << endl;
	return out;
}



bool NrIntregMare::compara(NrIntregMare& ob) ///compara valorile absolute
{
	if (this->noDigits > ob.noDigits)
		return true;

	if (ob.noDigits > this->noDigits)
		return false;

	for (int i = 0; i < noDigits; i++)
		if (this->v[i] > ob.v[i])
			return true;
		else
			if (this->v[i] < ob.v[i])
				return false;

	return true;
}



NrIntregMare NrIntregMare::operator+(NrIntregMare& ob)
{
	int lim;
	NrIntregMare res(this->noDigits + ob.noDigits);

	if (this->noDigits > ob.noDigits)
		lim = ob.noDigits;
	else
		lim = this->noDigits;

	if (this->s == ob.s)
	{
		int t = 0;
		res.s = this->s;

		for (int i = 0; i < lim; i++)
		{
			if (v[i] + ob.v[i] + t < 10)
			{
				res.v.push(this->v[i] + ob.v[i] + t);
				res.noDigits++;
				t = 0;
			}
			else
			{
				res.v.push((this->v[i] + ob.v[i] + t) % 10);
				t = 1;
				res.noDigits++;
			}
		}

		if (lim == ob.noDigits && this->noDigits > lim)
		{
			res.v.push((this->v[lim] + t) % 10);
			res.noDigits++;
			t = (this->v[lim] + t) / 10 ;

			for (int i = lim + 1; i < this->noDigits; i++)
			{
				res.v.push((this->v[i] + t) % 10);
				res.noDigits++;
				t = (this->v[i] + t) / 10;
			}
		}
		else
			if (lim == this->noDigits && ob.noDigits > lim)
			{
				res.v.push((ob.v[lim] + t) % 10);
				res.noDigits++;
				t = (ob.v[lim] + t) / 10 ;

				for (int i = lim + 1; i < ob.noDigits; i++)
				{
					res.v.push((ob.v[i] + t) % 10);
					res.noDigits++;
					t = (ob.v[i] + t) / 10;
				}
			}

		if (t > 0)
		{
			res.v.push(t);
			res.noDigits++;
		}
	}
	else
		if (this->s == '-' && ob.s == '+')
			res = ob + *this;
		else
			if (this->s == '+' && ob.s == '-')
			{
				if (this->compara(ob))
				{
					res.s = '+';
					int A[500], B[500];
					A[0] = this->noDigits;
					B[0] = ob.noDigits;
					int i, T = 0;

					for (i = 0; i < this->noDigits; i++)
						A[i + 1] = this->v[i];

					for (i = 0; i < ob.noDigits; i++)
						B[i + 1] = ob.v[i];

					for (i = B[0] + 1; i <= A[0];) B[i++] = 0;

					for (i = 1; i <= A[0]; i++)
						A[i] += (T = (A[i] -= B[i] + T) < 0) ? 10 : 0;

					while (!A[A[0]] && A[0] > 1) A[0]--;

					res.noDigits = A[0];

					for (i = 1; i <= A[0]; i++)
						res.v.push(A[i]);
				}
				else
				{
					ob.s = '+';
					this->s = '-';
					res = ob + *this;
					res.s = '-';
				}
			}

	return res;
}

NrIntregMare NrIntregMare::operator-(NrIntregMare& ob)
{
	if (this->s == '+' && ob.s == '-')
	{
		NrIntregMare copie = ob;
		copie.s = '+';
		return *this + copie;
	}

	if (this->s == '-' && ob.s == '+')
	{
		ob.s = '-';
		return *this + ob;
	}

	if (this->s == '+' && ob.s == '+')
	{
		ob.s = '-';
		return *this + ob;
	}

	if (this->s == '-' && ob.s == '-')
	{
		ob.s = '+';
		return *this + ob;
	}
}



NrIntregMare NrIntregMare::operator*(NrIntregMare& ob)
{
	int A[500], B[500], C[500];
	A[0] = this->noDigits;
	B[0] = ob.noDigits;
	C[0] = A[0] + B[0] - 1;
	int i, j, T = 0;

	for (i = 0; i < this->noDigits; i++)
		A[i + 1] = this->v[i];

	for (i = 0; i < ob.noDigits; i++)
		B[i + 1] = ob.v[i];

	for (i = 1; i <= A[0] + B[0];) C[i++] = 0;

	for (i = 1; i <= A[0]; i++)
		for (j = 1; j <= B[0]; j++)
			C[i + j - 1] += A[i] * B[j];

	for (i = 1; i <= C[0]; i++)
	{
		T = (C[i] += T) / 10;
		C[i] %= 10;
	}

	if (T) C[++C[0]] = T;

	NrIntregMare res;
	res.noDigits = C[0];

	for (i = 1; i <= C[0]; i++)
		res.v.push(C[i]);

	if (ob.s == this->s)
		res.s = '+';
	else
		res.s = '-';

	return res;
}

NrIntregMare NrIntregMare::operator/(NrIntregMare& ob)
{
	int A[500], B[500], C[500], R[500];
	A[0] = this->noDigits;
	B[0] = ob.noDigits;
	C[0] = A[0];
	R[0] = 0;
	int i;

	for (i = 0; i < this->noDigits; i++)
		A[i + 1] = this->v[i];

	for (i = 0; i < ob.noDigits; i++)
		B[i + 1] = ob.v[i];

	for (i = A[0]; i; i--)
	{
		Shl(R, 1);
		R[1] = A[i];
		C[i] = 0;

		while (Sgn(B, R) != 1)
		{
			C[i]++;
			///R=R-B;
			int k, T = 0;

			for (k = B[0] + 1; k <= R[0];) B[k++] = 0;

			for (k = 1; k <= R[0]; k++)
				R[k] += (T = (R[k] -= B[k] + T) < 0) ? 10 : 0;

			while (!R[R[0]] && R[0] > 1) R[0]--;
		}
	}

	while (!C[C[0]] && C[0] > 1) C[0]--;

	NrIntregMare res;
	res.noDigits = C[0];

	for (i = 1; i <= C[0]; i++)
		res.v.push(C[i]);

	if (ob.s == this->s)
		res.s = '+';
	else
		res.s = '-';

	return res;
}

void NrIntregMare :: af()
{
	cout << '\n' << "Af intreg : " << noDigits << '\n';
}

bool NrIntregMare::sgn()

{
	if (this->s != '+')
		if (this->s != '-')
			return false;

	return true;
}
