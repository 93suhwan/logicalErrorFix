#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int N = 500010;
inline int read() {
  int s = 0, w = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
char opt[10];
int n, m, vis[N];
vector<int> g[N];
signed main() {
  for (register int T = read(); T; T--) {
    n = read(), m = read();
    for (register int i = 1; i <= (n << 1); i++) vis[i] = 0, g[i].clear();
    for (register int i = 1; i <= m; i++) {
      int x, y;
      x = read(), y = read();
      scanf("%s", opt);
      if (opt[0] == 'c') {
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        g[x + n].emplace_back(y + n);
        g[y + n].emplace_back(x + n);
      } else {
        g[x].emplace_back(y + n);
        g[y].emplace_back(x + n);
        g[x + n].emplace_back(y);
        g[y + n].emplace_back(x);
      }
    }
    int ans = 0;
    for (register int i = 1; i <= n; i++) {
      if (vis[i] || vis[i + n]) continue;
      vis[i] = i;
      queue<int> Q;
      Q.push(i);
      int s1, s2;
      s1 = s2 = 0;
      while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        int go;
        if (x <= n)
          go = x + n;
        else
          go = x - n;
        if (vis[go] == vis[x]) {
          ans = -1;
          break;
        }
        s1 += (x <= n), s2 += (x > n);
        for (auto j : g[x]) {
          if (vis[j]) continue;
          vis[j] = i, Q.push(j);
        }
      }
      if (ans == -1) break;
      ans += max(s1, s2);
    }
    printf("%d\n", ans);
  }
  return 0;
}
