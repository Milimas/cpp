#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm ;

class Bureaucrat
{
private:
	const std::string	name ;
	unsigned			grade ;

	void	checkGrade( void ) const ;
public:
	Bureaucrat( void ) ;
    Bureaucrat( const Bureaucrat& bureaucrat ) ;
    Bureaucrat& operator=( const Bureaucrat& other ) ;
    ~Bureaucrat( void ) ;
	Bureaucrat( std::string name, unsigned grade ) ;

	std::string	getName( void ) const ;
	unsigned 	getGrade( void ) const ;

	void		increment( void ) ;
	void		decrement( void ) ;

	void 		signForm( AForm& form ) ;
	void		executeForm( const AForm& form ) const ;

	class GradeTooHighException: public std::exception
    {
    private:
		std::string			msg ;
    public:
		GradeTooHighException( void ) throw()
		{
			msg = "Exception::GradeTooHighException" ;
		} ;
        GradeTooHighException( std::string msg ) throw() {
			this->msg = "Exception::GradeTooHighException::" + msg ;
		} ;
        virtual ~GradeTooHighException( void ) throw() {} ;
        const char* what( void ) const throw() 
        {
            return (msg.c_str()) ;
        }
    } ;
	class GradeTooLowException: public std::exception
    {
    private:
		std::string			msg ;
    public:
		GradeTooLowException( void ) throw()
		{
			msg = "Exception::GradeTooLowException" ;
		} ;
        GradeTooLowException( std::string msg ) throw() {
			this->msg = "Exception::GradeTooLowException::" + msg ;
		} ;
        virtual ~GradeTooLowException( void ) throw() {} ;
        const char* what( void ) const throw() 
        {
            return (msg.c_str()) ;
        }
    } ;
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& bureaucrat ) ;

#endif