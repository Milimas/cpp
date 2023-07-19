#include "Weapon.hpp"

Weapon::Weapon( void ): type("Weapon Object")
{
    std::cout << this->type << ": Created" << std::endl ;
}

Weapon::Weapon( const std::string type ): type(type)
{
    std::cout << this->type << ": Created" << std::endl ;
}

Weapon::~Weapon( void )
{
    std::cout << this->type << ": Destroyed" << std::endl ;
}

void Weapon::setType( const std::string type )
{
    std::cout << this->type << ": type changed to " << type << std::endl ;
    this->type = type ;
}

const std::string& Weapon::getType( void ) const
{
    return (this->type);
}