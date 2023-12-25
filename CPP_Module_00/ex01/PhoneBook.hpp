#ifndef PHONE_BOOK_HPP

#define PHONE_BOOK_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8] ;
    static int size ;
    static int oldindex ;
    std::string trim( std::string str ) ;
    static bool isValid( std::string str ) ;
    static bool isPhoneNumber( std::string str ) ;
    static int toIndex( std::string str ) ;

public:
    PhoneBook() ;
    ~PhoneBook() ;
    void add(  ) ;
    void search(  ) ;
};

#endif