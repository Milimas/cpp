#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ): ClapTrap("DiamondTrap_clap_name"), ScavTrap("DiamondTrap_scav_name"), FragTrap("DiamondTrap_frag_name")
{
    this->name = "DiamondTrap" ;
    ClapTrap::name = name + "_clap_name" ;
    this->energyPoint = 50 ; 
    std::cout << this->name << " aka " << ClapTrap::name << " Spawned!" << std::endl ;
}

DiamondTrap::DiamondTrap( std::string name ): ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav_name"), FragTrap(name + "_frag_name")
{
    this->name = name ;
    ClapTrap::name = name + "_clap_name" ;
    this->energyPoint = 50 ;
    std::cout << this->name << " aka " << ClapTrap::name << " Spawned!" << std::endl ;
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << this->name << " aka " << ClapTrap::name << " Died!" << std::endl ;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I'm " << this->name << " and my clap name is " << ClapTrap::name << std::endl ;
    std::cout << "hitPoint: " << ClapTrap::hitPoint << std::endl ;
    std::cout << "energyPoint: " << ClapTrap::energyPoint << std::endl ;
    std::cout << "attackDamage: " << ClapTrap::attackDamage << std::endl ;
}
