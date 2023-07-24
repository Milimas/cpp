#include "Ice.hpp"

Ice::Ice( void )
{
}

Ice& Ice::Ice( const Ice& ice )
{
}

Ice& Ice::operator=( const Ice& ice )
{
}

Ice::~Ice( void )
{
}

void Ice::use(int idx, ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.name << " *" << std::endl ;
}
