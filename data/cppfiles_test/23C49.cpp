#include <bits/stdc++.h>
using namespace std;
const int N = 4005;
long long f[N][N], a[N];
int n, m, top, st[N], rt, ls[N], rs[N], s[N];
int read() {
  int x = 0, f = 1;
  char ch = getchar();
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
void dfs(int x) {
  s[x] = 1;
  if (ls[x] > 0 && rs[x] > 0) {
    dfs(ls[x]), dfs(rs[x]);
    s[x] += s[ls[x]] + s[rs[x]];
    for (int i = 0; i <= min(s[ls[x]], m); i++) {
      for (int j = 0; j <= min(s[rs[x]], m) && i + j <= m; j++) {
        f[x][i + j] =
            max(f[x][i + j], f[ls[x]][i] + f[rs[x]][j] - a[x] * i * j * 2);
        if (i + j < m)
          f[x][i + j + 1] = max(f[x][i + j + 1],
                                f[ls[x]][i] + f[rs[x]][j] - a[x] * i * j * 2 +
                                    a[x] * (m - 1) - a[x] * (i + j) * 2);
      }
    }
  } else if (ls[x] > 0 || rs[x] > 0) {
    int y = ls[x] ? ls[x] : rs[x];
    dfs(y);
    s[x] += s[y];
    for (int i = 0; i <= min(s[y], m); i++) {
      f[x][i] = max(f[x][i], f[y][i]);
      if (i < m)
        f[x][i + 1] = max(f[x][i + 1], f[y][i] + a[x] * (m - 1) - a[x] * i * 2);
    }
  } else
    f[x][1] = a[x] * (m - 1);
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) {
    int k = top;
    while (k > 0 && a[st[k]] > a[i]) k--;
    if (k > 0) rs[st[k]] = i;
    if (k < top) ls[i] = st[k + 1];
    st[++k] = i;
    top = k;
  }
  rt = 1;
  for (int i = 2; i <= n; i++)
    if (a[rt] > a[i]) rt = i;
  dfs(rt);
  printf("%lld\n", f[rt][m]);
  return 0;
}
