"""
https://projecteuler.net/problem=206

First of all, we need to know the lower bound of the answer.

Observe that the lowest integer that satisfies the form is,
    sqrt(1020304050607080900) = 1010101010.1010

So we can start the search from 1010101010 and take 10 steps
for each interval, since the last digit of the square have to
be 0. We do this until the answer is found.
"""

# function to validate if the square of n suits the form
def valid(n):
    n = str(n)
    if len(n) != 19 or n[-1] != '0':
        return False
    for i in range(1, 10):
        if str(i) != n[2 * i - 2]:
            return False
    return True

x = 1010101010
while not valid(x * x):
    x += 10

print(x)