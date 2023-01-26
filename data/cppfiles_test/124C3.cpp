#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = (ll)1e9 + 7;
const int N = (int)2e3 + 5;
int _ = 1, CNT = -1;
int n, a[N], b[N];
ll f[N][N + N], g[N][N + N], ans;
char s[N], t[N];
void work() {
  ans = 0;
  scanf("%d", &n);
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= n + n; j++) f[i][j] = g[i][j] = 0;
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  for (int i = 1; i <= n; i++)
    a[i] = s[i] == '?' ? -1 : (s[i] - '0') ^ (i % 2 == 0);
  for (int i = 1; i <= n; i++)
    b[i] = t[i] == '?' ? -1 : (t[i] - '0') ^ (i % 2 == 0);
  f[0][n] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n + n; j++) {
      if (a[i] != -1 && b[i] != -1) {
        if (j - a[i] + b[i] >= 0 && j - a[i] + b[i] <= n + n) {
          f[i][j] += f[i - 1][j - a[i] + b[i]];
          f[i][j] %= mod;
        }
      } else if (a[i] == -1 && b[i] != -1) {
        if (j - 0 + b[i] >= 0 && j - 0 + b[i] <= n + n) {
          f[i][j] += f[i - 1][j - 0 + b[i]];
          f[i][j] %= mod;
        }
        if (j - 1 + b[i] >= 0 & j - 1 + b[i] <= n + n) {
          f[i][j] += f[i - 1][j - 1 + b[i]];
          f[i][j] %= mod;
        }
      } else if (a[i] != -1 && b[i] == -1) {
        if (j - a[i] + 0 >= 0 && j - a[i] + 0 <= n + n) {
          f[i][j] += f[i - 1][j - a[i] + 0];
          f[i][j] %= mod;
        }
        if (j - a[i] + 1 >= 0 && j - a[i] + 1 <= n + n) {
          f[i][j] += f[i - 1][j - a[i] + 1];
          f[i][j] %= mod;
        }
      } else {
        f[i][j] += 2 * f[i - 1][j] % mod;
        f[i][j] %= mod;
        if (j + 1 <= n + n) {
          f[i][j] += f[i - 1][j + 1];
          f[i][j] %= mod;
        }
        if (j - 1 >= 0) {
          f[i][j] += f[i - 1][j - 1];
          f[i][j] %= mod;
        }
      }
    }
  }
  g[n + 1][n] = 1;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= n + n; j++) {
      if (a[i] != -1 && b[i] != -1) {
        if (j - a[i] + b[i] >= 0 && j - a[i] + b[i] <= n + n) {
          g[i][j] += g[i + 1][j - a[i] + b[i]];
          g[i][j] %= mod;
        }
      } else if (a[i] == -1 && b[i] != -1) {
        if (j - 0 + b[i] >= 0 && j - 0 + b[i] <= n + n) {
          g[i][j] += g[i + 1][j - 0 + b[i]];
          g[i][j] %= mod;
        }
        if (j - 1 + b[i] >= 0 & j - 1 + b[i] <= n + n) {
          g[i][j] += g[i + 1][j - 1 + b[i]];
          g[i][j] %= mod;
        }
      } else if (a[i] != -1 && b[i] == -1) {
        if (j - a[i] + 0 >= 0 && j - a[i] + 0 <= n + n) {
          g[i][j] += g[i + 1][j - a[i] + 0];
          g[i][j] %= mod;
        }
        if (j - a[i] + 1 >= 0 && j - a[i] + 1 <= n + n) {
          g[i][j] += g[i + 1][j - a[i] + 1];
          g[i][j] %= mod;
        }
      } else {
        g[i][j] += 2 * g[i + 1][j] % mod;
        g[i][j] %= mod;
        if (j + 1 <= n + n) {
          g[i][j] += g[i + 1][j + 1];
          g[i][j] %= mod;
        }
        if (j - 1 >= 0) {
          g[i][j] += g[i + 1][j - 1];
          g[i][j] %= mod;
        }
      }
    }
  }
  for (ll i = 1; i < n; i++) {
    for (ll j = 0; j <= n + n; j++) {
      ans += abs(j - n) * f[i][j] % mod * g[i + 1][2 * n - j] % mod;
      ans %= mod;
    }
  }
  printf("%lld\n", ans);
}
int main() {
  scanf("%d", &_);
  while (_--) {
    work();
  }
  return 0;
}
