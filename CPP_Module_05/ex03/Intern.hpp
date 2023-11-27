#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "form.h"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
public:
    Intern( void ) ;
    Intern( const Intern& other ) ;
    Intern& operator=( const Intern& other ) ;

    AForm*  makeForm( const std::string form, const std::string target ) ;
};

#endif