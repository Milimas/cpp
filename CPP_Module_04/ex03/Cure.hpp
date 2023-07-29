#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria 
{
private:
    const std::string type ;
public:
    Cure( void ) ;
    Cure( const Cure& cure ) ;
    Cure& operator=( const Cure& cure ) ;
    ~Cure( void ) ;

    const std::string getType( void ) const ;

    void use( ICharacter& target ) ;
    AMateria* clone( void ) const ;
};

#endif