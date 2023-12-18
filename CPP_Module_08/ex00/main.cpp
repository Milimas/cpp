#include "easyfind.hpp"

#define A_SIZE 10

static void fill(int &_int)
{
    _int = rand() % A_SIZE + 1 ;
}

static void print(int &_int)
{
    std::cout << _int << " " ;
}

int main( void )
{
    std::srand(time(NULL)) ;

    std::vector<int> _tmp ;
    _tmp.push_back(1) ;
    _tmp.push_back(2) ;
    _tmp.push_back(4) ;
    _tmp.push_back(5) ;
    _tmp.push_back(6) ;
    _tmp.push_back(7) ;
    _tmp.push_back(8) ;
    _tmp.push_back(9) ;
    _tmp.push_back(10) ;
    _tmp.push_back(3) ;
    std::for_each(_tmp.begin(), _tmp.end(), print) ;
    easyfind(_tmp, 3) ;
    std::cout << std::endl ;

    std::cout << "list" << std::endl ;
    std::list<int> _list(A_SIZE) ;
    std::for_each(_list.begin(), _list.end(), fill) ;
    std::for_each(_list.begin(), _list.end(), print) ;
    easyfind(_list, 3) ;
    std::cout << std::endl ;

    std::cout << "vector" << std::endl ;
    std::vector<int> _vector(A_SIZE) ;
    std::for_each(_vector.begin(), _vector.end(), fill) ;
    std::for_each(_vector.begin(), _vector.end(), print) ;
    easyfind(_vector, 3) ;
    std::cout << std::endl ;

    std::cout << "deque" << std::endl ;
    std::deque<int> _deque(A_SIZE) ;
    std::for_each(_deque.begin(), _deque.end(), fill) ;
    std::for_each(_deque.begin(), _deque.end(), print) ;
    easyfind(_deque, 3) ;
    std::cout << std::endl ;

    return (0) ;
}
