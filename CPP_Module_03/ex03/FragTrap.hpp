#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
    const std::string   _defaultName ;
    const int           _defaultHitPoint ;
    const int           _defaultEnergyPoint ;
    const int           _defaultAttackDamage ;
public:
    FragTrap( void ) ;
    FragTrap( const FragTrap& other ) ;
    FragTrap& operator=( const FragTrap& other ) ;
    FragTrap( std::string name ) ;
    ~FragTrap( void ) ;

    void    highFivesGuys(void) ;
    
    const std::string getName() const ;
};

std::ostream& operator<<(std::ostream& os, const FragTrap& fragTrap) ;

#endif