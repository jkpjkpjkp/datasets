from numpy import random
import os
import sys

A = int(sys.argv[1])
x = random.zipf(a=A, size=(1000))

for i in x:
    print(i)