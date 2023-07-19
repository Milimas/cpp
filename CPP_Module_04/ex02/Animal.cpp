#include "Animal.hpp"

Animal::Animal( void ): type("Animal")
{
    std::cout << "Animal::" << this->type << " Created" << std::endl ;
}

Animal::Animal( const std::string type ): type(type)
{
    std::cout << "Animal::" << this->type << " Created" << std::endl ;
}

Animal::Animal( const Animal& other ): type(other.type)
{
    std::cout << "Animal::" << this->type << " Called Copy Constructor" << std::endl ;
}

Animal::~Animal( void )
{
    std::cout << "Animal::" << this->type << " Called Destructor" << std::endl ;
}

Animal& Animal::operator=( const Animal& other)
{
    if (this != &other)
    {
        this->type = other.type ;
    }
    std::cout << "Animal::" << this->type << " Called Copy Assignment operator" << std::endl ;
    return (*this) ;
}

void Animal::makeSound( void ) const
{
    std::cout << "Animal::" << this->type << " Sound!!" << std::endl ;
}

std::string Animal::getType( void ) const
{
    return (this->type) ;
}