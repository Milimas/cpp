#include "Cure.hpp"

// Use their name in lowercase ("ice" for Ice, "cure" for Cure) to set their types.
Cure::Cure( void ): AMateria("cure"), type("cure")
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

Cure::Cure( const Cure& cure ): AMateria(cure.getType()), type(cure.AMateria::getType())
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

// While assigning a Materia to another, copying the type doesn’t make sense.
Cure& Cure::operator=( const Cure& cure )
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    (void)cure ;
    return (*this) ;
}

Cure::~Cure( void )
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

const std::string Cure::getType( void ) const
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
void Cure::use( ICharacter& target )
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl ;
}

// Of course, their member function clone() will return a new instance of the same type (i.e., if you clone an Ice Materia, you will get a new Ice Materia).
AMateria* Cure::clone( void ) const
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    return (new Cure()) ;
}
