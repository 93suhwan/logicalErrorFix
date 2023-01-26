#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int N = 1000010;
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
int n, D;
struct Node {
  int s, a, up;
} g[N];
inline bool cp(Node x, Node y) {
  return x.up == y.up ? x.s < y.s : x.up < y.up;
}
signed main() {
  n = read(), D = read();
  for (register int i = 1; i <= n; i++)
    g[i].s = read(), g[i].a = read(), g[i].up = max(g[i].s, g[i].a);
  sort(g + 1, g + 1 + n, cp);
  int ans = 0;
  for (register int i = 1; i <= n; i++)
    if (g[i].s >= D) ans++, D = max(D, g[i].a);
  printf("%d\n", ans);
  return 0;
}
