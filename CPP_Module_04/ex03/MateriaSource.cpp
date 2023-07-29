#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    for (int idx = 0; idx < 4; idx++)
        this->inventory[idx] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource& rhs )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    (void)rhs ;
    for (int idx = 0; idx < 4; idx++)
        this->inventory[idx] = rhs.inventory[idx];
}

MateriaSource& MateriaSource::operator=( const MateriaSource& rhs )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    if (this != &rhs)
    {
        for (int idx = 0; idx < 4; idx++)
            this->inventory[idx] = this->inventory[idx];
    }
    return (*this) ;
}

MateriaSource::~MateriaSource( void )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    for (int idx = 0; idx < 4; idx++)
        delete this->inventory[idx];
}

/*
* Copies the Materia passed as a parameter and store it in memory so it can be cloned later.
* Like the Character, the MateriaSource can know at most 4 Materias.
* They are not necessarily unique.
*/
void MateriaSource::learnMateria( AMateria* materia )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    for (int idx = 0; idx < 4; idx++)
    {
        if (!this->inventory[idx])
        {
            this->inventory[idx] = materia ;
            break ;
        }
    }
}

/*
* Returns a new Materia.
* The latter is a copy of the Materia previously learned by the MateriaSource whose type equals the one passed as parameter.
* Returns 0 if the type is unknown.
*/
AMateria* MateriaSource::createMateria( const std::string& type )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    for (int idx = 0; idx < 4; idx++)
    {
        if (this->inventory[idx]->getType() == type)
        {
            return (this->inventory[idx]->clone());
        }
    }
    return (NULL) ;
}