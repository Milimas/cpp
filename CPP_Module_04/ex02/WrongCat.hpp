#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
private:
    
public:
    WrongCat() ;
    WrongCat( WrongCat& other ) ;
    ~WrongCat() ;
    WrongCat& operator=( WrongCat& other) ;

    void makeSound( void ) const ;
};

#endif