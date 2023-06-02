#ifndef PHONE_BOOK_HPP

#define PHONE_BOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8] ;
    static int size ;
    std::string trim( std::string str ) ;
public:
    PhoneBook() ;
    ~PhoneBook() ;
    void add(  ) ;
    void search(  ) ;
};

#endif