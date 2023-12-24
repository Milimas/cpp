#include "RPN.hpp"

RPN::Operations RPN::operations ;
RPN::Numbers RPN::numbers ;

RPN::RPN( void ) 
{

}

RPN::RPN( const RPN& other ) 
{
    (void)other ;
}

RPN& RPN::operator=( const RPN& other ) 
{
    (void)other ;
    return (*this) ;
}

RPN::~RPN( void ) 
{

}

void RPN::error( const std::string& _error, const std::string& msg, const int isExcept )
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

bool RPN::isOperator( const std::string& input )
{
    if (std::string("+-/*").find(input[0]) != std::string::npos)
        return (true) ;
    return (false) ;
}

void RPN::add( void )
{
    operations.pop() ;
    int b = numbers.top() ;
    numbers.pop() ;
    int a = numbers.top() ;
    numbers.pop() ;

    numbers.push(a + b) ;
}

void RPN::sub( void )
{
    operations.pop() ;
    int b = numbers.top() ;
    numbers.pop() ;
    int a = numbers.top() ;
    numbers.pop() ;

    numbers.push(a - b) ;
}

void RPN::mul( void )
{
    operations.pop() ;
    int b = numbers.top() ;
    numbers.pop() ;
    int a = numbers.top() ;
    numbers.pop() ;

    numbers.push(a * b) ;
}

void RPN::div( void )
{
    operations.pop() ;
    int b = numbers.top() ;
    numbers.pop() ;
    int a = numbers.top() ;
    numbers.pop() ;

    if (!b)
        error(DIVISION_ZERO, "", ERR_EXIT) ;
    numbers.push(a / b) ;
}

void RPN::calculate( const std::string& input )
{
    std::stringstream ss(input) ;
    std::string elem ;
    while (ss.good())
    {
        ss >> elem >> std::ws ;
        if (elem.length() != 1)
            error(BAD_INPUT, elem, ERR_EXIT) ;
        if (isOperator(elem))
        {
            if (numbers.size() < 2)
                error(MISSING_NUMBER, "", ERR_EXIT) ;
            if (elem[0] == '+')
                add() ;
            else if (elem[0] == '-')
                sub() ;
            else if (elem[0] == '*')
                mul() ;
            else if (elem[0] == '/')
                div() ;
        }
        else
        {
            if (!isdigit(elem[0]))
                error(BAD_INPUT, elem, ERR_EXIT) ;
            numbers.push(std::atoi(elem.c_str())) ;
        }
    }
    if (numbers.size() == 1)
        std::cout << numbers.top() << std::endl ;
    else
        error(MISSING_OPERATOR, "", ERR_EXIT) ;
}