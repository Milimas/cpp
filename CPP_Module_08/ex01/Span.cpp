#include "Span.hpp"

Span::Span( void ) : _maxSize(0)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

Span::Span( unsigned int _maxSize ) : _maxSize(_maxSize)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    _vector.reserve(_maxSize) ;
}

Span::Span( const Span& other ) : _maxSize(other._maxSize), _vector(other._vector)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

Span& Span::operator=( const Span& other )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    _maxSize = other._maxSize ;
    _vector = other._vector ;
    return (*this) ;
}

Span::~Span( void )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    _vector.clear() ;
}

void Span::addNumber( const int num )
{
    if (_vector.size() >= _maxSize)
        throw Span::ArrayIsFullException() ;
    _vector.push_back(num) ;
}

static void printNum( int& num )
{
    std::cout << num << " " ;
}

int Span::longestSpan( void )
{
    if (_vector.size() < 2)
        throw Span::NoSpanException("longestSpan") ;
    int max = *(std::max_element(_vector.begin(), _vector.end())) ;
    int min = *(std::min_element(_vector.begin(), _vector.end())) ;
    return (abs(max - min)) ;
}

int Span::shortestSpan( void )
{
    if (_vector.size() < 2)
        throw Span::NoSpanException("shortestSpan") ;
    
    std::vector<int> ad = _vector ;
    std::sort(ad.begin(), ad.end()) ;
    std::adjacent_difference(ad.begin(), ad.end(), ad.begin()) ;
    ad.erase(ad.begin()) ;
    return (*std::min_element(ad.begin(), ad.end())) ;
}

void Span::fill( void )
{
    std::srand(time(NULL)) ;
    _vector.resize(_maxSize) ;
    std::generate_n(_vector.begin(), _maxSize, std::rand) ;
}

void Span::print( void )
{
    std::for_each(_vector.begin(), _vector.end(), printNum) ;
    std::cout << std::endl ;
}
