#include "Harl.hpp"

enum code
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
};

int main(int argc, char **argv)
{
    Harl h;
    std::string lvls[4] = {"DEBUG","INFO","WARNING","ERROR"};
    int i;

    if (argc != 2)
        return (1);
    for (i = 0; i < 4; i++)
    {
        if (lvls[i] == argv[1])
            break ;
    }
    switch (i)
    {
        case DEBUG :
            h.complain("DEBUG") ;
        case INFO :
            h.complain("INFO") ;
        case WARNING :
            h.complain("WARNING") ;
        case ERROR :
            h.complain("ERROR") ;
            break ;
        default :
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl ;
            break ;
    }
    
    return 0 ;
}