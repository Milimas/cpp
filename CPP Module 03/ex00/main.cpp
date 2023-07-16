#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap a ;
    ClapTrap b ;
    ClapTrap zac("Zac") ;
    ClapTrap ahri("Ahri") ;

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
}