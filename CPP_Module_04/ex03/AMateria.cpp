#include "AMateria.hpp"

AMateria::AMateria( void ): type("Undefined")
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

AMateria::AMateria( const AMateria& rhs ): type(rhs.type)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

AMateria& AMateria::operator=( const AMateria& rhs )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    (void)rhs ;
    return (*this) ;
}

AMateria::~AMateria( void )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

AMateria::AMateria( const std::string& type ): type(type)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

const std::string& AMateria::getType( void ) const //Returns the materia type
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    return (this->type) ;
}

void AMateria::use( ICharacter& target )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    (void)target ;
}
