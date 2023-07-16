#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap( "ScavTrap_scav_name", 100, 50, 20 )
{
    std::cout << this->getName() << " Spawned!" << std::endl ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name + "_scav_name", 100, 50, 20 )
{
    std::cout << this->getName() + "_scav_name" << " Spawned!" << std::endl ;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << this->getName() + "_scav_name" << " Died!" << std::endl ;
}

void ScavTrap::guardGate()
{
    std::cout << this->getName() + "_scav_name" << " is now in Gate keeper mode" << std::endl ;
}