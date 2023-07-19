#include "Dog.hpp"

Dog::Dog( void ): brain(new Brain())
{
    this->type = "Dog" ;
    std::cout << this->type << " Created" << std::endl ;
}

Dog::Dog( Dog& other )
{
    this->type = other.type ;
    this->brain = other.brain ;
    std::cout << this->type << " Called Copy Constructor" << std::endl ;
}

Dog::~Dog( void )
{
    delete this->brain ;
    std::cout << this->type << " Called Destructor" << std::endl ;
}

Dog& Dog::operator=( Dog& other)
{
    if (this != &other)
    {
        this->type = other.type ;
        this->brain = other.brain ;
    }
    std::cout << this->type << " Called Copy Assignment operator" << std::endl ;
    return (*this) ;
}

void Dog::makeSound( void ) const
{
    std::cout << this->type << " Barks!!" << std::endl ;
}
