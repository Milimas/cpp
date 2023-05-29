#include "Zombie.hpp"

Zombie* newZombie( std::string name );

void randomChump( std::string name )
{
    Zombie *Zombie = newZombie(name);
    Zombie->announce();
    delete Zombie;
}