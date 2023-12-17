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

bool    ScalarConverter::isPseudo( std::string input )
{
    if (input == "-inf" || input == "+inf" || input == "nan")
        return (1) ;
    return (0) ;
}

bool    ScalarConverter::isPseudoF( std::string input )
{
    if (input == "-inff" || input == "+inff" || input == "nanf")
        return (1) ;
    return (0) ;
}

bool    ScalarConverter::isChar( std::string input )
{
    if (input.length() != 1 || !std::isprint(*input.c_str()) || std::isdigit(*input.c_str()))
        return (0) ;
    return (1) ;
}

bool    ScalarConverter::isInt( double num, std::string input )
{
    if (input.find('.') != std::string::npos || std::abs(num) > std::numeric_limits<int>::max())
        return (0) ;
    return (1) ;
}

bool    ScalarConverter::isFloat( double num, std::string input )
{
    if (input.find('.') == std::string::npos || input.find('f', input.length() - 1) == std::string::npos)
        return (0) ;
    if (input.find('f', input.find('f') + 1) != std::string::npos)
        return (0) ;
    if (std::abs(num) > std::numeric_limits<float>::max())
        return (0) ;
    return (1) ;
}

bool    ScalarConverter::isDouble( double num, std::string input )
{
    if (input.find('f') != std::string::npos)
        return (0) ;
    if (std::abs(num) > std::numeric_limits<double>::max())
        return (0) ;
    return (1) ;
}

ScalarConverter::Type     ScalarConverter::getType( std::string input )
{
    if (isPseudo(input))
        return (ScalarConverter::tDouble) ;
    if (isPseudoF(input))
        return (ScalarConverter::tFloat) ;
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

double ScalarConverter::fromPseudo( std::string input )
{
    if (input == "+inf" || input == "+inff")
        return (std::numeric_limits<double>::infinity()) ;
    if (input == "-inf" || input == "-inff")
        return (-std::numeric_limits<double>::infinity()) ;
    return (std::numeric_limits<double>::quiet_NaN()) ;
}

float ScalarConverter::fromPseudoF( std::string input )
{
    if (input == "+inf" || input == "+inff")
        return (std::numeric_limits<float>::infinity()) ;
    if (input == "-inf" || input == "-inff")
        return (-std::numeric_limits<float>::infinity()) ;
    return (std::numeric_limits<float>::quiet_NaN()) ;
}

void ScalarConverter::fromFloat( std::string input )
{
    _float = atof(input.c_str()) ;
    if (isPseudoF(input))
        _float = fromPseudoF(input) ;
    _char = static_cast<float>(_float) ;
    _int = static_cast<float>(_float) ;
    _double = static_cast<float>(_float) ;
}

void ScalarConverter::fromDouble( std::string input )
{
    _double = atof(input.c_str());
    if (isPseudo(input))
        _double = fromPseudo(input) ;
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
    std::ostringstream tmp ;
    tmp << "int: " << _int << std::endl ;
    tmp << "float: " << _float << "f" << std::endl ;
    tmp << "double: " << _double << std::endl ;
    std::cout << tmp.str() ;
}
