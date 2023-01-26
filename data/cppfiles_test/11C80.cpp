#include <bits/stdc++.h>
using namespace std;
int a[500010];
pair<int, int> b[500010];
int c[500010];
int T, n, tot;
int main(void) {
  T = 1;
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      b[i] = {a[i], -i};
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; ++i) {
      if (-b[i].second >= b[i].first) {
        int x = -(b[i].second + b[i].first);
        int pos = upper_bound(c + 1, c + 1 + tot, x) - c;
        c[pos] = x;
        tot = max(pos, tot);
      }
    }
    printf("%d\n", tot);
  }
  return 0;
}
