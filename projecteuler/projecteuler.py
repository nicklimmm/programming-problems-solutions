from math import ceil, sqrt

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


def is_square(n):
    return ceil(sqrt(n)) ** 2 == n


def is_permutation(a, b):
    return set(str(a)) == set(str(b))


def is_power_of_2(n):
    return (n & (n - 1) == 0)
    

def create_sieve(n):
    sieve = [True for i in range(n + 1)]
    sieve[0] = sieve[1] = False
    for i in range(4, len(sieve), 2):
        sieve[i] = False
    for d in range(3, len(sieve), 2):
        if sieve[d]:
            for i in range(d * 2, len(sieve), d):
                sieve[i] = False
    return sieve


def create_prime_list(n):
    sieve = create_sieve(n)
    return [i for i in range(2, len(sieve)) if sieve[i]]


def create_prefix_sum(ls):
    prefix_sum = []
    cumulative_sum = 0
    for x in ls:
        cumulative_sum += x
        prefix_sum.append(cumulative_sum)
    return prefix_sum


def totient(n):
    result = 1
    d = 2
    k = 0
    while n != 1:
        while n % d == 0:
            k += 1
            n //= d
        if k != 0:
            result *= d ** (k - 1) * (d - 1)
        if d == 2:
            d -= 1
        d += 2
        k = 0
    return result


def prime_factorization(n):
    result = []

    k = 0
    while n % 2 == 0:
        if 2 not in result:
            result[2] = 0
        k += 1
        n //= 2

    if k != 0:
        result.append((2, k))
        k = 0

    d = 3
    while n != 1:
        k = 0
        while n % d == 0:
            k += 1
            n //= d

        if k != 0:
            result.append((d, k))
            k = 0

        d += 2
    return result