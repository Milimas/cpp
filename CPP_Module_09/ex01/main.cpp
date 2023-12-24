#include "RPN.hpp"

int main( int argc, char **argv )
{
    if (argc != 2)
    {
        std::cout << USAGE << std::endl ;
        return (2) ;
    }
    RPN::calculate(argv[1]) ;
    
    return (EXIT_SUCCESS) ;
}