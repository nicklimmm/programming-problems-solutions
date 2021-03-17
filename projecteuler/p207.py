"""
https://projecteuler.net/problem=207

We can rearrange 4^t = 2^t + k into,

    (2^t)^2 - (2^t) - k = 0.

Solving the above equation, we get

    2^t = (1 +  sqrt(1 + 4k)) / 2    ...(1)
                or
    2^t = (1 - sqrt(1 + 4k)) / 2

We are only using the first solution, 
as the second solution will result in
no real solution.

In order for 2^t to be an integer, sqrt(1 + 4k)
has to be an odd number. Suppose that

    sqrt(1 + 4k) = 2j + 1           ...(2)
    where j is an integer

By squaring both sides of equation (2), we then obtain

    1 + 4k = 4j^2 + 4j + 1
    k = j * (j + 1)

Hence, we can conclude that in order for 2^t to
be an integer, k must be in the form j * (j + 1).

For t to be an integer, the RHS of equation (1) has
to be a power of 2. From equation (2), we can simplify
equation (1) into

    2^t = (1 + 2j + 1) / 2
        = (2j + 2) / 2
    2^t = j + 1

Hence, to be perfect, j + 1 must be a power of 2.
"""

# Helper function to check if a number is a power of 2
def is_power_of_2(n):
    return (n & (n - 1) == 0)

# a -> numerator, b -> denominator
a = 0
b = 0

# j -> integer for defining k from equation (2)
# m -> keep track current m
j = 1
m = 1
while True:
    k = j * (j + 1)
    p = j + 1

    j += 1
    b += 1

    m = k

    if is_power_of_2(p):
        a += 1
        
    if (a / b) < (1 / 12345) and a != 0:
        print(m)
        break