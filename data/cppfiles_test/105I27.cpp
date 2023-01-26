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
pair<int, int> res[maxn];
struct Data {
    int a, b, m, id;
    int get() {
        return a + b - m;
    }
    void init() {
        if(b - m < 0) {
            res[id].fi = m - b;
            a -= res[id].fi; 
            m -= res[id].fi;
        }
        if(a - m < 0) {
            res[id].se = m - a;
            b -= res[id].se; 
            m -= res[id].se;
        }
    }
} c[maxn];
int t, n, ans;
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
            res[i] = {0, 0};
        }
        FOR(i, 1, n) c[i].init();
        sort(c + 1, c + 1 + n, [](Data u, Data v) {
                return u.get() < v.get(); 
        });
        for(int i = 1; i <= n; i++) {
            vector<Data> tmp;
            int j = i;
            while(c[j].get() == c[i].get() && j <= n) {
                tmp.push_back(c[j]);
                j++;
            } 
            sort(tmp.begin(), tmp.end(), [](auto u, auto v) {
                    return u.a < v.a;
            });
            int minX = tmp[0].a;
            ans++;
            for(auto &v : tmp) {
                auto [a, b, m, id] = v;
                if(v.a - m <= minX) {
                    res[id].fi += v.a - minX;
                    res[id].se += m - (v.a - minX);
                }
                else {
                    minX = v.a;
                    ans++;
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
