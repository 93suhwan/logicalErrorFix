#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 1e9 + 7, OO = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-8;
const double PI = M_PI;
const pair<int, int> MOVES[] = {{1, 0}, {0, 1},   {-1, 0}, {0, -1},
                                {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
int t, n, a[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      mx = max(mx, a[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(2 * mx + 1, OO));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
      for (int l = 0; l <= 2 * mx; ++l) {
        if (dp[i][l] == OO) continue;
        dp[i + 1][max(0, l - a[i])] = dp[i][l] + a[i];
        if (l + a[i] < dp[i + 1].size())
          dp[i + 1][l + a[i]] = max(0, dp[i][l] - a[i]);
      }
    int mn = OO;
    for (int l = 0; l <= 2 * mx; ++l) mn = min(mn, l + dp[n - 1][l]);
    printf("%d\n", mn);
  }
  return 0;
}
