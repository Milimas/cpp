#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "Brain Created" << std::endl ;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "No idea" ;
}

Brain::Brain( const Brain& other )
{
    std::cout << "Brain::" << " Copy Constructor" << std::endl ;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i] ;
}

Brain& Brain::operator=( const Brain& other )
{
    std::cout << "Brain::" << " Copy Assignment operator" << std::endl ;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i] ;
    }
    return (*this) ;
}

Brain::~Brain( void )
{
    std::cout << "Brain destroyed" << std::endl ;
}
