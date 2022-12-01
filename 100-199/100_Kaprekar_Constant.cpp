#include <iostream>
#include <algorithm>
#include <queue>


int Kaprekar(int number)
{
    int loops = 0;
    
    std::priority_queue<int> minQ;

    while (loops < 8)
    {
        int min = 0, max = 0;
        if (number == 6174) break;

        for (int i = 0; i < 4; i++)
        {
            int n = number % 10;
            number /= 10;
            minQ.push(n);
        }

        for (int i = 0; i < 4; i++)
        {
            int n = minQ.top(); minQ.pop();

            max += n * pow(10, 3 - i);
            min += n * pow(10, i);
        }
        number = max - min;


        loops++;
    }

    return loops;
}

int main()
{
    int cases;
    std::cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int number;
        std::cin >> number;

        std::cout << Kaprekar(number) << "\n";
    }
}