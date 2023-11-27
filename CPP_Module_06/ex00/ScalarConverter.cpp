#include "ScalarConverter.hpp"

ScalarConverter::Type ScalarConverter::type = ScalarConverter::tNan;
char ScalarConverter::_char = 0;
int ScalarConverter::_int = std::numeric_limits<int>::quiet_NaN();
float ScalarConverter::_float = std::numeric_limits<float>::quiet_NaN();
double ScalarConverter::_double = std::numeric_limits<double>::quiet_NaN();

ScalarConverter::ScalarConverter( void )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

ScalarConverter::ScalarConverter( const ScalarConverter& other )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    (void)other ;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    (void)other ;
    return (*this) ;
}

ScalarConverter::~ScalarConverter( void )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

bool    ScalarConverter::isChar( std::string input )
{
    if (input.length() != 1 || !std::isprint(*input.c_str()) || std::isdigit(*input.c_str()))
        return (0) ;
    return (1) ;
}

bool    ScalarConverter::isInt( double num, std::string input )
{
    if (input.find('.') != std::string::npos || num > INT_MAX || num < INT_MIN)
        return (0) ;
    return (1) ;
}

bool    ScalarConverter::isFloat( double num, std::string input )
{
    if (input.find('.') == std::string::npos || input.find('f', input.length() - 1) == std::string::npos)
        return (0) ;
    if (input.find('f', input.find('f') + 1) != std::string::npos)
        return (0) ;
    if (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min())
        return (0) ;
    return (1) ;
}

bool    ScalarConverter::isDouble( double num, std::string input )
{
    if (input.find('f') != std::string::npos)
        return (0) ;
    if (num > std::numeric_limits<double>::max() || num < std::numeric_limits<double>::min())
        return (0) ;
    return (1) ;
}

ScalarConverter::Type     ScalarConverter::getType( std::string input )
{
    double  tmp = std::strtod(input.c_str(), NULL) ;
    if (tmp == HUGE_VAL || tmp == -HUGE_VAL || input.empty())
        return (ScalarConverter::tNan) ;
    if (isChar(input))
        return (ScalarConverter::tChar) ;
    if (isInt(tmp, input))
        return (ScalarConverter::tInt) ;
    if (isFloat(tmp, input))
        return (ScalarConverter::tFloat) ;
    if (isDouble(tmp, input))
        return (ScalarConverter::tDouble) ;
    return (ScalarConverter::tNan) ;
}

void ScalarConverter::fromChar( std::string input )
{
    _char = input.c_str()[0];
    _int = static_cast<char>(_char);
    _float = static_cast<char>(_char);
    _double = static_cast<char>(_char);
}

void ScalarConverter::fromInt( std::string input )
{
    _int = atoi(input.c_str());
    _char = static_cast<int>(_int);
    _float = static_cast<int>(_int);
    _double = static_cast<int>(_int);
}

void ScalarConverter::fromFloat( std::string input )
{
    _float = atof(input.c_str());
    _char = static_cast<float>(_float);
    _int = static_cast<float>(_float);
    _double = static_cast<float>(_float);
}

void ScalarConverter::fromDouble( std::string input )
{
    _double = atof(input.c_str());
    _char = static_cast<double>(_double);
    _int = static_cast<double>(_double);
    _float = static_cast<double>(_double);
}

void    ScalarConverter::convert( const std::string input )
{
    switch (getType(input))
    {
    case tChar:
        fromChar(input) ;
        break;
    case tInt:
        fromInt(input) ;
        break;
    case tFloat:
        fromFloat(input) ;
        break;
    case tDouble:
        fromDouble(input) ;
        break;
    default:
        break;
    }
    print() ;
}

void    ScalarConverter::print( void )
{
    if (std::isprint(_char))
        std::cout << "char: " << _char << std::endl ;
    else
        std::cout << "char: Non displayable" << std::endl ;
    std::cout << "int: " << _int << std::endl ;
    std::cout << "float: " << _float << std::endl ;
    std::cout << "double: " << _double << std::endl ;
}
