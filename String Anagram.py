#!/bin/python3

import math
import os
import random
import re
import sys


def stringAnagram(dictionary, query):
    dict={}
    for s in dictionary:
        i=str(sorted(s))
        if i in dict:
            dict[i]+=1
        else:
            dict[i]=1
    ans=[]
    for s in query:
        i=str(sorted(s))
        if i in dict:
            ans.append(dict[i])
        else:
            ans.append(0)
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    dictionary_count = int(input().strip())

    dictionary = []

    for _ in range(dictionary_count):
        dictionary_item = input()
        dictionary.append(dictionary_item)

    query_count = int(input().strip())

    query = []

    for _ in range(query_count):
        query_item = input()
        query.append(query_item)

    result = stringAnagram(dictionary, query)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
