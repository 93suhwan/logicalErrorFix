#include <bits/stdc++.h>
using namespace std;
long long ksm(long long x, long long y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % 1000000007)
    if (y & 1) ret = ret * x % 1000000007;
  return ret;
}
long long dp[1 << 15], ans, F[1 << 15], a[15], ny[15][15], sz[1 << 15],
    f[1 << 15], n, i, j;
long long cal(int st1, int st2) {
  long long ret = 1;
  int i, j;
  for (i = 0; i < n; ++i) {
    if ((st1 >> i) & 1) {
      for (j = 0; j < n; ++j) {
        if ((st2 >> j) & 1) {
          (ret *= ny[i][j]) %= 1000000007;
        }
      }
    }
  }
  cout << st1 << " " << st2 << " " << ret << ' ' << F[st1] << " " << F[st2]
       << "\n";
  return ret * (ksm(F[st1], sz[st2]) % 1000000007 + ksm(F[st2], sz[st1])) %
         1000000007;
}
long long CAL(int st1, int st2) {
  long long ret = 1;
  int i, j;
  for (i = 0; i < n; ++i) {
    if ((st1 >> i) & 1) {
      for (j = 0; j < n; ++j) {
        if ((st2 >> j) & 1) {
          (ret *= ny[i][j]) %= 1000000007;
        }
      }
    }
  }
  return ret * ksm(F[st1], sz[st2]) % 1000000007;
}
int mx, x, f1;
signed main() {
  cin >> n;
  for (i = 0; i < n; ++i) cin >> a[i];
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      ny[i][j] = ksm(a[i] + a[j], 1000000007 - 2);
    }
  }
  for (i = 0; i < (1 << n); ++i) {
    F[i] = 1;
    for (j = 0; j < n; ++j) {
      if ((i >> j) & 1) (F[i] *= a[j]) %= 1000000007, ++sz[i];
    }
  }
  mx = (1 << n) - 1;
  for (i = 1; i < (1 << n); ++i) {
    f[i] = 1;
    x = (i & -i);
    for (j = i & (i - 1); j; j = (j - 1) & i)
      (f[i] -= f[j] * CAL(j, i ^ j)) %= 1000000007;
  }
  dp[0] = 1;
  for (i = 0; i < mx; ++i) {
    f1 = i ^ mx;
    (ans += CAL(f1, i) % 1000000007 * f[f1] % 1000000007 * sz[f1]) %=
        1000000007;
  }
  cout << (ans + 1000000007) % 1000000007;
}
