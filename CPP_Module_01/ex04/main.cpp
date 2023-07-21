#include "Sed.hpp"

int main( int argc, char **argv )
{
    std::string filename ;
    std::string string1 ;
    std::string string2 ;

    if (argc != 4)
        return (Sed::usage(argv[0])) ;

    filename = argv[1] ;
    string1 = argv[2] ;
    string2 = argv[3] ;

    Sed sed(filename, string1, string2) ;

    return 0 ;
}