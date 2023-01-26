#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
template <class T, class U>
inline bool chmax(T &a, U b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T, class U>
inline bool chmin(T &a, U b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
constexpr int INF = 1000000000;
constexpr ll llINF = 3000000000000000000;
constexpr int mod = 1000000007;
constexpr double eps = 1e-10;
vector<int> prime_list(int n) {
    vector<int> v(n + 1), res;
    for (int i = n; i >= 2; i--) {
        for (int j = i; j <= n; j += i) v[j] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (v[i] == i) res.push_back(i);
    }
    return res;
}
vector<int> next_divisor(int n) {
    vector<int> v(n + 1);
    for (int i = n; i >= 2; i--) {
        for (int j = i; j <= n; j += i) v[j] = i;
    }
    return v;
}
ll modpow(ll a, ll b, ll m = mod) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        b >>= 1;
    }
    return res;
}
vector<ll> inv, fact, factinv;
void init_fact(int n) {
    inv.resize(n + 1);
    fact.resize(n + 1);
    factinv.resize(n + 1);
    inv[0] = 0;
    inv[1] = 1;
    fact[0] = 1;
    factinv[0] = 1;
    for (ll i = 1; i <= n; i++) {
        if (i >= 2) inv[i] = mod - ((mod / i) * inv[mod % i] % mod);
        fact[i] = (fact[i - 1] * i) % mod;
        factinv[i] = factinv[i - 1] * inv[i] % mod;
    }
}
ll modinv(ll a, ll m = mod) {
    // gcd(a,m) must be 1
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
ll comb(int a, int b) {
    if (a < b || a < 0 || b < 0) return 0;
    return fact[a] * factinv[a - b] % mod * factinv[b] % mod;
}
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> k(q);
    vector<int> ans(q);
    vector<pair<int, int>> v;
    vector<ll> sum(n + m + 1), cnt(n + m + 1);
    ll res = 0;
    rep(i, n) {
        int x;
        cin >> x;
        res += x;
        v.push_back({x, 1});
    }
    rep(i, m) {
        int x;
        cin >> x;
        v.push_back({x, 0});
    }
    sort(all(v));
    set<int> st;
    st.insert(0);
    rep(i, n + m) {
        st.insert(i + 1);
        sum[i + 1] = sum[i] + v[i].first;
        cnt[i + 1] = cnt[i] + (v[i].second);
    }
    vector<pair<int, int>> bs;
    rep(i, n + m - 1) { bs.push_back({v[i + 1].first - v[i].first, i + 1}); }
    sort(all(bs), greater<>());
    rep(i, q) {
        cin >> k[i].first;
        k[i].second = i;
    }
    sort(all(k));
    for (auto [d, index] : k) {
        while (!bs.empty() && bs.back().first <= d) {
            int p = bs.back().second;
            bs.pop_back();
            auto it = st.find(p);
            it--;
            int l = *it;
            it++;
            it++;
            int r = *it;
            it--;
            st.erase(it);
            //[l,p),[p,r) -> [l,r)
            res -= sum[p] - sum[p - (cnt[p] - cnt[l])];
            res -= sum[r] - sum[r - (cnt[r] - cnt[p])];
            res += sum[r] - sum[r - (cnt[r] - cnt[l])];
        }
        ans[index] = res;
    }
    rep(i, q) cout << ans[i] << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    /*int t;
    cin >> t;
    while (t--)*/
    solve();
}