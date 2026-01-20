const { print, input, randint, sleep, clear } = require('./bettersyntax');

// --- 1. Basic I/O ---
print("--- SyntaX for JavaScript Showcase ---");

let name = input("Enter your developer name: ");
print("Welcome to SyntaX JS,", name);

// --- 2. Random & Utilities ---
let chance = randint(1, 10);
print("Your daily luck score (1-10):", chance);

print("The terminal will be cleared in 2 seconds...");
sleep(2);
clear();

print("SyntaX JS is ready for your web-backend projects!");
