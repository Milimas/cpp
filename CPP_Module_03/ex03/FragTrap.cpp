#include "FragTrap.hpp"

FragTrap::FragTrap( void ): _defaultName("FragTrap"), _defaultHitPoint(100), _defaultEnergyPoint(100), _defaultAttackDamage(30)
{
    std::cout << *this << " Default Constructor!" << std::endl ;
}

FragTrap::FragTrap( const FragTrap& other ): _defaultName(other._defaultName), _defaultHitPoint(other._defaultHitPoint), _defaultEnergyPoint(other._defaultEnergyPoint), _defaultAttackDamage(other._defaultAttackDamage)
{
    std::cout << *this << " Copied from " << other << "!" << std::endl ;
    ClapTrap::operator=(other) ;
}

FragTrap& FragTrap::operator=( const FragTrap& other )
{
    if (this != &other)
    {
        std::cout << *this << " Assigned From " << other << "!" << std::endl ;
        ClapTrap::operator=(other) ;
    }
    return (*this) ;
}

FragTrap::FragTrap( std::string name ) : _defaultName(name), _defaultHitPoint(100), _defaultEnergyPoint(100), _defaultAttackDamage(30)
{
    std::cout << *this << " Name Constructor!" << std::endl ;
}

FragTrap::~FragTrap( void )
{
    std::cout << *this << " Destructor!" << std::endl ;
}

void FragTrap::highFivesGuys()
{
    std::cout << *this << " requests a high fives" << std::endl ;
}

const std::string FragTrap::getName() const
{
    return (_defaultName + " aka " + ClapTrap::name) ;
}

std::ostream& operator<<(std::ostream& os, const FragTrap& fragTrap)
{
    os << fragTrap.getName() ;
    return (os) ;
}