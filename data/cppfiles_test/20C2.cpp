#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
vector<long long int> v;
long long int dp[405][405], dp2[5][405][405], dp3[5][405][405];
char grid[405][405];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int n, m, h, i, j, k, a, b, q, d, c, cnt, cur2,
      sum = 0, sum2 = 0, t, maxn, x = 0, y, z, ans, ans2, idx;
  string str = "", str2, str3;
  char ch;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) cin >> grid[i][j];
    }
    for (i = 0; i < m; i++) {
      for (j = i + 1; j < m; j++) dp[i][j] = 2e9;
    }
    ans = 2e9;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m - 1; j++) {
        dp2[i % 5][j][j + 1] = 0;
        for (k = j + 2; k < m; k++) {
          dp2[i % 5][j][k] = dp2[i % 5][j][k - 1];
          if (grid[i][k - 1] == '0') dp2[i % 5][j][k]++;
        }
        dp3[i % 5][j][j + 1] = 0;
        if (grid[i][j] == '0') dp3[i % 5][j][j + 1]++;
        if (grid[i][j + 1] == '0') dp3[i % 5][j][j + 1]++;
        for (k = j + 2; k < m; k++) {
          dp3[i % 5][j][k] = dp3[i % 5][j][k - 1];
          if (grid[i][k - 1] == '1')
            dp3[i % 5][j][k]++;
          else
            dp3[i % 5][j][k]--;
          if (grid[i][k] == '0') dp3[i % 5][j][k]++;
        }
      }
      if (i >= 4) {
        for (j = 0; j < m; j++) {
          for (k = j + 3; k < m; k++) {
            dp[j][k] -= dp2[(i - 1) % 5][j][k];
            dp[j][k] += dp3[(i - 1) % 5][j][k] + dp2[i % 5][j][k];
            dp[j][k] = min(dp[j][k],
                           dp2[(i - 4) % 5][j][k] + dp2[(i) % 5][j][k] +
                               dp3[(i - 1) % 5][j][k] + dp3[(i - 2) % 5][j][k] +
                               dp3[(i - 3) % 5][j][k]);
            ans = min(ans, dp[j][k]);
          }
        }
      }
    }
    cout << ans << "\n";
  }
}
