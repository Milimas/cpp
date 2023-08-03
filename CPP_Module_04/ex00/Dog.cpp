#include "Dog.hpp"

Dog::Dog( void ): Animal(), type("Dog")
{
    std::cout << "Dog::" << this->type << " Created" << std::endl ;
}

Dog::Dog( const Dog& other ): Animal(other), type(other.type)
{
    std::cout << "Dog::" << this->type << " Called Copy Constructor" << std::endl ;
}

Dog::~Dog( void )
{
    std::cout << "Dog::" << this->type << " Called Destructor" << std::endl ;
}

Dog& Dog::operator=( const Dog& other)
{
    if (this != &other)
    {
        this->type = other.type ;
        Animal::operator=(other) ;
    }
    std::cout << "Dog::" << this->type << " Called Copy Assignment operator" << std::endl ;
    return (*this) ;
}

void Dog::makeSound( void ) const
{
    std::cout << "Dog::" << this->type << " Barks!!" << std::endl ;
}

std::string Dog::getType( void ) const
{
    return (this->type) ;
}
