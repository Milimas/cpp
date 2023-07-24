#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource
{
private:
public:
    MateriaSource( void ) ;
    MateriaSource& MateriaSource( const MateriaSource& materiaSource ) ;
    MateriaSource& operator=( const MateriaSource& materiaSource ) ;
    ~MateriaSource( void ) ;

    void learnMateria( AMateria* materia ) ;
    AMateria* createMateria( std::string const &type ) ;
};

#endif