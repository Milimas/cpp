#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _name ;
public:
    DiamondTrap( void ) ;
    DiamondTrap( const DiamondTrap& other ) ;
    DiamondTrap& operator=( const DiamondTrap& other ) ;
    ~DiamondTrap( void ) ;

    DiamondTrap( const std::string& name ) ;
    
    void    whoAmI() ;
    void    attack( const std::string& target ) ;
};

#endif