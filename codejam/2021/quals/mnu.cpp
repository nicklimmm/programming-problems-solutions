#include <bits/stdc++.h>
using namespace std;

char S[1010];

void solve() {
    int x, y, cost = 0;
    scanf("%d %d %s", &x, &y, S);

    // if (strlen(S) == 1) {
    // }

    // Compression
    string sr;
    sr.push_back(S[0]);
    for (int i = 1; i < strlen(S); i++) {
        if (S[i] == '?' && sr[sr.size() - 1] == '?') continue;
        else if (S[i] == sr[sr.size() - 1]) continue;
        else if (S[i] == 'C' && sr[sr.size() - 1] == 'J') {
            cost += y;
        } else if (S[i] == 'J' && sr[sr.size() - 1] == 'C') {
            cost += x;
        }
        sr.push_back(S[i]);
    }
    // for (auto x: sr) printf("%c", x);
    // printf("\n");

    if (sr.size() == 1) {
        printf("0\n");
        return;
    }

    // if (sr[0] == '?') {
    //     if (sr[1] == 'J' && x < 0) cost += x;
    //     else if (sr[1] == 'C' && y < 0) cost += y;
    // }

    for (int i = 1; i < sr.size() - 1; i++) {
        if (sr[i] != '?') continue;
        char l = sr[i - 1], r = sr[i + 1];
        if (l != r) {
            // if (x + y < 0) {

            // }
            if (l == 'J') cost += y;
            else cost += x;
        }
    }
    printf("%d\n", cost);
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