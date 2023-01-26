#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0, f = 0;
  register char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + c - 48;
    c = getchar();
  }
  return f ? -x : x;
}
const int N = 5e3 + 3, M = 5e3 + 3, eps = 1e-4;
int n, num;
int vis[600];
signed main() {
  n = read();
  for (register int i = 1; i <= n; ++i) {
    int x = read();
    if (!vis[x])
      vis[x] = x;
    else
      vis[x] = min(x, vis[x]);
    for (register int j = 1; j <= 511; ++j) {
      if (!vis[j]) continue;
      if (x <= vis[j]) continue;
      int y = j ^ x;
      if (!vis[y])
        vis[y] = x;
      else
        vis[y] = min(vis[y], x);
    }
  }
  int ans = 1;
  for (register int i = 1; i <= 511; ++i)
    if (vis[i] > 0) ans++;
  printf("%d\n0 ", ans);
  for (register int i = 1; i <= 511; ++i)
    if (vis[i] > 0) printf("%d ", i);
  return 0;
}
