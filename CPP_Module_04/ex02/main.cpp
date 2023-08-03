#include "Dog.hpp"
#include "Cat.hpp"

int main2()
{
    // const AAnimal* animal = new AAnimal();
    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    dog->makeSound() ;
    cat->makeSound() ;

    delete dog; //should not create a leak
    delete cat;
    
    return (0) ;
}

int main()
{
    
    main2() ;
    system("leaks Abstract");

    return 0;
}