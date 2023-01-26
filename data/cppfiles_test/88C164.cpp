#include <bits/stdc++.h>
using namespace std;
int rr;
struct node {
  int a, i;
} a[90005];
bool cmp(node x, node y) {
  if (x.a != y.a) return x.a < y.a;
  return x.i < y.i;
}
void work() {
  int n, m, ans = 0;
  scanf("%d%d", &n, &m);
  rr = n * m;
  for (int i = 1; i <= rr; ++i) scanf("%d", &a[i].a), a[i].i = i;
  sort(a + 1, a + 1 + rr, cmp);
  for (int i = 1; i <= n; ++i) {
    int l = (i - 1) * m + 1, r = i * m;
    for (int j = l; j <= r; ++j)
      for (int k = l; a[k].a != a[j].a; ++k)
        if (a[j].i > a[k].i) ++ans;
  }
  printf("%d\n", ans);
}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) work();
  return 0;
}
