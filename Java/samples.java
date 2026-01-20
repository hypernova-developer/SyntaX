import java.util.Arrays;
import java.util.List;

/**
 * SyntaX for Java - Complete Function Showcase (samples.java)
 * This file demonstrates every single function available in the SyntaX library.
 */
public class samples {
    public static void main(String[] args) {
        
        // --- 1. OUTPUT (print) ---
        bettersyntax.print("--- Testing Output ---");
        bettersyntax.print("Hello", "World!", 2026, true); // Multiple arguments of different types

        // --- 2. UTILITIES (clear & sleep) ---
        bettersyntax.print("Wait 2 seconds, then screen will be cleared...");
        bettersyntax.sleep(2.0); // Wait for 2 seconds
        bettersyntax.clear();    // Clear the console

        // --- 3. INPUT (input) ---
        bettersyntax.print("--- Testing Input ---");
        String name = bettersyntax.input("Enter your name: ");
        String age = bettersyntax.input(); // Input without prompt
        bettersyntax.print("Welcome", name, "Age:", age);

        // --- 4. RANDOM (randint) ---
        bettersyntax.print("--- Testing Random ---");
        int dice = bettersyntax.randint(1, 6);
        bettersyntax.print("Dice Roll:", dice);

        // --- 5. LIST OPERATIONS (contains, sum, average) ---
        bettersyntax.print("--- Testing List Operations ---");
        List<Double> grades = Arrays.asList(85.0, 90.0, 78.5, 100.0);
        
        if (bettersyntax.contains(grades, 100.0)) {
            bettersyntax.print("Perfect score found in the list!");
        }
        bettersyntax.print("Total Points:", bettersyntax.sum(grades));
        bettersyntax.print("Class Average:", bettersyntax.average(grades));

        // --- 6. MATHEMATICAL FUNCTIONS (power, square_root, factorial) ---
        bettersyntax.print("--- Testing Math ---");
        bettersyntax.print("2 to the power 10:", bettersyntax.power(2, 10));
        bettersyntax.print("Square root of 81:", bettersyntax.square_root(81));
        bettersyntax.print("Factorial of 6:", bettersyntax.factorial(6));

        // --- 7. FILE I/O (write_file, read_file) ---
        bettersyntax.print("--- Testing File I/O ---");
        String fileName = "vortex_test.txt";
        String secretData = "VorteX v0.3 Initializing...";
        
        bettersyntax.write_file(fileName, secretData);
        bettersyntax.print("File created successfully.");
        
        String content = bettersyntax.read_file(fileName);
        bettersyntax.print("Read from file:", content);

        // --- FINAL CLEANUP ---
        bettersyntax.print("\nAll SyntaX functions tested successfully!");
        bettersyntax.terminate(); // Close the global scanner
    }
}
