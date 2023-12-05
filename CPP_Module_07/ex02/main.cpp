#include "Array.hpp"

int main( void )
{
    Array<int> _array(150) ;
    int *_int = new int[150] ;
    
    srand(time(NULL)) ;
    for (size_t i = 0; i < 150; i++)
    {
        int value = rand() ;
        _array[i] = value ;
        _int[i] = value ;
    }
    
    for (size_t i = 0; i < 150; i++)
    {
        if (_array[i] != _int[i])
        {
            std::cerr << "Not Equal" << std::endl ;
            return (0) ;
        }
    }
    std::cout << "Success: arrays are equal" << std::endl ;
    std::cout << "Array size is :" << _array.size() << std::endl ;

    std::cout << "Copy Constructor: " << std::endl ; 
    Array<int> _copy(_array) ;
    std::cout << "Copy Assignment: " << std::endl ; 
    Array<int> _assign = _copy ;

    try
    {
        _copy[160] = 10 ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        _assign[-1] = 1337 ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << _array << std::endl ;

    delete [] _int ;
    return (0) ;
}