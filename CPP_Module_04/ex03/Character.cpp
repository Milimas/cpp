#include "Character.hpp"

// The Character possesses an inventory of 4 slots, which means 4 Materias at most. The inventory is empty at construction.
Character::Character( void ): name("Unamed")
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    for (int idx = 0; idx < 4; idx++)
        this->inventory[idx] = NULL;
}

/*
* Any copy (using copy constructor or copy assignment operator) of a Character must be deep.
* During copy, the Materias of a Character must be deleted before the new ones are added to their inventory.
*/
Character::Character( const Character& rhs ): ICharacter(rhs), name(rhs.name)
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    for (int idx = 0; idx < 4; idx++)
        delete this->inventory[idx] ;
    for (int idx = 0; idx < 4; idx++)
        this->inventory[idx] = rhs.inventory[idx]->clone() ;
}

/*
* Any copy (using copy constructor or copy assignment operator) of a Character must be deep.
* During copy, the Materias of a Character must be deleted before the new ones are added to their inventory.
*/
Character& Character::operator=( const Character& rhs )
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    if (this != &rhs)
    {
        for (int idx = 0; idx < 4; idx++)
            delete this->inventory[idx] ;
        for (int idx = 0; idx < 4; idx++)
            this->inventory[idx] = rhs.inventory[idx]->clone() ;
    }
    return (*this) ;
}

// Of course, the Materias must be deleted when a Character is destroyed. 
Character::~Character( void )
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    for (int idx = 0; idx < 4; idx++)
        delete this->inventory[idx] ;
}

// Your Character must have a constructor taking its name as a parameter. 
// The Character possesses an inventory of 4 slots, which means 4 Materias at most. The inventory is empty at construction.
Character::Character( std::string name ): name(name), inventory()/*copy inventory*/
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    for (int idx = 0; idx < 4; idx++)
        this->inventory[idx] = NULL;
}

const std::string& Character::getName( void ) const
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    return (this->name) ;
}

/*
* They equip the Materias in the first empty slot they find. This means, in this order: from slot 0 to slot 3.
* In case they try to add a Materia to a full inventory, or use/unequip an unexisting Materia, don’t do anything (but still, bugs are forbidden).
*/
void Character::equip( AMateria* m )
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    for (int idx = 0; idx < 4; idx++)
    {
        if (!this->inventory[idx])
        {
            this->inventory[idx] = m ;
            break ;
        }
    }
}

// In case they try to add a Materia to a full inventory, or use/unequip an unexisting Materia, don’t do anything (but still, bugs are forbidden). 
// The unequip() member function must NOT delete the Materia!
// Handle the Materias your character left on the floor as you like. Save the addresses before calling unequip(), or anything else, but don’t forget that you have to avoid memory leaks.
void Character::unequip( int idx )
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    this->inventory[idx] = NULL ;
}

// The use(int, ICharacter&) member function will have to use the Materia at the slot[idx], and pass the target parameter to the AMateria::use function.
// or use/unequip an unexisting Materia, don’t do anything (but still, bugs are forbidden).
void Character::use( int idx, ICharacter& target )
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    if (inventory[idx])
        inventory[idx]->use(target) ;
}
