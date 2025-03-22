#include <iostream>
#include <vector>
#include <string>

void solve(std::vector<double>& sales);
std::vector<std::string> week = {"MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO"};

void solve(std::vector<double>& sales)
{
    int min = 0, max = 0;
    double average = sales[0];
    bool mintie = false, maxtie = false;
    std::string minString, maxString, averageString;
    
    for(int i = 1; i < 6; i++) 
    {
        average += sales[i];

        if(sales[i] < sales[min]) 
        {
            mintie = false;
            min = i;
        }
        else if(sales[i] == sales[min]) mintie = true;


        if(sales[i] > sales[max]) 
        {
            maxtie = false;
            max = i;
        }
        else if(sales[i] == sales[max]) maxtie = true;
    }

    average /= 6.0;

    maxString = maxtie? "EMPATE": week[max];
    minString = mintie? "EMPATE": week[min];
    averageString = (sales[5] > average) ? "SI" : "NO";

    std::cout << maxString << " " << minString << " " << averageString << "\n"; 
}


int main()
{
    std::vector<double> sales(6);
    
    std::cin >> sales[0];
    while (sales[0] != -1)
    {
        for(int i = 1; i < 6; i++) std::cin >> sales[i];
        solve(sales);

        std::cin >> sales[0];
    }

    return 0;
}