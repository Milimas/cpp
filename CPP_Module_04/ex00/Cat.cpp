#include "Cat.hpp"

Cat::Cat( void )
{
    this->type = "Cat" ;
    std::cout << this->type << " Created" << std::endl ;
}

Cat::Cat( Cat& other )
{
    if (this != &other)
    {
        this->type = other.type ;
    }
    std::cout << this->type << " Called Copy Constructor" << std::endl ;
}

Cat::~Cat( void )
{
    std::cout << this->type << " Called Destructor" << std::endl ;
}

Cat& Cat::operator=( Cat& other)
{
    if (this != &other)
    {
        this->type = other.type ;
    }
    std::cout << this->type << " Called Copy Assignment operator" << std::endl ;
    return (*this) ;
}

void Cat::makeSound( void ) const
{
    std::cout << this->type << " Moans!!" << std::endl ;
}
