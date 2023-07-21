#include "Sed.hpp"

Sed::Sed( const std::string &fileName, const std::string &string, const std::string &replace ):
    fileName(fileName), string(string), replace(replace)
{

    try
    {
        file.open(fileName) ;
        if (!file.is_open())
            throw OpenFileException(fileName) ;
        fileReplace.open(fileName + ".replace") ;
        if (!fileReplace.is_open())
            throw CreateFileException(fileName + ".replace") ;
        while ( getline(file, line) )
        {
            replaceAll(line) ;
            fileReplace << line ;
            if (!file.eof())
                fileReplace << std::endl ;
        }
    }
    catch ( std::exception& e )
    {
        std::cout << e.what() << std::endl ;
    }
}

Sed::~Sed( void )
{
    this->file.close() ;
    this->fileReplace.close() ;
}

void Sed::replaceAll( std::string &line )
{
    if (string.empty())
        return ;
    for (size_t pos = 0 ; ; pos += replace.length())
    {
        pos = line.find(string, pos) ;
        if (pos == std::string::npos)
            break ;
        line.erase(pos, string.length()) ;
        line.insert(pos, replace) ;
    }
}


int Sed::usage( const std::string programName )
{
    std::cout << "usage: " + programName + " <filename> <string1> <string2>" << std::endl;
    return (EXIT_FAILURE);
}