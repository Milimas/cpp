#include "Zombie.hpp"

Zombie::Zombie( void ): name("Zombie")
{
    std::cout << this->name << ": Born" << std::endl ;
}

Zombie::Zombie( std::string name ): name(name)
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