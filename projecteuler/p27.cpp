#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
https://projecteuler.net/problem=27

My approach for this problem is to use brute force method,
since the search size is small (~10^6).

So we iterate through all possible values of a and b,
keep track the maximum number of primes, and
product of the coefficients, a and b.

Another optimization for this problem is to search b
in the range [2, 1000]. This is valid because for n = 0
(the starting point), the expression becomes

    0 * 0 + a * 0 + b = b.

When b < 2, the expression is not a prime for n = 0, regardless 
of the value of a. Hence, we can start the search from b = 2 to 1000.
*/

// Helper function to check if a number is prime in O(sqrt(n))
bool is_prime(ll n) {
    if (n == 2) return true;
    if (n < 2) return false;
    for (int d = 3; d * d <= n; d += 2) {
        if (n % d == 0) return false;
    }
    return true;
}

int main() {
    int max_primes = 0, ab_max = 0, n, prime_count;
    ll eval;

    for (int a = -999; a <= 999; a++) {
        for (int b = 2; b <= 1000; b++) {
            n = 0;
            while (1) {
                eval = n * n + a * n + b;
                if (!is_prime(eval)) break;
                n++;
            }
            if (n > max_primes) {
                max_primes = n;
                ab_max = a * b;
            }
        }
    }

    printf("%d\n", ab_max);
    return 0;

}