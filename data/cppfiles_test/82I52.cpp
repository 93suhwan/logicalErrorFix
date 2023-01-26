///#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
///#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,popcnt,avx,avx2,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

/*
    zet:
        find_by_order(k): k-stat [k > 0]
        order_of_key(k) : {el < k}

    gp_hash_table<key, val, custom_hash>

    rope<T>:
        iterators: mutable_begin, ..
        methods  : erase, insert, substr, ..
*/

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define em_back emplace_back
#define sqrt(x) sqrt(abs(x))
#define makeunique(x) sort(all(x)), (x).erase(unique(all(x)), (x).end())

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T>
using zet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

mt19937 eng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5 + 4;
const int LGN = 19;

int n, k, q, a[N], b[N];
vector<int> c[N];
vector<ll> dp[N];

int logtab[N];
int xsp[N][LGN];

struct tab {
    vector<vector<pii>> sp;
    int len;

    tab() : len(0) {}

    void init(vector<int>& A) {
        len = sz(A);
        sp = vector<vector<pii>>(len, vector<pii>(LGN));
        for (int i = 0; i < sz(A); ++i) {
            sp[i][0].first = A[i];
            sp[i][0].second = i;
        }
        for (int j = 1; j < LGN; ++j) {
            for (int i = 0; i + (1 << j) - 1 < len; ++i) {
                pii L = sp[i][j - 1];
                pii R = sp[L.second][j - 1];
                sp[i][j] = min(L, R);
            }
        }
    }

    pii getmin(int l, int r) {
        int pw = logtab[r - l + 1];
        return min(sp[l][pw], sp[r - (1 << pw) + 1][pw]);
    }
};

tab tabs[N];

void prepare() {
    for (int i = 0; i < n; ++i) {
        xsp[i][0] = a[i];
    }
    for (int j = 1; j < LGN; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            xsp[i][j] = min(xsp[i][j - 1], xsp[i + (1 << (j - 1))][j - 1]);
        }
    }

    for (int i = 2; i < N; ++i) {
        logtab[i] = 1 + logtab[i >> 1];
    }

    int pw = logtab[k];
    for (int i = 0; i < k; ++i) {
        c[i].em_back(0);
    }
    for (int i = k; i < n; ++i) {
        b[i] = min(xsp[i - k][pw], xsp[i - (1 << pw) + 1][pw]);
        c[i % k].em_back(b[i]);
    }

    for (int mod = 0; mod < k; ++mod) {
        auto& X = c[mod];
        int len = sz(X);
        if (!len) {
            continue;
        }

        vector<int> to(len);
        vector<pii> st;
        for (int j = len - 1; j >= 0; --j) {
            while (sz(st) && st.back().first >= X[j]) {
                st.pop_back();
            }
            if (sz(st) == 0) {
                to[j] = len;
            } else {
                to[j] = st.back().second;
            }
            st.em_back(X[j], j);
        }

        dp[mod].resize(len);
        for (int i = len - 1; i >= 0; --i) {
            int j = to[i];
            if (j == len) {
                dp[mod][i] = ll(j - i) * X[i];
            } else {
                dp[mod][i] = ll(j - i) * X[i] + dp[mod][j];
            }
        }

        tabs[mod].init(X);
    }
}

void solve() {
    cin >> n >> q >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    prepare();

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int id = l % k;

        int t = (r - l) / k;
        int sl = (l + k) / k;
        int sr = (l + k * t) / k;

        ll ans = a[l];
        if (sl <= sr) {
            int p = tabs[id].getmin(sl, sr).second;
            ans += dp[id][sl] - dp[id][p] + ll(sr - p + 1) * c[id][p];
        }
        cout << ans << "\n";
    }
}

int main() {
#ifndef ONLY_HERE
    ///freopen("", "r", stdin);
    ///freopen("", "w", stdout);
#endif // ONLY_HERE
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    int z = 1;
    /// cin >> z;

    while (z--) {
        solve();
    }

    return 0;
}

