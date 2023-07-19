#ifndef HARL_HPP

#define HARL_HPP

#include <iostream>

class Harl
{
private:
    void debug( void ) const ;
    void info( void ) const ;
    void warning( void ) const ;
    void error( void ) const ;
    typedef void (Harl::*FnPtr)( void ) const ;

public:
    Harl( void ) ;
    ~Harl( void ) ;
    void complain( std::string level ) const ;

};


#endif
