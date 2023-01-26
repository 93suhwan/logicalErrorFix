#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T maxs(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T mins(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long MOD = 1000000007;
struct mod_int {
  long long val;
  mod_int(long long v = 0) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    val = v;
  }
  static long long mod_inv(long long a, long long m = MOD) {
    long long g = m, r = a, first = 0, second = 1;
    while (r != 0) {
      long long q = g / r;
      g %= r;
      swap(g, r);
      first -= q * second;
      swap(first, second);
    }
    return first < 0 ? first + m : first;
  }
  explicit operator long long() const { return val; }
  mod_int &operator+=(const mod_int &other) {
    val += other.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  mod_int &operator-=(const mod_int &other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  static unsigned fast_mod(uint64_t first, unsigned m = MOD) {
    return first % m;
    unsigned x_high = first >> 32, x_low = (unsigned)first;
    unsigned quot, rem;
    asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
    return rem;
  }
  mod_int &operator*=(const mod_int &other) {
    val = fast_mod((uint64_t)val * other.val);
    return *this;
  }
  mod_int &operator/=(const mod_int &other) { return *this *= other.inv(); }
  friend mod_int operator+(const mod_int &a, const mod_int &b) {
    return mod_int(a) += b;
  }
  friend mod_int operator-(const mod_int &a, const mod_int &b) {
    return mod_int(a) -= b;
  }
  friend mod_int operator*(const mod_int &a, const mod_int &b) {
    return mod_int(a) *= b;
  }
  friend mod_int operator/(const mod_int &a, const mod_int &b) {
    return mod_int(a) /= b;
  }
  mod_int &operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }
  mod_int &operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
  mod_int operator++(int32_t) {
    mod_int before = *this;
    ++*this;
    return before;
  }
  mod_int operator--(int32_t) {
    mod_int before = *this;
    --*this;
    return before;
  }
  mod_int operator-() const { return val == 0 ? 0 : MOD - val; }
  bool operator==(const mod_int &other) const { return val == other.val; }
  bool operator!=(const mod_int &other) const { return val != other.val; }
  mod_int inv() const { return mod_inv(val); }
  mod_int pow(long long p) const {
    assert(p >= 0);
    mod_int a = *this, result = 1;
    while (p > 0) {
      if (p & 1) result *= a;
      a *= a;
      p >>= 1;
    }
    return result;
  }
  friend ostream &operator<<(ostream &stream, const mod_int &m) {
    return stream << m.val;
  }
  friend istream &operator>>(istream &stream, mod_int &m) {
    return stream >> m.val;
  }
};
long long solve() {
  long long n, k;
  cin >> n >> k;
  vector<vector<long long>> g(n + 1);
  for (long long i = 0; i + 1 < n; i++) {
    long long a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  if (k == 2) {
    mod_int v = n;
    cout << v * (v - 1) / 2 << "\n";
    return 0;
  }
  function<void(long long, long long, long long, vector<long long> &)> dfs =
      [&](long long u, long long p, long long h, vector<long long> &d) {
        d[h]++;
        for (auto i : g[u]) {
          if (i != p) {
            dfs(i, u, h + 1, d);
          }
        }
      };
  mod_int ans = 0;
  auto solve = [&](long long r) {
    vector<vector<long long>> vals;
    for (auto i : g[r]) {
      vector<long long> d(n + 1);
      dfs(i, r, 1, d);
      vals.push_back(d);
    }
    for (long long d = 1; d <= n; d++) {
      vector<mod_int> dp(k + 1);
      dp[0] = 1;
      for (long long i = 0; i < vals.size(); i++) {
        vector<mod_int> new_dp(k + 1);
        for (long long j = 0; j <= k; j++) {
          new_dp[j] = dp[j];
          if (j >= 1) {
            new_dp[j] += dp[j - 1] * (vals[i][d]);
          }
        }
        swap(dp, new_dp);
      }
      ans += dp[k];
    }
  };
  for (long long i = 1; i <= n; i++) {
    solve(i);
  }
  cout << ans << "\n";
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
