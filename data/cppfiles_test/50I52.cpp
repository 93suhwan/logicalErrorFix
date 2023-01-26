/*

Developed by Nizamov Aynur from Kazan city
Road To ROI

Season 2021-2022:
   school stage: 500/500 (1 th place)
     city stage: 350/500 (10 th place)
 regional stage: N/A
            ROI: N/A

   vk: @nizamovoff
   tg: @nizamovoff
 inst: @nizamovoff
  dis: @nizamoff #2443

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

// #pragma GCC optimize ("Ofast")
#pragma GCC target ("popcnt")

#ifndef Road_To_ROI
#endif

template<class T>
using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

template<class S, class T>
using ordered_map = tree<S, T, less<>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename T2>
inline void nmax(T &a, T2 b) {
    a = max(a, (T) b);
}

template<typename T, typename T2>
inline void nmin(T &a, T2 b) {
    a = min(a, (T) b);
}

#define ff first
#define ss second
#define pb emplace_back
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cerr << #x << " = " << x << '\n';
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

mt19937 rnd(time(NULL));
mt19937_64 rndll(time(NULL));

const int N = 5e5 + 10;
const int INF = 2e9 + 10;
const ll INFLL = 4e18 + 10;
const int MOD = 998244353;
const ld EPS = 1e-6;

struct Stack {
    int l, r;
    ll sm;
};

int n, a[N];
ll sm[N];
vector<Stack> st;

ll f(ll val) {
    val %= MOD;
    if (val < 0) val += MOD;
    return val;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    st.push_back({1, a[0], 1});
    sm[0] = f(a[0]);
    for (int i = 1; i < n; ++i) {
        while (!st.empty() && st.back().l > a[i])
            st.pop_back();

        sm[i] = 1;
        bool ok = 1;
        for (auto &s : st) {
            int &l = s.l, &r = s.r;
            ll &cur = s.sm;

            cur = f(sm[i - 1] - cur);
            if (r <= a[i]) {
                sm[i] = f(sm[i] * f(cur * (ll)(r - l + 1)));
            }
            else {
                ok = 0;
                st.push_back({l, a[i], cur});
                sm[i] = f(sm[i] * f(cur * (ll)(a[i] - l + 1)));
                swap(st.back(), st[sz(st) - 2]);
                st.pop_back();
            }
        }

        if (ok) {
            int l = 1;
            if (!st.empty()) l = st.back().r + 1;
            if (l <= a[i]) {
                st.push_back({l, a[i], sm[i - 1]});
                sm[i] = f(sm[i] + f(st.back().sm * (ll)(a[i] - l + 1)));
            }
        }
    }
    cout << sm[n - 1];
}

signed main() {
#ifdef Road_To_ROI
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // freopen("Road_To_ROI.in", "r", stdin);
    // freopen("Road_To_ROI.out", "w", stdout);
#endif
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) solve();
}