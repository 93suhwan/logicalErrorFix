#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
template <typename T1, typename T2>
inline void mine(T1 &x, const T2 &y) {
  if (y < x) x = y;
}
template <typename T1, typename T2>
inline void maxe(T1 &x, const T2 &y) {
  if (x < y) x = y;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &b) {
  for (const auto &k : b) os << k << ' ';
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &b) {
  for (auto &k : b) is >> k;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &b) {
  for (const auto &k : b) os << k << ' ';
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &b) {
  os << b.first << ' ' << b.second;
  return os;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long MOD = 1e9 + 7;
namespace md {
long long mod(long long n) {
  if (n <= -MOD || n >= MOD) n %= MOD;
  if (n < 0)
    return n + MOD;
  else
    return n;
}
long long add(long long a, long long b) {
  a += b;
  if (a >= MOD) return a - MOD;
  return a;
}
long long sub(long long a, long long b) {
  a -= b;
  if (a < 0) return a + MOD;
  return a;
}
long long mult(long long a, long long b) { return a * b % MOD; }
long long powmod(long long a, long long p) {
  if (p == 0) return 1;
  if (p & 1) return mult(a, powmod(a, p - 1));
  return powmod(mult(a, a), p / 2);
}
long long rev(long long a) { return powmod(a, MOD - 2); }
}  // namespace md
struct M {
  long long x;
  M(long long _x) { x = md::mod(_x); }
  M() { x = 0; }
  M operator+(M y) const { return M(md::add(x, y.x)); }
  M operator-(M y) const { return M(md::sub(x, y.x)); }
  M operator*(M y) const { return md::mult(x, y.x); }
  M operator/(M y) const { return md::mult(x, md::rev(y.x)); }
  M operator+(long long y) { return (*this) + M(y); }
  M operator-(long long y) { return (*this) - M(y); }
  M operator*(long long y) { return (*this) * M(y); }
  M operator/(long long y) { return (*this) / M(y); }
  M operator^(long long y) const { return M(x ^ y); }
  void operator+=(M y) { *this = *this + y; }
  void operator-=(M y) { *this = *this - y; }
  void operator*=(M y) { *this = *this * y; }
  void operator/=(M y) { *this = *this / y; }
  void operator+=(long long y) { *this = *this + y; }
  void operator-=(long long y) { *this = *this - y; }
  void operator*=(long long y) { *this = *this * y; }
  void operator/=(long long y) { *this = *this / y; }
  void operator^=(long long y) { *this = *this ^ y; }
  bool operator==(M y) const { return x == y.x; }
  bool operator<(M y) const { return x < y.x; }
};
M operator*(long long x, const M &y) { return y * x; }
M operator+(long long x, const M &y) { return y + x; }
M operator-(long long x, const M &y) { return M(x) - y; }
M operator/(long long x, const M &y) { return M(x) / y; }
ostream &operator<<(ostream &os, const M &a) {
  os << a.x;
  return os;
}
istream &operator>>(istream &is, M &a) {
  long long x;
  is >> x;
  a = M(x);
  return is;
}
const long long N = 1e5 + 10;
vector<long long> divs[N];
long long cntsamed[N];
long long cntx[N];
long long ddp[N];
bool was[N];
vector<long long> pog[N];
long long calc(vector<long long> &b) {
  vector<long long> c;
  c.reserve(b.size());
  for (auto &x : b) {
    if (cntx[x] == 0) c.push_back(x);
    ++cntx[x];
  }
  b.clear();
  for (auto &x : c) {
    for (auto &d : divs[x]) {
      cntsamed[d] += cntx[x];
    }
  }
  vector<long long> vd;
  for (auto &x : c) {
    for (auto &d : divs[x]) {
      if (!was[d]) {
        vd.push_back(d);
        was[d] = true;
      }
    }
  }
  sort(vd.begin(), vd.end());
  reverse(vd.begin(), vd.end());
  long long ans = 0;
  for (auto &d : vd) {
    ddp[d] = cntsamed[d] * (cntsamed[d] - 1) / 2;
    for (long long j : pog[d]) {
      ddp[d] -= ddp[j];
    }
    for (long long dd : divs[d]) {
      pog[dd].push_back(d);
    }
    pog[d].clear();
    ans += ddp[d] * d;
  }
  for (auto &d : vd) {
    ddp[d] = 0;
    cntsamed[d] = 0;
    was[d] = false;
  }
  for (auto &x : c) {
    cntx[x] = 0;
  }
  return ans;
}
void solve() {
  for (long long i = 1; i < N; ++i) {
    for (long long j = i; j < N; j += i) {
      divs[j].push_back(i);
    }
  }
  long long n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> b;
  b.reserve(n);
  cin >> a;
  M ans = 0;
  vector<M> dp(n + 1, 0);
  for (long long i = n; i >= 1; --i) {
    for (long long j = i; j <= n; j += i) {
      b.push_back(a[j - 1]);
    }
    dp[i] = calc(b);
    for (long long j = 2 * i; j <= n; j += i) {
      dp[i] -= dp[j];
    }
    ans += dp[i] * i;
  }
  ans *= 2;
  for (long long i = 0; i < n; ++i) {
    ans += a[i] * (i + 1);
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
}
