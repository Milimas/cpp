#ifndef ICE_HPP
#define ICE_HPP

#include "ICharacter.hpp"

class Ice
{
private:
public:
    Ice( void ) ;
    Ice& Ice( const Ice& ice ) ;
    Ice& operator=( const Ice& ice ) ;
    ~Ice( void ) ;
    void use(int idx, ICharacter& target) ;
};

#endif