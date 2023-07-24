#include "Cure.hpp"

Cure::Cure( void )
{
}

Cure& Cure::Cure( const Cure& cure )
{
}

Cure& Cure::operator=( const Cure& cure )
{
}

Cure::~Cure( void )
{
}

void Cure::use(int idx, ICharacter& target)
{
    std::cout << "* heals " << target.name << "'s wounds *" << std::endl ;
}