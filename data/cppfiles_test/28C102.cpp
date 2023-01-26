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
struct unionfind {
 private:
  int maxN;
  vector<int> par, treesize;

 public:
  unionfind(int N) : maxN(N), par(N), treesize(N, 1) {
    for (int i = 0; i < maxN; ++i) par[i] = i;
  }
  int root(int x) {
    while (par[x] != x) {
      x = par[x] = par[par[x]];
    }
    return x;
  }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (treesize[x] > treesize[y]) swap(x, y);
    par[x] = y;
    treesize[y] += treesize[x];
    return true;
  }
  bool unite(pair<int, int> v) { return unite(v.first, v.second); }
  bool parcheck(int x, int y) { return root(x) == root(y); }
  bool parcheck(pair<int, int> v) { return parcheck(v.first, v.second); }
  int size(int x) { return treesize[root(x)]; }
  void clear() {
    treesize.assign(maxN, 1);
    for (int i = 0; i < maxN; ++i) par[i] = i;
  }
  vector<vector<int>> groups() {
    vector<vector<int>> res(maxN);
    for (int i = 0; i < maxN; ++i) res[root(i)].emplace_back(i);
    vector<vector<int>> res2;
    for (vector<int> x : res) {
      if (x.size()) res2.emplace_back(x);
    }
    return res2;
  }
};
ll N, M, K, H, W, A, B, C, D;
string s, t;
ll ans;
int main() {
  startupcpp();
  int codeforces;
  cin >> codeforces;
  while (codeforces--) {
    ll i, j;
    cin >> N >> M;
    vec p(N);
    map<ll, ll> mp;
    for (i = 0; i < (ll)N; ++i) {
      cin >> p[i];
      --p[i];
      mp[i - p[i] < 0 ? i - p[i] + N : i - p[i]]++;
    }
    vec ans;
    for (auto [val, cnt] : mp) {
      if (cnt < N - M * 2) continue;
      unionfind dsu(N);
      for (i = 0; i < (ll)N; ++i)
        dsu.unite(p[i], i >= val ? i - val : i - val + N);
      if (N - dsu.groups().size() <= M) ans.emplace_back(val);
    }
    cout << ans.size() << " ";
    do {
      bool f = 0;
      for (auto outi : ans) {
        cout << (f ? " " : "") << outi;
        f = 1;
      }
      cout << "\n";
    } while (0);
  }
}
