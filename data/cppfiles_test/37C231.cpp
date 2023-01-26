#include <bits/stdc++.h>
using namespace std;
bool vis[300017];
int main() {
  int T, a, b, c, n, m, s;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i += 1) {
      scanf("%d%d%d", &a, &b, &c);
      vis[b] = 1;
    }
    for (int i = 1; i <= n; i += 1)
      if (!vis[i]) {
        s = i;
        break;
      }
    for (int i = 1; i <= n; i += 1) {
      if (s == i) continue;
      printf("%d %d\n", s, i);
    }
    for (int i = 1; i <= n; i += 1) vis[i] = 0;
  }
  return 0;
}
