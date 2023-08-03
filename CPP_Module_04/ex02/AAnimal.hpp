#ifndef A_ANIMAL_HPP
#define A_ANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
    std::string type ;
public:
    AAnimal( void ) ;
    AAnimal( const AAnimal& other ) ;
    virtual ~AAnimal( void ) ;
    AAnimal& operator=( const AAnimal& other) ;

    AAnimal( const std::string type ) ;
    
    virtual void makeSound( void ) const = 0 ; // It will print an appropriate sound (cats don’t bark)
    virtual std::string getType( void ) const ;
};

#endif