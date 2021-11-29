#!/bin/python3

import math
import os
import random
import re
import sys


def taskOfPairing(freq):
  count = 0
  marker = False
  for i in freq:
    if i != 0:
      count += i // 2
      if i % 2 != 0 and marker:
        count += 1
        marker = False
      elif i % 2 != 0:
        marker = True
    else:
      marker = False
  return count


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    freq_count = int(input().strip())

    freq = []

    for _ in range(freq_count):
        freq_item = int(input().strip())
        freq.append(freq_item)

    result = taskOfPairing(freq)

    fptr.write(str(result) + '\n')

    fptr.close()
