#ifndef R_P_N_H
#define R_P_N_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <stack>

// Error type
#define EXCEPT              true                                // Throw exception 
#define NO_EXCEPT           false                               // Don't throw exception
#define ERR_EXIT                -1                                  // Exit with failure

// Error message
#define USAGE               "Usage: RPN <number number operator [...]>."
#define BAD_INPUT           "Bad input."
#define MISSING_OPERATOR    "Missing operator."
#define MISSING_NUMBER      "Missing number."
#define DIVISION_ZERO       "Attempting Division by Zero."

class RPN
{
public:
    typedef std::stack<int> Numbers ;
    typedef std::stack<char> Operations ;
    static void calculate( const std::string& input ) ;
private:
    RPN( void ) ;
    RPN( const RPN& other ) ;
    RPN& operator=( const RPN& other ) ;
    ~RPN( void ) ;
    
    static Numbers numbers ;
    static Operations operations ;
    static void error( const std::string& error, const std::string& msg, const int isExcept = EXCEPT ) ;

    // operations

    static void add( void ) ;
    static void sub( void ) ;
    static void mul( void ) ;
    static void div( void ) ;

    // helper
    
    static bool isOperator( const std::string& input ) ;
} ; 

#endif