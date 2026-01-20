using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

namespace bettersyntax
{
    public static class SyntaX
    {
        // --- OUTPUT ---
        public static void print(params object[] args)
        {
            if (args.Length == 0) { Console.WriteLine(); return; }
            Console.WriteLine(string.Join(" ", args));
        }

        // --- INPUT ---
        public static string input(string prompt = "")
        {
            Console.Write(prompt);
            return Console.ReadLine();
        }

        // --- UTILS ---
        public static void sleep(double seconds)
        {
            Thread.Sleep((int)(seconds * 1000));
        }

        public static void clear()
        {
            Console.Clear();
        }

        // --- RANDOM ---
        private static Random rand = new Random();
        public static int randint(int min, int max)
        {
            return rand.Next(min, max + 1);
        }

        // --- MATH ---
        public static double square_root(double val) => Math.Sqrt(val);
        
        public static long factorial(int n)
        {
            if (n <= 1) return 1;
            return n * factorial(n - 1);
        }

        // --- FILE OPS ---
        public static void write_file(string path, string content) => File.WriteAllText(path, content);
        public static string read_file(string path) => File.ReadAllText(path);
    }
}
