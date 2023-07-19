#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
private:
    
public:
    WrongCat( void ) ;
    WrongCat( const WrongCat& other ) ;
    ~WrongCat( void ) ;
    WrongCat& operator=( const WrongCat& other) ;

    void makeSound( void ) const ;
};

#endif