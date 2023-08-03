#include "Dog.hpp"

Dog::Dog( void ): AAnimal(), type("Dog"), brain(new Brain())
{
    std::cout << "Dog::" << this->type << " Created" << std::endl ;
}

Dog::Dog( const Dog& other ): AAnimal(other), type(other.type), brain(new Brain(*other.brain))
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
    std::cout << "Dog::" << this->type << " Called Copy Assignment operator" << std::endl ;
    if (this != &other)
    {
        AAnimal::operator=(other) ;
        this->type = other.type ;
        *this->brain = *other.brain ;
    }
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
