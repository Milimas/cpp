#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
private:
    std::string type ;
public:
    Dog( void ) ;
    Dog( const Dog& other ) ;
    ~Dog( void ) ;
    Dog& operator=( const Dog& other) ;

    void makeSound( void ) const ; // It will print an appropriate sound (cats don’t bark)
    std::string getType( void ) const ;
};

#endif