"""
https://projecteuler.net/problem=117

The number of ways to fill a row with n units of length
with grey (length of 1), red (length of 2), green (length of 3),
and blue (length of 4) is count(n) where,

                | 1; n = 0
                | 1; n = 1
    count(n) = {  2; n = 2
                | 4; n = 3
                | count(n - 1) + count(n - 2) + count(n - 3) + count(n - 4)

For efficiency purposes, we use the iterative method to solve the problem.
"""

n = 50

# Note that a here means count(0)

a, b, c, d = 1, 1, 2, 4
for i in range(n - 3 + 1):
    a, b, c, d = b, c, d, a + b + c + d

print(c)