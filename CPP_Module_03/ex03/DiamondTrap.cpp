#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ): ClapTrap("DiamondTrap_clap_name"), _name("DiamondTrap")
{
    ClapTrap::hitPoint = FragTrap::_defaultHitPoint ;
    ClapTrap::energyPoint = ScavTrap::_defaultEnergyPoint ;
    ClapTrap::attackDamage = FragTrap::_defaultAttackDamage ;
    std::cout << *this << " Default Constructor!" << std::endl ;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other ): ClapTrap(other.name + "_clap_name")
{
    this->_name = other._name ;
    ClapTrap::operator=(other) ;
    std::cout << *this << " Copied from " << other << std::endl ;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& other )
{
    if (this != &other)
    {
        std::cout << *this << " Assigned from " << other << "!" << std::endl ;
        this->_name = other._name ;
        ClapTrap::operator=(other) ;
    }
    return (*this) ;
}

DiamondTrap::DiamondTrap( const std::string& name ): ClapTrap(name + "_clap_name")
{
    this->_name = name ;
    ClapTrap::name = name + "_clap_name" ;
    ClapTrap::hitPoint = FragTrap::_defaultHitPoint ;
    ClapTrap::energyPoint = ScavTrap::_defaultEnergyPoint ;
    ClapTrap::attackDamage = FragTrap::_defaultAttackDamage ;
    std::cout << *this << " Name Constructor!" << std::endl ;
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << *this << " Destroyed!" << std::endl ;
}

void DiamondTrap::whoAmI()
{
    std::cout << "-------------------------------------------------" << std::endl ;
    std::cout << "Diamond::_defaultName:            " << *this << std::endl ;
    std::cout << "-------------------------------------------------" << std::endl ;
    std::cout << "ClapTrap::name:                   " << ClapTrap::name << std::endl ;
    std::cout << "ClapTrap::hitPoint:               " << ClapTrap::hitPoint << std::endl ;
    std::cout << "ClapTrap::energyPoint:            " << ClapTrap::energyPoint << std::endl ;
    std::cout << "ClapTrap::attackDamage:           " << ClapTrap::attackDamage << std::endl ;
    std::cout << "-------------------------------------------------" << std::endl ;
    std::cout << "ScavTrap::_defaultName:           " << ScavTrap::_defaultName << std::endl ;
    std::cout << "ScavTrap::_defaultHitPoint:       " << ScavTrap::_defaultHitPoint << std::endl ;
    std::cout << "ScavTrap::_defaultEnergyPoint:    " << ScavTrap::_defaultEnergyPoint << std::endl ;
    std::cout << "ScavTrap::_defaultAttackDamage:   " << ScavTrap::_defaultAttackDamage << std::endl ;
    std::cout << "-------------------------------------------------" << std::endl ;
    std::cout << "FragTrap::_defaultName:           " << FragTrap::_defaultName << std::endl ;
    std::cout << "FragTrap::_defaultHitPoint:       " << FragTrap::_defaultHitPoint << std::endl ;
    std::cout << "FragTrap::_defaultEnergyPoint:    " << FragTrap::_defaultEnergyPoint << std::endl ;
    std::cout << "FragTrap::_defaultAttackDamage:   " << FragTrap::_defaultAttackDamage << std::endl ;
    std::cout << "-------------------------------------------------" << std::endl ;
}

void DiamondTrap::attack( const std::string& target )
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
    ScavTrap::attack(target) ;
}

const std::string DiamondTrap::getName() const
{
    return (_name + " aka " + ClapTrap::name) ;
}

std::ostream& operator<<(std::ostream& os, const DiamondTrap& diamondTrap)
{
    os << diamondTrap.getName() ;
    return (os) ;
}