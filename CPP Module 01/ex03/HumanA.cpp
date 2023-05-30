#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ): weapon(weapon)
{
    this->name = name ;
    this->weapon = weapon ;
    std::cout << this->name << ": born" << std::endl ;
}

HumanA::~HumanA()
{
    std::cout << this->name << ": died" << std::endl ;
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl ;
}
