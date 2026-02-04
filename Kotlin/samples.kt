import bettersyntax.*

/**
 * Showcase of SyntaX Library for Kotlin
 * Demonstrating "Pure Performance" and minimalist syntax.
 */

fun main() {
    // --- 1. Basic Output and Input ---
    clear()
    print("Welcome to SyntaX Kotlin Edition")
    print("---------------------------------")
    
    val name = input("Enter your developer tag: ")
    print("Access granted,", name, "- Initializing HyperNova Engine...\n")
    sleep(1.5)

    // --- 2. Random and Math Operations ---
    val luck = randint(1, 100)
    print("Your luck level today is:", "$luck%")
    
    val base = 2.0
    val exp = 10.0
    print(base, "to the power of", exp, "is:", power(base, exp))
    
    val factNum = 5
    print("Factorial of", factNum, "is:", factorial(factNum))
    print("")

    // --- 3. List Operations (Using Extensions) ---
    val dataPoints = listOf(10, 20, 30, 40, 55.5)
    print("Data Points:", dataPoints)
    print("Sum of Data:", dataPoints.sumAll())
    print("Average of Data:", dataPoints.averageAll())
    print("")

    // --- 4. File I/O Simulation ---
    print("Saving session log...")
    val logContent = "User: $name | Luck: $luck | Status: Success"
    writeFile("session.log", logContent)
    
    sleep(1.0)
    print("Reading back the log file:")
    val savedData = readFile("session.log")
    print("File Content ->", savedData)

    // --- 5. Final Goodbye ---
    print("\nSystem execution finished.")
    print("The monster's running wild... Fading out.")
}
