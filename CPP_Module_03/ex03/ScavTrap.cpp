#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ): _defaultName("ScavTrap"), _defaultHitPoint(100), _defaultEnergyPoint(50), _defaultAttackDamage(20)
{
    std::cout << *this << " Default Constructor!" << std::endl ;
}

ScavTrap::ScavTrap( const ScavTrap& other ): _defaultName(other._defaultName), _defaultHitPoint(other._defaultHitPoint), _defaultEnergyPoint(other._defaultEnergyPoint), _defaultAttackDamage(other._defaultAttackDamage)
{
    std::cout << *this << " Copied from " << other << "!" << std::endl ;
    ClapTrap::operator=(other) ;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& other )
{
    if (this != &other)
    {
        std::cout << *this << " Assigned from " << other << "!" << std::endl ;
        ClapTrap::operator=(other) ;
    }
    return (*this) ;
}

ScavTrap::ScavTrap( const std::string& name ): _defaultName(name), _defaultHitPoint(100), _defaultEnergyPoint(50), _defaultAttackDamage(20)
{
    std::cout << *this << " Name Constructor!" << std::endl ;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << *this << " Destroyed!" << std::endl ;
}

void ScavTrap::guardGate()
{
    std::cout << *this << " is now in Gate keeper mode" << std::endl ;
}

void ScavTrap::attack( const std::string& target )
{
    if (this->hitPoint <= 0)
    {
        std::cout << " is already dead!" << std::endl ;
        return ;
    }
    if (this->energyPoint <= 0)
    {
        std::cout << "Not enough energy points to attack " << target << "!" << std::endl ;
        return ;
    }
    this->energyPoint--;
    std::cout << *this << " attacks " << target << ", causing " << this->_defaultAttackDamage << " points of damage!" << std::endl ;
}

const std::string ScavTrap::getName() const
{
    return (_defaultName + " aka " + ClapTrap::name) ;
}

std::ostream& operator<<(std::ostream& os, const ScavTrap& scavTrap)
{
    os << scavTrap.getName() ;
    return (os) ;
}
