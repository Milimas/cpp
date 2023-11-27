#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat ;

class AForm
{
private:
	const std::string   name ;
	bool                isSigned ;
	const unsigned      gradeToSign ;
	const unsigned      gradeToExecute ;

	void	checkGrade( std::string gradeName, unsigned grade ) const ;
	void	checkSigning( const Bureaucrat& signer ) const ;
protected:
	void	checkExecution( const Bureaucrat& executor ) const ;
public:
	AForm( void ) ;
	AForm( const AForm& form ) ;
	AForm& operator=( const AForm& other ) ;
	virtual ~AForm( void ) ;
	AForm( std::string name, unsigned gradeToSign, unsigned gradeToExecute ) ;

	std::string		getName( void ) const ;
	unsigned 		getGradeToSign( void ) const ;
	unsigned 		getGradeToExecute( void ) const ;
	unsigned		getIsSigned( void ) const ;

	void        	beSigned( const Bureaucrat& bureaucrat ) ;
	virtual void			execute( Bureaucrat const& bureaucrat) const = 0;

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
	class FormNotExecutedException: public std::exception
	{
	private:
		std::string			msg ;
	public:
		FormNotExecutedException( void ) throw()
		{
			msg = "Exception::FormNotExecutedException" ;
		} ;
		FormNotExecutedException( std::string msg ) throw() {
			this->msg = "Exception::FormNotExecutedException::" + msg ;
		} ;
		virtual ~FormNotExecutedException( void ) throw() {} ;
		const char* what( void ) const throw() 
		{
			return (msg.c_str()) ;
		}
	} ;
	class FormNotSignedException: public std::exception
	{
	private:
		std::string			msg ;
	public:
		FormNotSignedException( void ) throw()
		{
			msg = "Exception::FormNotSignedException" ;
		} ;
		FormNotSignedException( std::string msg ) throw() {
			this->msg = "Exception::FormNotSignedException::" + msg ;
		} ;
		virtual ~FormNotSignedException( void ) throw() {} ;
		const char* what( void ) const throw() 
		{
			return (msg.c_str()) ;
		}
	} ;
};

std::ostream& operator<<( std::ostream& os, const AForm& form ) ;

#endif