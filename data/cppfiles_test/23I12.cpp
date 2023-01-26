#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const long long N = 4e3 + 10;
long long n, m, ans, root, top, sta[N], s[N], siz[N], f[N][N];
struct Tree {
  long long son[2];
} tre[N];
void dfs(long long x) {
  siz[x] = 1;
  for (long long i = 0; i <= 1; i++) {
    if (!tre[x].son[i]) continue;
    long long to = tre[x].son[i];
    dfs(to);
    for (long long j = min(m, siz[x]); j >= 0; j--)
      for (long long k = min(m - j, siz[to]); k >= 0; k--)
        f[x][j + k] =
            max(f[x][j + k], f[x][j] + f[to][k] + (s[to] - s[x]) * (m - k) * k);
    siz[x] += siz[to];
  }
}
int main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++) s[i] = read();
  for (long long i = 1; i <= n; i++) {
    while (top && s[sta[top]] > s[i]) tre[i].son[0] = sta[top--];
    if (top) tre[sta[top]].son[1] = i;
    sta[++top] = i;
  }
  while (top) root = sta[top--];
  dfs(root);
  for (long long i = 1; i <= m; i++) ans = max(ans, f[root][i]);
  printf("%lld", ans);
  return 0;
}
