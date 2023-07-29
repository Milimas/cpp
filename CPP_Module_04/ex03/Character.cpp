#include "Character.hpp"

Character::Character( void ): name("Unamed")
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    for (int idx = 0; idx < 4; idx++)
        this->inventory[idx] = NULL;
}

Character::Character( const Character& rhs ): name(rhs.name)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    for (int idx = 0; idx < 4; idx++)
        this->inventory[idx] = rhs.inventory[idx] ;
}

Character& Character::operator=( const Character& rhs )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    if (this != &rhs)
    {
        for (int idx = 0; idx < 4; idx++)
            delete this->inventory[idx] ;
        for (int idx = 0; idx < 4; idx++)
            this->inventory[idx] = rhs.inventory[idx] ;
    }
    return (*this) ;
}

Character::~Character( void )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    for (int idx = 0; idx < 4; idx++)
        delete this->inventory[idx] ;
}

Character::Character( std::string name ): name(name), inventory()/*copy inventory*/
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    for (int idx = 0; idx < 4; idx++)
        this->inventory[idx] = NULL;
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
