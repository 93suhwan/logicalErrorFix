// Problem: D. New Year's Problem
// Contest: Codeforces - Codeforces Round #762 (Div. 3)
// URL: https://codeforces.com/contest/1619/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

#define dbg(x...) \
do { \
cout << #x << " -> "; \
err(x); \
} while (0)

void err() {
    cout << endl;
}

template<class T, class... Ts>
void err(T arg, Ts &... args) {
    cout << arg << ' ';
    err(args...);
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __int128 i128;
const int N = 2e5 + 10;
const ll mod = 1e9 + 7;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

ll rng(ll l, ll r) {
    uniform_int_distribution<ll> uni(l, r);
    return uni(mt);
}

vector<pair<int, int>> p[N];
int cnt[N];
int ans[N];
int n, m;

void solve(int tCase) {
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) ans[i] = 0;
    for (int i = 1; i <= m; ++i) {
        p[i].resize(n + 1);
        cnt[i] = 0;
        for (int j = 1; j <= n; ++j) {
            cin >> p[i][j].first;
            p[i][j].second = j;
        }
    }
    int mi = 1e9;
    for (int j = 1; j <= n; ++j) {
        int mx = 0;
        for (int i = 1; i <= m; ++i) {
            mx = max(mx, p[i][j].first);
        }
        mi = min(mi, mx);
        ans[j] = mx;
        for (int i = 1; i <= m; ++i) {
            if (p[i][j].first == mx) cnt[i]++;
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (cnt[i] > 1) {
            cout << mi << '\n';
            return;
        }
    }
    int idx = 1;
    for (int i = 2; i <= m; ++i) {
        sort(p[i].begin(), p[i].end(), greater<>());
        if (p[i][1].first > p[idx][1].first) {
            idx = i;
        }
    }
    ans[p[idx][0].second] = p[idx][0].first;
    ans[p[idx][1].second] = p[idx][1].first;
    mi = 1e9;
    for (int i = 1; i <= n; ++i) {
        mi = min(mi, ans[i]);
    }
    cout << mi << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        solve(t);
    }
    return 0;
}