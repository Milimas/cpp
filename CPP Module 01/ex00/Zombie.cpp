#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
    this->name = name;
    std::cout << this->name << ": born" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << ": died" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}