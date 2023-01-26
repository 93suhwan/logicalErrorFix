#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int dp[maxn][maxn];
int pr[maxn][maxn];
int a[maxn] = {0};
int main() {
  int ttt;
  cin >> ttt;
  while (ttt--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int res = -1;
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        dp[i][j] = 0;
        if (i > 1) dp[i][j] = pr[i - 1][j - 1];
        if (a[j] == i) ++dp[i][j];
        if (dp[i][j] >= k) {
          if (res == -1 || j - i < res) res = j - i;
        }
        if (j == i)
          pr[i][j] = dp[i][j];
        else
          pr[i][j] = max(pr[i][j - 1], dp[i][j]);
      }
    }
    cout << res << '\n';
  }
  return 0;
}
