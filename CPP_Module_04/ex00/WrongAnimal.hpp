#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
    std::string type ;
public:
    WrongAnimal( void ) ;
    WrongAnimal( const std::string type ) ;
    WrongAnimal( const WrongAnimal& other ) ;
    ~WrongAnimal( void ) ;
    WrongAnimal& operator=( const WrongAnimal& other) ;

    void makeSound( void ) const ; // It will print an appropriate sound (cats don’t bark)
    std::string getType( void ) const ;
};

#endif