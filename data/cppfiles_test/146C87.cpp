#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, bl, nxt[N], pre[N], jp[N];
int jump(int x) {
  for (int i = 1; i <= bl; i++) x = nxt[x];
  return x;
}
void update(int x) {
  jp[x] = jump(x);
  for (int i = 1; i <= bl; i++) {
    x = pre[x];
    jp[x] = pre[jp[nxt[x]]];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  bl = sqrt(n);
  for (int i = 1; i <= n; i++) scanf("%d", &nxt[i]), pre[nxt[i]] = i;
  for (int i = 1; i <= n; i++) jp[i] = jump(i);
  while (m--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      int px = nxt[x], py = nxt[y];
      nxt[x] = py, nxt[y] = px;
      pre[py] = x, pre[px] = y;
      update(x), update(y);
    } else {
      while (y >= bl) x = jp[x], y -= bl;
      for (int i = 1; i <= y; i++) x = nxt[x];
      printf("%d\n", x);
    }
  }
  return 0;
}
