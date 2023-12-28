#include "PmergeMe.hpp"

int main( int argc, char **argv )
{
    if (argc < 2)
    {
        std::cout << USAGE << std::endl ;
        return (2) ;
    }

    (void)argv ;
    // Fill containers
    std::vector<int> _v ;
    std::deque<int> _d ;

    PmergeMe<int, std::vector>::fill( argv + 1, argc - 1 ) ;
    PmergeMe<int, std::deque>::fill( argv + 1, argc - 1 ) ;
    // size_t size = PmergeMe<int, std::vector>::p.size() ;
    // for (size_t i = 0; i < size; i++)
    // {
    //     std::cout << PmergeMe<int, std::vector>::p[i].first << " " << PmergeMe<int, std::vector>::p[i].second << std::endl ;
    // }
    
    // size = _v.size() ;
    // for (size_t i = 0; i < size; i++)
    // {
    //     std::cout << _v[i] << std::endl ;
    // }


    // Numbers before sort
    std::cout << "Before:" ;
    for (int i = 1; i < argc; i++)
    {
        std::cout << " " << argv[i] ;
    }
    std::cout << std::endl ;

    // // Sort and recond timing
    clock_t vTime = PmergeMe<int, std::vector>::sort( _v ) ;
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
