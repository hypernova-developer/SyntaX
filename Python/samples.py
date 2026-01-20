from bettersyntax import print_s, input_s, randint, sleep, clear, square_root

# --- 1. Standardized I/O ---
print_s("--- SyntaX for Python Showcase ---")

hero = input_s("Enter your hero name: ")
print_s("Hero assigned:", hero)

# --- 2. Math & Random ---
num = randint(16, 64)
print_s(f"Random number: {num}")
print_s(f"Square root of {num} is:", square_root(num))

# --- 3. System Utilities ---
print_s("Cleaning up the console...")
sleep(1.5)
clear()

print_s("SyntaX Python is now active.")
