#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using vi = vector<long long>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vvvvi = vector<vvvi>;
using vp = vector<pair<long long, long long> >;
using vvp = vector<vp>;
using vb = vector<bool>;
using vvb = vector<vb>;
const long long inf = 1001001001001001001;
const long long INF = 1001001001;
long long mod;
const double eps = 1e-10;
template <class T>
bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
void out(T a) {
  cout << a << '\n';
}
template <class T>
void outp(T a) {
  cout << '(' << a.first << ',' << a.second << ')' << '\n';
}
template <class T>
void outvp(T v) {
  for (long long i = 0; i < (long long)(v.size()); i++)
    cout << '(' << v[i].first << ',' << v[i].second << ')';
  cout << '\n';
}
template <class T>
void outvvp(T v) {
  for (long long i = 0; i < (long long)(v.size()); i++) outvp(v[i]);
}
template <class T>
void outv(T v) {
  for (long long i = 0; i < (long long)(v.size()); i++) {
    if (i) cout << ' ';
    cout << v[i];
  }
  cout << '\n';
}
template <class T>
void outvv(T v) {
  for (long long i = 0; i < (long long)(v.size()); i++) outv(v[i]);
}
template <class T>
bool isin(T x, T l, T r) {
  return (l) <= (x) && (x) <= (r);
}
template <class T>
void yesno(T b) {
  if (b)
    out("yes");
  else
    out("no");
}
template <class T>
void YesNo(T b) {
  if (b)
    out("Yes");
  else
    out("No");
}
template <class T>
void YESNO(T b) {
  if (b)
    out("YES");
  else
    out("NO");
}
template <class T>
void outset(T s) {
  auto itr = s.begin();
  while (itr != s.end()) {
    if (itr != s.begin()) cout << ' ';
    cout << *itr;
    itr++;
  }
  cout << '\n';
}
void outs(long long a, long long b) {
  if (a >= inf - 100)
    out(b);
  else
    out(a);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long modpow(long long a, long long b) {
  long long res = 1;
  a %= mod;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long n, m, K;
  cin >> n >> m >> K >> mod;
  if (K >= 90) {
    out(0);
    return 0;
  };
  vvvi dp(n + 1, vvi(m + 1, vi(K + 1)));
  vvi modcom(n + 3, vi(n + 3));
  modcom[0][0] = 1;
  for (long long i = 0; i < (long long)(n + 2); i++)
    for (long long j = 0; j < (long long)(n + 2); j++) {
      modcom[i][j] %= mod;
      modcom[i + 1][j] += modcom[i][j];
      modcom[i + 1][j + 1] += modcom[i][j];
    }
  vi fac(n + 3);
  fac[0] = 1;
  for (long long i = 0; i < (long long)(n + 2); i++)
    fac[i + 1] = fac[i] * (i + 1) % mod;
  for (long long i = 0; i < (long long)(n + 1); i++) {
    for (int j = m; j >= 0; j--) {
      for (long long k = 0; k < (long long)(K + 1); k++) {
        if (i < k) continue;
        if (i == 0) {
          dp[i][j][k]++;
          continue;
        }
        if (j == m) {
          dp[i][j][k] = fac[i];
          continue;
        }
        if (j == m - 1) {
          if (k == 1) dp[i][j][k] = fac[i];
          continue;
        }
        for (long long t = 0; t < (long long)(i); t++)
          for (long long u = max(0ll, k + t - i - 1);
               u < (long long)(min(k + 1, t + 1)); u++)
            if (dp[t][j + 1][u] && dp[i - 1 - t][j + 1][k - u])
              dp[i][j][k] += dp[t][j + 1][u] * dp[i - 1 - t][j + 1][k - u] %
                             mod * modcom[i - 1][t] % mod;
        dp[i][j][k] %= mod;
      }
    }
  }
  out(dp[n][0][K]);
}
