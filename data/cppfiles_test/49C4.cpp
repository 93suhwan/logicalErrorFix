#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  string sep;
  for (const auto &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename T, size_t size>
ostream &operator<<(ostream &os, const array<T, size> &arr) {
  os << '{';
  string sep;
  for (const auto &x : arr) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
void dbg_out() { cout << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cout << ' ' << H;
  dbg_out(T...);
}
const int N = 15, mod = 1e9 + 7, bit = 61;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}
template <const int &MOD>
struct _m_int {
  int val;
  _m_int(int64_t v = 0) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    val = v;
  }
  static int mod_inv(int a, int m = MOD) {
    int g = m, r = a, x = 0, y = 1;
    while (r != 0) {
      int q = g / r;
      g %= r;
      swap(g, r);
      x -= q * y;
      swap(x, y);
    }
    return x < 0 ? x + m : x;
  }
  explicit operator int() const { return val; }
  explicit operator int64_t() const { return val; }
  _m_int &operator+=(const _m_int &other) {
    val -= MOD - other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  _m_int &operator-=(const _m_int &other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
    return x % m;
    unsigned x_high = x >> 32, x_low = (unsigned)x;
    unsigned quot, rem;
    asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
    return rem;
  }
  _m_int &operator*=(const _m_int &other) {
    val = fast_mod((uint64_t)val * other.val);
    return *this;
  }
  _m_int &operator/=(const _m_int &other) { return *this *= other.inv(); }
  friend _m_int operator+(const _m_int &a, const _m_int &b) {
    return _m_int(a) += b;
  }
  friend _m_int operator-(const _m_int &a, const _m_int &b) {
    return _m_int(a) -= b;
  }
  friend _m_int operator*(const _m_int &a, const _m_int &b) {
    return _m_int(a) *= b;
  }
  friend _m_int operator/(const _m_int &a, const _m_int &b) {
    return _m_int(a) /= b;
  }
  _m_int &operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }
  _m_int &operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
  _m_int operator++(int) {
    _m_int before = *this;
    ++*this;
    return before;
  }
  _m_int operator--(int) {
    _m_int before = *this;
    --*this;
    return before;
  }
  _m_int operator-() const { return val == 0 ? 0 : MOD - val; }
  bool operator==(const _m_int &other) const { return val == other.val; }
  bool operator!=(const _m_int &other) const { return val != other.val; }
  bool operator<(const _m_int &other) const { return val < other.val; }
  bool operator<=(const _m_int &other) const { return val <= other.val; }
  bool operator>(const _m_int &other) const { return val > other.val; }
  bool operator>=(const _m_int &other) const { return val >= other.val; }
  _m_int inv() const { return mod_inv(val); }
  _m_int pow(int64_t p) const {
    if (p < 0) return inv().pow(-p);
    _m_int a = *this, result = 1;
    while (p > 0) {
      if (p & 1) {
        result *= a;
      }
      a *= a;
      p >>= 1;
    }
    return result;
  }
  friend ostream &operator<<(ostream &os, const _m_int &m) {
    return os << m.val;
  }
};
extern const int MOD = 1e9 + 7;
using mod_int = _m_int<MOD>;
mod_int dp[(1 << N)];
bool vis[(1 << N)];
mod_int prob[N][N];
int n, a[N];
mod_int solve(int mask) {
  if (__builtin_popcountll(mask) <= 1) {
    return 1;
  }
  if (__builtin_popcountll(mask) == 2) {
    return 0;
  }
  if (vis[mask]) {
    return dp[mask];
  }
  vis[mask] = 1;
  mod_int ans = 1;
  for (int submask = mask; submask; submask = (submask - 1) & mask) {
    if (submask == mask) {
      continue;
    }
    mod_int curr = solve(submask);
    for (int x = 0; x < n; x++) {
      if (!(submask >> x & 1)) {
        continue;
      }
      int loserMask = mask ^ submask;
      for (int y = 0; y < n; y++) {
        if (!(loserMask >> y & 1)) {
          continue;
        }
        curr *= prob[x][y];
      }
    }
    ans -= curr;
  }
  return dp[mask] = ans;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t = 1;
  for (long long tc = 1; tc <= t; tc++) {
    cin >> n;
    for (long long i = 0; i <= n - 1; i++) {
      cin >> a[i];
    }
    for (long long i = 0; i <= n - 1; i++) {
      for (long long j = 0; j <= n - 1; j++) {
        prob[i][j] = ((mod_int)a[i]) / (mod_int)(a[i] + a[j]);
      }
    }
    mod_int ans = 0;
    memset(vis, 0, sizeof(vis));
    for (int mask = 0; mask < (1 << n); mask++) {
      mod_int together = solve(mask);
      for (int i = 0; i < n; i++) {
        if (mask >> i & 1) {
          for (int j = 0; j < n; j++) {
            if (mask >> j & 1) {
              continue;
            }
            together *= prob[i][j];
          }
        }
      }
      mod_int curr = __builtin_popcountll(mask) * together;
      ans += curr;
    }
    cout << ans << endl;
  }
  return 0;
}
