#include "Dog.hpp"

Dog::Dog( void ): Animal("Dog"), brain(new Brain())
{
    std::cout << "Dog::" << this->type << " Created" << std::endl ;
}

Dog::Dog( const Dog& other ): Animal(other.type), brain(other.brain)
{
    std::cout << "Dog::" << this->type << " Called Copy Constructor" << std::endl ;
}

Dog::~Dog( void )
{
    delete this->brain ;
    std::cout << "Dog::" << this->type << " Called Destructor" << std::endl ;
}

Dog& Dog::operator=( const Dog& other)
{
    if (this != &other)
    {
        this->type = other.type ;
        this->brain = other.brain ;
    }
    std::cout << "Dog::" << this->type << " Called Copy Assignment operator" << std::endl ;
    return (*this) ;
}

void Dog::makeSound( void ) const
{
    std::cout << "Dog::" << this->type << " Barks!!" << std::endl ;
}
