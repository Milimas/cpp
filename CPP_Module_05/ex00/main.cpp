#include "Bureaucrat.hpp"

int main( void )
{
    try
    {
        Bureaucrat amine = Bureaucrat("amine", 1) ;
        std::cout << amine << std::endl ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n' ;
    }
    return (0) ;
}