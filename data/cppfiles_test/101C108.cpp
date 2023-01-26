#include <bits/stdc++.h>
using namespace std;
long long vx[300005];
long long vy[300005];
int x[1000005], y[1000005];
int n, m, k;
struct node {
  int x, y;
} que1[300005];
int tot1;
struct node2 {
  int x, y;
} que2[300005];
int tot2;
map<long long, long long> mp1[1000005], mp2[1000005];
void init() {
  tot1 = 0;
  tot2 = 0;
  memset(vx, 0, sizeof(vx));
  memset(vy, 0, sizeof(vy));
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &k);
    init();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x[i]);
      mp2[i].clear();
    }
    for (int i = 1; i <= m; i++) {
      scanf("%d", &y[i]);
      mp1[i].clear();
    }
    for (int i = 1; i <= k; i++) {
      int tx, ty;
      scanf("%d%d", &tx, &ty);
      int px = upper_bound(x + 1, x + 1 + n, tx) - x - 1;
      int py = upper_bound(y + 1, y + 1 + m, ty) - y - 1;
      if (x[px] == tx && y[py] == ty)
        continue;
      else {
        if (x[px] == tx) {
          tot1++;
          que1[tot1].x = tx;
          que1[tot1].y = ty;
        } else {
          tot2++;
          que2[tot2].x = tx;
          que2[tot2].y = ty;
        }
      }
    }
    long long ans = 0;
    for (int i = 1; i <= tot1; i++) {
      int py = upper_bound(y + 1, y + 1 + m, que1[i].y) - y - 1;
      ans += vy[py]++ - mp1[py][que1[i].x]++;
    }
    for (int i = 1; i <= tot2; i++) {
      int px = upper_bound(x + 1, x + 1 + n, que2[i].x) - x - 1;
      ans += vx[px]++ - mp2[px][que2[i].y]++;
    }
    cout << ans << endl;
  }
  return 0;
}
