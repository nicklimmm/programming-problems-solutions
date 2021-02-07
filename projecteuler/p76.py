"""
https://projecteuler.net/problem=76

To solve this problem, I used dynamic programming.

Idea:
1. Suppose the target sum is n, then we can only choose a number
   x1 to include in the sum, where 1 <= x1 < n.
2. Then, our target sum now would be n - x, we can only choose a number
   x2 to include in the sum, where 1 <= x2 <= x1.
3. This works recursively, and the base case is when target = 0.
4. Add all the number of possibilites and memoize it.
"""

from math import ceil


memo = {}

# max_possible here means the maximum number that we can include in the sum
def solve(target, max_possible):
    if (target, max_possible) in memo:
        return memo[(target, max_possible)]
    if target == 0:
        return 1
    total = 0
    for x in range(1, min(max_possible, target) + 1):
        total += solve(target - x, x)
    memo[(target, max_possible)] = total
    return total

n = 100
print(solve(n, n - 1))  # n - 1 because we can't include n in the sum 