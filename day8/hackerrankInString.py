#!/bin/python3

import sys


q = int(input().strip())
for a0 in range(q):
    s = input().strip()
    # your code goes here
    hac = 'h a c k e r r a n k'.split(' ')
    i = 0
    j = 0
    while(i < len(s) and j < len(hac)):
        if(s[i] == hac[j]):
            j+=1
        i+=1
    if(j == 10):
        print("YES")
    else:
        print("NO")