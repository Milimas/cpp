#include "Harl.hpp"

enum code
{
    NONE,
    DEBUG,
    INFO,
    WARNING,
    ERROR,
};

int main(int argc, char **argv)
{
    Harl h;
    std::map<std::string, code> level;
    level["DEBUG"] = DEBUG;
    level["INFO"]= INFO;
    level["WARNING"]= WARNING;
    level["ERROR"]= ERROR;

    if (argc != 2)
        return (1);
    switch (level[argv[1]])
    {
        case NONE :
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl ;
            break ;
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