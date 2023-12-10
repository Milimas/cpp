#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name("Bureaucrat"), grade(1)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

Bureaucrat::Bureaucrat( const Bureaucrat& bureaucrat ) : name(bureaucrat.name)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    this->grade = bureaucrat.grade ;
    std::cerr << "Copy Constructor" << std::endl ;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    this->grade = other.grade ;
    return (*this) ;
}

Bureaucrat::~Bureaucrat( void )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

void Bureaucrat::checkGrade( void ) const
{
	std::ostringstream msg ;
	msg << "Grade : " << (int)grade ;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException(msg.str()) ;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException(msg.str()) ;
}

Bureaucrat::Bureaucrat( std::string name, unsigned grade ) : name(name)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    this->grade = grade ;
    checkGrade() ;
}

std::string Bureaucrat::getName( void ) const
{
    return (this->name) ;
}


unsigned Bureaucrat::getGrade( void ) const
{
    return (this->grade) ;
}

void Bureaucrat::increment( void )
{
    this->grade--;
    checkGrade() ;
}

void Bureaucrat::decrement( void )
{
    this->grade++;
    checkGrade() ;
}

void Bureaucrat::signForm( AForm& form )
{
    form.beSigned(*this) ;
    std::cout << name << " signed " << form.getName() << std::endl ;
}

void Bureaucrat::executeForm( AForm const& form ) const
{
    form.execute(*this) ;
    std::cout << name << " executed " << form.getName() << std::endl ;
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& bureaucrat )
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." ;
    return (os) ;
}
