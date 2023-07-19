#include "HumanA.hpp"


HumanA::HumanA( const std::string name, Weapon& weapon ): name(name), weapon(weapon)
{
    std::cout << this->name << ": born" << std::endl ;
}

HumanA::~HumanA( void )
{
    std::cout << this->name << ": died" << std::endl ;
}

void HumanA::attack( void ) const
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl ;
}
