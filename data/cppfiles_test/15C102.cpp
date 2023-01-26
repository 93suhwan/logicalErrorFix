#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using datas = pair<ll, ll>;
using ddatas = pair<long double, long double>;
using tdata = pair<ll, datas>;
using vec = vector<ll>;
using mat = vector<vec>;
using pvec = vector<datas>;
using pmat = vector<pvec>;
constexpr ll mod = 1000000007;
constexpr ll inf = 1LL << 60;
constexpr long double eps = 1e-9;
const long double PI = acosl(-1);
template <class T, class E>
ostream& operator<<(ostream& os, const pair<T, E>& p) {
  return os << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  bool f = false;
  for (auto& x : v) {
    if (f) os << ",";
    os << x;
    f = true;
  }
  os << "}";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "{";
  bool f = false;
  for (auto& x : v) {
    if (f) os << ",";
    os << x;
    f = true;
  }
  os << "}";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "{";
  bool f = false;
  for (auto& x : v) {
    if (f) os << ",";
    os << x;
    f = true;
  }
  os << "}";
  return os;
}
template <class T, class E>
ostream& operator<<(ostream& os, const map<T, E>& v) {
  os << "{";
  bool f = false;
  for (auto& x : v) {
    if (f) os << ",";
    os << x;
    f = true;
  }
  os << "}";
  return os;
}
template <class T>
inline bool chmax(T& a, const T b) {
  bool x = a < b;
  if (x) a = b;
  return x;
}
template <class T>
inline bool chmin(T& a, const T b) {
  bool x = a > b;
  if (x) a = b;
  return x;
}
inline void startupcpp(void) noexcept {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}
ll modinv(ll a, const ll m = mod) noexcept {
  ll b = m, u = 1, v = 0, t;
  while (b) {
    t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  return (u + m) % m;
}
ll moddevide(const ll a, const ll b) noexcept { return (a * modinv(b)) % mod; }
vec modncrlistp, modncrlistm;
ll modncr(const ll n, const ll r) noexcept {
  if (n < r) return 0;
  ll i, size = modncrlistp.size();
  if (size <= n) {
    modncrlistp.resize(n + 1);
    modncrlistm.resize(n + 1);
    if (!size) {
      modncrlistp[0] = modncrlistm[0] = 1;
      size++;
    }
    for (i = size; i < (ll)n + 1; ++i)
      modncrlistp[i] = modncrlistp[i - 1] * i % mod;
    modncrlistm[n] = modinv(modncrlistp[n]);
    for (i = n; i > size; --i) modncrlistm[i - 1] = modncrlistm[i] * i % mod;
  }
  return modncrlistp[n] * modncrlistm[r] % mod * modncrlistm[n - r] % mod;
}
ll modpow(ll a, ll n, const ll m = mod) {
  if (n < 0) return 0;
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return res;
}
constexpr ll gcd(const ll a, const ll b) noexcept {
  return (!b) ? abs(a) : (a % b == 0) ? abs(b) : gcd(b, a % b);
}
constexpr ll lcm(const ll a, const ll b) noexcept { return a / gcd(a, b) * b; }
ll N, K;
mat g;
deque<ll> dfs(ll now, ll par) {
  deque<ll> res;
  res.emplace_back(1);
  for (auto x : g[now]) {
    if (x == par) continue;
    auto p = dfs(x, now);
    p.emplace_front(0);
    if (p.size() > res.size()) swap(res, p);
    for (size_t i = 0; i < p.size(); ++i) res[i] += p[i];
  }
  return res;
}
ll solve(vec& v) {
  vec dp(K + 1, 0);
  dp[0] = 1;
  ll i;
  for (auto x : v) {
    for (i = K, --i; i >= (ll)0; --i) (dp[i + 1] += dp[i] * x) %= mod;
  }
  return dp[K];
}
int main() {
  startupcpp();
  int codeforces;
  cin >> codeforces;
  while (codeforces--) {
    ll i, j, a, b;
    cin >> N >> K;
    g.clear();
    g.resize(N);
    for (i = 1; i < (ll)N; ++i) {
      cin >> a >> b;
      --a;
      --b;
      g[a].emplace_back(b);
      g[b].emplace_back(a);
    }
    if (K == 2) {
      cout << N * (N - 1) / 2 << "\n";
      continue;
    }
    ll ans = 0;
    for (i = 0; i < (ll)N; ++i) {
      if (ll(g[i].size()) < K) continue;
      vector<deque<ll>> ch(g[i].size());
      for (j = 0; j < (ll)g[i].size(); ++j) ch[j] = dfs(g[i][j], i);
      for (j = 0; j < (ll)N; ++j) {
        vec res;
        for (auto& v : ch) {
          if (j >= ll(v.size())) continue;
          res.emplace_back(v[j]);
        }
        if (ll(res.size()) < K) break;
        ans += solve(res);
      }
    }
    cout << ans % mod << "\n";
  }
}
