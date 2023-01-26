#include <bits/stdc++.h>
using namespace std;
int t, n, m, a[15], ans, b[10010];
char s[15][10010];
struct P {
  int val, id;
} p[10010];
inline bool cmp(P x, P y) { return x.val < y.val; }
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    ans = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%s", s[i] + 1);
    for (int i = 0; i < 1 << n; i++) {
      int sum = 0;
      for (int j = 1; j <= m; j++) {
        p[j].val = 0;
        p[j].id = j;
      }
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          sum += a[j];
          for (int k = 1; k <= m; k++)
            if (s[j][k] == '1') p[k].val--;
        } else {
          sum -= a[j];
          for (int k = 1; k <= m; k++)
            if (s[j][k] == '1') p[k].val++;
        }
      }
      sort(p + 1, p + m + 1, cmp);
      for (int j = 1; j <= m; j++) sum += j * p[j].val;
      if (sum >= ans) {
        ans = sum;
        for (int j = 1; j <= m; j++) b[p[j].id] = j;
      }
    }
    for (int i = 1; i <= m; i++) printf("%d ", b[i]);
    printf("\n");
  }
  return 0;
}
