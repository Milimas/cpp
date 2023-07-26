#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
    this->name = "ScavTrap" ;
    this->hitPoint = 100 ;
    this->energyPoint = 50 ;
    this->attackDamage = 20 ;
    std::cout << getName() << "-Derived Spawned!" << std::endl ;
}

ScavTrap::ScavTrap( const ScavTrap& other )
{
    *this = other ;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& other )
{
    if (this != &other)
    {
        std::cout << getName() << " Becomes " << other.name << "!" << std::endl ;
        this->name = other.name ;
        this->hitPoint = other.hitPoint ;
        this->energyPoint = other.energyPoint ;
        this->attackDamage = other.attackDamage ;
    }
    return (*this) ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
    std::cout << getName() << "-Derived Spawned!" << std::endl ;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << getName() << "-Derived Died!" << std::endl ;
}

void ScavTrap::guardGate()
{
    std::cout << getName() << " is now in Gate keeper mode" << std::endl ;
}