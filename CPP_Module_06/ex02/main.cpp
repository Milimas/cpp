#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base*   generate(void)
{
    int chance ;
    std::srand(time(NULL));
    chance = std::rand() % 3;
    switch (chance)
    {
    case 0:
        std::cerr << "A created" << std::endl ;
        return (new A()) ;
    case 1:
        std::cerr << "B created" << std::endl ;
        return (new B()) ;
    case 2:
        std::cerr << "C created" << std::endl ;
        return (new C()) ;
    default:
        return (NULL) ;
    }
    return (NULL) ;
}

void    identify( Base* p )
{
    A *a = dynamic_cast<A *>(p) ;
    B *b = dynamic_cast<B *>(p) ;
    C *c = dynamic_cast<C *>(p) ;
    if (a != NULL)
    {
        std::cout << "Object pointer Type is A*" << std::endl ;
        return ;
    }
    if (b != NULL)
    {
        std::cout << "Object pointer Type is B*" << std::endl ;
        return ;
    }
    if (c != NULL)
    {
        std::cout << "Object pointer Type is C*" << std::endl ;
        return ;
    }
    std::cout << "Object Type is Not A, B or C" << std::endl ;
}

void identify(Base& p)
{
    try
	{
		A &a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << "Object Type is A" << std::endl;
        return ;
	}
	catch (std::exception &bc)
	{
	}
     try
	{
		B &b = dynamic_cast<B &>(p);
		(void) b;
		std::cout << "Object Type is B" << std::endl;
        return ;
	}
	catch (std::exception &bc)
	{
	}
     try
	{
		C &c = dynamic_cast<C &>(p);
		(void) c;
		std::cout << "Object Type is C" << std::endl;
        return ;
	}
	catch (std::exception &bc)
	{
	}
    std::cout << "Object Type is Not A, B or C" << std::endl ;
}

int main( void )
{
    Base *p ;

    p = generate() ;
    identify(p) ;
    identify(*p) ;
    delete p ;
    return (0) ;
}
