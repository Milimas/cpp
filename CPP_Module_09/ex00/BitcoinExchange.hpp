#ifndef BITCOIN_EXCHANGE_H
#define BITCOIN_EXCHANGE_H

// map
#include <map>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

// Error message
#define USAGE               "Usage: btc <input file>."
#define FILE_NOT_OPEN       "Could not open file."
#define FILE_IS_EMPTY       "Input file is empty."
#define BAD_DATE_FORMAT     "Bad date format."
#define BAD_DATE            "Bad date."
#define DATE_DONT_EXIST     "Date does't exist."
#define BAD_INPUT           "Bad input."
#define BAD_INPUT_FORMAT    "Bad input format."
#define NOT_POSITIVE        "Not a positive number."
#define TOO_LARGE           "Too large a number."

// Error type
#define EXCEPT              true                                // Throw exception 
#define NO_EXCEPT           false                               // Don't throw exception
#define ERR_EXIT            -1                                  // Exit with failure


class BitcoinExchange
{
public:
    typedef std::map<const std::tm, double> Data ;
    typedef std::pair<const std::tm, double> Pair ;

    static void exchange( const std::string& inputPath ) ;
    static void setData( const std::string& dataPath ) ;

private:
    static Data data ;
    BitcoinExchange( void ) ;
    BitcoinExchange( const BitcoinExchange& other ) ;
    BitcoinExchange& operator=( const BitcoinExchange& other ) ;
    ~BitcoinExchange( void ) ;

    static void error( const std::string& error, const std::string& msg, const int isExcept = EXCEPT ) ;

    static void insert( const std::string& key, const std::string& value ) ;
    static double convertInputPrice( const std::string& value ) ;
    static std::string dateToString( std::tm *tm ) ;
    static void checkInput( const std::string& key, const std::string& value ) ;
    static void isValidDade( const std::string& date ) ;

    static std::string trim( const std::string& str ) ;
} ;

bool operator < (const std::tm & t1, const std::tm & t2) ;

#endif