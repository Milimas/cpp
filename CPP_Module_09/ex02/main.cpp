#include "PmergeMe.hpp"

int main( int argc, char **argv )
{
    /**
     * Your program must be able to use a positive integer sequence as argument.
     * Your program must use the merge-insert sort algorithm to sort the positive integer sequence.
     * If an error occurs during program execution, an error message should be displayed on the standard output.
     * It is strongly advised to implement your algorithm for each container and thus to avoid using a generic function.
     * 
     * Display:
     * On the first line you must display an explicit text followed by the unsorted positive integer sequence.
     * On the second line you must display an explicit text followed by the sorted positive integer sequence.
     * On the third line you must display an explicit text indicating the time used by your algorithm by specifying the first container used to sort the positive integer sequence.
     * On the last line you must display an explicit text indicating the time used by your algorithm by specifying the second container used to sort the positive integer sequence.
     * The format for the display of the time used to carry out your sorting is free but the precision chosen must allow to clearly see the difference between the two containers used.
     * The indication of the time is deliberately strange in this example. Of course you have to indicate the time used to perform all your operations, both the sorting part and the data management part.
     * 
    */
    if (argc < 2)
    {
        std::cout << USAGE << std::endl ;
        return (2) ;
    }
    (void)argv ;
    std::clock_t timer = clock() ;
    PmergeMe::sortVector( &argv[1], argc - 1 ) ;
    timer = clock() - timer ;
    std::cout << "elapse: " << std::fixed << (timer / (double)CLOCKS_PER_SEC) << std::endl ;
    return (EXIT_SUCCESS) ;
}

/**
 * testing
 * You must use at least two different containers in your code to validate this exercise. Your program must be able to handle at least 3000 different integers.
*/