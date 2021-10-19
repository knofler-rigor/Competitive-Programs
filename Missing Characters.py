#!/bin/python3

import math
import os
import random
import re
import sys


def missingCharacters(s):
    char = [-1]*256
    for i in range(48,58):
        char[i] = 0
    for i in range(97,123):
        char[i] = 0
    for i in s:
        char[ord(i)] += 1
    res = ""
    for i in range(256):
        if(char[i] == 0):
            res = res + chr(i)
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = missingCharacters(s)

    fptr.write(result + '\n')

    fptr.close()
