#include <iostream>
#include <vector>
#include <string>
#include <utility>

const std::vector<std::pair<std::string,std::string>> COUNTRYCODES{
    {"0","EEUU"},{"380","Bulgaria"},{"50","Inglaterra"},
    {"539","Irlanda"},{"560","Portugal"},{"70","Noruega"},
    {"759","Venezuela"},{"850","Cuba"},{"890","India"}
};

std::string getCountry(const std::string& barcode){
    if(barcode.size() < 13) return "EEUU";
    for(auto pair : COUNTRYCODES)
    {
        std::string prefix = barcode.substr(0,pair.first.size());
        if(prefix == pair.first) return pair.second;
    }
  return "Desconocido";
}

void solve(const std::string& barcode)
{
    int i = 0, odd = 0, even = 0;
    for(auto c = barcode.rbegin()+1; c!= barcode.rend(); c++){
        i++;
        int digit = (*c) - '0';
        (i % 2) ? odd += digit : even += digit;
    }
    int total = odd * 3 + even;
    int checkDigit = (10 - total % 10) % 10;
    
    if(checkDigit != barcode[barcode.size() - 1] -'0')
    {
        std::cout << "NO\n";
        return;
    }

    std::string country = "";
    if(barcode.size() > 8) country = " " + getCountry(barcode);

    std::cout << "SI" << country << "\n";
}

int main()
{
    std::string barcode;
    
    std::cin >> barcode;
    while (barcode != "0")
    {
        solve(barcode);
        std::cin >> barcode;
    }

    return 0;
}