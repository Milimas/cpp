#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat ;

class Form
{
private:
	const std::string   name ;
	bool                isSigned ;
	const unsigned      gradeToSign ;
	const unsigned      gradeToExecute ;

	void	checkGrade( std::string gradeName, unsigned grade ) const ;
public:
	Form( void ) ;
	Form( const Form& form ) ;
	Form& operator=( const Form& other ) ;
	~Form( void ) ;
	Form( std::string name, unsigned gradeToSign, unsigned gradeToExecute ) ;

	std::string	getName( void ) const ;
	unsigned 	getGradeToSign( void ) const ;
	unsigned 	getGradeToExecute( void ) const ;
	unsigned	getIsSigned( void ) const ;

	void            beSigned( Bureaucrat& bureaucrat ) ;

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

std::ostream& operator<<( std::ostream& os, const Form& form ) ;

#endif