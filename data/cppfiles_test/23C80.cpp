#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &a) {
  T w = 1;
  a = 0;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') w = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) a = (a * 10) + (ch - '0');
  a *= w;
}
template <typename T>
inline void ckmax(T &a, T b) {
  a = a > b ? a : b;
}
template <typename T>
inline void ckmin(T &a, T b) {
  a = a < b ? a : b;
}
const long long N = 4040 + 10;
long long a[N], ls[N], rs[N];
long long sta[N], top;
long long n, m;
long long siz[N];
long long dp[N][N];
void Dp(long long u) {
  siz[u] = 1;
  if (ls[u]) {
    Dp(ls[u]);
    siz[u] += siz[ls[u]];
  }
  if (rs[u]) {
    Dp(rs[u]);
    siz[u] += siz[rs[u]];
  }
  for (long long i = 0; i <= siz[ls[u]]; ++i) {
    for (long long j = 0; j <= siz[rs[u]]; ++j) {
      long long x = i + j;
      if (x > m) continue;
      ckmax(dp[u][x], dp[ls[u]][i] + dp[rs[u]][j] - 2ll * i * j * a[u]);
      ckmax(dp[u][x + 1], dp[ls[u]][i] + dp[rs[u]][j] - 2 * i * j * a[u] -
                              a[u] + m * a[u] - 2 * (i + j) * a[u]);
    }
  }
}
signed main() {
  read(n);
  read(m);
  long long mx = 0, rt = 1;
  for (long long i = 1; i <= n; ++i) {
    read(a[i]);
    if (i == 1) mx = a[i];
    while (top && a[sta[top]] > a[i]) top--;
    ls[i] = rs[sta[top]], rs[sta[top]] = i;
    sta[++top] = i;
    if (a[i] < mx) mx = a[i], rt = i;
  }
  Dp(rt);
  cout << dp[rt][m];
  return 0;
}
