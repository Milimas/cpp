#include "PmergeMe.hpp"


PmergeMe::PmergeMe( void ) 
{

}

PmergeMe::PmergeMe( const PmergeMe& other ) 
{
    (void)other ;
}

PmergeMe& PmergeMe::operator=( const PmergeMe& other ) 
{
    (void)other ;
    return (*this) ;
}

PmergeMe::~PmergeMe( void ) 
{

}

void PmergeMe::error( const std::string& _error, const std::string& msg, const int isExcept )
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


void PmergeMe::printElem( const int& elem )
{
    std::cout << elem << " " ;
}

int PmergeMe::strToInt(const std::string& s, char *end, int base)
{
    int res = 0;
    long  l;
    errno = 0;
    l = strtol(s.c_str(), &end, base);
    if ((errno == ERANGE && l == LONG_MAX) || l > INT_MAX)
        error(BAD_INPUT, "OVERFLOW => " + s, ERR_EXIT) ;
    if ((errno == ERANGE && l == LONG_MIN) || l < INT_MIN)
        error(BAD_INPUT, "UNDERFLOW => " + s, ERR_EXIT) ;
    if (*s.c_str() == '\0' || *end != '\0')
        error(BAD_INPUT, "INCONVERTIBLE => " + s, ERR_EXIT) ;
    res = l;
    if (res < 0)
        error(BAD_INPUT, "NEGATIVE => " + s, ERR_EXIT) ;
    return (res);
}

std::string PmergeMe::getType( const Vector& container )
{
    (void)container ;
    return ("std::vector<int>") ;
}

std::string PmergeMe::getType( const Deque& container )
{
    (void)container ;
    return ("std::deque<int>") ;
}