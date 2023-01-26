#include <bits/stdc++.h>
using namespace std;
int t, n, ans, lcp[5009][5009], dp[5009];
char a[5009];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    scanf("%s", a + 1);
    ans = 0;
    for (int i = n; i >= 1; i--)
      for (int j = n; j >= 1; j--)
        lcp[i][j] = (a[i] == a[j]) ? (lcp[i + 1][j + 1] + 1) : 0;
    for (int i = 1; i <= n; i++) {
      dp[i] = n + 1 - i;
      for (int j = 1; j < i; j++) {
        int len = lcp[i][j];
        if (a[j + len] < a[i + len])
          dp[i] = max(dp[i], dp[j] + n + 1 - (i + len));
      }
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
