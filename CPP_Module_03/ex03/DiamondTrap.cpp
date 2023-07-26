#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ): ClapTrap("DiamondTrap_clap_name")
{
    this->_name = "DiamondTrap" ;
    ClapTrap::name = _name + "_clap_name" ;
    ClapTrap::hitPoint = FragTrap::_hitPoint ;
    ClapTrap::energyPoint = ScavTrap::energyPoint ;
    ClapTrap::attackDamage = FragTrap::_attackDamage ;
    // std::cout << this->_name << " aka " << ClapTrap::name << " Spawned!" << std::endl ;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other ): ClapTrap(other.name + "_clap_name")
{
    this->_name = other.name ;
    ClapTrap::operator=((ClapTrap)other) ;
    FragTrap::operator=((FragTrap)other) ;
    ScavTrap::operator=((ScavTrap)other) ;
    // std::cout << this->_name << " aka " << ClapTrap::name << " Spawned!" << std::endl ;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& other )
{
    std::cout << this->_name << " aka " << ClapTrap::name << " Changed to " << other.name << "!" << std::endl ;
    if (this != &other)
    {
        this->_name = other.name ;
        ClapTrap::operator=((ClapTrap)other) ;
        FragTrap::operator=((FragTrap)other) ;
        ScavTrap::operator=((ScavTrap)other) ;
    }
    return (*this) ;
}

DiamondTrap::DiamondTrap( const std::string& name ): ClapTrap(name + "_clap_name")
{
    this->_name = name ;
    ClapTrap::name = name + "_clap_name" ;
    ClapTrap::hitPoint = FragTrap::_hitPoint ;
    ClapTrap::energyPoint = ScavTrap::_energyPoint ;
    ClapTrap::attackDamage = FragTrap::_attackDamage ;
    // std::cout << this->_name << " aka " << ClapTrap::name << " Spawned!" << std::endl ;
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << this->_name << " aka " << ClapTrap::name << " Died!" << std::endl ;
}

void DiamondTrap::whoAmI()
{
    std::cout << "-------------------------------------------------" << std::endl ;
    std::cout << "Diamond::_name:            " << this->_name << std::endl ;
    std::cout << "-------------------------------------------------" << std::endl ;
    std::cout << "ClapTrap::name:            " << ClapTrap::name << std::endl ;
    std::cout << "ClapTrap::hitPoint:        " << ClapTrap::hitPoint << std::endl ;
    std::cout << "ClapTrap::energyPoint:     " << ClapTrap::energyPoint << std::endl ;
    std::cout << "ClapTrap::attackDamage:    " << ClapTrap::attackDamage << std::endl ;
    std::cout << "-------------------------------------------------" << std::endl ;
    std::cout << "ScavTrap::_name:           " << ScavTrap::_name << std::endl ;
    std::cout << "ScavTrap::_hitPoint:       " << ScavTrap::_hitPoint << std::endl ;
    std::cout << "ScavTrap::_energyPoint:    " << ScavTrap::_energyPoint << std::endl ;
    std::cout << "ScavTrap::_attackDamage:   " << ScavTrap::_attackDamage << std::endl ;
    std::cout << "-------------------------------------------------" << std::endl ;
    std::cout << "FragTrap::_name:           " << FragTrap::_name << std::endl ;
    std::cout << "FragTrap::_hitPoint:       " << FragTrap::_hitPoint << std::endl ;
    std::cout << "FragTrap::_energyPoint:    " << FragTrap::_energyPoint << std::endl ;
    std::cout << "FragTrap::_attackDamage:   " << FragTrap::_attackDamage << std::endl ;
    std::cout << "-------------------------------------------------" << std::endl ;
}

void DiamondTrap::attack( const std::string& target )
{
    ScavTrap::attack(target) ;
}