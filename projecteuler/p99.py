"""
https://projecteuler.net/problem=99

To solve this problem efficiently, we need to make use of logarithms.

Recall that:
    log(a^b) = b * log(a)
            and
    a^b > c^d  ---> b * log(a) > c * log(d)

Therefore, we can do solve this by finding the line where exp * log(base)
yields the maximum value.
"""


from math import log10

f = open("p099_base_exp.txt")   # get input from txt file

max_line = 0    # stores the line number that yields the max log value
max_val = 0     # stores the maximum value for comparison

cur_line = 1    # tracks the current visited line
for line in f:
    # extract base and exp
    base, exp = list(map(int, line.rstrip('\n').split(',')))
    
    val = exp * log10(base)

    if val > max_val:
        max_val = val
        max_line = cur_line

    cur_line += 1

print(max_line)   