#ifndef HUMAN_B_HPP

#define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string name ;
    Weapon*     weapon ;
public:
    HumanB( void ) ;
    HumanB( const std::string name ) ;
    ~HumanB( void ) ;

    void attack( void ) const ;
    void setWeapon( Weapon& weapon ) ;
};

#endif
