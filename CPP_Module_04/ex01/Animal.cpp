#include "Animal.hpp"

Animal::Animal( void ): type("Animal")
{
    std::cout << this->type << " Created" << std::endl ;
}

Animal::Animal( Animal& other ): type(other.type)
{
    std::cout << this->type << " Called Copy Constructor" << std::endl ;
}

Animal::~Animal( void )
{
    std::cout << this->type << " Called Destructor" << std::endl ;
}

Animal& Animal::operator=( Animal& other)
{
    if (this != &other)
    {
        this->type = other.type ;
    }
    std::cout << this->type << " Called Copy Assignment operator" << std::endl ;
    return (*this) ;
}

void Animal::makeSound( void ) const
{
    std::cout << this->type << " Sound!!" << std::endl ;
}

std::string Animal::getType( void ) const
{
    return (this->type) ;
}