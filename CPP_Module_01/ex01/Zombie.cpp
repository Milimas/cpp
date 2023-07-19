#include "Zombie.hpp"

Zombie::Zombie( void ): name("Zombie Object")
{
    std::cout << this->name << ": Born" << std::endl ;
}

Zombie::Zombie( const std::string name ): name(name)
{
    std::cout << this->name << ": Born" << std::endl ;
}

Zombie::~Zombie( void )
{
    std::cout << this->name << ": Died" << std::endl ;
}

void Zombie::announce( void ) const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl ;
}

void Zombie::setName( const std::string name )
{
    std::cout << this->name << ": Name changed to " << name << std::endl ;
    this->name = name ;
}