#!/usr/bin/python3
from math import sqrt
from sys import argv


def fact3(num):

    sqrt_num = int(sqrt(abs(num)))

    if num % 2 == 0:
        return [num//2, 2]

    for i in range(3, sqrt_num + 1):
        if i == sqrt_num and num % sqrt_num != 0:
            return [num, 1]
        if num % i == 0:
            return [num//i, i]


def RSA():

    if len(argv) > 1:
        input_file = argv[1]
        try:
            with open(input_file, "r") as f:
                line = f.readline()
                while line:
                    if line == "\n":
                        break
                    x = int(line)
                    factors = fact3(x)
                    print(f"{x}={factors[0]}*{factors[1]}")
                    line = f.readline()
        except FileNotFoundError:
            print(f"Error: Can't open file {argv[1]}")
    else:
        print("Usage: factors <file>")


RSA()
