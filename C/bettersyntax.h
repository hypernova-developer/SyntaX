/*
 * SyntaX for C
 * Developed by: hypernova-developer
 * Repository: SyntaX_for_C
 * Description: A simplified C header to make C development more intuitive.
 * https://github.com/hypernova-developer
 * License: GNU General Public License v3.0
 */

#ifndef BETTERSYNTAX_C_H
#define BETTERSYNTAX_C_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/* Cross-platform sleep support */
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

/* --- 1. OUTPUT SYSTEM --- */
/* Using macros to simplify printf for different data types */
#define print_s(text) printf("%s\n", text)
#define print_i(num)  printf("%d\n", num)
#define print_f(num)  printf("%.2f\n", num)
#define print_d(num)  printf("%.2lf\n", num)

/* --- 2. INPUT SYSTEM --- */
/* Safe input handling with buffer cleaning */
static inline void input(const char* prompt, char* buffer, int size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        /* Remove trailing newline character */
        buffer[strcspn(buffer, "\n")] = 0;
    }
}

/* --- 3. UTILITIES --- */
/* Simple screen management and timing */
static inline void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static inline void delay(double seconds) {
#ifdef _WIN32
    Sleep((DWORD)(seconds * 1000));
#else
    usleep((useconds_t)(seconds * 1000000));
#endif
}

/* --- 4. RANDOM NUMBERS --- */
static inline void seed_random() {
    srand((unsigned int)time(NULL));
}

static inline int randint(int min, int max) {
    if (min > max) return 0;
    return min + (rand() % (max - min + 1));
}

/* --- 5. MATHEMATICS --- */
static inline double power(double base, double exp) { return pow(base, exp); }
static inline double square_root(double val) { return sqrt(val); }

/* Recursive factorial calculation */
static inline long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

#endif /* BETTERSYNTAX_C_H */
