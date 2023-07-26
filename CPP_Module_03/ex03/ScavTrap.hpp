#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
    const std::string   _defaultName ;
    const int           _defaultHitPoint ;
    const int           _defaultEnergyPoint ;
    const int           _defaultAttackDamage ;
public:
    ScavTrap( void ) ;
    ScavTrap( const ScavTrap& other ) ;
    ScavTrap& operator=( const ScavTrap& other ) ;
    ~ScavTrap( void ) ;

    ScavTrap( const std::string& name ) ;

    void attack( const std::string& target ) ;
    void guardGate() ;

    const std::string getName() const ;
};

std::ostream& operator<<(std::ostream& os, const ScavTrap& scavTrap) ;

#endif