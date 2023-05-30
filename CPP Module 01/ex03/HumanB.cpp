#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB()
{
    this->name = "HumanB Object" ;
    std::cout << this->name << ": born" << std::endl ;
}

HumanB::HumanB( std::string name )
{
    this->name = name ;
    std::cout << this->name << ": born" << std::endl ;
}

HumanB::HumanB( std::string name, Weapon weapon )
{
    this->name = name ;
    this->setWeapon(weapon);
    std::cout << this->name << ": born" << std::endl ;
}

HumanB::~HumanB()
{
    std::cout << this->name << ": died" << std::endl ;
}

void HumanB::setWeapon( Weapon weapon )
{
    this->weapon = weapon;
}

void HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl ;
}
