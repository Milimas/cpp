#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB( std::string name ): name(name), weapon(NULL)
{
    std::cout << this->name << ": born" << std::endl ;
}

void HumanB::setWeapon( Weapon& weapon )
{
    this->weapon = &weapon;
}

HumanB::~HumanB()
{
    std::cout << this->name << ": died" << std::endl ;
}

void HumanB::attack()
{
    if (this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl ;
    else
        std::cout << this->name << " doesn't have a weapon to attack with!" << std::endl ;
}
