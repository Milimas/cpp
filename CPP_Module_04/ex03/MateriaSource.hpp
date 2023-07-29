#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

/*
* Write the concrete class MateriaSource which will implement the following interface IMateriaSource
* In a nutshell, your MateriaSource must be able to learn "templates" of Materias to create them when needed.
* Then, you will be able to generate a new Materia using just a string that identifies its type.
*/
class MateriaSource : public IMateriaSource
{
private:
    AMateria *inventory[4] ;
public:
    MateriaSource( void ) ;
    MateriaSource( const MateriaSource& rhs ) ;
    MateriaSource& operator=( const MateriaSource& rhs ) ;
    ~MateriaSource( void ) ;

    void learnMateria( AMateria* materia ) ;
    AMateria* createMateria( std::string const &type ) ;
};

#endif