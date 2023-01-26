/*
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define eb emplace_back
#define vec vector

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
/*
#define int ll
#define double ld
*/
typedef pair<int, int> pii;
template <class T> using indexed_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7, INF = 2e9;
const ll INFLL = 1e18;

int binpow(int b, int e) {
    int res = 1;
    while(e) {
        if(e & 1) res = (1LL * res * b) % MOD;
        b = (1LL * b * b) % MOD;
        e >>= 1;
    }
    return res;
}

template<typename T> void umax(T& a, T b){ a = max(a, b); }
template<typename T> void umin(T& a, T b){ a = min(a, b); }
template<typename T> T ceildiv(T x, T y) { return (x + y - 1) / y; }


const int SIZE = 2e5 + 5;

int n, m, q, p[SIZE], h[SIZE];
vec<int> g[SIZE];

bool used[SIZE], fl[SIZE];

void dfs(int x) {
    used[x] = 1;
    for(auto i : g[x]) {
        if(!used[i]) {
            p[i] = x;
            h[i] = h[x] + 1;
            dfs(i);
        }
    }
}

vec<int> get_path(int u, int v) {
    if(h[u] < h[v]) {
        swap(u, v);
    }

    vec<int> pu(1, u + 1), pv(1, v + 1);
    while(h[u] > h[v]) {
        pu.pb(p[u] + 1);
        u = p[u];
        fl[u] ^= 1;
    }

    while(u != v) {
        pu.pb(p[u] + 1);
        pv.pb(p[v] + 1);
        fl[u] ^= 1;
        fl[v] ^= 1;
        u = p[u];
        v = p[v];
    }

    pv.pop_back();
    reverse(all(pv));
    for(auto i : pv) pu.pb(i);
    return pu;
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            dfs(i);
        }
    }

    vec<vec<int>> ans;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        ans.pb(get_path(u, v));
        if(ans.back()[0] != u + 1) {
            reverse(all(ans.back()));
        }
    }

    bool y = 1;

    for(int i = 0; i < n; i++) {
        if(fl[i]) y = 0;
    }

    if(y) {
        cout << "YES" << endl;
        for(auto &i : ans) {
            cout << i.size() << endl;
            for(auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "NO" << endl;
        int ans = 0;

        vec<int> vr(n); iota(all(vr), 0);
        sort(all(vr), [&](auto lhs, auto rhs) { return h[lhs] > h[rhs]; });
        for(auto i : vr) {
            int u = i;
            if(fl[u]) {
                ans++;
            }
            while(fl[u]) {
                fl[u] = 0;
                u = p[u];
            }
        }
        cout << ans;
    }

}



signed main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    //cin >> t;

    while(t--) {
        solve();
        cout << endl;
    }

    return 0;
}
