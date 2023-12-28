#include "PmergeMe.hpp"

int main( int argc, char **argv )
{
    if (argc < 2)
    {
        std::cout << USAGE << std::endl ;
        return (2) ;
    }

    (void)argv ;
    // Numbers before sort
    std::cout << "Before:" ;
    for (int i = 1; i < argc; i++)
    {
        std::cout << " " << argv[i] ;
    }
    std::cout << std::endl ;

    // Fill containers
    // Sort and record timing
    std::vector<int> _v ;
    PmergeMe<int, std::vector>::fill( argv + 1, argc - 1 ) ;
    clock_t vTime = PmergeMe<int, std::vector>::sort( _v ) ;
    
    std::deque<int> _d ;
    PmergeMe<int, std::deque>::fill( argv + 1, argc - 1 ) ;
    clock_t dTime = PmergeMe<int, std::deque>::sort( _d ) ;

    // Number after sort
    std::cout << "after:" ;
    std::for_each(_v.begin(), _v.end(), PmergeMe<int, std::vector>::printElem) ;
    std::cout << std::endl ;

    // Desplay benchmark
    PmergeMe<int, std::vector>::printTime(_v, vTime) ;
    PmergeMe<int, std::deque>::printTime(_d, dTime) ;

    // Test if arrays are sorted:
    std::vector<int>::iterator _vSorted = std::adjacent_find(_v.begin(), _v.end(), std::greater<int>()) ;
    if (_vSorted == _v.end())
        std::cout << "vector: ✅ Success" << std::endl ;
    else
        std::cerr << "Error: ❌ " << *_vSorted << std::endl ;
    std::deque<int>::iterator _dSorted = std::adjacent_find(_d.begin(), _d.end(), std::greater<int>()) ;
    if (_dSorted == _d.end())
        std::cout << "deque: ✅ Success" << std::endl ;
    else
        std::cerr << "Error: ❌ " << *_dSorted << std::endl ;

    return (EXIT_SUCCESS) ;
}
