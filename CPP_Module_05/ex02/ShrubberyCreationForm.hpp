#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string target ;
public:
	ShrubberyCreationForm( void ) ;
	ShrubberyCreationForm( std::string name ) ;
	ShrubberyCreationForm( const ShrubberyCreationForm& form ) ;
	ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other ) ;
	~ShrubberyCreationForm( void ) ;

	void	execute( Bureaucrat const& executor ) const ;
};



#endif