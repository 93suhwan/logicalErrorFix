#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 1e9 + 7;
double eps = 1e-12;
long long mpow(long long a, long long b) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long t1 = mpow(a, b / 2);
  t1 *= t1;
  t1 %= MOD;
  if (b % 2) t1 *= a;
  t1 %= MOD;
  return t1;
}
long long mpow(long long a, long long b, long long p) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long t1 = mpow(a, b / 2, p);
  t1 *= t1;
  t1 %= p;
  if (b % 2) t1 *= a;
  t1 %= p;
  return t1;
}
long long modinverse(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
long long range(long long l, long long r) { return l + mt() % (r - l + 1); }
long long rev(long long v) { return mpow(v, MOD - 2); }
long long nc2(long long n) { return (n * (n - 1)) / 2; }
bool possible(char c1, char c2, char t1, char t2) {
  if (c1 != '?' && c1 != t1) return false;
  if (c2 != '?' && c2 != t2) return false;
  return true;
}
void solve() {
  long long n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  long long m = 2 * n + 1;
  long long pr[n][m], suf[n][m];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) pr[i][j] = suf[i][j] = 0;
  pr[0][n] = suf[n - 1][n] = 1;
  for (long long i = 0; i < n - 1; i++) {
    vector<long long> c(3, 0);
    if (i % 2) {
      if (possible(s[i], t[i], '0', '0')) c[1]++;
      if (possible(s[i], t[i], '0', '1')) c[0]++;
      if (possible(s[i], t[i], '1', '0')) c[2]++;
      if (possible(s[i], t[i], '1', '1')) c[1]++;
    } else {
      if (possible(s[i], t[i], '0', '0')) c[1]++;
      if (possible(s[i], t[i], '0', '1')) c[2]++;
      if (possible(s[i], t[i], '1', '0')) c[0]++;
      if (possible(s[i], t[i], '1', '1')) c[1]++;
    }
    for (long long j = 0; j < m; j++) {
      if (j) pr[i + 1][j - 1] += c[0] * pr[i][j];
      pr[i + 1][j] += c[1] * pr[i][j];
      if (j + 1 < m) pr[i + 1][j + 1] += c[2] * pr[i][j];
    }
    for (long long j = 0; j < m; j++) pr[i + 1][j] %= MOD;
  }
  for (long long i = n - 1; i >= 1; i--) {
    vector<long long> c(3, 0);
    if (i % 2) {
      if (possible(s[i], t[i], '0', '0')) c[1]++;
      if (possible(s[i], t[i], '0', '1')) c[0]++;
      if (possible(s[i], t[i], '1', '0')) c[2]++;
      if (possible(s[i], t[i], '1', '1')) c[1]++;
    } else {
      if (possible(s[i], t[i], '0', '0')) c[1]++;
      if (possible(s[i], t[i], '0', '1')) c[2]++;
      if (possible(s[i], t[i], '1', '0')) c[0]++;
      if (possible(s[i], t[i], '1', '1')) c[1]++;
    }
    for (long long j = 0; j < m; j++) {
      if (j) suf[i - 1][j - 1] += c[0] * suf[i][j];
      suf[i - 1][j] += c[1] * suf[i][j];
      if (j + 1 < m) suf[i - 1][j + 1] += c[2] * suf[i][j];
    }
    for (long long j = 0; j < m; j++) suf[i - 1][j] %= MOD;
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (i % 2) {
      if (possible(s[i], t[i], '0', '1')) {
        for (long long j = -n + 1; j < n; j++) {
          if (j > 0)
            ans += i * (pr[i][n + j] * suf[i][n + 1 - j]) % MOD;
          else
            ans -= i * (pr[i][n + j] * suf[i][n + 1 - j]) % MOD;
          ans %= MOD;
        }
      }
      if (possible(s[i], t[i], '1', '0')) {
        for (long long j = -n + 1; j < n; j++) {
          if (j < 0)
            ans += i * (pr[i][n + j] * suf[i][n - 1 - j]) % MOD;
          else
            ans -= i * (pr[i][n + j] * suf[i][n - 1 - j]) % MOD;
          ans %= MOD;
        }
      }
    } else {
      if (possible(s[i], t[i], '0', '1')) {
        for (long long j = -n + 1; j < n; j++) {
          if (j < 0)
            ans += i * (pr[i][n + j] * suf[i][n - 1 - j]) % MOD;
          else
            ans -= i * (pr[i][n + j] * suf[i][n - 1 - j]) % MOD;
          ans %= MOD;
        }
      }
      if (possible(s[i], t[i], '1', '0')) {
        for (long long j = -n + 1; j < n; j++) {
          if (j > 0)
            ans += i * (pr[i][n + j] * suf[i][n + 1 - j]) % MOD;
          else
            ans -= i * (pr[i][n + j] * suf[i][n + 1 - j]) % MOD;
          ans %= MOD;
        }
      }
    }
  }
  if (ans < 0) ans += MOD;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
