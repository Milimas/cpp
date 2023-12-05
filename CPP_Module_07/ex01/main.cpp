#include "iter.hpp"

int main( void )
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} ;
    double _double[] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9} ;
    std::string str = "Hello" ;

    ::iter(array, 10, ::print) ;
    std::cout << std::endl ;
    ::iter(str.c_str(), str.length(), ::print) ;
    std::cout << std::endl ;
    ::iter(_double, 10, ::print) ;
    std::cout << std::endl ;

    return (0) ;    
}