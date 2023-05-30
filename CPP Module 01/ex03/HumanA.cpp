#include "HumanA.hpp"

HumanA::HumanA()
{
    this->name = "HumanA Object" ;
    this->weapon.setType("AK-47");
    std::cout << this->name << ": born" << std::endl ;
}

HumanA::HumanA( std::string name, Weapon weapon )
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