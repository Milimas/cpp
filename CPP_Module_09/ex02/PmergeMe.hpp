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
#define BAD_INPUT           "Bad input."

class PmergeMe
{
public:
    typedef std::vector<int> Vector ;
    typedef std::deque<int> Deque ;

    template<typename T>
    static void sort( T& conatiner ) ;

    template<typename T>
    static void fill( T& container, char **argv, size_t size ) ;

private:
    static const size_t k = 5;

    static void error( const std::string& error, const std::string& msg, const int isExcept = EXCEPT ) ;
    static int strToInt(const std::string& s, char *end = NULL, int base = 10) ;
    static void printElem( const int& elem ) ;
    
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
void PmergeMe::sort( T& conatiner )
{
    std::cout << "Before: " ;
    std::for_each(conatiner.begin(), conatiner.end(), printElem) ;
    std::cout << std::endl ;
    std::clock_t timer = clock() ;
    _sort(conatiner) ;
    timer = clock() - timer ;
    std::cout << "after: " ;
    std::for_each(conatiner.begin(), conatiner.end(), printElem) ;
    std::cout << std::endl ;
    std::cout << "Time to process a range of : " << conatiner.size()
            << " elements with " << typeid(conatiner).name() << " : " << std::fixed << (timer / (double)CLOCKS_PER_SEC) << std::endl ;
}

template<typename T>
void PmergeMe::fill( T& container, char **argv, size_t size )
{
    size_t i = 0 ;
    while (i < size)
        container.push_back(strToInt(argv[i++], NULL)) ;
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

#endif