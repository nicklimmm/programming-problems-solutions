from math import sqrt, ceil
from collections import deque

"""
https://projecteuler.net/problem=37

This problem is solvable using brute force.

Observe that 23 is the 1st number that satisfies the condition.
So we can start from 23 and check the other 10 numbers that also
satisfies the condition.
"""


# Helper function to check if a number is prime
def is_prime(n):
    n = int(n)
    if n == 2:
        return True
    if n < 2 or n % 2 == 0:
        return False
    for d in range(3, ceil(sqrt(n)) + 1, 2):
        if n % d == 0:
            return False
    return True


# Helper function to check if a number is a truncatable prime
def is_truncatable_prime(n):
    # This uses string slicing
    n = str(n)

    # 2, 3, 5, and 7 are not considered
    if len(n) == 1:
        return False

    for i in range(1, len(n) + 1):
        # Remove digits from right
        truncated_num = int(n[0:i])
        if not is_prime(truncated_num):
            return False

        # Remove digits from left            
        truncated_num = int(n[len(n) - i:len(n)])
        if not is_prime(truncated_num):
            return False
        
    return True

total = 0
trunc_primes_count = 0

n = 23
while trunc_primes_count != 11:
    # Skip multiples of 5 to prevent unnecessary computations
    if n % 5 == 0:
        n += 2
        continue
    
    if is_truncatable_prime(n):
        total += n
        trunc_primes_count += 1
    
    n += 2

print(total)