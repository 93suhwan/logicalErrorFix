#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
// Make __builtin_popcount faster: https://codeforces.com/blog/entry/13134?#comment-736517
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

#define FOR(i, l, r) for(int i = l; i <= r; ++i)
#define FOD(i, r, l) for(int i = r; i >= l; --i)
#define fi first
#define se second
#define bit(x, k) (1ll&((x) >> (k)))
#define on(x, k) ((x)|(1ll << (k)))
#define off(x, k) ((x)&~(1ll << (k)))
#define sz(a) ((int)a.size())

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2 * 1e5 + 11;
struct Data {
    int a, b, m, id;
    int get() {
        return a + b - m;
    }
    int get2() {
        return a - max(0, m - b);
    }
    int get3() {
        return b - max(0, m - a);
    }
} c[maxn];
int t, n, ans;
pair<int, int> res[maxn];
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> n;
        FOR(i, 1, n) {
            cin >> c[i].a >> c[i].b >> c[i].m;
            c[i].id = i;
        }
        sort(c + 1, c + 1 + n, [](Data u, Data v) {
                return u.get() < v.get(); 
                });
        for(int i = 1; i <= n; i++) {
            vector<Data> tmp, _tmp;
            int j = i;
            while(c[j].get() == c[i].get() && j <= n) {
                tmp.push_back(c[j]);
                j++;
            } 
            sort(tmp.begin(), tmp.end(), [](auto u, auto v) {
                    return u.get2() < v.get2();
            });
            int minX = tmp[0].get2();
            ans++;
            for(auto &[a, b, m, id] : tmp) {
                if(a - minX <= m) {
                    res[id].fi = a - minX;
                    res[id].se = m - res[id].fi;
                    a = -1, b = -1;
                }
                else {
                    _tmp.push_back({a, b, m, id});
                }
            }
            tmp = _tmp;
            if(tmp.size()) {
                ans++;
                sort(tmp.begin(), tmp.end(), [](auto u, auto v) {
                        return u.get3() < v.get3();
                });
                int minY = tmp[0].get3();
                for(auto &[a, b, m, id] : tmp) {
                    res[id].se = b - minY;
                    res[id].fi = m - res[id].se;
                }
            }
            i = j - 1;
        }
        cout << ans << '\n';
        FOR(i, 1, n) {
            cout << res[i].fi << " " << res[i].se << '\n';
        }
    }

    return 0;
}
