#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
    Zombie *z = newZombie("newZombie");

    z->announce();
    
    randomChump("randomChump");
    delete z;
    return (0);
}
