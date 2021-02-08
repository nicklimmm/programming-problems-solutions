#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
#define PI 3.14159265358979
const int MOD = 1000000007;

/* 
https://projecteuler.net/problem=31

To solve this problem, I used dynamic programming.

Idea:
1. Suppose the target sum is n, then if we chose a coin whose value in pence is
   p, then we need to solve for target sum n - p.
2. For the next iteration, if we chose p previously, then we can only choose a coin
   whose value is less than or equal to p (<= p). This is because we don't need to
   count the permutations of it.
3. The base cases are 0 when target < 0 and 1 when target = 0.
*/

// memoization
map<pii, int> dp;

int solve(int target, int last_coin_index, vector<int> coins) {
    pii p = make_pair(target, last_coin_index);
    if (dp.count(p)) return dp[p];
    if (target < 0) return 0;
    if (target == 0) return 1;
    int total = 0;
    for (int i = last_coin_index; i < coins.size(); i++) {
        total += solve(target - coins[i], i, coins);
    }
    dp[p] = total;
    return total;
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    // cout.setf(ios::fixed);
    int target = 200;
    vector<int> coins = {200, 100, 50, 20, 10, 5, 2, 1};
    cout << solve(target, 0, coins) << endl;
    return 0;
}