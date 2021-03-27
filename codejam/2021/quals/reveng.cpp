#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, c;
    scanf("%d %d", &n, &c);

    if (c < n - 1 || c > (n + 2) * (n - 1) / 2) {
        printf("IMPOSSIBLE\n");
        return;
    }

    int e = c - n + 1;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    for (int i = n - 2, d = 1; i >= 0; i--, d++) {
        if (e >= d) {
            reverse(arr + i, arr + i + d + 1);
            e -= d;
        } else {
            reverse(arr + i, arr + i + e + 1);
            break;
        }
    }
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
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