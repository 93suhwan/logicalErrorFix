#include <bits/stdc++.h>
#include <bits/extc++.h>

#define sz(v) int (v.size())
#define ff first
#define ss second
#define pb push_back
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int MOD = 1000000009;
mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());

double GetTime() { return clock() / (double) CLOCKS_PER_SEC; };
/// Actual code starts here
int n, k;
const int N = 2005;
int dp[N][N], TT = 1;
int used[N][N];
vector<pair<int, int>> g[N];
int v[N];

int go(int p, int del, int ri, int tt) {
    if (p == n) return 0;
    if (used[p][del] == tt) return dp[p][del];
    used[p][del] = tt;
    int res = go(p + 1, del, ri, tt) + (p + del < n && v[p + del] == p);
    for (auto i : g[p])
        if (i.ss >= del && i.ss <= ri)
            res = max(res, go(i.ff, i.ss, ri, tt) + 1);
    dp[p][del] = res;
    return res;
}



bool check(int cnt) {
    TT++;
    int res = go(0, 0, cnt, TT);
    return res >= k;
}

void solve() {
    cin >> n >> k;
    for(int i = 0;i <= n;i++) {
        g[i].clear();
        v[i] = MOD;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
    }
    for (int i = 0; i < n; i++)
        if(i >= v[i] && i != v[i])
            g[v[i]].pb({i, i - v[i]});
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (check(c)) r = c;
        else l = c;
    }
    while (r > 0 && !check(r)) r--;
    if (r == 0) r = -1;
    cout << r << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
}
