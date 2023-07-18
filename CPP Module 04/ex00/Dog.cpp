#include "Dog.hpp"

Dog::Dog( void )
{
    this->type = "Dog" ;
    std::cout << this->type << " Created" << std::endl ;
}

Dog::Dog( Dog& other )
{
    if (this != &other)
    {
        this->type = other.type ;
    }
    std::cout << this->type << " Called Copy Constructor" << std::endl ;
}

Dog::~Dog( void )
{
    std::cout << this->type << " Called Destructor" << std::endl ;
}

Dog& Dog::operator=( Dog& other)
{
    if (this != &other)
    {
        this->type = other.type ;
    }
    std::cout << this->type << " Called Copy Assignment operator" << std::endl ;
    return (*this) ;
}

void Dog::makeSound( void ) const
{
    std::cout << this->type << " Barks!!" << std::endl ;
}
