#include "DiamondTrap.hpp"

// Objects are always destroyed in reverse order of their creation. The reason for reverse order is, an object created later may use the previously created object

int main( void )
{
    // DiamondTrap a ;
    // DiamondTrap b ;
    DiamondTrap zac("Zac") ;
    DiamondTrap sac("Sac") ;

    std::cout << "------------------------" << std::endl ;
    zac.attack(sac.getName()) ;
    std::cout << "------------------------" << std::endl ;

    std::cout << "------------------------" << std::endl ;
    zac.takeDamage(10) ;
    std::cout << "------------------------" << std::endl ;

    std::cout << "------------------------" << std::endl ;
    sac = zac ;
    std::cout << "------------------------" << std::endl ;

    std::cout << "------------------------" << std::endl ;
    zac.beRepaired(1);
    std::cout << "------------------------" << std::endl ;

    zac.guardGate() ;
    zac.highFivesGuys() ;

    sac.whoAmI() ;
    zac.whoAmI() ;
    // DiamondTrap ahri("Ahri") ;

    // a.attack(b.getName()) ;
    // b.attack(a.getName()) ;
    // ahri.attack(zac.getName()) ;
    // zac.takeDamage(ahri.getAttackDamage()) ;
    // zac.attack(ahri.getName()) ;
    // ahri.takeDamage(zac.getAttackDamage());
    // int i = 10;
    // while (i--)
    //     zac.beRepaired(1) ;
    // ahri.beRepaired(2) ;
    // ahri.highFivesGuys() ;
    // zac.highFivesGuys() ;

    // std::cout << "Values:" << std::endl ;
    // std::cout << "zac.getName ==> " <<  zac.getName() << std::endl ;
    // std::cout << "zac.getHitPoint ==> " <<  zac.getHitPoint() << std::endl ;
    // std::cout << "zac.getEnergyPoint ==> " <<  zac.getEnergyPoint() << std::endl ;
    // std::cout << "zac.getAttackDamage ==> " <<  zac.getAttackDamage() << std::endl ;

    // zac.highFivesGuys() ;
    // zac.guardGate() ;
    // zac.whoAmI() ;
    // zac.attack("Ahri") ;
}