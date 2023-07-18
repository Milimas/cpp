#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap( "FragTrap", 100, 100, 30 )
{
    std::cout << this->getName() << "-Derived Spawned!" << std::endl ;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name, 100, 100, 30 )
{
    std::cout << this->getName() << "-Derived Spawned!" << std::endl ;
}

FragTrap::~FragTrap( void )
{
    std::cout << this->getName() << "-Derived Died!" << std::endl ;
}

void FragTrap::highFivesGuys()
{
    std::cout << this->getName() << " request high fives" << std::endl ;
}