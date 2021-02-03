#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
#define PI 3.14159265358979
const int MOD = 1000000007;


// https://projecteuler.net/problem=115

/* 
    This is similar to problem 114, but with added constraints and different approach.

    In p114, the red blocks has to be at least 3 units. In this problem, it has
    to be at least 50 units instead of 3. Which means that we can tweak some
    values in the function from p114.

    Since the question asks for the first n to exceed 1 mil, we solve this in
    a bottom-up manner (the dp table is built in that way by appending new values).

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
    if (!used && n >= 50) { // NOTE: here it is 50 instead of 3
        for (int i = 50; i <= n; i++) {
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

    // initialize dp table for bottom-up
    vector<vector<long long>> dp(1, vector<long long> (2, -1));

    int n = 1;
    ll result;
    while (1) {
        // increase the size of dp table
        dp.push_back({-1, -1});

        result = recur(n, 0, dp);
        if (result >= (ll) 1e6) {
            printf("%d\n", n);
            break;
        }
        n++;
    }
    
    return 0;
}