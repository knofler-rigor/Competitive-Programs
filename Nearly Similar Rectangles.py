#!/bin/python3

import math
import os
import random
import re
import sys

def nearlySimilarRectangles(sides):
    totalSides = len(sides)
    freq = {}
    ns = 0
    for side in sides:
        ratio = side[0]/side[1]
        if freq.get(ratio) is None:
            freq[ratio] = 1
        else:
            freq[ratio] += 1
    for k,v in freq.items():
        if v!=1:
            ns += int(math.factorial(v)/(math.factorial(v-2)*math.factorial(2)))
    return ns

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    sides_rows = int(input().strip())
    sides_columns = int(input().strip())

    sides = []

    for _ in range(sides_rows):
        sides.append(list(map(int, input().rstrip().split())))

    result = nearlySimilarRectangles(sides)

    fptr.write(str(result) + '\n')

    fptr.close()
