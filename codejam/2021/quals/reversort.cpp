#include <bits/stdc++.h>
using namespace std;

int find_min(int s, int arr[], int n) {
    int pos = s, least = arr[s];
    for (int i = s; i < n; i++) {
        if (arr[i] < least) {
            pos = i;
            least = arr[i];
        }
    }
    return pos;
}


void solve() {
    int n, ans = 0;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int j = find_min(i, arr, n);
        ans += j - i + 1;
        reverse(arr + i, arr + j + 1);
    }
    printf("%d\n", ans);
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