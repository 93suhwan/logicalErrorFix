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

#define int ll
#define double ld

typedef pair<int, int> pii;
template <class T> using indexed_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int SIZE = 2e5, MOD = 1e9 + 7, INF = 2e9;
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


int n, a[SIZE], b[SIZE];

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    map<int, int> cnta, cntb;
    int ans = (n * (n - 1) * (n - 2)) / 6;

    for(int i = 0; i < n; i++) {
        if(i > 1) {
            int same_a = cnta[a[i]], same_b = cntb[b[i]];
            ans -= same_a * (i - same_a);
            ans -= same_b * (i - same_b - same_a);
        }

        cnta[a[i]]++;
        cntb[b[i]]++;
    }

    cout << ans;
}



signed main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
        cout << endl;
    }

    return 0;
}
