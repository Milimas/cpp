#ifndef CURE_HPP
#define CURE_HPP

#include "ICharacter.hpp"

class Cure
{
private:
public:
    Cure( void ) ;
    Cure& Cure( const Cure& cure ) ;
    Cure& operator=( const Cure& cure ) ;
    ~Cure( void ) ;

    void use(int idx, ICharacter& target) ;
};

#endif