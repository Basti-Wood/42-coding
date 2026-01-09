#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int r = std::rand() % 3 + 1;
	if(r == 1)
		return(new A);
	else if(r == 2)
		return(new B);
	else if(r == 3)
		return(new C);
	else
	{
		std::cout << "An Error Occured. Position yourself in a recovery position and cry silently" << std::endl;
		return NULL;
	}
}

void identify(Base* p)
{
	if(dynamic_cast<A*> (p))
		std::cout << "Base was Class A" << std::endl;
	else if(dynamic_cast<B*> (p))
		std::cout << "Base was Class B" << std::endl;
	else if(dynamic_cast<C*> (p))
		std::cout << "Base was Class C" << std::endl;
	else
		std::cout << "Base was of no known class" << std::endl;
		
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Base was Class A" << std::endl;
        return;
    } catch (...) {/*std::cout << "Base was not Class A" << std::endl;*/}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Base was Class B" << std::endl;
        return;
    } catch (...) {/*std::cout << "Base was not Class B" << std::endl;*/}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Base was Class C" << std::endl;
        return;
    } catch (...) {/*std::cout << "Base was not Class C" << std::endl;*/}
    
    std::cout << "Base was of no known class" << std::endl;
}


int main()
{
	std::srand(std::time(NULL));
	
	Base *b = generate();
	identify(b);
	identify(*b);
	delete b;
	return 0;
}