#include "Form.hpp"

Form::Form( void ) : name("Form"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

Form::Form( const Form& form )
    : name(form.name), isSigned(form.isSigned), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

Form& Form::operator=( const Form& other )
{
    this->isSigned = other.isSigned ;
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    return (*this) ;
}

Form::~Form( void )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

void Form::checkGrade( std::string gradeName, unsigned grade ) const
{
	std::ostringstream msg ;
	msg << gradeName << ": " << (int)grade ;
    if (grade < 1)
        throw Form::GradeTooHighException(msg.str()) ;
    if (grade > 150)
        throw Form::GradeTooLowException(msg.str()) ;
}

Form::Form( std::string name, unsigned gradeToSign, unsigned gradeToExecute )
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    checkGrade("GradeToSign", gradeToSign) ;
    checkGrade("GradeToExecute", gradeToExecute) ;
}

std::string Form::getName( void ) const
{
    return (this->name) ;
}


unsigned Form::getGradeToSign( void ) const
{
    return (this->gradeToSign) ;
}

unsigned Form::getGradeToExecute( void ) const
{
    return (this->gradeToExecute) ;
}

unsigned Form::getIsSigned( void ) const
{
    return (this->isSigned) ;
}

void    Form::beSigned( Bureaucrat& bureaucrat )
{
    if (bureaucrat.getGrade() > gradeToSign)
    {
        std::cout << bureaucrat.getName() << " couldn't sign " << name << "because grade is too low to sign" << std::endl ;
        throw Form::GradeTooLowException("To Sign");
    }
    if (!isSigned)
    {
        this->isSigned = true ;
        std::cout << bureaucrat.getName() << " signed " << name << std::endl ;
    }
    else
        std::cout << bureaucrat.getName() << " couldn't sign " << name << "because it's already signed" << std::endl ;
}

std::ostream& operator<<( std::ostream& os, const Form& form )
{
    os << form.getName() << ", form grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute() << "." ;
    return (os) ;
}
