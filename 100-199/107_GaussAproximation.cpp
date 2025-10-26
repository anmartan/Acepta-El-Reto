#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> pi(100001, 0);
std::vector<bool>primes(100001, true);


void findPrimes()
{
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i <= sqrt(100000); i++)
    {
        for (int j = i; j <= 100000 / i; j++)
        {
            primes[i * j] = false;
        }
    }
    int primeCount = 0;
    for (int i = 0; i <= 100000; i++)
    {
        if (primes[i]) primeCount++;
        pi[i] = primeCount;
    }
}


double gaussError(int n)
{
    return std::abs(pi[n] * std::log(n) - n);
}

int main()
{
    findPrimes();

    int n, m;
    std::cin >> n >> m;
    
    while (n != 0 || m != 0)
    {
        double error = gaussError(n);
        double limit = n * std::log(n) * std::pow(10, -m);
        (error > limit) ? (std::cout << "Mayor\n") :
        (error < limit) ? (std::cout << "Menor\n") :
            std::cout << "Igual\n";

        std::cin >> n >> m;
    }
}

