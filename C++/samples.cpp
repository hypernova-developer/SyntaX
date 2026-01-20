#include "bettersyntax.hpp"
#include <vector>
#include <string>

using namespace bettersyntax;

int main() {
    // 1. SYSTEM UTILITIES & SEEDING
    // Clear the console screen (Cross-platform)
    clear();
    // Initialize random seed
    seed_random();

    print("--- SyntaX Library Demo ---");
    print("Welcome to the sample code for bettersyntax.h");
    print("");

    // 2. INPUT & OUTPUT
    // Python-style input and multi-argument print
    std::string name = input("Please enter your name: ");
    print("Hello", name, "! Let's test some features.");
    print("");

    // 3. TIME & SLEEP
    print("Waiting for 1.5 seconds...");
    sleep(1.5);
    print("Done waiting!");
    print("");

    // 4. RANDOM & MATH
    int luckyNumber = randint(1, 100);
    print("Your lucky number for today is:", luckyNumber);
    print("Factorial of 5 is:", factorial(5));
    print("2 to the power of 10 is:", power(2, 10));
    print("");

    // 5. VECTOR OPERATIONS (The Python 'in' equivalent)
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    print("Checking our vector...");
    if (contains(numbers, 20)) {
        print("Vector contains 20!");
    }
    print("Sum of numbers:", sum(numbers));
    print("Average of numbers:", average(numbers));
    print("");

    // 6. FILE OPERATIONS
    print("Saving your session to log.txt...");
    std::string logContent = "User " + name + " generated lucky number: " + std::to_string(luckyNumber);
    write_file("log.txt", logContent);
    
    print("Reading back from log.txt:");
    print(read_file("log.txt"));

    print("");
    print("Demo finished successfully. Happy coding with SyntaX!");

    return 0;
}
