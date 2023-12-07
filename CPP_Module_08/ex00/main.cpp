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

    std::cout << "list" << std::endl ;
    std::list<int> _list(A_SIZE) ;
    std::for_each(_list.begin(), _list.end(), fill);
    std::for_each(_list.begin(), _list.end(), print);
    easyfind(_list, 3) ;
    std::cout << std::endl ;

    std::cout << "vector" << std::endl ;
    std::vector<int> _vector(A_SIZE) ;
    std::for_each(_vector.begin(), _vector.end(), fill);
    std::for_each(_vector.begin(), _vector.end(), print);
    easyfind(_vector, 3) ;
    std::cout << std::endl ;

    std::cout << "array" << std::endl ;
    std::array<int, A_SIZE> _array ;
    std::for_each(_array.begin(), _array.end(), fill);
    std::for_each(_array.begin(), _array.end(), print);
    easyfind(_array, 3) ;
    std::cout << std::endl ;

    std::cout << "deque" << std::endl ;
    std::deque<int> _deque(A_SIZE) ;
    std::for_each(_deque.begin(), _deque.end(), fill);
    std::for_each(_deque.begin(), _deque.end(), print);
    easyfind(_deque, 3) ;
    std::cout << std::endl ;

    std::cout << "forward_list" << std::endl ;
    std::forward_list<int> _forward_list(A_SIZE) ;
    std::for_each(_forward_list.begin(), _forward_list.end(), fill);
    std::for_each(_forward_list.begin(), _forward_list.end(), print);
    easyfind(_forward_list, 3) ;
    std::cout << std::endl ;
}