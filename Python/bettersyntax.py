"""
SyntaX for Python
Library: bettersyntax.py
"""
import time
import random
import os

# --- OUTPUT ---
def print_s(*args):
    print(*(args))

# --- INPUT ---
def input_s(prompt=""):
    return input(prompt)

# --- UTILS ---
def sleep(seconds):
    time.sleep(seconds)

def clear():
    # Supports both Windows (cls) and Linux/Mac (clear)
    os.system('cls' if os.name == 'nt' else 'clear')

# --- RANDOM ---
def randint(min_val, max_val):
    return random.randint(min_val, max_val)

# --- MATH ---
def square_root(val):
    return val ** 0.5
