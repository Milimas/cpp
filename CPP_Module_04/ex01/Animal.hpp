#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type ;
public:
    Animal( void ) ;
    Animal( Animal& other ) ;
    virtual ~Animal( void ) ;
    Animal& operator=( Animal& other) ;

    virtual void makeSound( void ) const ; // It will print an appropriate sound (cats don’t bark)
    std::string getType( void ) const ;
};

#endif