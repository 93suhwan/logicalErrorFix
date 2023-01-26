#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = (int)1e5 + 5;
int _ = 1;
int n, q;
int a[N], pos[N];
int nex[N], blo;
int calc(int x) {
  for (int i = 1; i <= blo; i++) x = a[x];
  return x;
}
void work() {
  scanf("%d%d", &n, &q);
  blo = sqrt(n) + 1;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) pos[a[i]] = i;
  for (int i = 1; i <= n; i++) nex[i] = calc(i);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x, y;
      scanf("%d%d", &x, &y);
      swap(pos[a[x]], pos[a[y]]);
      swap(a[x], a[y]);
      nex[x] = calc(x);
      nex[y] = calc(y);
      for (int i = 1; i <= blo; i++) {
        x = pos[x];
        y = pos[y];
      }
      int ex = calc(x), ey = calc(y);
      for (int i = 1; i <= blo; i++) {
        nex[x] = ex;
        nex[y] = ey;
        x = a[x];
        y = a[y];
        ex = a[ex];
        ey = a[ey];
      }
    } else {
      int x, y;
      scanf("%d%d", &x, &y);
      while (y >= blo) {
        x = nex[x];
        y -= blo;
      }
      while (y) {
        x = a[x];
        y--;
      }
      printf("%d\n", x);
    }
  }
}
int main() {
  while (_--) {
    work();
  }
  return 0;
}
