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
  if (n < r || r < 0) return 0;
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
ll N, M, K, H, W, A, B, C, D;
string s, t;
ll ans;
int main() {
  startupcpp();
  int codeforces;
  cin >> codeforces;
  while (codeforces--) {
    ll i, j = 0;
    cin >> N;
    vec v(N);
    for (i = 0; i < (ll)N; ++i) {
      cin >> v[i];
      j |= 1 << (v[i] % 3);
    }
    sort((v).begin(), (v).end()),
        (v).erase(unique((v).begin(), (v).end()), (v).end());
    if (__builtin_popcountll(j) == 1)
      cout << (v.back() + 2) / 3 << "\n";
    else if (j == 3 || j == 5)
      cout << v.back() / 3 + 1 << "\n";
    else if (v.back() % 3 != 1 || v[0] == 1 ||
             count((v).begin(), (v).end(), v.back() - 1))
      cout << (v.back() + 2) / 3 + 1 << "\n";
    else
      cout << (v.back() + 2) / 3 << "\n";
  }
}
