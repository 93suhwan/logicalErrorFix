#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
bool st[maxn];
int n, m;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) st[i] = 0;
    while (m--) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      st[y] = 1;
    }
    int center;
    for (int i = 1; i <= n; ++i)
      if (!st[i]) {
        center = i;
        break;
      }
    for (int i = 1; i <= n; ++i) {
      if (i != center) {
        printf("%d %d\n", center, i);
      }
    }
  }
  return 0;
}
