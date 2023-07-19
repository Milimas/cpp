#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB( void ): name("HumanB"), weapon(NULL)
{
    std::cout << this->name << ": born" << std::endl ;
}

HumanB::HumanB( const std::string name ): name(name), weapon(NULL)
{
    std::cout << this->name << ": born" << std::endl ;
}

void HumanB::setWeapon( Weapon& weapon )
{
    this->weapon = &weapon;
}

HumanB::~HumanB( void )
{
    std::cout << this->name << ": died" << std::endl ;
}

void HumanB::attack( void ) const
{
    if (this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl ;
    else
        std::cout << this->name << " doesn't have a weapon to attack with!" << std::endl ;
}
