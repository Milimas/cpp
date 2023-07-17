#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap( "FragTrap_frag_name" )
{
    this->name = "FragTrap_frag_name" ;
    this->hitPoint = 100 ;
    this->energyPoint = 100 ;
    this->attackDamage = 30 ;
    std::cout << this->name << " Spawned!" << std::endl ;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
    this->name = name ;
    this->hitPoint = 100 ;
    this->energyPoint = 100 ;
    this->attackDamage = 30 ;
    std::cout << this->name << " Spawned!" << std::endl ;
}

FragTrap::~FragTrap( void )
{
    std::cout << this->name << " Died!" << std::endl ;
}

void FragTrap::highFivesGuys()
{
    std::cout << this->name << " request high fives" << std::endl ;
}