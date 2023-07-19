
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ): type("WrongAnimal")
{
    std::cout << "WrongAnimal::" << this->type << " Created" << std::endl ;
}

WrongAnimal::WrongAnimal( const std::string type ): type(type)
{
    std::cout << "WrongAnimal::" << this->type << " Called Copy Constructor" << std::endl ;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ): type(other.type)
{
    std::cout << "WrongAnimal::" << this->type << " Called Copy Constructor" << std::endl ;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal::" << this->type << " Called Destructor" << std::endl ;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other)
{
    if (this != &other)
    {
        this->type = other.type ;
    }
    std::cout << "WrongAnimal::" << this->type << " Called Copy Assignment operator" << std::endl ;
    return (*this) ;
}

void WrongAnimal::makeSound( void ) const
{
    std::cout << "WrongAnimal::" << this->type << " Sound!!" << std::endl ;
}

std::string WrongAnimal::getType( void ) const
{
    return (this->type) ;
}