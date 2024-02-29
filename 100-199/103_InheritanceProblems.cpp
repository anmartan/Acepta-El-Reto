#include <iostream>
#include <string>
#include <vector>
#include <math.h>

double calculateHeight(const std::vector<int>& equation, double x)
{
    double height = equation[0];
    for (int i = 1; i < equation.size(); i++)
    {
        height += pow(x, i) * (double)equation[i];
    }
    if (height < 0) return 0;
    if (height > 1) return 1;
    return height;
}

double riemann(const std::vector<int>& equation, int steps)
{
    double base = (double)1 / steps;
    double riemmannSum = 0;
    for (int i = 0; i < steps; i++)
    {
        double height = calculateHeight(equation, base * i);
        riemmannSum += base * height;
    }

    return riemmannSum;
}

void solve(int grade)
{
    std::vector<int>equation(grade + 1);

    // Read equation
    for (int i = grade; i >= 0; i--)
    {
        std::cin >> equation[i];
    }

    int steps;
    std::cin >> steps;

    double area = riemann(equation, steps);

    if (area < 0.4995) std::cout << "ABEL\n";
    else if (area > 0.5005) std::cout << "CAIN\n";
    else std::cout << "JUSTO\n";
}


int main()
{
    int grade;
    std::cin >> grade;

    while (grade != 20)
    {
        solve(grade);
        std::cin >> grade;
    }
    return 0;
}