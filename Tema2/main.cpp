#include <iostream>
#include "Vector.h"
#include "Nr_Natural_Mare.h"
#include "Numar_Intreg_mare.h"
#include <vector>
//#include <exception>
using namespace std;


class my_exception : public std::exception
{

	char e;
public:
	my_exception(char e) noexcept
	{
		this->e = e;
	}
	my_exception(const my_exception&) noexcept = default;
	my_exception& operator= (const my_exception&) noexcept = default;
	virtual ~my_exception() noexcept = default;
};

vector <NrIntregMare> v;
int main()
{
	int n, i;
	NrIntregMare x;
	cin >> n;

	try
	{
		for (i = 0; i < n; i++)
		{
			cin >> x;

			if (x.sgn())
				cout << "e ok" << '\n';
			else
				throw (my_exception('e'));

			v.push_back(x);
		}
	}
	catch (my_exception& e)
	{
		cout << "'\n' mesaj de eroare '\n'";
	}

	for (i = 0; i < n; i++)
	{
		v[i] << cout;
	}

	/*NrIntregMare x, y, r;
	cin >> x;
	cin >> y;
	r=x/y;
	r<< cout;*/
	return 0;
}
