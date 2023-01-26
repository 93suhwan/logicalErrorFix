#include <bits/stdc++.h>
using namespace std;
int n, q, block, d[100005];
int p[100005], p2[100005];
int nxt(int x, int y = block) {
  while (y--) x = p[x];
  return x;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    p2[p[i]] = i;
  }
  block = sqrt(n);
  for (int i = 1; i <= n; i++) {
    d[i] = nxt(i, block);
  }
  while (q--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      swap(p[x], p[y]);
      p2[p[x]] = x, p2[p[y]] = y;
      d[x] = nxt(x, block), d[y] = nxt(y, block);
      for (int i = 1; i <= block; i++) {
        d[p2[x]] = p2[d[x]];
        d[p2[y]] = p2[d[y]];
        x = p2[x], y = p2[y];
      }
    } else {
      while (y >= block) {
        x = d[x];
        y -= block;
      }
      while (y >= 1) {
        x = p[x];
        y--;
      }
      printf("%d\n", x);
    }
  }
  return 0;
}
