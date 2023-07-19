#ifndef HUMAN_A_HPP

#define HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string     name ;
    Weapon&         weapon ;
public:
    HumanA( const std::string name, Weapon& weapon ) ;
    ~HumanA( void ) ;

    void attack( void ) const ;
};

#endif
