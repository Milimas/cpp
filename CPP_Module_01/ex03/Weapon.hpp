#ifndef WEAPON_HPP

#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
    std::string type ;
public:
    Weapon( void ) ;
    Weapon( const std::string type ) ;
    ~Weapon( void ) ;

    void setType( const std::string type ) ;
    const std::string& getType( void ) const ;
};

#endif
