#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
    std::string _name ;
    int         _hitPoint ;
    int         _energyPoint ;
    int         _attackDamage ;
public:
    FragTrap( void ) ;
    FragTrap( const FragTrap& other ) ;
    FragTrap& operator=( const FragTrap& other ) ;
    FragTrap( std::string name ) ;
    ~FragTrap( void ) ;

    void    highFivesGuys(void) ;
};

#endif