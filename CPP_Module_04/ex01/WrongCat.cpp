#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
    this->type = "WrongCat" ;
    std::cout << this->type << " Created" << std::endl ;
}

WrongCat::WrongCat( WrongCat& other )
{
    this->type = other.type ;
    std::cout << this->type << " Called Copy Constructor" << std::endl ;
}

WrongCat::~WrongCat( void )
{
    std::cout << this->type << " Called Destructor" << std::endl ;
}

WrongCat& WrongCat::operator=( WrongCat& other)
{
    if (this != &other)
    {
        this->type = other.type ;
    }
    std::cout << this->type << " Called Copy Assignment operator" << std::endl ;
    return (*this) ;
}

void WrongCat::makeSound( void ) const
{
    std::cout << this->type << " Moans!!" << std::endl ;
}
