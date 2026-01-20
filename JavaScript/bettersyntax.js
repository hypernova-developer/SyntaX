/**
 * SyntaX for JavaScript (Node.js)
 * Library: bettersyntax.js
 */

const readline = require('readline-sync');

const bettersyntax = {
    // --- OUTPUT ---
    print: (...args) => {
        console.log(args.join(' '));
    },

    // --- INPUT ---
    input: (prompt = "") => {
        return readline.question(prompt);
    },

    // --- UTILS ---
    sleep: (seconds) => {
        // Synchronous sleep for CLI simplicity
        const ms = seconds * 1000;
        const start = Date.now();
        while (Date.now() < start + ms);
    },

    clear: () => {
        console.clear();
    },

    // --- RANDOM ---
    randint: (min, max) => {
        return Math.floor(Math.random() * (max - min + 1)) + min;
    }
};

module.exports = bettersyntax;
