#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("Presidential Pardon", 25, 5), target("Presidential Pardon")
{
	std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm(target, 25, 5), target(target)
{
	std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& form ) : AForm(form), target(form.target)
{
	std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
	std::cerr << __PRETTY_FUNCTION__ << std::endl ;
	this->target = other.target ;
	AForm::operator=(other) ;
	return (*this) ;
}

void	PresidentialPardonForm::execute( Bureaucrat const& executor ) const
{
	AForm::checkExecution(executor) ;
	std::cout  << target << " has been pardoned by Zaphod Beeblebrox." << std::endl ;
}
