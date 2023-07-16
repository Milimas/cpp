#include "ScavTrap.hpp"

// Objects are always destroyed in reverse order of their creation. The reason for reverse order is, an object created later may use the previously created object

int main( void )
{
    ScavTrap a ;
    ScavTrap b ;
    ScavTrap zac("Zac") ;
    ScavTrap ahri("Ahri") ;

    a.attack(b.getName()) ;
    b.attack(a.getName()) ;
    ahri.attack(zac.getName()) ;
    zac.takeDamage(ahri.getAttackDamage()) ;
    zac.attack(ahri.getName()) ;
    ahri.takeDamage(zac.getAttackDamage());
    int i = 10;
    while (i--)
        zac.beRepaired(1) ;
    ahri.beRepaired(2) ;
    ahri.guardGate() ;
    zac.guardGate() ;
}