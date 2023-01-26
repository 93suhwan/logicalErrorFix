#include <bits/stdc++.h>
using namespace std;
inline long long gcd(long long a, long long b) {
  return b > 0 ? gcd(b, a % b) : a;
}
inline void YES() { cout << "YES\n"; }
inline void NO() { cout << "NO\n"; }
const long long mod = 1e9 + 7;
const long long maxn = 300;
long long rand_int(long long l, long long r) {
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<long long>(l, r)(gen);
}
long long quick(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * x) % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
long long inv(long long x) { return quick(x, mod - 2); }
long long fac[maxn], invfac[maxn], Inv[maxn];
void init() {
  Inv[1] = 1;
  for (long long i = 2; i < maxn; ++i)
    Inv[i] = (long long)(mod - mod / i) * Inv[mod % i] % mod;
  fac[0] = 1;
  for (long long i = 1; i < maxn; ++i) fac[i] = (fac[i - 1] * i) % mod;
  invfac[maxn - 1] = inv(fac[maxn - 1]);
  for (long long i = maxn - 2; i >= 0; --i)
    invfac[i] = (invfac[i + 1] * (i + 1)) % mod;
}
long long C(long long n, long long m) {
  if (n < m || m < 0) return 0;
  return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}
long long n, m;
long long es[100][100];
const long long lim = 40;
template <typename T>
void subset(long long k, long long n, T &&f) {
  long long t = (1 << k) - 1;
  while (t < 1 << n) {
    vector<long long> ans;
    ans.clear();
    for (long long i = 0; i < lim; i++)
      if ((1ll << i) & t) ans.push_back(i + 1);
    bool swi = 1;
    for (long long i = 0; i < ans.size(); i++)
      for (long long j = 0; j < ans.size(); j++) {
        if (i == j) continue;
        if (!es[ans[i]][ans[j]]) {
          swi = false;
          break;
        }
      }
    bool swi2 = 1;
    for (long long i = 0; i < ans.size(); i++)
      for (long long j = 0; j < ans.size(); j++) {
        if (i == j) continue;
        if (es[ans[i]][ans[j]]) {
          swi2 = false;
          break;
        }
      }
    if (swi || swi2) {
      for (auto &v : ans) cout << v << " ";
      cout << '\n';
      exit(0);
    }
    long long x = t & -t, y = t + x;
    t = ((t & ~y) / x >> 1) | y;
  }
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  cin >> n >> m;
  if (n <= lim) {
    for (long long i = 1; i <= m; i++) {
      long long u, v;
      cin >> u >> v;
      es[u][v] = es[v][u] = 1;
    }
    subset(5, n, std::cout);
    cout << -1 << '\n';
    return 0;
  } else {
    while (1) {
      vector<long long> ans;
      ans.clear();
      for (long long i = 1; i <= 5; i++) ans.push_back(rand_int(1, n));
      sort(ans.begin(), ans.end());
      ans.erase(unique(ans.begin(), ans.end()), ans.end());
      if (ans.size() != 5) continue;
      bool swi = 1;
      for (long long i = 0; i < ans.size(); i++)
        for (long long j = 0; j < ans.size(); j++) {
          if (i == j) continue;
          if (!es[ans[i]][ans[j]]) {
            swi = false;
            break;
          }
        }
      bool swi2 = 1;
      for (long long i = 0; i < ans.size(); i++)
        for (long long j = 0; j < ans.size(); j++) {
          if (i == j) continue;
          if (es[ans[i]][ans[j]]) {
            swi2 = false;
            break;
          }
        }
      if (swi || swi2) {
        for (auto &v : ans) cout << v << " ";
        cout << '\n';
        exit(0);
      }
    }
  }
  return 0;
}
