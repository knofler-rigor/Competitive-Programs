#!/bin/python3

import math
import os
import random
import re
import sys

def minimumNumber(n, password):
    cnt=[0]*4
    cnt1=0
    numbers = "0123456789"
    lower_case = "abcdefghijklmnopqrstuvwxyz"
    upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    special_characters = "!@#$%^&*()-+"
 
    for i in password:

        if i in numbers:
            cnt[0]+=1
        elif i in lower_case:
            cnt[1]+=1
        elif i in upper_case:
            cnt[2]+=1
        elif i in special_characters:
            cnt[3]+=1
   
    for j in cnt:
        if j==0:
            cnt1+=1
            
    if n>5:
        return cnt1
    
    else:
        a = 6-n
        return max(a,cnt1)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    password = input()

    answer = minimumNumber(n, password)

    fptr.write(str(answer) + '\n')

    fptr.close()
