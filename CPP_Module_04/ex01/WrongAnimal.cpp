
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ): type("WrongAnimal")
{
    std::cout << this->type << " Created" << std::endl ;
}

WrongAnimal::WrongAnimal( WrongAnimal& other ): type(other.type)
{
    std::cout << this->type << " Called Copy Constructor" << std::endl ;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << this->type << " Called Destructor" << std::endl ;
}

WrongAnimal& WrongAnimal::operator=( WrongAnimal& other)
{
    if (this != &other)
    {
        this->type = other.type ;
    }
    std::cout << this->type << " Called Copy Assignment operator" << std::endl ;
    return (*this) ;
}

void WrongAnimal::makeSound( void ) const
{
    std::cout << this->type << " Sound!!" << std::endl ;
}

std::string WrongAnimal::getType( void ) const
{
    return (this->type) ;
}