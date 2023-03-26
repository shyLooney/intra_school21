#include "Form.hpp"

int main()
{
	Form form("C-28", 12, 13);
	Bureaucrat br("Sema", 5);
	br.signForm(form);
	br.signForm(form);

	Form form2("C-31", 12, 13);
	Bureaucrat br2("Ivan", 15);
	br2.signForm(form2);
	br2.signForm(form2);

	try
	{
		Form("Aaa", 151, 12);
	}
	catch(const std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}

	try
	{
		Form("Aaa", 15, -1200);
	}
	catch(const std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}

	std::cout << form << std::endl;
	return (0);
}