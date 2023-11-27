#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target ;
public:
    PresidentialPardonForm( void ) ;
    PresidentialPardonForm( std::string name ) ;
	PresidentialPardonForm( const PresidentialPardonForm& form ) ;
	PresidentialPardonForm& operator=( const PresidentialPardonForm& other ) ;
	~PresidentialPardonForm( void ) ;

    void    execute( Bureaucrat const& executor ) const ;
};

#endif