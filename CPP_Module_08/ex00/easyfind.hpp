#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template <class T>
bool easyfind(T& container, const int toFind)
{
    if (std::find(container.begin(), container.end(), toFind) != container.end())
    {
        std::cout << "Success Found" << std::endl ;
        return (true) ;
    }
    std::cout << "Not Found" << std::endl ;
    return (false) ;
}

#endif