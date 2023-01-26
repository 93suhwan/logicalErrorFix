#pragma gcc optimize("Ofast,unroll-loops")
#pragma gcc target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native,avx2")

/*
 ⠄⠄⠄⢰⣧⣼⣯⠄⣸⣠⣶⣶⣦⣾⠄⠄⠄⠄⡀⠄⢀⣿⣿⠄⠄⠄⢸⡇⠄⠄
⠄⠄⠄⣾⣿⠿⠿⠶⠿⢿⣿⣿⣿⣿⣦⣤⣄⢀⡅⢠⣾⣛⡉⠄⠄⠄⠸⢀⣿⠄
⠄⠄⢀⡋⣡⣴⣶⣶⡀⠄⠄⠙⢿⣿⣿⣿⣿⣿⣴⣿⣿⣿⢃⣤⣄⣀⣥⣿⣿⠄
⠄⠄⢸⣇⠻⣿⣿⣿⣧⣀⢀⣠⡌⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⣿⣿⣿⠄
⠄⢀⢸⣿⣷⣤⣤⣤⣬⣙⣛⢿⣿⣿⣿⣿⣿⣿⡿⣿⣿⡍⠄⠄⢀⣤⣄⠉⠋⣰
⠄⣼⣖⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⢇⣿⣿⡷⠶⠶⢿⣿⣿⠇⢀⣤
⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣷⣶⣥⣴⣿⡗
⢀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠄
⢸⣿⣦⣌⣛⣻⣿⣿⣧⠙⠛⠛⡭⠅⠒⠦⠭⣭⡻⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠄
⠘⣿⣿⣿⣿⣿⣿⣿⣿⡆⠄⠄⠄⠄⠄⠄⠄⠄⠹⠈⢋⣽⣿⣿⣿⣿⣵⣾⠃⠄
⠄⠘⣿⣿⣿⣿⣿⣿⣿⣿⠄⣴⣿⣶⣄⠄⣴⣶⠄⢀⣾⣿⣿⣿⣿⣿⣿⠃⠄⠄
⠄⠄⠈⠻⣿⣿⣿⣿⣿⣿⡄⢻⣿⣿⣿⠄⣿⣿⡀⣾⣿⣿⣿⣿⣛⠛⠁⠄⠄⠄
⠄⠄⠄⠄⠈⠛⢿⣿⣿⣿⠁⠞⢿⣿⣿⡄⢿⣿⡇⣸⣿⣿⠿⠛⠁⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠉⠻⣿⣿⣾⣦⡙⠻⣷⣾⣿⠃⠿⠋⠁⠄⠄⠄⠄⠄⢀⣠⣴
⣿⣿⣿⣶⣶⣮⣥⣒⠲⢮⣝⡿⣿⣿⡆⣿⡿⠃⠄⠄⠄⠄⠄⠄⠄⣠⣴⣿⣿⣿
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef double db;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
#define all(x) (x).begin(), (x).end()
#define dbg(a) cout << #a << " = " << a << "\n";
#define dbg1(a) cout << #a << " = [ "; for (auto& _ : a) cout << _ << ' '; cout << "]" << "\n";
#define dbg2(a) cout << #a << " = [ "; for (auto& _ : a) cout << '(' << _.first << ' ' << _.second << ") "; cout << "]" << "\n";
mt19937 mt_rand(time(nullptr));

int test = 1;

ll binpow(ll a, ll b) {
    if (!b) return 1;
    if (b % 2) return binpow(a, b - 1) * a;
    ll cur = binpow(a, b / 2);
    return cur * cur;
}

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<set<pii>> g;
vector<vector<int>> already;
vector<int> used;

int CHECK = 1, id = 0;

void dfs(int u, int p, int color) {
    already[id].push_back(u);
    used[u] = color;
    for (auto v : g[u]) {
        if (!(v.first ^ p)) continue;
        if (!used[v.first]) {
            if (v.second) {
                dfs(v.first, u, color ^ 1);
            } else {
                dfs(v.first, u, color);
            }
        } else {
            if (v.second) {
                if (used[v.first] == used[u]) {
                    CHECK = 0;
                    return;
                }
            } else {
                if (used[v.first] != used[u]) {
                    CHECK = 0;
                    return;
                }
            }
        }

    }
}
void solve() {
    CHECK = 1;
    int n, m;
    cin >> n >> m;
    if (!m) {
        cout << n << "\n";
        return;
    }
    g.clear();
    used.clear();
    already.clear();
    already.resize(n);
    g.resize(n);
    used.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        string s;
        cin >> s;
        u--, v--;
        int flag = s[0] == 'i';
        g[u].insert({v, flag});
        g[v].insert({u, flag});
    }
    id = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, 0, 2);
            if (!CHECK) {
                cout << -1 << "\n";
                return;
            }
            id++;
        }
    }
    int ans = 0;
    for (auto i : already) {
        int f = 0, s = 0;
        for (auto j : i) {
            if (j == 2) f++;
            else s++;
        }
        ans += max(f, s);
    }
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    fastio();
    if (test) cin >> t;
    while (t--) { solve(); }
    return 0;
}