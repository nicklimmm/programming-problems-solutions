#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
#define PI 3.14159265358979
const int MOD = 1000000007;


// https://projecteuler.net/problem=114

// This is a tiling problem, which usually can be solved using dynamic programming

/* 
    Constraints:
    1. The red blocks must have a length of 3 or more units
    2. We cannot put 2 red blocks consecutively (have to be separated by at least 1 grey square)

    Idea:
    1. We need 2 dp states, which are 'n' (the number of spaces that are already filled) and 'used'
       (1 if we have placed a red block previously and 0 otherwise).
    2. Suppose it's 'n' units long.
       If we placed a grey square (1 unit). We just need to fill 
        the remaining 'n - 1' units and then set 'used' to 0.
       If 'used' is 0 and we want to place a red block of k units. We need
        to fill the remaining 'n - k' units and we set 'used' to 1.
        (For all possible k in [3, n]). We can also place a grey square
        in this condition.
       If 'used' is 1, then we can only place a grey squeare.
    3. Let recur(n, used) be a function such that,
                                                / sum(recur(n - k, 1)) for each k in [3, n]; when used = 0
            recur(n, used) = recur(n - 1, 0) + {
                                                \ 0; when used = 1
*/

ll recur(int n, bool used, vector<vector<ll>> &dp) {
    // retrieve calculated values
    if (dp[n][used] != -1) return dp[n][used];

    // base cases
    if (n < 0) return 0;
    if (n == 0) return 1;

    ll sum = 0;

    // placing grey squares
    sum += recur(n - 1, 0, dp);

    // placing red blocks
    if (!used && n >= 3) {
        for (int i = 3; i <= n; i++) {
            sum += recur(n - i, 1, dp);
        }   
    }

    // save calculated values
    dp[n][used] = sum;
    return sum;
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    // cout.setf(ios::fixed);

    // length of row
    int n = 50;

    // initialize dp table
    vector<vector<ll>> dp(n + 1, vector<long long> (2, -1));

    printf("%lld\n", recur(n, 0, dp));
    
    return 0;
}