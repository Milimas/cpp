#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter ;

/*
* Complete the definition of the following AMateria class and implement the necessary member functions.
*/
class AMateria
{
protected:
    const std::string type ;
public:
    AMateria( void ) ;
    AMateria( const AMateria& rhs ) ;
    AMateria& operator=( const AMateria& rhs ) ;
    virtual ~AMateria( void ) ;

    AMateria( const std::string& type ) ;

    const std::string& getType( void ) const ; //Returns the materia type

    virtual void use( ICharacter& ) ;
    virtual AMateria* clone( void ) const = 0 ;
};

#endif