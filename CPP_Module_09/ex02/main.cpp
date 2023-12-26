#include "PmergeMe.hpp"

int main( int argc, char **argv )
{
    if (argc < 2)
    {
        std::cout << USAGE << std::endl ;
        return (2) ;
    }

    // Fill containers
    std::vector<int> _v ;
    std::deque<int> _d ;
    PmergeMe::fill(_v, argv + 1, argc - 1) ;
    PmergeMe::fill(_d, argv + 1, argc - 1) ;

    // Numbers before sort
    std::cout << "Before: " ;
    std::for_each(_v.begin(), _v.end(), PmergeMe::printElem) ;
    std::cout << std::endl ;

    // Sort and recond timing
    clock_t vTime = PmergeMe::sort( _v ) ;
    clock_t dTime = PmergeMe::sort( _d ) ;

    // Number after sort
    std::cout << "after: " ;
    std::for_each(_v.begin(), _v.end(), PmergeMe::printElem) ;
    std::cout << std::endl ;

    // Desplay benchmark
    PmergeMe::printTime(_v, vTime) ;
    PmergeMe::printTime(_d, dTime) ;

    // Test if arrays are sorted:
    std::deque<int>::iterator _dSorted = std::adjacent_find(_d.begin(), _d.end(), std::greater<int>()) ;
    if (_dSorted == _d.end())
        std::cout << "deque: ✅ Success" << std::endl ;
    else
        std::cerr << "Error: ❌ " << *_dSorted << std::endl ;
    std::vector<int>::iterator _vSorted = std::adjacent_find(_v.begin(), _v.end(), std::greater<int>()) ;
    if (_vSorted == _v.end())
        std::cout << "vector: ✅ Success" << std::endl ;
    else
        std::cerr << "Error: ❌ " << *_vSorted << std::endl ;

    return (EXIT_SUCCESS) ;
}
