#include "Intern.hpp"


Intern::Intern( void )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

Intern::Intern( const Intern& other )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    (void)other ;
}

Intern& Intern::operator=( const Intern& other )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    (void)other ;
    return (*this) ;
}

static AForm*   makePresidentialPardonForm( const std::string target )
{
    return (new PresidentialPardonForm(target)) ;
}

static AForm*   makeShrubberyCreationForm( const std::string target )
{
    return (new ShrubberyCreationForm(target)) ;
}

static AForm*   makeRobotomyRequestForm( const std::string target )
{
    return (new RobotomyRequestForm(target)) ;
}

AForm*  Intern::makeForm( const std::string formType, const std::string target )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    AForm   *(*formMaker[])(const std::string target) = {
        &makePresidentialPardonForm,
        &makeShrubberyCreationForm,
        &makeRobotomyRequestForm,
    };
    std::string formName[] = {
        "PresidentialPardonForm",
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
    };
    for (int i = 0; i < 3; i++)
    {
        if (formType == formName[i])
        {
            std::cout << "Intern creates " << formType << std::endl ;
            return (formMaker[i](target));
        }
    }
    std::cout << "Intern couldn't create form " << formType << std::endl ;
    return (NULL) ;
}
