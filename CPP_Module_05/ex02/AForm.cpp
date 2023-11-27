#include "AForm.hpp"

AForm::AForm( void ) : name("AForm"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

AForm::AForm( const AForm& form )
    : name(form.name), isSigned(form.isSigned), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

AForm& AForm::operator=( const AForm& other )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    this->isSigned = other.isSigned ;
    return (*this) ;
}

AForm::~AForm( void )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

void AForm::checkGrade( std::string gradeName, unsigned grade ) const
{
    if (grade < 1)
        throw AForm::GradeTooHighException(gradeName + ": " + std::to_string(grade)) ;
    if (grade > 150)
        throw AForm::GradeTooLowException(gradeName + ": " + std::to_string(grade)) ;
}

void AForm::checkExecution( const Bureaucrat& executor ) const
{
    if (!AForm::getIsSigned())
        throw AForm::FormNotExecutedException(executor.getName() + " couldn't execute " + name + " because it's not signed.") ;
    if (executor.getGrade() > AForm::getGradeToExecute())
        throw AForm::GradeTooLowException(executor.getName() + " couldn't execute " + name + " because grade is too low to execute.") ;
}

void AForm::checkSigning( const Bureaucrat& signer ) const
{
    if (signer.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException(signer.getName() + " couldn't sign " + name + " because grade is too low to sign." );
    if (isSigned)
        throw AForm::FormNotSignedException(signer.getName() + " couldn't sign " + name + " because it's already signed.") ;
}

AForm::AForm( std::string name, unsigned gradeToSign, unsigned gradeToExecute )
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    checkGrade("GradeToSign", gradeToSign) ;
    checkGrade("GradeToExecute", gradeToExecute) ;
}

std::string AForm::getName( void ) const
{
    return (this->name) ;
}

unsigned AForm::getGradeToSign( void ) const
{
    return (this->gradeToSign) ;
}

unsigned AForm::getGradeToExecute( void ) const
{
    return (this->gradeToExecute) ;
}

unsigned AForm::getIsSigned( void ) const
{
    return (this->isSigned) ;
}

void    AForm::beSigned( const Bureaucrat& signer )
{
    checkSigning(signer) ;
    this->isSigned = true ;
}

std::ostream& operator<<( std::ostream& os, const AForm& form )
{
    os << form.getName() << ", form grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute() << "." ;
    return (os) ;
}