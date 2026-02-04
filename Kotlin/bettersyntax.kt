package bettersyntax

import java.util.*
import java.io.*
import java.nio.file.*
import kotlin.math.*

/**
 * SyntaX Library for Kotlin
 * Optimized for speed and minimalist syntax.
 * @author hypernova-developer
 * @version 1.0 (Pure Performance Edition)
 */

// Global Scanner instance - Using 'lazy' to initialize only when needed
val sc by lazy { Scanner(System.`in`) }

// --- 1. OUTPUT ---

/** * Prints multiple objects separated by spaces.
 * Mimics Python's print() functionality.
 */
fun print(vararg args: Any?) {
    if (args.isEmpty()) println()
    else println(args.joinToString(" "))
}

// --- 2. INPUT ---

/** * Reads a line of input from the console with an optional prompt.
 */
fun input(prompt: Any? = ""): String {
    kotlin.io.print(prompt)
    return sc.nextLine() ?: ""
}

// --- 3. UTILITIES ---

/** * Pauses execution for a specified duration in seconds.
 */
fun sleep(seconds: Double) {
    Thread.sleep((seconds * 1000).toLong())
}

/** * Clears the console screen. Supports Windows (cls) and Unix-based systems (ANSI).
 */
fun clear() {
    val os = System.getProperty("os.name").lowercase()
    if (os.contains("win")) {
        ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor()
    } else {
        kotlin.io.print("\u001b[H\u001b[2J")
        System.out.flush()
    }
}

// --- 4. RANDOM ---

/** * Generates a random integer within the specified range [min, max].
 */
fun randint(min: Int, max: Int): Int = (min..max).random()

// --- 5. LIST OPERATIONS ---

/** * Extension function to calculate the sum of all elements in a numeric list.
 */
fun List<Number>.sumAll(): Double = this.sumOf { it.toDouble() }

/** * Extension function to calculate the average of a numeric list.
 */
fun List<Number>.averageAll(): Double = if (this.isEmpty()) 0.0 else this.sumAll() / this.size

// --- 6. MATHEMATICAL FUNCTIONS ---

fun power(base: Double, exp: Double): Double = base.pow(exp)

fun squareRoot(valIn: Double): Double = sqrt(valIn)

/** * Calculates factorial using tail recursion for maximum performance and memory safety.
 */
tailrec fun factorial(n: Int, run: Long = 1): Long {
    return if (n <= 1) run else factorial(n - 1, run * n)
}

// --- 7. FILE I/O ---

/** * Reads the entire content of a file. Returns an error message if the file is not found.
 */
fun readFile(filename: String): String {
    return try { File(filename).readText() } catch (e: Exception) { "Error: Could not read $filename" }
}

/** * Writes content to a file. Overwrites if the file already exists.
 */
fun writeFile(filename: String, content: String) {
    try { File(filename).writeText(content) } catch (e: Exception) { println("Error: Could not write $filename") }
}
