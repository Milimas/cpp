#include <iostream>

int main(int argc, char **argv)
{
    std::string str;

    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" ;
    for (int i = 1; i < argc; i++)
    {
        str = argv[i] ;
        for (size_t j = 0; j < str.length(); j++)
            str[j] = toupper(str[j]) ;
        std::cout << str ;
    }
    std::cout << std::endl ;
    return 0 ;
}