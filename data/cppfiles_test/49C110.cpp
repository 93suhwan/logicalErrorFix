#include <bits/stdc++.h>
using namespace std;
const int N = 14;
const long long mod = 1e9 + 7;
int n;
long long a[N], w[N][N], f[1 << N];
long long ans;
long long qpow(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = r * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return r;
}
long long rev(long long x) { return qpow(x, mod - 2); }
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      w[i][j] = a[i] * rev(a[i] + a[j]) % mod;
    }
  for (int S = 1; S < (1 << n); ++S) {
    f[S] = 1;
    for (int T = (S - 1) & S; T != S; T = (T - 1) & S) {
      long long val = f[T];
      for (int i = 0; i < n; ++i)
        if (T & 1 << i) {
          for (int j = 0; j < n; ++j)
            if ((S ^ T) & 1 << j) {
              val *= w[i][j];
              val %= mod;
            }
        }
      f[S] = (f[S] - val + mod) % mod;
    }
    long long val = f[S];
    for (int i = 0; i < n; ++i)
      if (S & 1 << i) {
        for (int j = 0; j < n; ++j)
          if (!(S & 1 << j)) {
            val *= w[i][j];
            val %= mod;
          }
      }
    ans += val * __builtin_popcount(S) % mod;
  }
  cout << ans % mod << endl;
}
