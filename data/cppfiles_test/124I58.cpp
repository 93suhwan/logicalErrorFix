#include <bits/stdc++.h>
const int N = 4e3 + 10;
const long long mod = 1e9 + 7;
using namespace std;
long long n, m, t;
char a[N], s[N];
long long pre[N][N], suf[N][N];
signed main() {
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> a + 1;
    cin >> s + 1;
    for (long long i = 1; i <= n; i += 2) {
      if (a[i] != '?') a[i] = '1' + '0' - a[i];
      if (s[i] != '?') s[i] = '1' + '0' - s[i];
    }
    cout << a + 1 << " " << s + 1 << endl;
    memset(pre, 0, sizeof(pre));
    memset(suf, 0, sizeof(suf));
    pre[0][n] = 1;
    for (long long i = 1; i <= n; i++) {
      long long amax, amin, smax, smin;
      if (a[i] == '0')
        amax = amin = 0;
      else if (a[i] == '1')
        amax = amin = 1;
      else
        amax = 1, amin = 0;
      if (s[i] == '0')
        smax = smin = 0;
      else if (s[i] == '1')
        smax = smin = 1;
      else
        smax = 1, smin = 0;
      for (long long w = -n; w <= n; w++) {
        pre[i][n + w] = 0;
        for (long long j = amin; j <= amax; j++) {
          for (long long k = smin; k <= smax; k++) {
            if (w - (k - j) >= -n && w - (k - j) <= n)
              pre[i][n + w] =
                  (pre[i][n + w] + pre[i - 1][n + w - (k - j)]) % mod;
          }
        }
      }
    }
    for (long long i = -n; i <= n; i++) suf[n + 1][i] = 0;
    suf[n + 1][n] = 1;
    for (long long i = n; i >= 1; i--) {
      long long amax, amin, smax, smin;
      if (a[i] == '0')
        amax = amin = 0;
      else if (a[i] == '1')
        amax = amin = 1;
      else
        amax = 1, amin = 0;
      if (s[i] == '0')
        smax = smin = 0;
      else if (s[i] == '1')
        smax = smin = 1;
      else
        smax = 1, smin = 0;
      for (long long w = -n; w <= n; w++) {
        suf[i][w + n] = 0;
        for (long long j = amin; j <= amax; j++) {
          for (long long k = smin; k <= smax; k++) {
            if (w - (k - j) >= -n && w - (k - j) <= n)
              suf[i][w + n] =
                  (suf[i][n + w] + suf[i + 1][w + n - (k - j)]) % mod;
          }
        }
      }
    }
    long long ans = 0;
    for (long long i = 1; i < n; i++) {
      for (long long j = -n; j <= n; j++) {
        ans = (ans + abs(j) * pre[i][n + j] * suf[i + 1][n - j]) % mod;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
