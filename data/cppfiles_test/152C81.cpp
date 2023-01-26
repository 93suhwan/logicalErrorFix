#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, inf = 1e9;
int T, n, p[N], dp[N][2][2], a[N];
pair<int, int> pre[N][2][2];
void print() {
  for (int pos = 0; pos < 2; pos++)
    for (int sg = 0; sg < 2; sg++)
      if (dp[n][pos][sg] != inf) {
        printf("YES\n");
        for (int j = n; j >= 1; j--) {
          a[j] = sg ? p[j] : -p[j];
          auto pr = pre[j][pos][sg];
          pos = pr.first, sg = pr.second;
        }
        for (int j = 1; j <= n; j++) printf("%d ", a[j]);
        printf("\n");
        return;
      }
  printf("NO\n");
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++)
      for (int pos = 0; pos < 2; pos++)
        for (int sg = 0; sg < 2; sg++) dp[i][pos][sg] = inf;
    dp[1][0][0] = -inf, dp[1][0][1] = -inf;
    for (int i = 1; i < n; i++)
      for (int pos = 0; pos < 2; pos++)
        for (int sg = 0; sg < 2; sg++)
          if (dp[i][pos][sg] != inf) {
            for (int sig = 0; sig < 2; sig++) {
              int z = sig ? p[i + 1] : -p[i + 1], x, y;
              if (!pos)
                x = sg ? p[i] : -p[i], y = dp[i][pos][sg];
              else
                x = dp[i][pos][sg], y = sg ? p[i] : -p[i];
              if (y < z && z < x) {
                if (x < dp[i + 1][1][sig]) {
                  dp[i + 1][1][sig] = x;
                  pre[i + 1][1][sig] = {pos, sg};
                }
              } else if (z > x) {
                if (y < dp[i + 1][0][sig]) {
                  dp[i + 1][0][sig] = min(dp[i + 1][0][sig], y);
                  pre[i + 1][0][sig] = {pos, sg};
                }
              }
            }
          }
    print();
  }
  return 0;
}
