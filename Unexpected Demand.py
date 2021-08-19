#!/bin/python3

import math
import os
import random
import re
import sys

def filledOrders(order, k):
    order.sort()
    c=0
    for i in range(0, len(order)):
        if order[i]<=k:
            c+=1
            k-=order[i]
    return c

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    order_count = int(input().strip())

    order = []

    for _ in range(order_count):
        order_item = int(input().strip())
        order.append(order_item)

    k = int(input().strip())

    result = filledOrders(order, k)

    fptr.write(str(result) + '\n')

    fptr.close()
