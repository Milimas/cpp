#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template <class T>
typename T::iterator easyfind(T& container, const int toFind)
{
    typename T::iterator found = std::find(container.begin(), container.end(), toFind);
    if (found != container.end())
        std::cout << "Success Found" << std::endl ;
    else
        std::cout << "Not Found" << std::endl ;
    return (found) ;
}

#endif
