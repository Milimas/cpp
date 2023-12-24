#include "BitcoinExchange.hpp"

BitcoinExchange::Data BitcoinExchange::data ;

BitcoinExchange::BitcoinExchange( void ) 
{
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) 
{
    (void)other ;
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& other ) 
{
    (void)other ;
    return (*this) ;
}

BitcoinExchange::~BitcoinExchange( void ) 
{
}

void BitcoinExchange::setData( const std::string& dataPath )
{
    std::ifstream dataFile ;
    std::string key ;
    std::string value ;
    std::string delimiter(",") ;

    dataFile.open(dataPath.c_str()) ;
    if (!dataFile)
        error(FILE_NOT_OPEN, dataPath, EXIT) ;
    if (dataFile.peek() == std::ifstream::traits_type::eof())
        error(FILE_IS_EMPTY, dataPath, EXIT) ;
    while ( dataFile.good() )
    {
        std::getline(dataFile, value) ; 
        if ( value.find(delimiter) == std::string::npos)
            error(BAD_DATE_FORMAT, "value => " + value, NO_EXCEPT) ;
        else
        {
            key = value.substr(0, value.find(delimiter)) ;
            value.erase(0, value.find(delimiter) + delimiter.length()) ;
            if (key.find("date") != std::string::npos && value.find("exchange_rate") != std::string::npos)
                continue ;
            BitcoinExchange::insert(key, value) ;
        }
    }
    dataFile.close() ;
}

std::string BitcoinExchange::trim( const std::string& str )
{
    std::stringstream ss(str) ;
    std::string tmp ;
    ss >> tmp ;
    return (tmp) ;
}

void BitcoinExchange::exchange( const std::string& inputPath )
{
    std::ifstream inputFile ;
    std::string delimiter("|") ;

    inputFile.open(inputPath.c_str()) ;
    if (!inputFile)
        error(FILE_NOT_OPEN, inputPath, EXIT) ;
    if (inputFile.peek() == std::ifstream::traits_type::eof())
        error(FILE_IS_EMPTY, inputPath, EXIT) ;
    while ( inputFile.good() )
    {
        std::string value ;
        std::string key ;
        std::getline(inputFile >> std::ws, value) ;
        if (value.empty())
            continue ;
        if ( value.find(delimiter) == std::string::npos)
            error(BAD_INPUT_FORMAT, value, NO_EXCEPT) ;
        else
        {
            key = BitcoinExchange::trim(value.substr(0, value.find(delimiter))) ;
            value.erase(0, value.find(delimiter) + delimiter.length()) ;
            if (key.find("date") != std::string::npos && value.find("value") != std::string::npos)
                continue ;
            BitcoinExchange::checkInput(key, value) ;
        }
    }
    inputFile.close() ;
}

void BitcoinExchange::error( const std::string& _error, const std::string& msg, const int isExcept )
{
    std::string _msg = "Error: " + _error + " " ;
    if (!msg.empty())
        _msg += "\"" + msg + "\"" ;
    if (isExcept == true)
        throw std::runtime_error(_msg) ;
    else
        std::cerr << _msg << std::endl ;
    if (isExcept == -1)
        exit(EXIT_FAILURE) ;
}

double BitcoinExchange::convertInputPrice( const std::string& value )
{
    std::stringstream ss(value) ;
    double rate ;
    ss >> rate ;
    if (!ss.eof() && ss.fail())
        error(BAD_INPUT, value) ;
    if (rate < 0)
        error(NOT_POSITIVE, "") ;
    if (rate > 1000)
        error(TOO_LARGE, "") ;
    return (rate) ;
}

void BitcoinExchange::insert( const std::string& key, const std::string& value )
{
    std::stringstream ss(value) ;
    std::tm tm;
    memset(&tm, 0, sizeof(std::tm)) ;
    tm.tm_isdst = -1;
    if (!strptime(key.c_str(), "%F", &tm) || key.length() != 10)
        error(BAD_DATE_FORMAT, " => " + key) ;
    else
        ss >> data[tm] ;
}

std::string BitcoinExchange::dateToString( std::tm *tm )
{
    char buff[100] ;
    strftime(buff, 100, "%F", tm) ;
    std::string dateStr(buff) ;
    return (dateStr) ;
}

void BitcoinExchange::isValidDade( const std::string& date )
{
    std::tm tm ;
    memset(&tm, 0, sizeof(std::tm)) ;
    tm.tm_isdst = -1;
    if (strptime(date.c_str(), "%F", &tm) == NULL)
        error(BAD_DATE_FORMAT, " => " + date) ;
    time_t t = mktime(&tm) ;
    if (t == (time_t)-1)
        error(BAD_DATE, " => " + date) ;
    if (dateToString(localtime(&t)) != date || date.length() != 10)
        error(DATE_DONT_EXIST, " => " + date) ;
}

void BitcoinExchange::checkInput( const std::string& key, const std::string& value )
{
    std::tm tm;
    memset(&tm, 0, sizeof(std::tm)) ;
    tm.tm_isdst = - 1 ;
    try
    {
        double price = convertInputPrice(value) ;
        isValidDade(key) ;
        strptime(key.c_str(), "%F", &tm) ;
        Data::iterator it = --data.upper_bound(tm) ;
        std::cout << dateToString(&tm) << " => " << price << " = " << it->second * price << std::endl ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool operator < (const std::tm& t1, const std::tm& t2)
{
    if (t1.tm_year != t2.tm_year)
        return (t1.tm_year < t2.tm_year) ;
    if (t1.tm_mon != t2.tm_mon)
        return (t1.tm_mon < t2.tm_mon) ;
    if (t1.tm_mday != t2.tm_mday)
        return (t1.tm_mday < t2.tm_mday) ;
    return (false) ;
};
