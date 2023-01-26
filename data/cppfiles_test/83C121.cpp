#include <bits/stdc++.h>
using namespace std;
char c[5000];
int match[5000][5000], dp[5000];
int main() {
  int test_case = 1;
  scanf("%d", &test_case);
  while (test_case--) {
    int n, ans = 0;
    scanf("%d %s", &n, &c);
    n = strlen(c);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) match[i][j] = 0;
    for (int i = n - 1; i >= 0; i--)
      for (int j = n - 1; j > i; j--)
        if (c[i] == c[j]) match[i][j] = 1 + match[i + 1][j + 1];
    for (int i = 0; i < n; i++) {
      dp[i] = n - i;
      for (int j = i - 1; j >= 0; j--)
        if ((i + match[j][i] < n) && c[i + match[j][i]] > c[j + match[j][i]])
          dp[i] = max(dp[i], dp[j] + n - i - match[j][i]);
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
