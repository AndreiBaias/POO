#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

#include <exception>


class my_exception : public std::exception
{
private:
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

#endif // MY_EXCEPTION_H

