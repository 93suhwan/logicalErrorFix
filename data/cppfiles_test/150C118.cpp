#include <bits/stdc++.h>
const int maxn = 105;
int n;
int a[maxn];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int ans = 1000000000;
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 10; j++) {
      int max3 = 0;
      for (int k = 1; k <= n; k++) {
        int temp = 1000000000;
        for (int p1 = 0; p1 <= 2; p1++) {
          for (int p2 = 0; p2 <= 2; p2++) {
            if (p1 > i || p2 > j) continue;
            int rem = a[k] - p1 - p2 - p2;
            if (rem < 0 || rem % 3 != 0) continue;
            temp = std::min(temp, rem / 3);
          }
        }
        max3 = std::max(max3, temp);
      }
      ans = std::min(ans, max3 + i + j);
    }
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
