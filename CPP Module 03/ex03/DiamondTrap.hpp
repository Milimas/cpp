#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string name ;

public:
    DiamondTrap( void ) ;
    DiamondTrap( std::string name ) ;
    DiamondTrap( std::string name, int hitPoint, int energyPoint, int attackDamage ) ;
    ~DiamondTrap( void ) ;
    
    void    whoAmI() ;
};

#endif