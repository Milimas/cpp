#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
{
private:
    std::string type ;
    Brain* brain ;
public:
    Cat( void ) ;
    Cat( const Cat& other ) ;
    ~Cat( void ) ;
    Cat& operator=( const Cat& other) ;

    void makeSound( void ) const ;
    std::string getType( void ) const ;
};

#endif