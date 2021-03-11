from math import sqrt, ceil

"""
https://projecteuler.net/problem=46

We can rewrite the conjecture in the form,

    n = p + 2 * c^2

where n is a odd composite number, p is a prime number,
and c is a positive integer. Note that p < n in order for
c to exist.

We can brute force this problem by iterating through all
possible n and p. We can find the value of c by rearranging
the equation into,

    c = sqrt((n - p) / 2).

If for a given n, we cannot find any primes p < n that makes
c a positive integer, then the answer is n.
"""

# Helper function to check if a number is a square number
def is_square(n):
    return ceil(sqrt(n)) ** 2 == n

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

# List of primes to prevent recalculations
primes = [3, 5, 7]

# Start the search from the 1st odd composite number
n = 9

while True:
    # Increment by 2 to make n an odd composite number
    while is_prime(n):
        n += 2
    
    # Add new primes p to the list that satisfies p < n
    for k in range(primes[-1] + 2, n, 2):
        if is_prime(k):
            primes.append(k)

    valid = False
    for p in primes:
        # Check if c is a positive integer
        if is_square((n - p) // 2):
            valid = True
            break

    if not valid:
        print(n)
        break

    n += 2
            