#include "Cat.hpp"

Cat::Cat( void ): AAnimal(), type("Cat"), brain(new Brain())
{
    std::cout << "Cat::" << this->type << " Created" << std::endl ;
}

Cat::Cat( const Cat& other ): AAnimal(other), type(other.type), brain(new Brain(*other.brain))
{
    std::cout << "Cat::" << this->type << " Called Copy Constructor" << std::endl ;
}

Cat::~Cat( void )
{
    delete this->brain ;
    std::cout << "Cat::" << this->type << " Called Destructor" << std::endl ;
}

Cat& Cat::operator=( const Cat& other )
{
    std::cout << "Cat::" << this->type << " Called Copy Assignment operator" << std::endl ;
    if (this != &other)
    {
        AAnimal::operator=(other) ;
        this->type = other.type ;
        *this->brain = *other.brain ;
    }
    return (*this) ;
}

void Cat::makeSound( void ) const
{
    std::cout << "Cat::" << this->type << " Moans!!" << std::endl ;
}

std::string Cat::getType( void ) const
{
    return (this->type) ;
}
