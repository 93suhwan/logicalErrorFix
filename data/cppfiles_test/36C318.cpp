#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];
bool vis[maxn];
struct node {
  int w, lo;
} ji[maxn];
int main() {
  int t, n, tot, ans, sum;
  scanf("%d", &t);
  for (register int i = 1; i <= t; ++i) {
    memset(vis, 0, sizeof(vis));
    memset(ji, 0, sizeof(ji));
    ans = tot = sum = 0;
    scanf("%d", &n);
    for (register int j = 1; j <= n; ++j) {
      scanf("%d", &a[j]);
      if (a[j] % 2 == 0) {
        ans++;
        sum += a[j];
        vis[j] = 1;
      } else {
        tot++;
        ji[tot].w = a[j];
        ji[tot].lo = j;
      }
    }
    for (register int j = 1; j <= tot; j += 2) {
      if (ji[j + 1].w != 0) {
        ans += 2;
        sum += (ji[j].w + ji[j + 1].w);
        vis[ji[j].lo] = vis[ji[j + 1].lo] = 1;
      }
    }
    if (tot == 0) {
      printf("%d\n", ans);
      for (register int j = 1; j <= n; ++j) {
        if (vis[j]) printf("%d ", j);
      }
      printf("\n");
      continue;
    }
    if (!vis[ji[tot].lo]) {
      sum += ji[tot].w;
      for (register int k = 2; k <= sqrt(sum); ++k) {
        if (sum % k == 0) {
          ans++;
          vis[ji[tot].lo] = 1;
          break;
        }
      }
    }
    printf("%d\n", ans);
    for (register int j = 1; j <= n; ++j) {
      if (vis[j]) printf("%d ", j);
    }
    printf("\n");
  }
  return 0;
}
