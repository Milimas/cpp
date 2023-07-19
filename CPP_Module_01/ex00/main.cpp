#include "Zombie.hpp"

Zombie* newZombie( std::string name ) ;
void randomChump( std::string name ) ;

int main( void )
{
    Zombie zombie("Foo") ;
    zombie.announce() ;

    Zombie *z = newZombie("newZombie") ;
    z->announce() ;
    delete z ;
    
    randomChump("randomChump") ;

    return (0) ;
}
