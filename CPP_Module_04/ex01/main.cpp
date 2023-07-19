#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    j->makeSound() ;
    i->makeSound() ;

    delete j; //should not create a leak
    delete i;

    Animal** animals = new Animal*[100] ;

    for (int inx = 0; inx < 50; inx++)
    {
        animals[inx] = new Cat() ;
        animals[50 + inx] = new Dog() ;
    }
    
    for (int inx = 0; inx < 50; inx++)
    {
        delete animals[inx] ;
    }

    system("leaks WorldOnFire");

    return 0;
}