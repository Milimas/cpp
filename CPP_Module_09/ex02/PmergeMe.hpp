#ifndef PMERGE_ME_H
#define PMERGE_ME_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <deque>
#include <vector>
#include <ctime>
#include <string>
#include <cerrno>
#include <climits>

// Error type
#define EXCEPT              true                                // Throw exception 
#define NO_EXCEPT           false                               // Don't throw exception
#define ERR_EXIT            -1                                  // Exit with failure

// Error message
#define USAGE               "Usage: PmergeMe <set of positive numbers>."
#define BAD_INPUT           "❌ Bad input ."

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
class PmergeMe
{
public:
    static C<std::pair<T,T> > p ;
    static std::clock_t start ;

    static clock_t sort( C<T>& container ) ;
    static void fill( char **argv, size_t size ) ;

    static void printTime ( C<T>& container, clock_t time ) ;
    static void printElem( const T& elem ) ;

private:
    static void error( const std::string& _error, const std::string& msg, const int isExcept = EXCEPT ) ;

    static int strToInt(const std::string& s, char *end = NULL, int base = 10) ;

    static void _sort ( C<std::pair<int,int> >& pair ) ;
    static void mergeSort( C<std::pair<int,int> >& container, const C<std::pair<int,int> >& right, const C<std::pair<int,int> >& left ) ;
    static void insertionSort( C<T>& container,  C<std::pair<T,T> >& pairs ) ;

    static std::string getType( const std::vector<T>& container ) ;
    static std::string getType( const std::deque<T>& container ) ;

    PmergeMe( void ) ;
    PmergeMe( const PmergeMe& other ) ;
    PmergeMe& operator=( const PmergeMe& other ) ;
    ~PmergeMe( void ) ;
} ;

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
C<std::pair<T,T> > PmergeMe<T, C>::p ;

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
clock_t  PmergeMe<T, C>::start = clock() ;

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
clock_t PmergeMe<T, C>::sort( C<T>& container )
{
    _sort(p) ;
    insertionSort(container, p) ;
    return (clock() - start) ;
}

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
void PmergeMe<T, C>::fill( char **argv, size_t size )
{
    start = clock() ;
    size_t i = 0 ;
    std::stringstream ss ;
    while (i < size)
    {
        ss << argv[i++] << " " ; 
    }
    std::string num1 = "" ;
    std::string num2 = "" ;
    while (ss >> num1 >> num2)
    {
        int n1 = strToInt(num1) ;
        int n2 = strToInt(num2) ;
        if (n1 < n2)
            std::swap(n1, n2) ;
        PmergeMe::p.push_back(std::make_pair(n1, n2)) ;
        num1 = "" ;
        num2 = "" ;
    }
    if (!num1.empty())
        PmergeMe::p.push_back(std::make_pair(-1, strToInt(num1))) ;
}

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
void PmergeMe<T, C>::printTime( C<T>& container, clock_t time )
{
    std::cout << "Time to process a range of : " << container.size()
        << " elements with " << getType(container) << " : " << std::fixed << (time / (double)CLOCKS_PER_SEC) << " s" << std::endl ;

}

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
void PmergeMe<T, C>::printElem( const T& elem )
{
    std::cout << " " << elem ;
}

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
void PmergeMe<T, C>::error( const std::string& _error, const std::string& msg, const int isExcept )
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

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
int PmergeMe<T, C>::strToInt( const std::string& s, char *end, int base )
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

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
std::string PmergeMe<T, C>::getType( const std::vector<T>& container )
{
    (void)container ;
    return ("std::vector<int>") ;
}

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
std::string PmergeMe<T, C>::getType( const std::deque<T>& container )
{
    (void)container ;
    return ("std::deque<int>") ;
}

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
void PmergeMe<T, C>::_sort ( C<std::pair<int,int> >& pair )
{
    if (pair.size() == 1)
        return ;
    int pvt = (pair.size() / 2) + (pair.size() % 2) ;
    C<std::pair<int,int> > right(pair.begin(), pair.begin() + pvt) ;
    C<std::pair<int,int> > left(pair.begin() + pvt, pair.end()) ;
    pair.clear() ;
    _sort(right) ;
    _sort(left) ;
    mergeSort(pair, right, left) ;
}

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
void PmergeMe<T, C>::insertionSort( C<T>& container,  C<std::pair<T,T> >& pairs ) 
{
    typename C<std::pair<T,T> >::iterator it = pairs.begin() ;
    container.push_back(it->second) ;
    if (it->first > 0)
        container.push_back(it->first) ;
    it++ ;
    for ( ; it < pairs.end(); it++)
    {
        if (it->first > 0)
            container.push_back(it->first) ;
        container.insert(std::lower_bound(container.begin(), container.end(), it->second), it->second) ;
    }  
}

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
void PmergeMe<T, C>::mergeSort( C<std::pair<int,int> >& container, const C<std::pair<int,int> >& right, const C<std::pair<int,int> >& left )
{
    int rinx = 0 ;
    int linx = 0 ;

    int rSize = right.size() ;
    int lSize = left.size() ;
    for (int i = 0 ; i < rSize + lSize ; i++)
    {
        if (rinx == rSize)
            container.push_back(left[linx++]) ;
        else if (linx == lSize)
            container.push_back(right[rinx++]) ;
        else if (right[rinx].first > left[linx].first && left[linx].first > 0)
            container.push_back(left[linx++]) ;
        else
            container.push_back(right[rinx++]) ;
    }
}

#endif