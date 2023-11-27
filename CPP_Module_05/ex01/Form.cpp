#include "Form.hpp"

Form::Form( void ) : name("Form"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
    std::cout << "Form Created" << std::endl ;
}

Form::Form( const Form& form )
    : name(form.name), isSigned(form.isSigned), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute)
{
    std::cout << "Copy Constructor" << std::endl ;
}

Form& Form::operator=( const Form& other )
{
    this->isSigned = other.isSigned ;
    std::cout << "Copy assignment Constructor" << std::endl ;
    return (*this) ;
}

Form::~Form( void )
{
    std::cout << "Destructor" << std::endl ;
}

void Form::checkGrade( std::string gradeName, unsigned grade ) const
{
    if (grade < 1)
        throw Form::GradeTooHighException(gradeName + ": " + std::to_string(grade)) ;
    if (grade > 150)
        throw Form::GradeTooLowException(gradeName + ": " + std::to_string(grade)) ;
}

Form::Form( std::string name, unsigned gradeToSign, unsigned gradeToExecute )
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "Form: " << name << " Created" << std::endl ;
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

std::ostream& operator<<( std::ostream& os, const Form& Form )
{
    os << Form.getName() << ", Form grade to sign: " << Form.getGradeToSign()
        << ", grade to execute: " << Form.getGradeToExecute() << "." ;
    return (os) ;
}