#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type ;
public:
    Animal( void ) ;
    Animal( const std::string type ) ;
    Animal( const Animal& other ) ;
    virtual ~Animal( void ) ;
    Animal& operator=( const Animal& other) ;

    virtual void makeSound( void ) const = 0 ; // It will print an appropriate sound (cats don’t bark)
    std::string getType( void ) const ;
};

#endif