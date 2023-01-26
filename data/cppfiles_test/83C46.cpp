#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 5;
int f[N][N], dp[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    f[n + 1][n + 1] = f[n][n + 1] = f[n + 1][n] = 0;
    for (int i = n; i >= 1; i--) {
      for (int j = n; j >= 1; j--) {
        if (s[i] == s[j])
          f[i][j] = f[i + 1][j + 1] + 1;
        else
          f[i][j] = 0;
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      dp[i] = n - i + 1;
      for (int j = 1; j < i; j++) {
        int len = f[i][j];
        if (i + len - 1 <= n && s[i + len] >= s[j + len])
          dp[i] = max(dp[i], dp[j] + n - i + 1 - len);
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
