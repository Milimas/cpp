#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class Ice : public AMateria
{
private:
    const std::string type ;
public:
    Ice( void ) ;
    Ice( const Ice& ice ) ;
    Ice& operator=( const Ice& ice ) ;
    ~Ice( void ) ;

    const std::string getType( void ) const ;

    void use( ICharacter& target ) ;
    AMateria* clone( void ) const ;
};

#endif