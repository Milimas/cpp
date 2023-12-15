#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
    
int main( void )
{
    try
    {
        Bureaucrat  amine = Bureaucrat("Amine", 13) ;
        std::cout << amine << std::endl ;
        ShrubberyCreationForm home = ShrubberyCreationForm("home") ;
        amine.signForm(home) ;
        // amine.signForm(home) ;
        amine.executeForm(home) ;
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
        RobotomyRequestForm pForm = RobotomyRequestForm("Amine") ;
        amine.signForm(pForm) ;
        amine.executeForm(pForm) ;
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
        PresidentialPardonForm pForm = PresidentialPardonForm("Amine") ;
        amine.signForm(pForm) ;
        amine.executeForm(pForm) ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n' ;
    }
    std::cout << std::endl ;
    return (0) ;
}