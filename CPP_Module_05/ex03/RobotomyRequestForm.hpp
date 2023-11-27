#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string target ;
public:
    RobotomyRequestForm( void ) ;
    RobotomyRequestForm( std::string name ) ;
	RobotomyRequestForm( const RobotomyRequestForm& form ) ;
	RobotomyRequestForm& operator=( const RobotomyRequestForm& other ) ;
	~RobotomyRequestForm( void ) ;

    void    execute( Bureaucrat const& executor ) const ;
};

#endif