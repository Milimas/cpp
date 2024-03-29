#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap( void ) ;
    FragTrap( const FragTrap& other ) ;
    FragTrap& operator=( const FragTrap& other ) ;
    FragTrap( std::string name ) ;
    ~FragTrap( void ) ;

    void    highFivesGuys(void) ;
};

#endif