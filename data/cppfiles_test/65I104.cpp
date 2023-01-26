#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)name.size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(const T &t, const V &...v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long long N = 1e5 + 10;
const long long mod = 998244353;
long long n, m;
long long dp[55][N];
long long f[N];
long long g[N];
long long l[N], r[N];
long long l1[N], r1[N];
void solve() {
  cin >> n >> m;
  for (long long i = 0; i < (n); ++i) {
    cin >> l[i] >> r[i];
  }
  auto construct_f = [&](long long m_new) {
    memset((dp), 0, sizeof((dp)));
    dp[0][0] = 1;
    for (long long i = 1; i < (n + 1); ++i) {
      ;
      for (long long j = 0; j < (m_new + 1); ++j) {
        for (long long k = l1[i - 1]; k < (r1[i - 1] + 1); ++k) {
          if (j >= k) dp[i][j] += dp[i - 1][j - k];
          if (dp[i][j] >= mod) dp[i][j] -= mod;
        }
      }
    }
    long long res = 0;
    for (long long j = 0; j <= m_new; ++j) {
      res += dp[n][j];
    }
    return res % mod;
  };
  for (long long i = 1; i < (m + 1); ++i) {
    long long max_l = -1;
    for (long long j = 0; j < (n); ++j) {
      l1[j] = 1e9, r1[j] = -1;
      for (long long k = i; k <= m; k += i) {
        if (l[j] <= k && k <= r[j]) {
          l1[j] = min(l1[j], k);
          r1[j] = k;
        }
        max_l = max(max_l, l1[j]);
      }
    }
    if (max_l > 1e8) {
      f[i] = 0;
    } else {
      for (long long k = 0; k < (n); ++k) {
        l1[k] /= i, r1[k] /= i;
      }
      f[i] = construct_f(m / i);
    }
  }
  for (long long i = 0; i < n + 1; ++i) {
    for (long long j = 0; j <= m; ++j) {
      ;
    }
  }
  for (long long i = m; i > 0; --i) {
    ;
    for (long long j = 2 * i; j <= m; j += i) {
      ;
      f[i] -= f[j];
      ;
      if (f[i] < 0) f[i] += mod;
    }
  }
  for (long long i = 0; i <= m; ++i) {
    ;
  }
  cout << f[1] << "\n";
}
signed main() {
  setIO();
  long long t = 1;
  while (t--) solve();
  return 0;
}
