#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main2()
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    dog->makeSound() ;
    cat->makeSound() ;

    delete dog; //should not create a leak
    delete cat;


    int numberOfAnimals = 100;
    Animal** animals = new Animal*[numberOfAnimals] ;

    for (int inx = 0; inx < numberOfAnimals/2; inx++)
    {
        animals[inx] = new Cat() ;
        animals[numberOfAnimals/2 + inx] = new Dog() ;
    }
    
    for (int inx = 0; inx < numberOfAnimals; inx++)
    {
        delete animals[inx] ;
    }
    delete [] animals ;
    return (0) ;
}

int main()
{
    main2() ;
    system("leaks WorldOnFire");

    return 0;
}