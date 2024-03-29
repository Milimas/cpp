#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap( void ) ;
    ScavTrap( const ScavTrap& other ) ;
    ScavTrap& operator=( const ScavTrap& other ) ;
    ~ScavTrap( void ) ;

    ScavTrap( std::string name ) ;

    void guardGate() ;
};

#endif