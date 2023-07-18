#include "Zombie.hpp"

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