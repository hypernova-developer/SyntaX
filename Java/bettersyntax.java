import java.util.*;
import java.io.*;
import java.nio.file.*;

/**
 * SyntaX Library for Java
 * A utility library to make Java syntax more user-friendly, 
 * similar to Python and C++ BetterSyntax.
 * * @author hypernova-developer
 * * https://github.com/hypernova-developer?tab=repositories
 * @version 1.0
 */
public class bettersyntax {

    // Global Scanner instance to prevent "Resource Leak" and "System.in Closed" errors.
    private static final Scanner sc = new Scanner(System.in);

    // --- 1. OUTPUT ---

    /**
     * Prints multiple objects to the console, separated by spaces.
     * Equivalent to Python's print() function.
     */
    public static void print(Object... args) {
        if (args.length == 0) {
            System.out.println();
            return;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < args.length; i++) {
            sb.append(args[i]);
            if (i < args.length - 1) sb.append(" ");
        }
        System.out.println(sb.toString());
    }

    // --- 2. INPUT ---

    /**
     * Reads a line of text from the console with a prompt.
     * Note: Do not close the scanner manually to keep System.in open.
     */
    public static String input(String prompt) {
        System.out.print(prompt);
        return sc.nextLine();
    }

    /**
     * Reads a line of text from the console without a prompt.
     */
    public static String input() {
        return input("");
    }

    /**
     * Closes the global scanner resource. 
     * Call this only at the very end of your main method if necessary.
     */
    public static void terminate() {
        sc.close();
    }

    // --- 3. UTILITIES ---

    /**
     * Pauses the execution for a given number of seconds.
     */
    public static void sleep(double seconds) {
        try {
            Thread.sleep((long) (seconds * 1000));
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    /**
     * Clears the console screen. Supports Windows (cls) and Unix (ANSI).
     */
    public static void clear() {
        try {
            String os = System.getProperty("os.name").toLowerCase();
            if (os.contains("win")) {
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            } else {
                System.out.print("\033[H\033[2J");
                System.out.flush();
            }
        } catch (Exception e) {
            // Fallback: Print empty lines if system clear fails
            for (int i = 0; i < 50; i++) System.out.println();
        }
    }

    // --- 4. RANDOM ---

    private static final Random random = new Random();

    /**
     * Generates a random integer between min and max (inclusive).
     */
    public static int randint(int min, int max) {
        if (min > max) return 0;
        return random.nextInt((max - min) + 1) + min;
    }

    // --- 5. LIST OPERATIONS ---

    /**
     * Checks if a list contains a specific element.
     */
    public static <T> boolean contains(List<T> list, T element) {
        return list.contains(element);
    }

    /**
     * Calculates the sum of a list containing numbers.
     */
    public static double sum(List<? extends Number> list) {
        double total = 0;
        for (Number n : list) total += n.doubleValue();
        return total;
    }

    /**
     * Calculates the average of a list containing numbers.
     */
    public static double average(List<? extends Number> list) {
        if (list.isEmpty()) return 0.0;
        return sum(list) / list.size();
    }

    // --- 6. MATHEMATICAL FUNCTIONS ---

    public static double power(double base, double exp) { return Math.pow(base, exp); }
    
    public static double square_root(double val) { return Math.sqrt(val); }
    
    /**
     * Calculates the factorial of n recursively.
     */
    public static long factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }

    // --- 7. FILE I/O ---

    /**
     * Reads the entire content of a file into a String.
     */
    public static String read_file(String filename) {
        try {
            return Files.readString(Path.of(filename));
        } catch (IOException e) {
            return "Error: Could not read file " + filename;
        }
    }

    /**
     * Writes content to a file. Overwrites if the file exists.
     */
    public static void write_file(String filename, String content) {
        try {
            Files.writeString(Path.of(filename), content);
        } catch (IOException e) {
            System.err.println("Error: Could not write to file " + filename);
        }
    }
}
