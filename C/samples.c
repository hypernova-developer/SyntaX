/*
 * samples.c - Demonstration of SyntaX_for_C
 * Part of the SyntaX Ecosystem by hypernova-developer
 * Compile with: gcc samples.c -lm -o samples
 * https://github.com/hypernova-developer
 */

#include "bettersyntax.h"

int main() {
    // 1. Clear the screen to start fresh
    clear();

    // 2. Output and Header
    print_s("======================================");
    print_s("   SyntaX for C - Library Demo        ");
    print_s("======================================");
    print_s(""); // Empty line

    // 3. User Input
    char name[50];
    input("Please enter your name: ", name, 50);
    
    print_s(""); 
    print_s("Hello,");
    print_s(name);
    print_s("Let's test some features!");

    // 4. Random Numbers & Delay
    print_s("\nGenerating a random lucky number (1-100)...");
    seed_random();
    delay(1.5); // Wait for 1.5 seconds for dramatic effect
    
    int lucky = randint(1, 100);
    printf("Your lucky number is: ");
    print_i(lucky);

    // 5. Mathematics
    print_s("\n--- Math Operations ---");
    double value = 16.0;
    printf("Square root of 16: ");
    print_f(square_root(value));

    printf("Factorial of 5: ");
    print_i((int)factorial(5));

    // 6. Finishing up
    print_s("\n======================================");
    print_s("Test completed successfully! Enjoy SyntaX.");
    print_s("======================================");

    return 0;
}
