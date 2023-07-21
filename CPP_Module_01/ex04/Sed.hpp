#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
private:
    std::string     fileName ;
    std::string     string ;
    std::string     replace ;
    std::string     line ;
    
    std::ifstream   file ;
    std::ofstream   fileReplace ;
    void replaceAll( std::string &line ) ;
    
public:
    class OpenFileException: public std::exception
    {
    private:
        std::string fileName ;
    public:
        OpenFileException( std::string fileName ) throw(): fileName(fileName) {} ;
        virtual ~OpenFileException( void ) throw() {} ;
        const char* what( void ) const throw() 
        {
            return (("Sed: " + fileName + ": Failed to open file").c_str()) ;
        }
    } ;
    class CreateFileException: public std::exception
    {
    private:
        std::string fileName ;
    public:
        CreateFileException( std::string fileName ) throw(): fileName(fileName) {} ;
        virtual ~CreateFileException( void ) throw() {} ;
        const char* what( void ) const throw()
        {
            return (("Sed: " + fileName + ": Failed to create file").c_str()) ;
        }
    } ;
    Sed( const std::string &fileName, const std::string &string, const std::string &replace ) ;
    ~Sed( void ) ;
    
    static int  usage( const std::string programName ) ;
};

#endif