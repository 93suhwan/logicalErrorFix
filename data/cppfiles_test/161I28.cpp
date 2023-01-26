#include <bits/stdc++.h>
using namespace std;
struct node {
  int l, r;
} e[1005];
inline bool cmp(node x, node y) { return x.r - x.l <= y.r - y.l; }
int n;
int main() {
  int t;
  scanf("%d", &t);
  bool gg = 0;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &e[i].l, &e[i].r);
    sort(e + 1, e + n + 1, cmp);
    bool num[1005] = {0};
    if (gg)
      printf("\n");
    else
      gg = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = e[i].l; j <= e[i].r; ++j) {
        if (!num[j]) {
          num[j] = 1;
          printf("%d %d %d\n", e[i].l, e[i].r, j);
          break;
        }
      }
    }
  }
  return 0;
}
