# include "Contact.hpp"
# include "PhoneBook.hpp"
# include <cstdlib>
# include <fstream>
# include <string>

int main()
{
    PhoneBook phoneBook ;

    while (1)
    {
        std::system("clear") ;
        std::string choice ;
        std::cout << "PhoneBook" << std::endl ;
        std::cout << "Commands:" << std::endl ;
        std::cout << "ADD" << std::endl ;
        std::cout << "SEARCH" << std::endl ;
        std::cout << "EXIT" << std::endl ;

        if (std::cin.eof())
            return (0);
        std::cout << "$ " ;
        std::getline(std::cin, choice) ;
        while (choice.empty() && !std::cin.eof())
        {
            std::cout << "$ " ;
            std::getline(std::cin, choice) ;
        }

        if (choice == "ADD")
            phoneBook.add() ;
        else if (choice == "SEARCH")
            phoneBook.search() ;
        else if (choice == "EXIT")
            break ;
        else if (!choice.empty())
        {
            std::cout << "Wrong input try again" << std::endl ;
            std::cout << "Press any key to continue..." << std::endl ;
            std::system("read") ;
        }
    }
    return (0) ;
}
