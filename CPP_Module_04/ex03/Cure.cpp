#include "Cure.hpp"

Cure::Cure( void ): AMateria("cure"), type("cure")
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

Cure::Cure( const Cure& cure ): AMateria(cure.getType()), type(cure.AMateria::getType())
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

Cure& Cure::operator=( const Cure& cure )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    (void)cure ;
    return (*this) ;
}

Cure::~Cure( void )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

const std::string Cure::getType( void ) const
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    return (this->type) ;
}

void Cure::use( ICharacter& target )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl ;
}

AMateria* Cure::clone( void ) const
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    return (new Cure()) ;
}
