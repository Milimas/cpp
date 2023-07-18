#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap( "ScavTrap_scav_name")
{
    this->name = "ScavTrap_scav_name" ;
    this->hitPoint = 100 ;
    this->energyPoint = 50 ;
    this->attackDamage = 20 ;
    std::cout << this->name << " Spawned!" << std::endl ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
    this->name = name ;
    this->hitPoint = 100 ;
    this->energyPoint = 50 ;
    this->attackDamage = 20 ;
    std::cout << this->name << " Spawned!" << std::endl ;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << this->name << " Died!" << std::endl ;
}

void ScavTrap::guardGate()
{
    std::cout << this->name << " is now in Gate keeper mode" << std::endl ;
}
void ScavTrap::attack( const std::string& target )
{
     if (this->hitPoint <= 0)
    {
        std::cout << this->name << " is already dead!" << std::endl ;
        return ;
    }
    if (this->energyPoint <= 0)
    {
        std::cout << "Not enough energy points to attack " << target << "!" << std::endl ;
        return ;
    }
    this->energyPoint--;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl ;
}