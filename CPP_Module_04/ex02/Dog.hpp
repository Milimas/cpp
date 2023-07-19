#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
private:
    Brain* brain ;
public:
    Dog( void ) ;
    Dog( const Dog& other ) ;
    ~Dog( void ) ;
    Dog& operator=( const Dog& other) ;

    void makeSound( void ) const ; // It will print an appropriate sound (cats don’t bark)
};

#endif