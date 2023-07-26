#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
    std::string _name ;
    int         _hitPoint ;
    int         _energyPoint ;
    int         _attackDamage ;
public:
    ScavTrap( void ) ;
    ScavTrap( const ScavTrap& other ) ;
    ScavTrap& operator=( const ScavTrap& other ) ;
    ~ScavTrap( void ) ;

    ScavTrap( const std::string& name ) ;

    void attack( const std::string& target ) ;
    void guardGate() ;
};

#endif