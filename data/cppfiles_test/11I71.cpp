#include <bits/stdc++.h>
using namespace std;
int a[500010];
struct node {
  int x, y;
  bool operator<(const node &tmp) const { return x < tmp.x && y <= tmp.y; }
} b[500010];
int T, n, tot;
int main(void) {
  T = 1;
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      if (i >= a[i]) {
        node pa = node{a[i], i - a[i]};
        int pos = lower_bound(b + 1, b + 1 + tot, pa) - b;
        if (pos > tot) {
          b[++tot] = pa;
        } else {
          b[pos] = pa;
        }
      }
    }
    printf("%d\n", tot);
  }
  return 0;
}
