#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type ;
public:
    Animal( void ) ;
    Animal( const Animal& other ) ;
    virtual ~Animal( void ) ;
    Animal& operator=( const Animal& other) ;

    Animal( const std::string name ) ;
    
    virtual void makeSound( void ) const ; // It will print an appropriate sound (cats don’t bark)
    virtual std::string getType( void ) const ;
};

#endif