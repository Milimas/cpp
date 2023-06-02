# include "Contact.hpp"
# include "PhoneBook.hpp"
# include <cstdlib>

int main()
{
    PhoneBook phoneBook ;

    while (1)
    {
        std::system("clear") ;
        int choice = -1 ;
        std::cout << "PhoneBook" << std::endl ;
        std::cout << "Menu:" << std::endl ;
        std::cout << "1 - ADD" << std::endl ;
        std::cout << "2 - SEARCH" << std::endl ;
        std::cout << "0 - EXIT" << std::endl ;

        std::cin >> choice ;
        if (choice == 1)
            phoneBook.add() ;
        else if (choice == 2)
            phoneBook.search() ;
        else if (choice == 0)
            break ;
        else
            std::cout << "Wrong input try again" << std::endl ;
    }
    return (0) ;
}