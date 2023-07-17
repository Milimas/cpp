#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    std::string name ;
    int    hitPoint ;       //10
    int    energyPoint ;    //10
    int    attackDamage ;   //0

    ClapTrap( void ) ;
    
public:
    ClapTrap( std::string name ) ;
    ClapTrap( std::string name, int hitPoint, int energyPoint, int attackDamage ) ;
    ClapTrap( const ClapTrap& other ) ;
    ~ClapTrap( void ) ;
    ClapTrap& operator=( const ClapTrap& other ) ;

    virtual void attack( const std::string& target ) ;
    void takeDamage( unsigned int amount ) ;
    void beRepaired( unsigned int amount ) ;

    // std::string getName() ;
    // int getHitPoint() ;
    // int getEnergyPoint() ;
    // int getAttackDamage() ;

    // void setName( std::string name ) ;
    // void setHitPoint( int amount ) ;
    // void setEnergyPoint( int amount ) ;
    // void setAttackDamage( int amount ) ;

};

#endif