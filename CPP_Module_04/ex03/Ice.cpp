#include "Ice.hpp"

Ice::Ice( void ): AMateria("ice"), type("ice")
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

Ice::Ice( const Ice& ice ): AMateria(ice), type(ice.type)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

Ice& Ice::operator=( const Ice& ice )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    (void) ice ;
    return (*this) ;
}

Ice::~Ice( void )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

const std::string Ice::getType( void ) const
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    return (this->type) ;
}

void Ice::use( ICharacter& target )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl ;
}

AMateria* Ice::clone( void ) const
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    return (new Ice()) ;
}
