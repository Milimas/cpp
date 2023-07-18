#include "Weapon.hpp"

Weapon::Weapon(): type("Weapon Object")
{
    std::cout << this->type << ": Created" << std::endl ;
}

Weapon::Weapon( std::string type ): type(type)
{
    std::cout << this->type << ": Created" << std::endl ;
}

Weapon::~Weapon()
{
    std::cout << this->type << ": Destroyed" << std::endl ;
}

void Weapon::setType( std::string type )
{
    std::cout << this->type << ": type changed to " << type << std::endl ;
    this->type = type ;
}

std::string Weapon::getType ()
{
    return this->type;
}