#include <bits/stdc++.h>
using namespace std;


int count(int a, int b) {
    return min(a - 1, b / 2 - 1) + min(b - 1, a / 2 - 1);
}

int query(int i, int j, char dir, vector<vector<pair<int, int>>> &pcom_r, vector<vector<pair<int, int>>> &pcom_c) {
    if (dir == 'n') {
        return pcom_c[i][j].first;
    } else if (dir == 'w') {
        return pcom_r[i][j].second - pcom_r[i][j].first + 1;
    } else if (dir == 's') {
        return pcom_c[i][j].second - pcom_c[i][j].first + 1;
    } else {
        return pcom_r[i][j].first;
    }
}

void solve() {

    map<char, pair<int, int>> dirm;
    vector<char> dir = {'n', 'w', 's', 'e'};
    dirm['n'] = {-1, 0};
    dirm['w'] = {0, 1};
    dirm['s'] = {1, 0};
    dirm['e'] = {0, -1};
    int r, c, ans = 0;
    scanf("%d %d", &r, &c);
    int arr[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    vector<vector<pair<int, int>>> precom_c(r, vector<pair<int, int>>(c)), precom_r(r, vector<pair<int, int>>(c));
    for (int j = 0; j < c; j++)  {
        int start = -1, end = -1, sum;
        for (int i = 0; i < r; i++) {
            if (arr[i][j]) {
                if (start == -1) {
                    start = i;
                    end = i;
                } else {
                    end++;
                }
            }
            else if (start != -1) {
                sum = end - start + 1;
                for (int i1 = start, csum = 1; i1 <= end; i1++, csum++) {
                    precom_c[i1][j] = {csum, sum};
                }
                start = -1;
                end = -1;
            }
        }
        if (start != -1) {
            sum = end - start + 1;
            for (int i1 = start, csum = 1; i1 <= end; i1++, csum++) {
                precom_c[i1][j] = {csum, sum};
            }
            start = -1;
            end = -1;
        }
    }

    for (int i = 0; i < r; i++)  {
        int start = -1, end = -1, sum;
        for (int j = 0; j < c; j++) {
            if (arr[i][j]) {
                if (start == -1) {
                    start = j;
                    end = j;
                } else {
                    end++;
                }
            }
            else if (start != -1) {
                sum = end - start + 1;
                for (int j1 = start, csum = 1; j1 <= end; j1++, csum++) {
                    precom_r[i][j1] = {csum, sum};
                }
                start = -1;
                end = -1;
            }
        }
        if (start != -1) {
            sum = end - start + 1;
            for (int j1 = start, csum = 1; j1 <= end; j1++, csum++) {
                precom_r[i][j1] = {csum, sum};
            }
            start = -1;
            end = -1;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!arr[i][j]) continue;
            for (int k = 0; k < 4; k++) {
                int di1 = dirm[dir[k]].first, di2 = dirm[dir[(k + 1) % 4]].first;
                int dj1 = dirm[dir[k]].second, dj2 = dirm[dir[(k + 1) % 4]].second;
                int i1 = i + di1, i2 = i + di2;
                int j1 = j + dj1, j2 = j + dj2;
                if (0 <= i1 && i1 <= r - 1 
                    && 0 <= j1 && j1 <= c - 1 
                    && 0 <= i2 && i2 <= r - 1 
                    && 0 <= j2 && j2 <= c - 1
                    && arr[i1][j1] && arr[i2][j2]) {
                        int l1 = query(i, j, dir[k], precom_r, precom_c), l2 = query(i, j, dir[(k + 1) % 4], precom_r, precom_c);
                        ans += count(l1, l2);
                }
            }
        }
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