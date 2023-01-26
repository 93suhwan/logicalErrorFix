#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
const int oo = 2e9;
int dp[2005][2005];
int a[2005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n, k, m;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++) dp[i][j] = -1;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= i; j++)
        if (dp[i][j] >= 0) {
          dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
          dp[i + 1][j + 1] =
              max(dp[i + 1][j + 1], dp[i][j] + (a[i + 1] == j + 1));
        }
    int res = -1;
    for (int i = n; i; i--)
      if (dp[n][i] >= k) {
        res = n - i;
        break;
      }
    cout << res << "\n";
  }
}
