#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap( "ScavTrap", 100, 50, 20 )
{
    std::cout << this->getName() << "-Derived Spawned!" << std::endl ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name, 100, 50, 20 )
{
    std::cout << this->getName() << "-Derived Spawned!" << std::endl ;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << this->getName() << "-Derived Died!" << std::endl ;
}

void ScavTrap::guardGate()
{
    std::cout << this->getName() << " is now in Gate keeper mode" << std::endl ;
}