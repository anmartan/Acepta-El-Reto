#include <iostream>
#include <string>

int countVowels(const std::string& message)
{
    std::string vowels = "aeiouAEIOU";
    int vowelCounter = 0;

    for (auto letter : message)
    {
        if (vowels.find(letter) != std::string::npos) vowelCounter++;
    }

    return vowelCounter;
}

std::string decypherMessage(const std::string& message)
{
    int difference = message[0] - 'p';
    std::string decypheredMessage = "";

    for (int i = 1; i < message.size(); i++)
    {
        int letter = message[i];

        if (letter >= 'a' && letter <= 'z')
        {
            letter -= difference;
            if (letter < 'a') letter = letter + 'z' - 'a' + 1;
            if (letter > 'z') letter = letter + 'a' - 'z' - 1;
        }
        else if (letter >= 'A' && letter <= 'Z')
        {
            letter -= difference;
            if (letter < 'A') letter = letter + 'Z' - 'A' + 1;
            if (letter > 'Z') letter = letter + 'A' - 'Z' - 1;
        }
        decypheredMessage += letter;
    }

    return decypheredMessage;
}

bool solve(const std::string& message)
{
    std::string newString = decypherMessage(message);
    if (newString == "FIN")
        return false;

    std::cout << countVowels(newString) << '\n';
    return true;
}

int main()
{
    std::string message;

    do
    {
        std::getline(std::cin, message);
    } while (solve(message));
    return 0;
}