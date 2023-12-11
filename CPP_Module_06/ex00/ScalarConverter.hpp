#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <sstream>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
private:
    enum            Type {tNan, tPseudo, tChar, tInt, tFloat, tDouble} ;
    static Type     type ;
    static char     _char ;
    static int      _int ;
    static float    _float ;
    static double   _double ;

    ScalarConverter( void ) ;
    ScalarConverter( const std::string input ) ;
	ScalarConverter( const ScalarConverter& other ) ;
	ScalarConverter& operator=( const ScalarConverter& other ) ;
	~ScalarConverter( void ) ;

    static Type getType( std::string input ) ;
    
    static bool isPseudo( std::string input ) ;
    static bool isPseudoF( std::string input ) ;
    static bool isChar( std::string input ) ;
    static bool isInt( double num, std::string input ) ;
    static bool isFloat( double num, std::string input ) ;
    static bool isDouble( double num, std::string input ) ;

    static double fromPseudo( std::string input ) ;
    static float fromPseudoF( std::string input ) ;
    static void fromChar( std::string input ) ;
    static void fromInt( std::string input ) ;
    static void fromFloat( std::string input ) ;
    static void fromDouble( std::string input ) ;

    static void print( void ) ;
public:
    static void    convert( const std::string str ) ;
};


#endif
