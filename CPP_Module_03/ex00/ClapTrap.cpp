#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ): name("ClapTrap"), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << *this << " Spawned!" << std::endl ;
}

ClapTrap::ClapTrap( const ClapTrap& other ): name(other.name), hitPoint(other.hitPoint), energyPoint(other.energyPoint), attackDamage(other.attackDamage)
{
    std::cout << *this << " Created from " << other.name << "!" << std::endl ;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other )
{
    if (this != &other)
    {
        std::cout << *this << " Becomes " << other.name << "!" << std::endl ;
        this->name = other.name ;
        this->hitPoint = other.hitPoint ;
        this->energyPoint = other.energyPoint ;
        this->attackDamage = other.attackDamage ;
    }
    return (*this) ;
}

ClapTrap::ClapTrap( std::string name ): name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << *this << " Spawned!" << std::endl ;
}

void ClapTrap::attack( const std::string& target )
{
    if (this->hitPoint <= 0)
    {
        std::cout << *this << " is already dead!" << std::endl ;
        return ;
    }
    if (this->energyPoint <= 0)
    {
        std::cout << "Not enough energy points to attack " << target << "!" << std::endl ;
        return ;
    }
    this->energyPoint--;
    std::cout << *this << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl ;
}

void ClapTrap::takeDamage( unsigned int amount )
{
    if (this->hitPoint <= 0)
    {
        std::cout << *this << " is already dead!" << std::endl ;
        return ;
    }
    this->hitPoint -= amount ;
    if (this->hitPoint < 0)
        this->hitPoint = 0 ;
    std::cout << *this << " toke " << amount << " points of damage!" << " Current Health is " << this->hitPoint << std::endl ;
}

void ClapTrap::beRepaired( unsigned int amount )
{
    if (this->energyPoint <= 0)
    {
        std::cout << "Not enough energy points to repair " << *this << "!" << std::endl ;
        return ;
    }
    if (this->hitPoint <= 0)
    {
        std::cout << *this << " is already dead!" << std::endl ;
        return ;
    }
    this->hitPoint += amount;
    this->energyPoint--;
    std::cout << *this << " repaired itself" << ", by " << amount << " Current Health is " << this->hitPoint << std::endl ;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << *this << " Died!" << std::endl ;
}

std::string ClapTrap::getName() const
{
    return (this->name) ;
}

int ClapTrap::getAttackDamage() const
{
    return (this->attackDamage) ;
}

std::ostream& operator<<(std::ostream& os, const ClapTrap& clapTrap)
{
    os << clapTrap.getName() ;
    return (os) ;
}
