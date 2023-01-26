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
ll K;
unordered_map<ll, tuple<ll, ll, ll>> memo;
tuple<ll, ll, ll> dp[61];
tuple<ll, ll, ll> getval(ll id, ll frag) {
  if (memo.find(id) != memo.end()) return memo[id];
  int cnt = 0;
  while (~id >> (K - cnt) & 1) ++cnt;
  assert(cnt);
  auto& [a, b, c] = memo[id];
  if (cnt == 1) {
    if (frag == 7) return {2, 2, 2};
    if (frag & 1) a = 1;
    if (frag & 2) b = 1;
    if (frag & 4) c = 1;
    return {a, b, c};
  }
  auto [al, bl, cl] =
      (memo.find(id * 2) != memo.end() ? memo[id * 2] : dp[cnt - 1]);
  auto [ar, br, cr] =
      (memo.find(id * 2 + 1) != memo.end() ? memo[id * 2 + 1] : dp[cnt - 1]);
  if (frag & 1) a = (bl + cl) * (br + cr) * (2 - (frag == 1)) % mod;
  if (frag & 2) b = (cl + al) * (cr + ar) * (2 - (frag == 2)) % mod;
  if (frag & 4) c = (al + bl) * (ar + br) * (2 - (frag == 4)) % mod;
  return {a, b, c};
}
ll N;
int main() {
  startupcpp();
  ll i, j;
  cin >> K >> N;
  dp[1] = {2, 2, 2};
  for (i = 1; i < (ll)K; ++i) {
    ll x = get<0>(dp[i]);
    ll y = x * x * 8 % mod;
    dp[i + 1] = {y, y, y};
    (void(0));
  }
  pvec v;
  while (N--) {
    ll id;
    string s;
    cin >> id >> s;
    ll f = (s[0] == 'w' || s[0] == 'y') | (s[0] == 'g' || s[0] == 'b') << 1 |
           (s[0] == 'r' || s[0] == 'o') << 2;
    v.emplace_back(id, f);
    while (id /= 2) v.emplace_back(id, 7);
  }
  sort((v).begin(), (v).end()),
      (v).erase(unique((v).begin(), (v).end()), (v).end());
  for (i = 1; i < (ll)v.size(); ++i)
    if (v[i - 1].first == v[i].first) {
      if (v[i].second == 7)
        v[i].second = v[i - 1].second;
      else {
        cout << 0 << "\n";
        return 0;
      }
    }
  reverse((v).begin(), (v).end());
  for (auto [id, f] : v) {
    auto [r, g, b] = getval(id, f);
    (void(0));
  }
  auto [ans1, ans2, ans3] = getval(1, 7);
  cout << (ans1 + ans2 + ans3) % mod << "\n";
}
