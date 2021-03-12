"""
https://projecteuler.net/problem=49

We can use brute force to search for the other prime
that exhibits this property.

To check if 2 numbers are permutations of one another,
first, we can change the number from int datatype to string,
then, we can split the string per character and put it into a set,
and lastly, check if both sets are equal.
"""

def create_prime_sieve(n):
    sieve = [True for i in range(n + 1)]
    sieve[0] = sieve[1] = False
    for i in range(4, len(sieve), 2):
        sieve[i] = False
    for d in range(3, len(sieve), 2):
        if sieve[d]:
            for i in range(d * 2, len(sieve), d):
                sieve[i] = False
    return sieve

def is_permutation(a, b):
    return set(str(a)) == set(str(b))

sieve = create_prime_sieve(9999)

# List to store the valid primes
valid = []
d = 3330

for x in range(1001, 10000, 2):
    # Breaks the loop when it exceeds 4 digits
    if x + 2 * d >= 10000:
        break

    # Check if the arithmetic sequence is all prime and permutation of one another
    if sieve[x] and sieve[x + d] and sieve[x + 2 * d] and is_permutation(x, x + d) and is_permutation(x, x + 2 * d):
        valid.append((x, x + d, x + 2 * d))

print(''.join(map(str, valid[1])))