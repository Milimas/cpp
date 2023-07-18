#ifndef CONTACT_HPP

#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
    std::string firstName ;
    std::string lastName ;
    std::string nickname ;
    std::string phoneNumber ;
    std::string darketSecret ;
public:
    Contact( std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darketSecret ) ;
    Contact( ) ;
    ~Contact() ;
    std::string getFirstName() ;
    std::string getLastName() ;
    std::string getNickname() ;
    std::string getPhoneNumber() ;
    std::string getDarketSecret() ;
};

#endif
