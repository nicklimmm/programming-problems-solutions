"""
https://projecteuler.net/problem=120

First of all, let's simplify the expression into several cases.

    Case 1: n is odd

                (a-1)^n = C(n, 0) * a^n - C(n, 1) * a^(n-1) + C(n, 2) * a^(n-2) - ... + C(n, n-1) * a - C(n, n)
                (a+1)^n = C(n, 0) * a^n + C(n, 1) * a^(n-1) + C(n, 2) * a^(n-2) - ... + C(n, n-1) * a + C(n, n)                +
      ---------------------------------------------------------------------------------------------------------------------------
      (a-1)^n + (a+1)^n = 2 * C(n, 0) * a^n + 2 * C(n, 2) * a^(n-2) + ... + 2 * C(n, n-1) * a
                          <--------------------------------------------->
                                these terms are divisible by a^2

        Then,
            ((a-1)^n + (a+1)^n) mod a^2 = 2 * C(n, n-1) * a
                                        = 2 * n * a

    
    Case 2: n is even

                (a-1)^n = C(n, 0) * a^n - C(n, 1) * a^(n-1) + C(n, 2) * a^(n-2) - ... - C(n, n-1) * a + C(n, n)
                (a+1)^n = C(n, 0) * a^n + C(n, 1) * a^(n-1) + C(n, 2) * a^(n-2) - ... + C(n, n-1) * a + C(n, n)                +
      ---------------------------------------------------------------------------------------------------------------------------
      (a-1)^n + (a+1)^n = 2 * C(n, 0) * a^n + 2 * C(n, 2) * a^(n-2) + ... + 2 * C(n, n)
                          <--------------------------------------------->
                                these terms are divisible by a^2

        Then,
            ((a-1)^n + (a+1)^n) mod a^2 = 2 * C(n, n)
                                        = 2


For each a, we need to iterate the value of n from 1 until 2a - 1, because of the nature of modulo operator on odd numbers.

Then we sum up all of the rmax for every a.
"""

ans = 0
for a in range(3, 1001):
    rmax = 2
    for n in range(1, 2*a, 2):
        rmax = max(rmax, (2 * n * a) % (a * a))
    ans += rmax

print(ans)