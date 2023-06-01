#include <iostream>
#include <fstream>

int    usage(void)
{
    std::cout << "usage: sed <filename> <string1> <string2>" << std::endl;
    return (EXIT_FAILURE);
}

void    replaceAll(std::string &line, std::string &str, std::string &replace)
{
    for (size_t pos = 0; ; pos += replace.length())
    {
        pos = line.find(str, pos) ;
        if (pos == std::string::npos)
            break ;
        line.erase(pos, str.length()) ;
        line.insert(pos, replace) ;
    }
}

int main(int argc, char **argv)
{
    std::string filename ;
    std::string string1 ;
    std::string string2 ;
    std::ifstream file ;
    std::ofstream filereplace ;
    std::string line ;

    if (argc != 4)
        return (usage()) ;
    filename = argv[1] ;
    string1 = argv[2] ;
    string2 = argv[3] ;
    file.open(filename) ; 
    if (file.is_open())
    {
        filereplace.open(filename + ".replace") ;
        if ( !filereplace.is_open() )
            return 1 ;
        while ( getline(file, line) )
        {
            replaceAll(line, string1, string2) ;
            filereplace << line << std::endl ;
        }
        file.close() ;
        filereplace.close() ;
    }
    else
        std::cout << "Couldn't open file " << filename << std::endl ;
    return 0 ;
}