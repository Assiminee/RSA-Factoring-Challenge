#!/usr/bin/python3
from math import sqrt
from sys import argv
from time import time

start = time()

def fact3(num):

    sqrt_num = int(sqrt(abs(num)))

    for i in range(2, sqrt_num + 1):
        if num % i == 0:
            print(f"{num}={num//i}*{i}")
            return
    print(f"{num}={num}*{1}")


def RSA():

    if len(argv) > 1:
        input_file = argv[1]
        try:
            with open(input_file, "r") as f:
                factors = []
                line = f.readline()
                while line:
                    if line == "\n":
                        break
                    fact3(int(line))
                    line = f.readline()
        except FileNotFoundError:
            print(f"Error: Can't open file {argv[1]}")
    else:
        print("Usage: factors <file>")


RSA()

end = time()
print(f"Elapsed time: {end-start:.6f} seconds\n")
