#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap("FragTrap")
{
    this->hitPoint = 100 ;
    this->energyPoint = 100 ;
    this->attackDamage = 30 ;
    std::cout << getName() << "-Derived Spawned!" << std::endl ;
}

FragTrap::FragTrap( const FragTrap& other )
{
    std::cout << getName() << " Created from " << other.name << "!" << std::endl ;
    this->name = other.name ;
    this->hitPoint = other.hitPoint ;
    this->energyPoint = other.energyPoint ;
    this->attackDamage = other.attackDamage ;
}

FragTrap& FragTrap::operator=( const FragTrap& other )
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

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
    this->hitPoint = 100 ;
    this->energyPoint = 100 ;
    this->attackDamage = 30 ;
    std::cout << getName() << "-Derived Spawned!" << std::endl ;
}

FragTrap::~FragTrap( void )
{
    std::cout << getName() << "-Derived Died!" << std::endl ;
}

void FragTrap::highFivesGuys()
{
    std::cout << getName() << " request high fives" << std::endl ;
}