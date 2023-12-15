#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("Shrubbery", 72, 45), target("_shrubbery")
{
	std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string name ) : AForm(name, 72, 45), target(name + "_shrubbery")
{
	std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& form ) : AForm(form), target(form.target)
{
	std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
{
	std::cerr << __PRETTY_FUNCTION__ << std::endl ;
	this->target = other.target ;
	AForm::operator=(other) ;
	return (*this) ;
}

void	RobotomyRequestForm::execute( Bureaucrat const& executor ) const
{
	AForm::checkExecution(executor) ;
	std::srand(std::time(NULL));
	if (std::rand() % 2)
	std::cout << "*Drilling noises*. " << target << " has been robotomized successfully." << std::endl ;
	else
	std::cout << "*Drilling noises*. " << target << " the robotomy failed!." << std::endl ;
}
