#include "Ice.hpp"

// Use their name in lowercase ("ice" for Ice, "cure" for Cure) to set their types.
Ice::Ice( void ): AMateria("ice"), type("ice")
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

Ice::Ice( const Ice& ice ): AMateria(ice), type(ice.type)
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

// While assigning a Materia to another, copying the type doesn’t make sense.
Ice& Ice::operator=( const Ice& ice )
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    (void) ice ;
    return (*this) ;
}

Ice::~Ice( void )
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

const std::string Ice::getType( void ) const
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    return (this->type) ;
}

/*
* The use(ICharacter&) member function will display:
* • Ice: "* shoots an ice bolt at <name> *"
* • Cure: "* heals <name>’s wounds *"
* <name> is the name of the Character passed as parameter. Don’t print the angle brackets (< and >).
*/
void Ice::use( ICharacter& target )
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl ;
}

// Of course, their member function clone() will return a new instance of the same type (i.e., if you clone an Ice Materia, you will get a new Ice Materia).
AMateria* Ice::clone( void ) const
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    return (new Ice()) ;
}
