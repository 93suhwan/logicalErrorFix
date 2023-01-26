#include <bits/stdc++.h>
using namespace std;
void sxseven();
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  sxseven();
  return 0;
}
int a[1001], b[1001];
int finda(int x) { return x == a[x] ? x : a[x] = finda(a[x]); }
int findb(int x) { return x == b[x] ? x : b[x] = findb(b[x]); }
struct node {
  int x, y;
} c[1001];
void sxseven() {
  int n, m1, m2, x, y, u, v, an = 0;
  scanf("%d%d%d", &n, &m1, &m2);
  for (int i = 1; i <= n; ++i) a[i] = i, b[i] = i;
  while (m1--) {
    scanf("%d%d", &x, &y);
    x = finda(x);
    y = finda(y);
    if (x != y) a[x] = y;
  }
  while (m2--) {
    scanf("%d%d", &u, &v);
    u = findb(u);
    v = findb(v);
    if (u != v) b[u] = v;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      x = finda(i);
      y = finda(j);
      u = findb(i);
      v = findb(j);
      if (x != y && u != v) {
        c[++an].x = i;
        c[an].y = j;
        a[x] = y;
        b[u] = v;
      }
    }
  }
  printf("%d\n", an);
  for (int i = 1; i <= an; ++i) printf("%d %d\n", c[i].x, c[i].y);
}
