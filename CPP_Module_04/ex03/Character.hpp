#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string name ;
    // Your character’s inventory will be able to support any type of AMateria.
    AMateria    *(inventory[4]) ;
public:
    Character( void ) ;
    // Any copy (using copy constructor or copy assignment operator) of a Character must be deep. During copy, the Materias of a Character must be deleted before the new ones are added to their inventory.
    Character( const Character& Character ) ;
    Character& operator=( const Character& Character ) ;
    // Of course, the Materias must be deleted when a Character is destroyed.
    ~Character( void ) ;

    // Your Character must have a constructor taking its name as a parameter.
    Character( std::string name ) ;

    const std::string& getName( void ) const ;
    void equip( AMateria* m ) ;
    void unequip( int idx ) ;
    void use( int idx, ICharacter& target ) ;
};

#endif