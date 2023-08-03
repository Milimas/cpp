#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    {
        const Animal* animal = new Animal() ;
        const Animal* dog = new Dog() ;
        const Animal* cat = new Cat() ;

        std::cout << "---------" << std::endl ;
        
        std::cout << dog->getType() << " " << std::endl ;
        std::cout << cat->getType() << " " << std::endl ;
        
        std::cout << "---------" << std::endl ;

        cat->makeSound() ; //will output the cat sound!
        dog->makeSound() ;
        animal->makeSound() ;

        std::cout << "---------" << std::endl ;

        delete animal ;
        delete cat ;
        delete dog ;
    }
    std::cout << "---------" << std::endl ;
    {
        const WrongAnimal* wAnimal = new WrongAnimal() ;
        const WrongAnimal* wCat = new WrongCat() ;

        std::cout << "---------" << std::endl ;

        std::cout << wCat->getType() << " " << std::endl ;

        std::cout << "---------" << std::endl ;

        wCat->makeSound() ; //will output the wrong animal sound!
        wAnimal->makeSound() ;

        std::cout << "---------" << std::endl ;

        delete wAnimal ;
        delete wCat ;
    }
    return 0 ;
}