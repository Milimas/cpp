#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap( void ) ;
    ScavTrap( std::string name ) ;
    ~ScavTrap( void ) ;

    void guardGate() ;
};

#endif