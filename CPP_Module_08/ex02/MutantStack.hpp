#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>

template<typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
private:
public:
    MutantStack( void ) ;
    MutantStack( const MutantStack& other ) ;
    MutantStack& operator=( const MutantStack& other ) ;
    ~MutantStack( void ) ;

    typedef typename C::iterator iterator;

    iterator begin() { return this->c.begin() ; }
    iterator end() { return this->c.end() ; }
};

template<typename T, typename C>
MutantStack<T, C>::MutantStack( void )
{
}

template<typename T, typename C>
MutantStack<T, C>::MutantStack( const MutantStack& other )
{
    *this = other ;
}

template<typename T, typename C>
MutantStack<T, C>& MutantStack<T, C>::operator=( const MutantStack<T, C>& other )
{
    std::stack<T, C>::operator=(other) ;
    return (*this) ;
}

template<typename T, typename C>
MutantStack<T, C>::~MutantStack( void )
{
}

#endif
