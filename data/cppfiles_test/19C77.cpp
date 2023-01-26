#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000;
int a[maxn + 1], b[maxn + 1];
int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    memset(a, 0, sizeof a);
    int x, s, t;
    scanf("%d", &x);
    a[x] = x;
    for (int i = 2; i <= n; i++) {
      scanf("%d", &x);
      memset(b, 0, sizeof b);
      for (int j = 1; j <= maxn; j++) {
        if (a[j] != 0) {
          if (j >= x) {
            s = a[j];
            t = max(j - x, a[j] - j + x);
          } else {
            s = a[j] + x - j;
            t = s;
          }
          if (s <= maxn) {
            if (b[t] == 0 || b[t] > s) {
              b[t] = s;
            }
          }
          if (a[j] - j >= x) {
            s = a[j];
            t = max(j + x, a[j] - j - x);
          } else {
            s = x + j;
            t = s;
          }
          if (s <= maxn) {
            if (b[t] == 0 || b[t] > s) {
              b[t] = s;
            }
          }
        }
      }
      for (int j = 1; j <= maxn; j++) {
        a[j] = b[j];
      }
    }
    int ans = maxn;
    for (int i = 1; i <= maxn; i++) {
      if (a[i] > 0) ans = min(ans, a[i]);
    }
    printf("%d\n", ans);
  }
}
