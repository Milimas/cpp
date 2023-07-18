#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
    : name(""), hitPoint(10), energyPoint(10), attackDamage(10)
{
    std::cout << "ClapTrap" << " Default constructor!" << std::endl ;
}

ClapTrap::ClapTrap( std::string name )
    : name(name), hitPoint(10), energyPoint(10), attackDamage(10)
{
    std::cout << this->name << " Name constructor!" << std::endl ;
}

ClapTrap::ClapTrap( const ClapTrap& other )
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoint = other.hitPoint;
        this->energyPoint = other.energyPoint;
        this->attackDamage = other.attackDamage;
    }
    std::cout << this->name << " Copy construtor!" << std::endl ;
}

ClapTrap&   ClapTrap::operator=( const ClapTrap& other )
{
    if (this != &other)
    {
        this->name = other.name ;
        this->hitPoint = other.hitPoint ;
        this->energyPoint = other.energyPoint;
        this->attackDamage = other.attackDamage;
    }
    std::cout << this->name << " Copy assignment operator!" << std::endl ;
    return (*this) ;
}

ClapTrap::ClapTrap( std::string name, int hitPoint, int energyPoint, int attackDamage )
    : name(name), hitPoint(hitPoint), energyPoint(energyPoint), attackDamage(attackDamage)
{
    std::cout << this->name << " Full constructor!" << std::endl ;
}

void ClapTrap::attack( const std::string& target )
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
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl ;
}

void ClapTrap::takeDamage( unsigned int amount )
{
    if (this->hitPoint <= 0)
    {
        std::cout << this->name << " is already dead!" << std::endl ;
        return ;
    }
    this->hitPoint -= amount ;
    if (this->hitPoint < 0)
        this->hitPoint = 0 ;
    std::cout << "ClapTrap " << this->name << " toke " << amount << " points of damage!" << " Current Health is " << this->hitPoint << std::endl ;
}

void ClapTrap::beRepaired( unsigned int amount )
{
    if (this->energyPoint <= 0)
    {
        std::cout << "Not enough energy points to repair " << this->name << "!" << std::endl ;
        return ;
    }
    if (this->hitPoint <= 0)
    {
        std::cout << this->name << " is already dead!" << std::endl ;
        return ;
    }
    this->hitPoint += amount;
    this->energyPoint--;
    std::cout << "ClapTrap " << this->name << " repaired itself" << ", by " << amount << " Current Health is " << this->hitPoint << std::endl ;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << this->name << " Died!" << std::endl ;
}
