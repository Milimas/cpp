#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ): name("ClapTrap"), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << getName() << " Spawned!" << std::endl ;
}

ClapTrap::ClapTrap( const ClapTrap& other ) : name(other.name), hitPoint(other.hitPoint), energyPoint(other.hitPoint), attackDamage(other.attackDamage) 
{
    std::cout << getName() << " Created from " << other.name << "!" << std::endl ;
    // *this = other ;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other )
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

ClapTrap::ClapTrap( std::string name ): name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << getName() << " Spawned!" << std::endl ;
}

void ClapTrap::attack( const std::string& target )
{
    if (this->hitPoint <= 0)
    {
        std::cout << getName() << " is already dead!" << std::endl ;
        return ;
    }
    if (this->energyPoint <= 0)
    {
        std::cout << "Not enough energy points to attack " << target << "!" << std::endl ;
        return ;
    }
    this->energyPoint--;
    std::cout << getName() << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl ;
}

void ClapTrap::takeDamage( unsigned int amount )
{
    if (this->hitPoint <= 0)
    {
        std::cout << getName() << " is already dead!" << std::endl ;
        return ;
    }
    this->hitPoint -= amount ;
    if (this->hitPoint < 0)
        this->hitPoint = 0 ;
    std::cout << getName() << " toke " << amount << " points of damage!" << " Current Health is " << this->hitPoint << std::endl ;
}

void ClapTrap::beRepaired( unsigned int amount )
{
    if (this->energyPoint <= 0)
    {
        std::cout << "Not enough energy points to repair " << getName() << "!" << std::endl ;
        return ;
    }
    if (this->hitPoint <= 0)
    {
        std::cout << getName() << " is already dead!" << std::endl ;
        return ;
    }
    this->hitPoint += amount;
    this->energyPoint--;
    std::cout << getName() << " repaired itself" << ", by " << amount << " Current Health is " << this->hitPoint << std::endl ;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << getName() << " Died!" << std::endl ;
}

std::string ClapTrap::getName()
{
    return (this->name) ;
}

// int ClapTrap::getHitPoint()
// {
//     return (this->hitPoint) ;
// }

// int ClapTrap::getEnergyPoint()
// {
//     return (this->energyPoint) ;
// }

int ClapTrap::getAttackDamage()
{
    return (this->attackDamage) ;
}

// void ClapTrap::setName( std::string name )
// {
//     this->name = name ;
// }

// void ClapTrap::setHitPoint( int amount )
// {
//     this->hitPoint = amount ;
// }

// void ClapTrap::setEnergyPoint( int amount )
// {
//     this->energyPoint = amount ;
// }

// void ClapTrap::setAttackDamage( int amount )
// {
//     this->attackDamage = amount ;
// }