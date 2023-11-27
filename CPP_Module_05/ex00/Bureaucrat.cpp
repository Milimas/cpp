#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name("Bureaucrat"), grade(1)
{
    std::cout << "Bureaucrat Created" << std::endl ;
}

Bureaucrat::Bureaucrat( const Bureaucrat& bureaucrat ) : name(bureaucrat.name)
{
    this->grade = bureaucrat.grade ;
    std::cout << "Copy Constructor" << std::endl ;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
    this->grade = other.grade ;
    std::cout << "Copy assignment Constructor" << std::endl ;
    return (*this) ;
}

Bureaucrat::~Bureaucrat( void )
{
    std::cout << "Destructor" << std::endl ;
}

void Bureaucrat::checkGrade( void ) const
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException("Grade: " + std::to_string(grade)) ;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException("Grade: " + std::to_string(grade)) ;
}

Bureaucrat::Bureaucrat( std::string name, unsigned grade ) : name(name)
{
    std::cout << "Bureaucrat: " << name << " Created" << std::endl ;
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

std::ostream& operator<<( std::ostream& os, const Bureaucrat& bureaucrat )
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." ;
    return (os) ;
}