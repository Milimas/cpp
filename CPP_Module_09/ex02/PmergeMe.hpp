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
    enum strToInt_t { SUCCESS, OVERFLOW, UNDERFLOW, INCONVERTIBLE };

    static void sortVector( char **argv, size_t size ) ;
    static void sortDeque( char **argv, size_t size ) ;

private:
    static Vector _vec ;
    static Deque _deq ;
    static void error( const std::string& error, const std::string& msg, const int isExcept = EXCEPT ) ;
    static int strToInt(const std::string& s, char *end = NULL, int base = 10) ;

    PmergeMe( void ) ;
    PmergeMe( const PmergeMe& other ) ;
    PmergeMe& operator=( const PmergeMe& other ) ;
    ~PmergeMe( void ) ;
} ; 

#endif