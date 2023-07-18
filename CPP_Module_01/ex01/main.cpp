#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
    int N = 10;
    Zombie *z;
    z = zombieHorde(N, "Zombie");
    for (int i = 0; i < N; i++)
    {
        z[i].announce();
    }
    delete [] z;
    return (0);
}
