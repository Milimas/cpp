#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
    std::string name ;
    int    hitPoint ;       //10
    int    energyPoint ;    //10
    int    attackDamage ;   //0
public:
    ClapTrap( void ) ;
    ClapTrap( const ClapTrap& clapTrap ) ;
    ClapTrap& operator=( const ClapTrap& other ) ;
    ~ClapTrap( void ) ;
    
    ClapTrap( std::string name ) ;

    virtual void attack( const std::string& target ) ;
    void takeDamage( unsigned int amount ) ;
    void beRepaired( unsigned int amount ) ;

    std::string getName() const ;
    int getAttackDamage() const ;
};

std::ostream& operator<<( std::ostream& os, const ClapTrap& clapTrap ) ;

#endif