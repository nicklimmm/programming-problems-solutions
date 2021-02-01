#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
#define PI 3.14159265358979
const int MOD = 1000000007;

// unordered_map<pair<int, int>, unsigned long long> dp;

long long recur(int m, int n, short int used, vector<vector<long long>> &dp) {
    if (dp[n][used] != -1) return dp[n][used];
    if (n < 0) return 0;
    if (n == 0) return 1;
    long long sum = 0;
    sum += recur(m, n - 1, 0, dp);
    if (!used && n >= m) {
        for (int i = m; i <= n; i++) {
            sum += recur(m, n - i, 1, dp);
        }   
    }
    dp[n][used] = sum;
    return sum;
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    // cout.setf(ios::fixed);

    vector<vector<long long>> dp(1, vector<long long> (2, -1));
    dp[0][0] = 1;
    dp[0][1] = 1;
    int n = 1;
    long long result;
    while (1) {
        if (dp.size() == n) dp.push_back({-1, -1});
        result = recur(50, n, 0, dp);
        if (result >= (long long) 1e6) {
            cout << n;
            break;
        }
        n++;
    }
    
    return 0;
}