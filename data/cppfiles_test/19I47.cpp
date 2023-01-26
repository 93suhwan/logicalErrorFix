#include <bits/stdc++.h>
using namespace std;
int a[1501], b[1501];
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
      for (int j = 1; j <= 1500; j++) {
        if (a[j] != 0) {
          if (j >= x) {
            s = a[j];
            t = max(j - x, a[j] - j + x);
          } else {
            s = a[j] + x - j;
            t = s;
          }
          if (s <= 1500) {
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
          if (s <= 1500) {
            if (b[t] == 0 || b[t] > s) {
              b[t] = s;
            }
          }
        }
      }
      for (int j = 1; j <= 1500; j++) {
        a[j] = b[j];
      }
    }
    int ans = 1500;
    for (int i = 1; i <= 1500; i++) {
      if (a[i] > 0) ans = min(ans, a[i]);
    }
    printf("%d\n", ans);
  }
}
