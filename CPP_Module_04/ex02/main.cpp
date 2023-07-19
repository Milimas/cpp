#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main2()
{
    // const Animal* animal = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    j->makeSound() ;
    i->makeSound() ;

    delete j; //should not create a leak
    delete i;


    int numberOfAnimals = 4;
    Animal** animals = new Animal*[numberOfAnimals] ;

    for (int inx = 0; inx < numberOfAnimals/2; inx++)
    {
        animals[inx] = new Cat() ;
        animals[numberOfAnimals/2 + inx] = new Dog() ;
    }
    
    for (int inx = 0; inx < numberOfAnimals; inx++)
        animals[inx]->makeSound() ;

    for (int inx = 0; inx < numberOfAnimals; inx++)
        delete animals[inx] ;

    delete [] animals ;
    
    return (0) ;
}

int main()
{
    
    main2() ;
    system("leaks WorldOnFire");

    return 0;
}