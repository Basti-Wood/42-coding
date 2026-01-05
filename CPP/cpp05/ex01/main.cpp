#include "Form.hpp"

int main()
{
	Bureaucrat *Louis;
	Bureaucrat *LilLouis;
	Bureaucrat *Willhelm;
	Form 		*Treaty;

	Willhelm = new Bureaucrat("Willhelm Von Germania", 1);
	Louis = new Bureaucrat("Louis de France", 120);
	LilLouis = new Bureaucrat(*Louis);
	Treaty = new Form("Treaty Of Luxemburg", false, 20, 20);
	
	std::cout << *Treaty << std::endl;

	try
	{
		Treaty->beSigned(*Louis);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if(Treaty->getSign())
		std::cout <<GREEN " TREATY HAS BEEN SIGNED! PEACE IS UPON US " RESET<< std::endl;
	else
		std::cout <<RED " the treaty is doomed... " RESET<< std::endl;
	try
	{
		Treaty->beSigned(*Willhelm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if(Treaty->getSign())
		std::cout <<Treaty->getName() << GREEN " HAS BEEN SIGNED! PEACE IS UPON US " RESET<< std::endl;
	else
		std::cout <<RED " the treaty is doomed... " RESET<< std::endl;
	

	std::cout << *Treaty << std::endl;
	delete(Willhelm);
	delete(Louis);
	delete(LilLouis);
	delete(Treaty);
	return 0;
}