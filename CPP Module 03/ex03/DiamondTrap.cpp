#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : FragTrap( "FragTrap_frag_name" ), ScavTrap( "ScavTrap_scav_name" ) //ClapTrap( "DiamondTrap_clap_name", 100, 50, 30 )//, 
{
    this->name = "DiamondTrap" ;
    std::cout << this->name << " Spawned!" << std::endl ;
}

DiamondTrap::DiamondTrap( std::string name ) : FragTrap( name + "_frag_name" ), ScavTrap( name + "_scav_name" )//ClapTrap( name + "_clap_name", 100, 50, 30 )//, 
{
    this->name = name ;
    std::cout << this->name << " Spawned!" << std::endl ;
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << this->name << " Died!" << std::endl ;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I'm " << this->name << " and my clap name is " << this->getName() << std::endl ;
}