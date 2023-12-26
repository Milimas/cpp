#ifndef PMERGE_ME_H
#define PMERGE_ME_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <deque>
#include <vector>
#include <unistd.h>
#include <ctime>
#include <string>
#include <cerrno>
#include <climits>
#include <typeinfo>

// Error type
#define EXCEPT              true                                // Throw exception 
#define NO_EXCEPT           false                               // Don't throw exception
#define ERR_EXIT            -1                                  // Exit with failure

// Error message
#define USAGE               "Usage: PmergeMe <set of positive numbers>."
#define BAD_INPUT           "❌ Bad input ."

class PmergeMe
{
public:
    typedef std::vector<int> Vector ;
    typedef std::deque<int> Deque ;

    template<typename T>
    static clock_t sort( T& container ) ;
    template<typename T>
    static void fill( T& container, char **argv, size_t size ) ;
    
    template<typename T>
    static void printTime ( T& container, clock_t time ) ;
    static void printElem( const int& elem ) ;

private:
    static const size_t k = 5;

    static void error( const std::string& error, const std::string& msg, const int isExcept = EXCEPT ) ;
    static int strToInt(const std::string& s, char *end = NULL, int base = 10) ;
    static std::string getType( const Vector& container ) ;
    static std::string getType( const Deque& container ) ;
    
    template<typename T>
    static void _sort ( T& container ) ;

    template<typename T>
    static void insertionSort( T& container ) ;

    template<typename T>
    static void mergeSort( T& container, const T& right, const T& left ) ;

    PmergeMe( void ) ;
    PmergeMe( const PmergeMe& other ) ;
    PmergeMe& operator=( const PmergeMe& other ) ;
    ~PmergeMe( void ) ;
} ;

template<typename T>
clock_t PmergeMe::sort( T& container )
{
    std::clock_t start = clock() ;
    _sort(container) ;
    return (clock() - start) ;
}

template<typename T>
void PmergeMe::fill( T& container, char **argv, size_t size )
{
    size_t i = 0 ;
    while (i < size)
    {
        std::stringstream ss(argv[i++]) ;
        std::string num ;
        while (ss >> num)
        {
            container.push_back(strToInt(num, NULL)) ;
        }
    }
}

template<typename T>
void PmergeMe::_sort ( T& container )
{
    if ( container.size() > k )
    {
        int pvt = (container.size() / 2) + (container.size() % 2) ;
        T right(container.begin(), container.begin() + pvt) ;
        T left(container.begin() + pvt, container.end()) ;
        container.clear() ;
        _sort(right) ;
        _sort(left) ;
        mergeSort(container, right, left) ;
    }
    else if (container.size())
        insertionSort(container) ;
}

template<typename T>
void PmergeMe::insertionSort( T& container )
{
    for (typename T::iterator it = container.begin(); it < container.end() - 1; it++)
    {
        typename T::iterator j = it + 1 ;
        int tmp = *j ;
        while (j > container.begin() && j[-1] > tmp)
        {
            *j = j[-1] ;
            j-- ;
        }
        *j = tmp ;
    }  
}

template<typename T>
void PmergeMe::mergeSort( T& container, const T& right, const T& left )
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
        else if (right[rinx] > left[linx])
            container.push_back(left[linx++]) ;
        else
            container.push_back(right[rinx++]) ;
    }
}

template<typename T>
void PmergeMe::printTime ( T& container, clock_t time )
{
    std::cout << "Time to process a range of : " << container.size()
            << " elements with " << getType(container) << " : " << std::fixed << (time / (double)CLOCKS_PER_SEC) << " s" << std::endl ;

}

#endif