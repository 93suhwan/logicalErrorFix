#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
const int N = 4005;
const long long INF = 1e15;
int n, m, mn[N][N], tot;
long long a[N], f[N][N];
short int mp[N][N];
bool g[N][N];
inline void init() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
}
inline long long dp(int l, int r, int k) {
  if (k < 0) return -INF;
  if (l > r) {
    if (!k) return 0;
    return -INF;
  }
  if (l == r) {
    if (k == 0) return 0;
    if (k == 1) return 1ll * a[l] * (m - 1);
    return -INF;
  }
  if (!mp[l][r]) mp[l][r] = ++tot;
  int x = mp[l][r];
  if (g[x][k]) return f[x][k];
  g[x][k] = 1;
  int p = mn[l][r];
  if (p == l)
    return f[x][k] =
               max(dp(l + 1, r, k), dp(l + 1, r, k - 1) + a[l] * (m - 1ll) -
                                        2ll * a[l] * (k - 1));
  if (p == r)
    return f[x][k] =
               max(dp(l, r - 1, k), dp(l, r - 1, k - 1) + a[r] * (m - 1ll) -
                                        2ll * a[r] * (k - 1));
  if (p - l < r - p) {
    for (int i = 0; i <= min(k, p - l + 1); i++) {
      f[x][k] = max(f[x][k], dp(l, p, i) + dp(p + 1, r, k - i) -
                                 2ll * (k - i) * i * a[p]);
    }
  } else {
    for (int i = 0; i <= min(k, r - p + 1); i++) {
      f[x][k] = max(f[x][k], dp(l, p, k - i) + dp(p + 1, r, i) -
                                 2ll * (k - i) * i * a[p]);
    }
  }
  return f[x][k];
}
inline void solve() {
  for (int i = 1; i <= n; i++) {
    mn[i][i] = i;
    for (int j = i + 1; j <= n; j++) {
      if (a[j] < a[mn[i][j - 1]])
        mn[i][j] = j;
      else
        mn[i][j] = mn[i][j - 1];
    }
  }
  writeln(dp(1, n, m));
}
int main() {
  init();
  solve();
  return 0;
}
