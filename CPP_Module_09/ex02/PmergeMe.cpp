#include "PmergeMe.hpp"

PmergeMe::Deque PmergeMe::_deq ;
PmergeMe::Vector PmergeMe::_vec ;

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

void PmergeMe::sortVector( char **argv, size_t size )
{
    std::cout << "size " << size << std::endl ;
    size_t i = 0 ;
    while (i < size)
    {
        _vec.push_back(strToInt(argv[i], NULL)) ;
        std::cout << _vec.back() << std::endl ;
        i++ ;
    }
}

int PmergeMe::strToInt(const std::string& s, char *end, int base)
{
    int res = 0;
    long  l;
    errno = 0;
    l = strtol(s.c_str(), &end, base);
    if ((errno == ERANGE && l == LONG_MAX) || l > INT_MAX)
        error(BAD_INPUT, "OVERFLOW => " + s, EXCEPT) ;
    if ((errno == ERANGE && l == LONG_MIN) || l < INT_MIN)
        error(BAD_INPUT, "UNDERFLOW => " + s, EXCEPT) ;
    if (*s.c_str() == '\0' || *end != '\0')
        error(BAD_INPUT, "INCONVERTIBLE => " + s, EXCEPT) ;
    res = l;
    if (res < 0)
        error(BAD_INPUT, "NEGATIVE => " + s, EXCEPT) ;
    return (res);
}

void PmergeMe::sortDeque( char **argv, size_t size )
{
    (void)argv ;
    (void)size ;
}
