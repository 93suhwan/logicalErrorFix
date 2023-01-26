#include <bits/stdc++.h>
using namespace std;
long long su(long long a, long long b) {
  a += b;
  return (a >= 998244353) ? a - 998244353 : a;
}
int i, j, k, n, m, t, a[30][30], c[30], t0, t1, t2;
long long f[20005000], p[1005000], x, y, res;
int main() {
  p[0] = 1;
  for (i = 1; i <= 1000000; i++) p[i] = su(p[i - 1], p[i - 1]);
  ios::sync_with_stdio(0);
  cin >> n;
  for (i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (auto j : s) {
      a[i][j - 'a' + 1]++;
    }
  }
  for (i = 1; i < (1 << ((n + 1) - 1)); i++) {
    memset(c, 1, sizeof(c));
    for (j = 1; j <= n; j++) {
      if (!(i & (1 << ((j)-1)))) continue;
      for (k = 1; k <= 26; k++) {
        c[k] = min(c[k], a[j][k]);
      }
    }
    t0 = 0;
    f[i] = 1;
    for (j = 1; j <= 26; j++) {
      f[i] = f[i] * (c[j] + 1) % 998244353;
    }
    if (__builtin_popcount(i) & 1) {
    } else {
      f[i] = 998244353 - f[i];
    }
  }
  for (int i = 0; i < n; ++i)
    for (int mask = 0; mask < (1 << n); ++mask) {
      if (mask & (1 << i)) f[mask] = su(f[mask], f[mask ^ (1 << i)]);
    }
  for (i = 1; i < (1 << ((n + 1) - 1)); i++) {
    x = y = 0;
    for (j = 1; j <= n; j++) {
      if ((1 << ((j)-1)) & i) {
        x++;
        y += j;
      }
    }
    res ^= (f[i] * x * y);
  }
  cout << res;
}
