#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
char buf[121], *p1 = buf, *p2 = buf;
inline int getc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 121, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int ret = 0, f = 0;
  char ch = getc();
  while (!isdigit(ch)) {
    if (ch == '-') f = 1;
    ch = getc();
  }
  while (isdigit(ch)) {
    ret = ret * 10 + ch - 48;
    ch = getc();
  }
  return f ? -ret : ret;
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
int qkpow(int a, int b) {
  int base = a, ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * base % mod;
    base = 1ll * base * base % mod;
    b >>= 1;
  }
  return ans;
}
int n, m, a[4005], sta[4005], ls[4005], rs[4005], si[4005];
long long dp[4005][4005], tmp[4005][4005];
void dfs(int u) {
  dp[u][0] = 0, si[u] = 1;
  dp[u][1] = (m - 1) * a[u];
  if (ls[u] && !rs[u]) {
    dfs(ls[u]);
    for (int i = 0; i <= si[ls[u]]; i++) {
      tmp[u][i] = max(tmp[u][i], dp[ls[u]][i]);
      tmp[u][i + 1] =
          max(tmp[u][i + 1], dp[ls[u]][i] + (m - 1) * a[u] - 2 * i * a[u]);
    }
    si[u] += si[ls[u]];
    for (int i = 1; i <= si[u]; i++) dp[u][i] = tmp[u][i];
  } else if (rs[u] && !ls[u]) {
    dfs(rs[u]);
    for (int i = 0; i <= si[rs[u]]; i++) {
      tmp[u][i] = max(tmp[u][i], dp[rs[u]][i]);
      tmp[u][i + 1] =
          max(tmp[u][i + 1], dp[rs[u]][i] + (m - 1) * a[u] - 2 * i * a[u]);
    }
    si[u] += si[rs[u]];
    for (int i = 1; i <= si[u]; i++) dp[u][i] = tmp[u][i];
  } else if (ls[u] && rs[u]) {
    dfs(ls[u]), dfs(rs[u]);
    for (int i = 0; i <= si[ls[u]]; i++) {
      for (int j = 0; j <= si[rs[u]]; j++) {
        tmp[u][i + j] =
            max(tmp[u][i + j], dp[ls[u]][i] + dp[rs[u]][j] - 2 * i * j * a[u]);
        tmp[u][i + j + 1] =
            max(tmp[u][i + j + 1], dp[ls[u]][i] + dp[rs[u]][j] +
                                       (m - 1) * a[u] - 2 * i * j * a[u] -
                                       2 * i * a[u] - 2 * j * a[u]);
      }
    }
    si[u] += si[ls[u]], si[u] += si[rs[u]];
    for (int i = 1; i <= si[u]; i++) dp[u][i] = tmp[u][i];
  }
}
signed main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  int top = 0, now = 0, rt = 0;
  for (int i = 1; i <= n; i++) {
    now = top;
    while (now && a[sta[now]] > a[i]) now--;
    if (!now)
      rt = i;
    else
      rs[sta[now]] = i;
    if (now < top) ls[i] = sta[now + 1];
    top = now;
    sta[++top] = i;
  }
  memset(dp, -0x3f, sizeof dp);
  memset(tmp, -0x3f, sizeof tmp);
  dfs(rt);
  printf("%lld\n", dp[rt][m]);
  return 0;
}
