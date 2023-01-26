#include <bits/stdc++.h>
using namespace std;
const int maxn = 55000;
int a[220];
int f[220];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      a[x] = y;
      a[y] = x;
      f[x] = 1;
      f[y] = 1;
    }
    for (int i = 1; i <= 2 * n; i++) {
      if (a[i] != 0) continue;
      int l = 0, cnt = 1;
      while (l != n - k && cnt + i <= 2 * n) {
        if (f[cnt + i] == 0) l++;
        cnt++;
      }
      a[i] = cnt - 1 + i;
      a[cnt - 1 + i] = i;
    }
    int ans = 0;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= 2 * n; i++) {
      if (f[i] == 1) continue;
      for (int j = i + 1; j < a[i]; j++) {
        if (f[j] == 1) continue;
        if (a[j] < i || a[j] > a[i]) {
          ans++;
        }
      }
      f[i] = 1, f[a[i]] = 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
