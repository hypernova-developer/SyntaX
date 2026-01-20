/*
Programmed by hypernova-developer
https://github.com/hypernova-developer?tab=repositories
*/

#ifndef BETTERSYNTAX_H
#define BETTERSYNTAX_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <algorithm>
#include <cmath>

// Cross-platform compatibility for Sleep and Clear Screen
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

namespace bettersyntax {

    // --- 1. OUTPUT (Python-like print with multiple arguments) ---
    template <typename T>
    void print(T lastArg) {
        std::cout << lastArg << std::endl;
    }

    template <typename T, typename... Args>
    void print(T firstArg, Args... args) {
        std::cout << firstArg << " ";
        print(args...);
    }

    // --- 2. INPUT (Safe input handling with buffer cleaning) ---
    inline std::string input(std::string prompt = "") {
        std::cout << prompt;
        std::string value;
        // std::ws removes leading whitespaces and newlines from previous inputs
        std::getline(std::cin >> std::ws, value);
        return value;
    }

    // --- 3. UTILITIES (Time and Screen Management) ---
    inline void sleep(double seconds) {
        #ifdef _WIN32
            Sleep(static_cast<DWORD>(seconds * 1000));
        #else
            usleep(static_cast<useconds_t>(seconds * 1000000));
        #endif
    }

    inline void clear() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    // --- 4. RANDOM (Simplified random number generation) ---
    inline void seed_random() {
        std::srand(static_cast<unsigned int>(std::time(0)));
    }

    inline int randint(int min, int max) {
        if (min > max) return 0;
        return min + (std::rand() % (max - min + 1));
    }

    // --- 5. VECTOR OPERATIONS (Python-like list helpers) ---
    
    // Checks if an element exists in a vector (Equivalent to 'in' keyword in Python)
    template <typename T>
    bool contains(const std::vector<T>& vec, T element) {
        for (const auto& item : vec) {
            if (item == element) return true;
        }
        return false;
    }

    // Calculates the sum of all elements in a vector
    template <typename T>
    T sum(const std::vector<T>& vec) {
        T total = 0;
        for (const auto& item : vec) total += item;
        return total;
    }

    // Calculates the average of elements in a vector
    template <typename T>
    double average(const std::vector<T>& vec) {
        if (vec.empty()) return 0.0;
        return static_cast<double>(sum(vec)) / vec.size();
    }

    // --- 6. MATHEMATICAL FUNCTIONS ---
    
    inline double power(double base, double exp) { return std::pow(base, exp); }
    inline double square_root(double val) { return std::sqrt(val); }
    
    // Recursive factorial calculation
    inline long long factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }

    // --- 7. FILE I/O (Simplified file reading and writing) ---
    inline std::string read_file(std::string filename) {
        std::ifstream file(filename.c_str());
        if (!file.is_open()) return "Error: Could not open file.";
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    inline void write_file(std::string filename, std::string content) {
        std::ofstream file(filename.c_str());
        if (file.is_open()) {
            file << content;
            file.close();
        }
    }
}

#endif
