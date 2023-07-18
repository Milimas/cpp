#include "Zombie.hpp"

Zombie::Zombie()
{
    this->name = "Zombie Object" ;
    std::cout << this->name << ": Born" << std::endl ;
}

Zombie::Zombie( std::string name )
{
    this->name = name ;
    std::cout << this->name << ": Born" << std::endl ;
}

Zombie::~Zombie()
{
    std::cout << this->name << ": Died" << std::endl ;
}

void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl ;
}

void Zombie::setName( std::string name )
{
    std::cout << this->name << ": Name changed to " << name << std::endl ;
    this->name = name ;
}