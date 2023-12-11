#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

class Span
{
private:
    unsigned int _maxSize ;
    std::vector<int> _vector ;
public:
    Span( void ) ;
    Span( unsigned int _size ) ;
    Span( const Span& other ) ;
    Span& operator=( const Span& other ) ;
    ~Span( void ) ;

    void addNumber( const int num ) ;

    int shortestSpan( void ) ;
    int longestSpan( void ) ;

    void fill( void ) ;
    void print( void ) ;

    class ArrayIsFullException: public std::exception
    {
    private:
		std::string			msg ;
    public:
		ArrayIsFullException( void ) throw()
		{
			msg = "Exception::ArrayIsFullException" ;
		} ;
        ArrayIsFullException( std::string msg ) throw() {
			this->msg = "Exception::ArrayIsFullException::" + msg ;
		} ;
        virtual ~ArrayIsFullException( void ) throw() {} ;
        const char* what( void ) const throw() 
        {
            return (msg.c_str()) ;
        } ;
    } ;
     class NoSpanException: public std::exception
    {
    private:
		std::string			msg ;
    public:
		NoSpanException( void ) throw()
		{
			msg = "Exception::NoSpanException" ;
		} ;
        NoSpanException( std::string msg ) throw() {
			this->msg = "Exception::NoSpanException::" + msg ;
		} ;
        virtual ~NoSpanException( void ) throw() {} ;
        const char* what( void ) const throw() 
        {
            return (msg.c_str()) ;
        } ;
    } ;
};

#endif
