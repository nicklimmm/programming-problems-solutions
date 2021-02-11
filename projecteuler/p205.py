"""
https://projecteuler.net/problem=205

To solve this problem, we need to make use of a library function
to generate all possible dice rolls, which uses combination with
replacement.

Lets take a simpler example to illustrate further, note that the 
roll below is a combination (or multiset).

->  Suppose that Peter rolls {2, 2, 3, 3, 4, 4} (sum = 18) and
    Colin rolls {3, 3, 5, 6} (sum = 18).

    ^ This example will remain for the following descriptions.

Since the dice rolls also take the ordering into account, we need
to count the number of permutations possible for each dice roll using
permutations with repetition formula.

->  The number of occurences that Peter got that roll is,
        6! / 2! / 2! / 2! = 90
    and for Colin,
        4! / 2! / 1! / 2! = 6

Then, the number of occurences for each Peter's combination and
Colin's combination is the product of them.

-> The number of occurences that Peter and Colin got that set of roll is,
        90 * 6 = 540
    
Sum all the number of occurences such that the sum of the values that Peter got
is greater than the sum of Colin's, and let that sum be X.

Furthermore, let the total number of occurences that can happen be N.

Then the answer to the question is X / N (the probability) rounded to 7 decimal points.
"""


from itertools import combinations_with_replacement as comwr
from math import factorial

win = 0
matches = 0
peter = tuple(comwr((x for x in range(1, 5)), 9))
colin = tuple(comwr((x for x in range(1, 7)), 6))
for x in peter:
    for y in colin:
        x_denom = 1
        y_denom = 1
        for dice in set(x):
            x_denom *= factorial(x.count(dice))
        for dice in set(y):
            y_denom *= factorial(y.count(dice))
        occurences = factorial(9) / x_denom * factorial(6) / y_denom
        if sum(x) > sum(y):
            win += occurences
        matches += occurences


print(round(win / matches, 7))