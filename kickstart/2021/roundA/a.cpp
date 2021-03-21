#include <bits/stdc++.h>
using namespace std;

char str[500000];

void solve() {
    int n, k, score = 0;
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) score++;
    }

    printf("%d\n", abs(k - score));
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    // cout.setf(ios::fixed);
    int T;
    scanf("%d", &T);
    for (int _ = 1; _ <= T; _++) {
        printf("Case #%d: ", _);
        solve();
    }
    
    
    return 0;
}