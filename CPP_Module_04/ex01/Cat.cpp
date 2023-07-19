#include "Cat.hpp"

Cat::Cat( void ): Animal("Cat"), brain(new Brain())
{
    std::cout << "Cat::" << this->type << " Created" << std::endl ;
}

Cat::Cat( const int i ): Animal("Cat_" + std::to_string(i)), brain(new Brain())
{
    std::cout << "Cat::" << this->type << " Created" << std::endl ;
}

Cat::Cat( const Cat& other ): Animal(other.type), brain(other.brain)
{
    std::cout << "Cat::" << this->type << " Called Copy Constructor" << std::endl ;
}

Cat::~Cat( void )
{
    delete this->brain ;
    std::cout << "Cat::" << this->type << " Called Destructor" << std::endl ;
}

Cat& Cat::operator=( const Cat& other)
{
    if (this != &other)
    {
        this->type = other.type ;
        this->brain = other.brain ;
    }
    std::cout << "Cat::" << this->type << " Called Copy Assignment operator" << std::endl ;
    return (*this) ;
}

void Cat::makeSound( void ) const
{
    std::cout << "Cat::" << this->type << " Moans!!" << std::endl ;
}
