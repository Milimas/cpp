#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB( std::string name ): weapon(NULL)
{
    this->name = name ;
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
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl ;
}
