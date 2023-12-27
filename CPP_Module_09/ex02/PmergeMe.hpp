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

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
class PmergeMe
{
public:
    static C<std::pair<T,T> > p ;
    static C<T> res ;
    

    // typedef std::vector<int> Vector ;
    // typedef std::deque<int> Deque ;

    // static clock_t sort( C& container, const size_t k = 5 ) ;
    static void fill( char **argv, size_t size )
    {
        size_t i = 0 ;
        std::stringstream ss ;
        while (i < size)
        {
            ss << argv[i++] << " " ; 
        }
        T num1 ;
        T num2 ;
        while (ss >> num1 >> num2)
        {
            if (num1 < num2)
                std::swap(num1, num2) ;
            PmergeMe::p.push_back(std::make_pair(num1, num2)) ;
            num1 = -1 ;
        }
        if (num1 > 0)
            PmergeMe::p.push_back(std::make_pair(-1, num1)) ;
        _sort(p) ;
        insertionSort(p) ;   
    }
    
    // template<typename C>
    // static void printTime ( C& container, clock_t time ) ;
    // static void printElem( const int& elem ) ;

private:

    // static void error( const std::string& error, const std::string& msg, const int isExcept = EXCEPT ) ;
    // static int strToInt(const std::string& s, char *end = NULL, int base = 10) ;
    // static std::string getType( const Vector& container ) ;
    // static std::string getType( const Deque& container ) ;
    
    static void _sort ( C<std::pair<int,int> >& container )
    {
        if (container.size() == 1)
            return ;
        int pvt = (container.size() / 2) + (container.size() % 2) ;
        C<std::pair<int,int> > right(container.begin(), container.begin() + pvt) ;
        C<std::pair<int,int> > left(container.begin() + pvt, container.end()) ;
        container.clear() ;
        _sort(right) ;
        _sort(left) ;
        mergeSort(container, right, left) ;
    }

    static void insertionSort( C<std::pair<T,T> >& container ) 
    {
        typename C<std::pair<T,T> >::iterator it = container.begin() ;
        res.push_back(it->second) ;
        res.push_back(it->first) ;
        it++ ;
        for ( ; it < container.end(); it++)
        {
            if (it->first > 0)
                res.push_back(it->first) ;
            // typename C<T>::iterator bs = res.end() ;
            // while (bs > res.begin() && it->second < bs[-1] )
            // {
            //     bs-- ;
            // }
            // res.insert(bs, it->second) ;
            res.insert(std::lower_bound(res.begin(), res.end(), it->second), it->second) ;
        }  
    }

    static void mergeSort( C<std::pair<int,int> >& container, const C<std::pair<int,int> >& right, const C<std::pair<int,int> >& left )
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

    PmergeMe( void ) ;
    PmergeMe( const PmergeMe& other ) ;
    PmergeMe& operator=( const PmergeMe& other ) ;
    ~PmergeMe( void ) ;
} ;

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
C<std::pair<T,T> > PmergeMe<T, C>::p ;
template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
C<T > PmergeMe<T, C>::res ;


template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
PmergeMe<T, C>::PmergeMe( void ) 
{

}

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
PmergeMe<T, C>::PmergeMe( const PmergeMe& other ) 
{
    (void)other ;
}

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
PmergeMe<T, C>& PmergeMe<T, C>::operator=( const PmergeMe& other ) 
{
    (void)other ;
    return (*this) ;
}

template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
PmergeMe<T, C>::~PmergeMe( void ) 
{

}

// template<typename C>
// clock_t PmergeMe::sort( C& container, const size_t k )
// {
//     std::clock_t start = clock() ;
//     _sort(container, k) ;
//     return (clock() - start) ;
// }

// template <typename T, template <class _Tp = T, class A = std::allocator<T> > class C >
// void PmergeMe<T, C<T> >::_sort ( void )
// {
//         int pvt = (container.size() / 2) + (container.size() % 2) ;
//         T right(container.begin(), container.begin() + pvt) ;
//         T left(container.begin() + pvt, container.end()) ;
//         container.clear() ;
//         _sort(right) ;
//         _sort(left) ;
//         mergeSort(container, right, left) ;
// }

// template<typename C>
// void PmergeMe::insertionSort( C& container )
// {
//     for (typename C::iterator it = container.begin(); it < container.end() - 1; it++)
//     {
//         typename C::iterator j = it + 1 ;
//         int tmp = *j ;
//         while (j > container.begin() && j[-1] > tmp)
//         {
//             *j = j[-1] ;
//             j-- ;
//         }
//         *j = tmp ;
//     }  
// }

// template<typename C>
// void PmergeMe::mergeSort( C& container, const C& right, const C& left )
// {
//     int rinx = 0 ;
//     int linx = 0 ;

//     int rSize = right.size() ;
//     int lSize = left.size() ;
//     for (int i = 0 ; i < rSize + lSize ; i++)
//     {
//         if (rinx == rSize)
//             container.push_back(left[linx++]) ;
//         else if (linx == lSize)
//             container.push_back(right[rinx++]) ;
//         else if (right[rinx] > left[linx])
//             container.push_back(left[linx++]) ;
//         else
//             container.push_back(right[rinx++]) ;
//     }
// }

// template<typename C>
// void PmergeMe::printTime ( C& container, clock_t time )
// {
//     std::cout << "Time to process a range of : " << container.size()
//             << " elements with " << getType(container) << " : " << std::fixed << (time / (double)CLOCKS_PER_SEC) << " s" << std::endl ;

// }

#endif