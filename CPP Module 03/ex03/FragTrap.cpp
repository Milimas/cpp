#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap( "FragTrap_frag_name", 100, 100, 30 )
{
    std::cout << this->getName() << " Spawned!" << std::endl ;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name + "_frag_name", 100, 100, 30 )
{
    std::cout << this->getName() + "_frag_name" << " Spawned!" << std::endl ;
}

FragTrap::~FragTrap( void )
{
    std::cout << this->getName() + "_frag_name" << " Died!" << std::endl ;
}

void FragTrap::highFivesGuys()
{
    std::cout << this->getName() + "_frag_name" << " request high fives" << std::endl ;
}