#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <array>

auto main() -> int {
    using std::string_literals::operator""s;
    std::cout << "Welcome to the fortune teller program!" << std::endl;
    std::cout << "Please enter your name:" << std::endl;
    std::string name{};
    std::cin >> name;

    std::cout << "Please enter the time of year when you were born:" << std::endl;
    std::cout << "(pick from 'spring', 'summer', 'autumn', 'winter')" << std::endl;
    std::string time_of_year{};
    std::cin >> time_of_year;
    std::map<std::string, std::string> nouns{
        {"spring", "STL guru"},
        {"summer", "C++ expert"},
        {"autumn", "coding beast"},
        {"winter", "software design hero"}};

    std::cout << "Please enter an adjective:" << std::endl;
    std::vector<std::string> adjectives;
    std::string first_adjective{};
    std::cin >> first_adjective;
    adjectives.emplace_back(first_adjective);

    std::cout << "Please enter another adjective:" << std::endl;
    std::string second_adjective{};
    std::cin >> second_adjective;
    adjectives.emplace_back(second_adjective);

    std::array endings{"eats UB for breakfast",
                       "finds errors quicker than the compiler",
                       "is not afraid of C++ error messages"};

    std::cout << name + ", the "s + adjectives.at(name.size() % adjectives.size()) + " "s + nouns.at(time_of_year) + " that "s + endings[name.size() % endings.size()] << std::endl;
}