#include "BitcoinExchange.hpp"

#include <set>
int main( int argc, char **argv )
{
    if (argc != 2)
    {
        std::cout << USAGE << std::endl ;
        return (2) ;
    }

    BitcoinExchange::setData("data.csv") ;
    BitcoinExchange::exchange(argv[1]) ;

    return (EXIT_SUCCESS) ;
}