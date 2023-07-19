#include "WrongCat.hpp"

WrongCat::WrongCat( void ): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat::" << this->type << " Created" << std::endl ;
}

WrongCat::WrongCat( const WrongCat& other )
{
    this->type = other.type ;
    std::cout << "WrongCat::" << this->type << " Called Copy Constructor" << std::endl ;
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat::" << this->type << " Called Destructor" << std::endl ;
}

WrongCat& WrongCat::operator=( const WrongCat& other)
{
    if (this != &other)
    {
        this->type = other.type ;
    }
    std::cout << "WrongCat::" << this->type << " Called Copy Assignment operator" << std::endl ;
    return (*this) ;
}

void WrongCat::makeSound( void ) const
{
    std::cout << "WrongCat::" << this->type << " Moans!!" << std::endl ;
}
