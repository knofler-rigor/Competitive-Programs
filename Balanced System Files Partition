#!/bin/python3

import math
import os
import random
import re
import sys

def mostBalancedPartition(parent, files_size):
    n=len(parent)
    total=[0 for i in range(n)]
    for i in range(n):
        cur=i
        while(cur!=-1):
            total[cur]+=files_size[i]
            cur=parent[cur]
            
    val=abs(total[0]-2*total[1])
    for i in range(2,n):
        temp=abs(total[0]-2*total[i])
        if(val>temp):
            val=temp
    return val

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    parent_count = int(input().strip())

    parent = []

    for _ in range(parent_count):
        parent_item = int(input().strip())
        parent.append(parent_item)

    files_size_count = int(input().strip())

    files_size = []

    for _ in range(files_size_count):
        files_size_item = int(input().strip())
        files_size.append(files_size_item)

    result = mostBalancedPartition(parent, files_size)

    fptr.write(str(result) + '\n')

    fptr.close()
