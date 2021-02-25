#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define pseq(a) trit(it, a) {cout << *it << ' ';} cout << '\n'
#define deb(x) cout << #x << "=" << x << '\n'
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << '\n'
#define cmpf(x, y) abs(x - y) < eps
#define eps 0.000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define sortseq(x) sort(x.begin(), x.end())
#define rsortseq(x) sort(x.rbegin(), x.rend())
#define trit(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define trseq(x, a) for (auto &x:a)
#define PI 3.1415926535897932384626
#define INF INFINITY
#define cbig(x) cout << setprecision(0) << x
typedef long long ll;
typedef long double ldbl;
typedef string str;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef set<int> seti;
typedef set<ll> setl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<int, vi> AdjList;
typedef queue<int> qi;
typedef queue<ll> ql;
typedef deque<int> dqi;
typedef deque<ll> dql;
typedef stack<int> sti;
typedef stack<ll> stl;
typedef multiset<int> msi;
typedef multiset<ll> msl;
typedef unordered_set<int> useti;
typedef unordered_set<ll> usetl;
typedef unordered_map<int, int> umapii;
typedef unordered_map<ll, ll> umapll;
typedef priority_queue<int> pq;
typedef priority_queue<int, vi, greater<int>> pqmin;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    // cout.setf(ios::fixed);
    int d, i, s, v, f;
    int b, e, l;
    int p;
    string buf;
    cin >> d >> i >> s >> v >> f;

    vector<vector<string>> itl(i);
    vector<int> min_l(i, INT32_MAX);

    for (int _ = 0; _ < s; _++) {
        cin >> b >> e >> buf >> l;
        itl[e].push_back(buf);
        min_l[e] = min(min_l[e], l);
    }

    for (int _ = 0; _ < v; _++) {
        cin >> p;
        for (int __ = 0; __ < p; __++) {
            cin >> buf;
        }
    }

    cout << i << endl;
    for (int k = 0; k < i; k++) {
        cout << k << endl;
        cout << (int) itl[k].size() << endl;
        for (auto s_name: itl[k]) {
            cout << s_name << ' ';
            // cout << min_l[k] - floor(min_l[k] / exp(1)) << endl;
            cout << 5 << endl;
        }
    }
    
    return 0;
}