#include <iostream>
#include <random>
#include <string>

auto main() -> int {
    // Print a welcome statement:
    std::cout << "Welcome to the GUESSING GAME!" << std::endl;
    std::cout << "I will generate a number and you will guess it!" << std::endl;

    // Ask the user (and read the answer) for the smallest number of the allowed range:
    std::cout << "Please provide the smallest number:" << std::endl;
    std::string user_string{};
    std::cin >> user_string;
    int user_smallest_number{std::stoi(user_string)};

    // Ask the user (and read the answer) for the largest number of the allowed range:
    std::cout << "Please provide the largest number:" << std::endl;
    std::cin >> user_string;
    int user_largest_number{std::stoi(user_string)};

    // Generate the random number that the user will have to guess and write the message about it to stdout:
    std::random_device random_device;
    std::mt19937 random_engine{random_device()};
    std::uniform_int_distribution distribution{user_smallest_number, user_largest_number};
    std::cout << "I've generated a number. Try to guess it!" << std::endl;

    int n{distribution(random_engine)};
    int k{0};
    int user_number{};

    while (true) {
        k++;

        // Ask the user for the next guess and read it:
        std::cout << "Please provide the next guess: "; 
        std::cin >> user_string; 

        user_number = std::stoi(user_string);
        if (user_number < n) {
            std::cout << "Your number is too small. Try again!" << std::endl;
        } else if (user_number > n) {
            std::cout << "Your number is too big. Try again!" << std::endl;
        } else { break; }
    }
    std::cout << "You've done it! You guessed the number " << n << " in " << k << " guesses!" << std::endl;

    return 0;
}