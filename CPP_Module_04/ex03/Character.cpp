#include "Character.hpp"

Character::Character( void ): name("Unamed"), inventory()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    for (int idx = 0; idx < 4; idx++)
        this->inventory[idx] = NULL;
}

Character::Character( const Character& rhs )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    this->name = rhs.name ;
    for (int idx = 0; idx < 4; idx++)
        *this->inventory[idx] = *rhs.inventory[idx] ;
}

Character& Character::operator=( const Character& rhs )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    if (this != &rhs)
    {
        this->name = rhs.name ;
        // delete [] inventory ;
        // copy new inventory
    }
    return (*this) ;
}

Character::~Character( void )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    // check if you need to delete inventory
    // delete [] inventory ;
}

Character::Character( std::string name ): name(name), inventory()/*copy inventory*/
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

const std::string& Character::getName( void ) const
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    return (this->name) ;
}

void Character::equip( AMateria* m )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    for (int idx = 0; idx < 4; idx++)
    {
        if (!this->inventory[idx])
        {
            this->inventory[idx] = m ;
            break ;
        }
    }
}

void Character::unequip( int idx )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    this->inventory[idx] = NULL ;
}

void Character::use( int idx, ICharacter& target )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    if (inventory[idx])
        inventory[idx]->use(target) ;
}
