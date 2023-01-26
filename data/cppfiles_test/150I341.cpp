#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Общий файл.
#include <ext/pb_ds/tree_policy.hpp> // Содержит класс tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2,fma,tune=native")

typedef long long ll;
typedef long double ld;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int int_fast32_t

mt19937 rnd(time(0));

const ll INF = (ll)(1e18);
const ll MOD = (ll)(1e9 + 7);  // 998244353; // 
const ld EPS = (ld)(1e-6);
const ld PI = acos(-1);

void fast_stream() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << fixed << setprecision(30);
}

typedef tree<
pair<pair<int, int>, int>,
null_type,
less<pair<pair<int, int>, int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = INF;
    for (ll cnt_ed = 0; cnt_ed < 3; ++cnt_ed) {
        for (ll cnt_dv = 0; cnt_dv < 3; ++cnt_dv) {
            bool flag = true;
            ll min_3 = 0;

            for (ll i = 0; i < n; ++i) {
                ll h = INF;

                for (ll j = 0; j <= cnt_ed; ++j) {
                    for (ll k = 0; k <= cnt_dv; ++k) {
                        ll now_x = a[i] - j - k * 2;

                        if (now_x % 3) continue;

                        h = min(h, now_x / 3);
                    }
                }

                if (h == INF) {
                    flag = false;
                    break;
                }

                min_3 = max(min_3, h);
            }

            if (flag) ans = min(ans, min_3 + cnt_ed + cnt_dv);
        }
    }

    cout << ans << '\n';
}

signed main() {
	// freopen("cutting.in", "r", stdin);
	// freopen("cutting.out", "w", stdout);
    fast_stream();
    
    int tests = 1;
    cin >> tests;
    while (tests--) {
        solve();
    }
}

/*

1 2 1 2 3 4 3 2

 . . .
......

005
*/  