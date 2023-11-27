#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main( void )
{
    Intern  someRandomIntern ;
    try
    {
        Bureaucrat  amine = Bureaucrat("Amine", 13) ;
        std::cout << amine << std::endl ;
        AForm   *rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "home") ;
        amine.signForm(*rrf) ;
        // amine.signForm(*rrf) ;
        amine.executeForm(*rrf) ;
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n' ;
    }
    std::cout << std::endl ;
    try
    {
        Bureaucrat  amine = Bureaucrat("Amine", 4) ;
        std::cout << amine << std::endl ;
        AForm   *rrf = someRandomIntern.makeForm("RobotomyRequestForm", "home") ;
        amine.signForm(*rrf) ;
        amine.executeForm(*rrf) ;
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n' ;
    }
    std::cout << std::endl ;
    try
    {
        Bureaucrat  amine = Bureaucrat("Amine", 5) ;
        std::cout << amine << std::endl ;
        AForm   *rrf = someRandomIntern.makeForm("PresidentialPardonForm", "home") ;
        amine.signForm(*rrf) ;
        amine.executeForm(*rrf) ;
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n' ;
    }
    std::cout << std::endl ;
    return (0) ;
}