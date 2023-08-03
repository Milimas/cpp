#include "AAnimal.hpp"

AAnimal::AAnimal( void ): type("AAnimal")
{
    std::cout << "AAnimal::" << this->type << " Created" << std::endl ;
}

AAnimal::AAnimal( const std::string type ): type(type)
{
    std::cout << "AAnimal::" << this->type << " Created" << std::endl ;
}

AAnimal::AAnimal( const AAnimal& other ): type(other.type)
{
    std::cout << "AAnimal::" << this->type << " Called Copy Constructor" << std::endl ;
}

AAnimal::~AAnimal( void )
{
    std::cout << "AAnimal::" << this->type << " Called Destructor" << std::endl ;
}

AAnimal& AAnimal::operator=( const AAnimal& other)
{
    if (this != &other)
    {
        this->type = other.type ;
    }
    std::cout << "AAnimal::" << this->type << " Called Copy Assignment operator" << std::endl ;
    return (*this) ;
}

std::string AAnimal::getType( void ) const
{
    return (this->type) ;
}