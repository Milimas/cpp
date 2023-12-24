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
    while ( dataFile.good() )
    {
        try
        {
            std::getline(dataFile, value) ; 
            if ( value.find(delimiter) == std::string::npos)
                error(BAD_DATE_FORMAT, "value => " + value) ;
            else
            {
                key = value.substr(0, value.find(delimiter)) ;
                value.erase(0, value.find(delimiter) + delimiter.length()) ;
                if (key.find("date") != std::string::npos && value.find("exchange_rate") != std::string::npos)
                    continue ;
                BitcoinExchange::insert(key, value) ;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    dataFile.close() ;
}

static std::string trim( const std::string& str )
{
    std::stringstream ss(str) ;
    std::string tmp ;
    ss >> tmp ;
    return (tmp) ;
}

void BitcoinExchange::exchange( const std::string& dataPath )
{
    std::ifstream dataFile ;
    std::string delimiter("|") ;

    dataFile.open(dataPath.c_str()) ;
    if (!dataFile)
        error(FILE_NOT_OPEN, dataPath, EXIT) ;
    if (dataFile.peek() == std::ifstream::traits_type::eof())
        error(FILE_IS_EMPTY, dataPath, EXIT) ;
    while ( dataFile.good() )
    {
        try
        {
            std::string value ;
            std::string key ;
            std::getline(dataFile >> std::ws, value) ;
            if (value.empty())
                continue ;
            if ( value.find(delimiter) == std::string::npos)
                error(BAD_INPUT_FORMAT, value) ;
            else
            {
                key = trim(value.substr(0, value.find(delimiter))) ;
                value.erase(0, value.find(delimiter) + delimiter.length()) ;
                if (key.find("date") != std::string::npos && value.find("value") != std::string::npos)
                    continue ;
                BitcoinExchange::checkInput(key, value) ;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    dataFile.close() ;
}

static std::string dateToString( const std::tm& tm )
{
    std::stringstream ss;
    ss << tm.tm_year + 1900 << "-" << std::setw(2) << std::setfill('0') << tm.tm_mon + 1 << "-" << std::setw(2) << std::setfill('0') << tm.tm_mday ;
    return (ss.str()) ;
}

static void print(BitcoinExchange::Pair& pair)
{
    std::cout << dateToString(pair.first) << "," << pair.second << std::endl ;
    (void) pair ;
}

void BitcoinExchange::printData( void )
{
    std::for_each(data.begin(), data.end(), print) ;
}

void BitcoinExchange::error( const std::string& error, const std::string& msg, const int isExcept )
{
    std::string _msg = "Error: " + error + " " ;
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
    struct tm tm;
    if (!strptime(key.c_str(), "%Y-%m-%d", &tm) || key.length() != 10)
        error(BAD_DATE_FORMAT, " => " + key) ;
    else
        ss >> data[tm] ;
}

static std::string dateToString( std::tm *tm )
{
    char buff[100] ;
    strftime(buff, 100, "%Y-%m-%d", tm) ;
    std::string dateStr(buff) ;
    return (dateStr) ;
}

static bool isValidDade( std::string date )
{
    std::tm tm ;
    memset(&tm, 0, sizeof(std::tm)) ;
    tm.tm_isdst = -1;
    if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
        return (false) ;
    time_t t = time(0) ;
    t = mktime(&tm) ;
    if (t == (time_t)-1)
        return (false) ;
    if (dateToString(localtime(&t)) != date || date.length() != 10)
        return (false) ;
    return (true) ;
}

void BitcoinExchange::checkInput( const std::string& key, const std::string& value )
{
    struct tm tm;
    try
    {
        double price = convertInputPrice(value) ;
        if (!isValidDade(key))
        {
            error(BAD_DATE_FORMAT, " => " + key) ;
            return ;
        }
        strptime(key.c_str(), "%Y-%m-%d", &tm) ;
        Data::iterator it = --data.upper_bound(tm) ;
        std::cout << dateToString(tm) << " => " << price << " = " << it->second * price << std::endl ;
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
