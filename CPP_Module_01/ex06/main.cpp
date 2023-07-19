#include "Harl.hpp"

enum code
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
};

int    usage( std::string name )
{
    std::cout << "usage: " + name + " <level>" << std::endl;
    return (EXIT_FAILURE);
}

int main( int argc, char **argv )
{
    std::string lvls[4] = {"DEBUG","INFO","WARNING","ERROR"};
    int i;

    if (argc != 2)
        return (usage(argv[0]));
    for (i = 0; i < 4; i++)
    {
        if (lvls[i] == argv[1])
            break ;
    }
    Harl harl;
    switch (i)
    {
        case DEBUG :
            harl.complain("DEBUG") ;
        case INFO :
            harl.complain("INFO") ;
        case WARNING :
            harl.complain("WARNING") ;
        case ERROR :
            harl.complain("ERROR") ;
            break ;
        default :
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl ;
            break ;
    }
    
    return 0 ;
}