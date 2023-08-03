#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
private:
    std::string type ;
public:
    Cat( void ) ;
    Cat( const Cat& other ) ;
    ~Cat( void ) ;
    Cat& operator=( const Cat& other) ;

    void makeSound( void ) const ;
    std::string getType( void ) const ;
};

#endif