#include "Cat.hpp"

Cat::Cat( void ): Animal(), type("Cat")
{
    std::cout << "Cat::" << this->type << " Created" << std::endl ;
}

Cat::Cat( const Cat& other ): Animal(other), type(other.type)
{
    std::cout << "Cat::" << this->type << " Called Copy Constructor" << std::endl ;
}

Cat::~Cat( void )
{
    std::cout << "Cat::" << this->type << " Called Destructor" << std::endl ;
}

Cat& Cat::operator=( const Cat& other )
{
    if (this != &other)
    {
        this->type = other.type ;
        Animal::operator=(other) ;
    }
    std::cout << "Cat::" << this->type << " Called Copy Assignment operator" << std::endl ;
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
