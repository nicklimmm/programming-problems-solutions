"""
https://projecteuler.net/problem=116

To solve this problem, I used the idea of recursion, but in the form iterative method.
O(n) time and O(1) space

For colored tiles with length k, the number of ways to replaces the tiles is,
                / 1; n <= k
    count(n) = {
                \ count(n - 1) + count(n - k); otherwise

In the end, we sum the number of ways for 3 types of colored tiles, and then subtract it
by 3, because in each type of colored tiles, there is 1 time where there are no colored tiles
that is placed.
"""

n = 50
result = 0

# Note that all a's in here means count(0)

a, b = 1, 1
for i in range(n - 2 + 1):
    a, b = b, a + b
result += b

a, b, c = 1, 1, 1
for i in range(n - 3 + 1):
    a, b, c = b, c, a + c
result += c

a, b, c, d = 1, 1, 1, 1
for i in range(n - 4 + 1):
    a, b, c, d = b, c, d, a + d
result += d

result -= 3

print(result)