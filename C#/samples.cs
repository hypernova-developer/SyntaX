using System;
using System.Collections.Generic;
// Importing the library as static allows us to use functions like print() directly
using static bettersyntax.SyntaX; 

namespace bettersyntax
{
    class Samples
    {
        static void Main(string[] args)
        {
            // --- 1. Basic I/O Operations ---
            print("--- SyntaX for C# Showcase ---");
            
            string user = input("Enter your username: ");
            print("Welcome,", user, "! You are ready to code.");

            // --- 2. Randomization and Math ---
            int r = randint(1, 100);
            print("Generated a random number for you:", r);
            
            double root = square_root(r);
            print("The square root of", r, "is:", root);

            // --- 3. Data Collections (Using C# Lists) ---
            List<string> languages = new List<string> { "C++", "Java", "C#" };
            print("Supported languages:", string.Join(", ", languages));

            // --- 4. File Management ---
            print("Saving data to file...");
            write_file("session_log.txt", $"User: {user}, Lucky Number: {r}");
            
            string content = read_file("session_log.txt");
            print("Content read from file:", content);

            // --- 5. System Utilities ---
            print("The screen will be cleared in 3 seconds...");
            sleep(3.0);
            clear();

            print("System cleared successfully. Happy coding!");
        }
    }
}
